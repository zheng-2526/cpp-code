#include <bits/stdc++.h>
using namespace std;

int x, y;

int main() {
    for (int i = 1; i <= 10; i++) {
        // 构造输入输出文件名
        string infile = "zyz" + to_string(i) + ".in";
        string outfile = "zyz" + to_string(i) + ".out";
        
        // 重定向输入输出
        freopen(infile.c_str(), "r", stdin);
        freopen(outfile.c_str(), "w", stdout);
        
        // 你的原逻辑（修正优先级问题）
        cin >> x >> y;
        cout << ((x == y) ? x + 1 : min(x, y) + 2) << endl;
        
        // 关闭重定向（重要！）
        fclose(stdin);
        fclose(stdout);
    }
    
    return 0;
}