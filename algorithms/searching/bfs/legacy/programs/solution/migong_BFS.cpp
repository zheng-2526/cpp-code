#include<bits/stdc++.h>
using namespace std;

int n, m;
bool a[1005][1005], vis[1005][1005]; //a数组是用来保存地图的状态的，能不能走， vis有没有被走过
int dx[5] = {0, 0, 0, 1, -1};
int dy[5] = {0, 1, -1, 0, 0};

struct node{
    int x, y, st;
};

queue<node> q;

int main() {
    cin >> n >> m;
    getchar();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            char c;
            c = getchar();
            if(c == '.') a[i][j] = 1;
        }
        getchar();
    }
    q.push({1, 1, 0});
    while(!q.empty()) {
        node tmp = q.front(); // 把队头元素取出，用来扩展
        q.pop(); // 队头元素出队

        // 开始扩展，从当前位置往上下左右四个方向扩展
        for(int i = 1; i <= 4; i++) {
            if(a[tmp.x + dx[i]][tmp.y + dy[i]] && !vis[tmp.x + dx[i]][tmp.y + dy[i]]) {//这个点不是障碍物，也没被走过
                if(tmp.x + dx[i] == n && tmp.y + dy[i] == m) {//这个点是终点
                    cout << tmp.st + 1;
                    return 0;
                }
                q.push({tmp.x + dx[i], tmp.y + dy[i], tmp.st + 1});//不是终点时入队
                vis[tmp.x + dx[i]][tmp.y + dy[i]] = 1;
            }
        }
    }
    cout << "No solution";
}