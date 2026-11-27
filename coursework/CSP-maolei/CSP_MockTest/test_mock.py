"""生成合法测试点，编译并自测 C、D、E。运行 python test_mock.py --stress。"""

import argparse
from collections import deque
from fractions import Fraction
import os
from pathlib import Path
import random
import shutil
import subprocess
import tempfile

ELEMENTS = (
    "h he li be b c n o f ne na mg al si p s cl ar k ca "
    "sc ti v cr mn fe co ni cu zn ga ge as se br kr rb sr y zr"
).split()


def check(exe, case, data, expected):
    result = subprocess.run([str(exe)], input=data, capture_output=True, text=True, timeout=10)
    actual = result.stdout.split()
    if result.returncode or actual != expected.split():
        raise AssertionError(
            f"{exe.stem} / {case}: exit={result.returncode}\n"
            f"input: {data[:800]}\nexpected: {expected[:800]}\n"
            f"output: {result.stdout[:800]}\n{result.stderr}"
        )


def exact_rank(matrix):
    rows = [list(map(Fraction, row)) for row in matrix]
    rank = 0
    for col in range(len(rows[0])):
        pivot = next((i for i in range(rank, len(rows)) if rows[i][col]), None)
        if pivot is None:
            continue
        rows[rank], rows[pivot] = rows[pivot], rows[rank]
        for i in range(rank + 1, len(rows)):
            if rows[i][col]:
                factor = rows[i][col] / rows[rank][col]
                for j in range(col, len(rows[i])):
                    rows[i][j] -= factor * rows[rank][j]
        rank += 1
    return rank


def first_prime_minor():
    # 用负进制构造一个行列式绝对值为 1000000007 的矩阵。
    digits = []
    value = 1000000007
    while value:
        digit = value % 10
        digits.append(digit)
        value = (digit - value) // 10
    size = len(digits)
    matrix = [digits[::-1]] + [[0] * size for _ in range(size - 1)]
    for i in range(1, size):
        matrix[i][i - 1] = 1
        matrix[i][i] = 10
    return matrix


def test_formula(exe, rng):
    matrices = [
        [[1]],
        [[1, 50]],
        [[12, 6], [4, 3], [0, 9]],
        [[4, 12, 0], [0, 0, 7]],
        [[3, 7, 10], [6, 1, 7], [8, 7, 15]],
        [[1 if i == j else 50 if i == j + 1 else 0 for j in range(40)] for i in range(40)],
        [[50 if i == j else 0 for j in range(40)] for i in range(40)],
        first_prime_minor(),
    ]
    for _ in range(100):
        height, width = rng.randint(1, 8), rng.randint(1, 8)
        matrix = [[rng.randint(0, 50) for _ in range(width)] for _ in range(height)]
        for col in range(width):
            if not any(row[col] for row in matrix):
                matrix[0][col] = 1
        if width > 1 and rng.randrange(3) == 0:
            for row in matrix:
                row[-1] = row[0]
        matrices.append(matrix)

    for start in range(0, len(matrices), 10):
        batch = matrices[start:start + 10]
        data = [str(len(batch))]
        expected = []
        for matrix in batch:
            formulas = [
                "".join(f"{name}{count}" for name, count in zip(ELEMENTS, col) if count)
                for col in zip(*matrix)
            ]
            data.append(f"{len(formulas)} " + " ".join(formulas))
            expected.append("Y" if exact_rank(matrix) < len(formulas) else "N")
        check(exe, f"equations {start + 1}..{start + len(batch)}", "\n".join(data) + "\n", " ".join(expected))
    return len(matrices)


def hopscotch_data(a, k):
    return f"{len(a)}\n" + " ".join(map(str, a)) + "\n" + " ".join(map(str, k)) + "\n"


def brute_hops(a, k):
    n = len(a)
    queue = deque([(0, 0)])
    seen = {0}
    while queue:
        pos, steps = queue.popleft()
        if pos == n - 1:
            return steps
        for landing in range(pos + 1, min(n, pos + k[pos] + 1)):
            to = landing - a[landing]
            if to not in seen:
                seen.add(to)
                queue.append((to, steps + 1))
    return -1


