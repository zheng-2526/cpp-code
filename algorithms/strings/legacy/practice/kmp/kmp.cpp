#include <bits/stdc++.h>
using namespace std;

string a, b;
int nex[1000005];

void build_nex() {
    int i = 1, j = 0;
    while(1) {
        if(a[i + 1] == a[j + 1]) {
            nex[i + 1] = j + 1;
            i++, j++;
        }
        else {
            if(j == 0) i++;
            else j = nex[j];
        }
        if(i == a.size() - 1) break;
    }
    return;
}

int main() {
    cin>>b>>a;
    a = " " + a, b = " " + b;
    build_nex();
    int i = 0, j = 0;
    while(i < b.size()) {
        if(b[i + 1] == a[j + 1]) {
            j++, i++;
        }
        else {
            if(j == 0) i++;
            else j = nex[j];
        }
        if(j == a.size() - 1) {
            printf("%d\n", i - j + 1);
        }
    }
    for(int i = 1; i <= a.size() - 1; i++) printf("%d ", nex[i]);
    return 0;
}
