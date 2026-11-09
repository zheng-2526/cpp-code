#include <bits/stdc++.h>
using namespace std;
 
stack<char> a;
 
int main(){
    char x;
    while ( cin >> x ){
        if ( x != ')' ){
            a.push (x);
            continue;
        }
        char v1 = a.top();
        a.pop();
        char op = a.top();
        a.pop();
        if( op == '!' ){
            if( v1 == '0' )v1 = '1';
            else v1 = '0';
            a.pop();
            a.push(v1);
            continue;
        }
        char v2 = a.top();
        a.pop();
        char v = '0';
        if( op == '|' )
            v += (v1-'0') || (v2-'0');
        else v += (v1-'0') && (v2-'0');
        a.pop();
        a.push(v);
    }
    cout << a.top();
    return 0;
}