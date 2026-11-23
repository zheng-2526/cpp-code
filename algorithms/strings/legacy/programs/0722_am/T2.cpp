// 题意或用途（据代码整理）：尝试输出 Jam 递增字符序列之后的至多五个字典序后继。
// 阅读要点：从右找可增的位置，增一后把右侧重置为尽可能小的严格递增后缀。
// 注意：循环跳过下标 0，且边界比较需对照具体字符范围。

#include <bits/stdc++.h>
using namespace std;
int s, t, w;
string jam;
int main()
{
	cin >> s >> t >> w >> jam;
	for (int i = 1; i <= 5; i++) // 最多加 5 次 1
	{
		bool flag = true; // 记录能不能加 1
		for (int j = w - 1; j; j--) // 从右往左扫描
		{
			if (jam[j] - 'a' + 1 <= j - w + t) // 如果这一位无需进位
			{ // 注意在 Jam 数字中第 j 位只能达到 j - w + t
				jam[j]++;
				for (int k = j + 1; k < w; k++)
                    jam[k] = jam[k - 1] + 1;
				cout << jam << '\n';
				flag = false; // 能加 1
				break;
			}
		}
		if (flag) // 不能加 1
		    break;
	}
	return 0;
}