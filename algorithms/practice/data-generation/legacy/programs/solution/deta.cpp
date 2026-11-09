#include <bits/stdc++.h>
#include <chrono>  // chrono 库
using namespace std;

int main() {
    // 使用毫秒级时间戳作为种子
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    default_random_engine e(seed);
    uniform_int_distribution<int> v(1, 1e9);
    
    for (int i = 4; i <= 10; i++) {
        string filename = "zyz" + to_string(i) + ".in";
        ofstream fout(filename);
        
        int n = v(e), x = v(e);
        fout << n << " " << x << endl;  // 两个相同的数
        
        fout.close();
        cout << "已生成: " << filename << " -> " << n << " " << x << endl;
    }
    
    return 0;
}