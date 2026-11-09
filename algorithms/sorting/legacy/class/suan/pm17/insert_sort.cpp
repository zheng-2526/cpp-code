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