def test_hops(exe, rng, stress):
    cases = [
        ([0], [0]),
        ([0, 0], [0, 0]),
        ([0, 0], [2, 0]),
        ([0, 1, 2, 0], [2, 3, 3, 0]),
        ([0, 0, 0, 2, 0, 0], [3, 0, 3, 0, 0, 0]),
        ([0, 0, 1, 0, 3, 3, 0], [3, 1, 2, 3, 2, 1, 0]),
    ]
    for _ in range(144):
        n = rng.randint(1, 35)
        cases.append(([rng.randint(0, i) for i in range(n - 1)] + [0],
                      [rng.randint(0, n) for _ in range(n)]))
    for i, (a, k) in enumerate(cases, 1):
        check(exe, f"board {i}", hopscotch_data(a, k), str(brute_hops(a, k)))
    if stress:
        n = 200_000
        check(exe, "long chain", hopscotch_data([0] * n, [1] * n), str(n - 1))
        check(exe, "overlapping ranges", hopscotch_data([0] * n, [n - 2] * n), "2")
        return len(cases) + 2
    return len(cases)


def burst(water, p):
    water[p] += 1
    while True:
        x = min((x for x, w in water.items() if w >= 5), default=None)
        if x is None:
            return len(water)
        del water[x]
        left = max((y for y in water if y < x), default=None)
        right = min((y for y in water if y > x), default=None)
        for neighbor in (left, right):
            if neighbor is not None:
                water[neighbor] += 1


def drops_data(width, initial, ops):
    cells = "".join(f"{x} {w}\n" for x, w in initial.items())
    return f"{width} {len(initial)} {len(ops)}\n" + cells + "\n".join(map(str, ops)) + "\n"


def test_drops(exe, rng, stress):
    cases = [
        (1, {1: 1}, [1, 1, 1, 1]),
        (4, {4: 4, 1: 3, 3: 4, 2: 4}, [3]),
        (10**9, {10**9: 1, 500_000_000: 4, 1: 4}, [500_000_000, 10**9, 10**9]),
        (7, {1: 4, 2: 1, 7: 2}, [1, 7, 2, 7, 7]),
    ]
    for _ in range(146):
        width = rng.randint(1, 70)
        positions = rng.sample(range(1, width + 1), rng.randint(1, min(18, width)))
        initial = {x: rng.randint(1, 4) for x in positions}
        water = initial.copy()
        ops = []
        for _ in range(rng.randint(1, 4 * len(initial))):
            if not water:
                break
            p = rng.choice(list(water))
            ops.append(p)
            burst(water, p)
        cases.append((width, initial, ops))
    for i, (width, initial, ops) in enumerate(cases, 1):
        water = initial.copy()
        expected = " ".join(str(burst(water, p)) for p in ops)
        check(exe, f"game {i}", drops_data(width, initial, ops), expected)
    if stress:
        m = 300_000
        positions = range(1, 1 + 3333 * m, 3333)
        initial = dict.fromkeys(reversed(positions), 4)
        check(exe, "maximum cascade", drops_data(10**9, initial, [positions[m // 2]]), "0")
        initial = dict.fromkeys(reversed(positions), 1)
        ops = list(positions) * 3
        check(exe, "900000 legal operations", drops_data(10**9, initial, ops), f"{m} " * len(ops))
        return len(cases) + 2
    return len(cases)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--compiler", default="g++")
    parser.add_argument("--stress", action="store_true")
    args = parser.parse_args()
    compiler = shutil.which(args.compiler)
    if compiler is None:
        parser.error(f"compiler not found: {args.compiler}")
    os.environ["PATH"] = str(Path(compiler).parent) + os.pathsep + os.environ.get("PATH", "")

    root = Path(__file__).resolve().parent
    rng = random.Random(1292)
    with tempfile.TemporaryDirectory(prefix="csp-mock-test-") as directory:
        for name, test in [
            ("formlar", lambda exe: test_formula(exe, rng)),
            ("hopscotch", lambda exe: test_hops(exe, rng, args.stress)),
            ("tendrops", lambda exe: test_drops(exe, rng, args.stress)),
        ]:
            exe = Path(directory) / f"{name}.exe"
            subprocess.run(
                [compiler, "-std=c++17", "-O2", "-Wall", "-Wextra", "-pedantic",
                 str(root / f"{name}.cpp"), "-o", str(exe)],
                check=True,
            )
            print(f"{name}: {test(exe)} cases passed", flush=True)


if __name__ == "__main__":
    main()
