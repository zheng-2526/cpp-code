// 题意或用途（据代码整理）：判断字符串中的圆括号和方括号是否正确嵌套。
// 阅读要点：字符数组模拟栈，t 是栈顶，右括号必须和最近尚未配对的左括号同型。
// 注意：旧写法没有显式判断空栈，正确实现可参考 check.cpp 的结构。

#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int t=0;
    char s[266],z[266];
    cin>>s;               
    int len=strlen(s) ;
    for(int i=0;i<len;i++)   {
        if(s[i]=='['||s[i]=='('){
            z[++t]=s[i];    
        }
        else         {
            if(s[i]==']'){
                if(z[t]=='[')    {              
                    t--;        
                }
                else{
                    cout<<"Wrong";
                    return 0;
                }
            }
            else{ 
                if(z[t]=='(')   {
                    t--;
                }
                else{
                    cout<<"Wrong";
                    return 0;
                }
            }
        }
    }
    if(!t) cout<<"Ya";
    else cout<<"Wrong";
    return 0;
}