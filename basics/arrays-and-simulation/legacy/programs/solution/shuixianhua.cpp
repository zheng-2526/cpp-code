#include <bits/stdc++.h>
using namespace std;

bool isShuixianhua(int x) {
    int sum = 0, temp = x;
    while (temp > 0) {
        sum += (temp % 10) * (temp % 10) * (temp % 10);
        temp /= 10;
    }
    return sum == x;
}

int main() {
    for(int i = 100; i <= 1000; i++) {
        if(isShuixianhua(i)) {
            cout << i << '\n';
        }
    }
}