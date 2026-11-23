// 题意或用途（据代码整理）：读取二叉树节点及左右孩子，尝试求树深度和最大层宽。
// 阅读要点：递归向下时深度加一，对应层的节点数累加，返回上层时恢复深度。
// 注意：程序虽然寻找根节点，最后却固定从 1 开始，且行号与节点编号的映射需核对。

#include <bits/stdc++.h>
using namespace std;
 
int a[30][4], n, d, w[31], dm, ans;
bool chi[31],pa[31];
 
void dfs(int k) {
    if(a[k][1] == 0) {
        d = max(d, dm);
        return;
    }
    dm++;
    w[dm]++;
    dfs(a[k][2]);
    dfs(a[k][3]);
    dm--;
}
 
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
        chi[a[i][2]] = chi[a[i][3]] = 1;
        pa[a[i][1]] = 1;
    }
    for(int i = 1; i <= n; i++) {
        if(!chi[i] && pa[i]) {
            dfs(1);
            break;
        }
    }
    for(int i = 1; i <= n; i++) {
        ans = max(ans, w[i]);
    }
    printf("%d %d", d, ans);
    return 0;
}