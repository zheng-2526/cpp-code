#include <bits/stdc++.h>
using namespace std;

struct node{
    int lx, ly, rx,ry;
}a[5005];

int n, t[5005];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d%d%d%d", &a[i].lx, &a[i].ly, &a[i].rx, &a[i].ry);
        for(int j = 1; j < i; j++) {
            if(a[i].lx <= a[j].rx && a[i].ly <= a[j].ry && a[i].lx >= a[j].lx && a[i].ly >= a[j].ly)
                t[i]++, t[j]++;
            else if(a[i].lx <= a[j].rx && a[i].ry >= a[j].ly && a[i].lx >= a[j].lx && a[i].ry <= a[j].ry)
                t[i]++, t[j]++;
            else if(a[i].rx >= a[j].lx && a[i].ry >= a[j].ly && a[i].rx <= a[j].rx && a[i].ry <= a[j].ry)
                t[i]++, t[j]++;
            else if(a[i].rx >= a[j].lx && a[i].ly <= a[j].ry && a[i].rx <= a[j].rx && a[i].ry >= a[j].ry)
                t[i]++, t[j]++;
            else if(a[j].lx <= a[i].rx && a[j].ly <= a[i].ry && a[j].lx >= a[i].lx && a[j].ly >= a[i].ly)
                t[i]++, t[j]++;
            else if(a[j].lx <= a[i].rx && a[j].ry >= a[i].ly && a[j].lx >= a[i].lx && a[j].ry <= a[i].ry)
                t[i]++, t[j]++;
            else if(a[j].rx >= a[i].lx && a[j].ry >= a[i].ly && a[j].rx <= a[i].rx && a[j].ry <= a[i].ry)
                t[i]++, t[j]++;
            else if(a[j].rx >= a[i].lx && a[j].ly <= a[i].ry && a[j].rx <= a[i].rx && a[j].ry >= a[i].ry)
                t[i]++, t[j]++;
        }
    }
    for(int i = 1; i <= n; i++) {
        printf("%d ", t[i]);
    }
}