#include <bits/stdc++.h>
using namespace std;

int A[3][3];

struct State {
    int grid[3][3];
    int scores[2];
    int turn;

    bool operator<(const State& other) const {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (grid[i][j] != other.grid[i][j]) {
                    return grid[i][j] < other.grid[i][j];
                }
            }
        }
        if (scores[0] != other.scores[0]) return scores[0] < other.scores[0];
        if (scores[1] != other.scores[1]) return scores[1] < other.scores[1];
        return turn < other.turn;
    }
};

map<State, int> memo;

int check_win(const State& state) {
    for (int i = 0; i < 3; ++i) {
        if (state.grid[i][0] != 0 && 
            state.grid[i][0] == state.grid[i][1] && 
            state.grid[i][1] == state.grid[i][2]) {
            return state.grid[i][0];
        }
        if (state.grid[0][i] != 0 && 
            state.grid[0][i] == state.grid[1][i] && 
            state.grid[1][i] == state.grid[2][i]) {
            return state.grid[0][i];
        }
    }
    if (state.grid[0][0] != 0 && 
        state.grid[0][0] == state.grid[1][1] && 
        state.grid[1][1] == state.grid[2][2]) {
        return state.grid[0][0];
    }
    if (state.grid[0][2] != 0 && 
        state.grid[0][2] == state.grid[1][1] && 
        state.grid[1][1] == state.grid[2][0]) {
        return state.grid[0][2];
    }
    bool full = true;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (state.grid[i][j] == 0) {
                full = false;
                break;
            }
        }
    }
    if (full) {
        if (state.scores[0] > state.scores[1]) return 1;
        else return 2;
    }
    return 0;
}

int dfs(State state) {
    int res = check_win(state);
    if (res == 1) return 1;
    if (res == 2) return -1; 

    if (memo.count(state)) return memo[state];

    int best = -1;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (state.grid[i][j] == 0) {
                State next = state;
                next.grid[i][j] = state.turn + 1;
                next.scores[state.turn] += A[i][j];
                next.turn = 1 - state.turn;

                int val = -dfs(next); 
                best = max(best, val);
            }
        }
    }
    memo[state] = best;
    return best;
}

int main() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> A[i][j];
        }
    }
    State initial;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            initial.grid[i][j] = 0;
        }
    }
    initial.scores[0] = initial.scores[1] = 0;
    initial.turn = 0;
    int result = dfs(initial);
    if (result == 1) {
        cout << "Takahashi" << endl;
    } else {
        cout << "Aoki" << endl;
    }

    return 0;
}