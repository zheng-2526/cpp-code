// 题意或用途（据代码整理）：按输入类别分别用不同阈值判断身高与体重，给出题面要求的两段提示。
// 阅读要点：两项相互独立，每项都有小于、等于和大于三种情况。这是条件分支练习。

#include <bits/stdc++.h>
using namespace std;

int sex, hi, we, T;

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &sex, &hi, &we);
        if(sex == 1) {
            if(hi < 130) printf("duo chi yu! ");
            else if(hi == 130) printf("wan mei! ");
            else printf("ni li hai! ");
            if(we < 27) printf("duo chi rou!\n");
            else if(we == 27) printf("wan mei!\n");
            else printf("shao chi rou!\n");
        }
        else {
            if(hi < 129) printf("duo chi yu! ");
            else if(hi == 129) printf("wan mei! ");
            else printf("ni li hai! ");
            if(we < 25) printf("duo chi rou!\n");
            else if(we == 25) printf("wan mei!\n");
            else printf("shao chi rou!\n");
        }
    }
}