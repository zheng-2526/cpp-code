#include <bits/stdc++.h>
using namespace std;

struct node{
    int a, b, st;
}xx;

int x, y, z;
bool vis[105][105];

queue<node> a;

int main() {
    vis[0][0] = 1;
    scanf("%d%d%d", &x, &y, &z);
    if(x < z && y < z) {
        printf("No Solution!");
        return 0;
    }
    if(x == z || y == z) {
        printf("1");
        return 0;
    }
    a.push({0, 0, 0});
    while(1) {
        xx = a.front();
        a.pop();
        if(xx.a == z || xx.b == z) {
            printf("%d", xx.st);
            return 0;
        }
        if(xx.a == z || xx.b == z) printf("%d", xx.st);
        if(!vis[x][xx.b]) {
            a.push({x, xx.b, xx.st + 1});
            vis[x][xx.b] = 1;
        }
        if(!vis[0][xx.b]) {
            a.push({0, xx.b, xx.st + 1});
            vis[0][xx.b] = 1;
        }
        if(!vis[xx.a][y]) {
            a.push({xx.a, y, xx.st + 1});
            vis[xx.a][y] = 1;
        }
        if(!vis[xx.a][0]) {
            a.push({xx.a, 0, xx.st + 1});
            vis[xx.a][0] = 0;
        }
        if(xx.a > 0 && xx.b < y) {
            if(xx.b + xx.a > y) {
                if(!vis[xx.a - y + xx.b][y]) {
                    a.push({xx.a - y + xx.b, y, xx.st + 1});
                    vis[xx.a - y + xx.b][y] = 1;
                }
            }
            else {
                if(!vis[0][xx.a + xx.b]) {
                    a.push({0, xx.a + xx.b, xx.st + 1});
                    vis[0][xx.a + xx.b] = 1;
                }
            }
        }
        if(xx.b > 0 && xx.a < y) {
            if(xx.a + xx.b > x) {
                if(!vis[x][xx.b - x + xx.a]) {
                    a.push({x, xx.b - x + xx.a, xx.st + 1});
                    vis[x][xx.b - x + xx.a] = 1;
                }
            }
            else {
                if(!vis[xx.b + xx.a][0]) {
                    a.push({xx.b + xx.a, 0, xx.st + 1});
                    vis[xx.b + xx.a][0] = 1;
                }
            }
        }
    }
    return 0;
}