#include <bits/stdc++.h>
using namespace std;

string s1, s2;

int main() {
    cin >> s1 >> s2;
    if(s1 == "Ocelot") {
        if(s2 == "Ocelot") {
            printf("Yes");
            return 0;
        }
        else {
            printf("No");
            return 0;
        }
    }
    if(s1 == "Serval") {
        if(s2 == "Lynx") {
            printf("No");
            return 0;
        }
        else {
            printf("Yes");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}