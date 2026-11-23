// 题意或用途（据代码整理）：用直接插入排序将数组升序排列。
// 阅读要点：每轮把 a[i] 插进左侧有序前缀，向右挪比它大的数，直到找到插入位置。

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
int n;
int a[1009];
 
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int t = a[i];
        for (int j = i - 1; j >= 0; j--) {
            if (a[j] > t) {
                a[j + 1] = a[j];
                if (j == 0 && a[j] > t) {
                a[j + 1] = a[j];
                a[j] = t;
                }
            }
            else {
                a[j + 1] = t;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) cout << a[i] << " ";
 
    return 0;
}