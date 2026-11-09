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