#include <bits/stdc++.h>
using namespace std;

int main() {
    char *p;
    char a = 97;
    p = &a; // Pointer p now points to the address of a
    cout << p << endl; // Output the address stored in p
    cout << *p << endl; // Output the value at the address stored in p (which is a)
    cout << a << endl; // Output the value of a
    a++;
    cout << *p << endl; // Output the updated value at the address stored in p (which is now a + 1)
    cout << a << endl; // Output the updated value of a
    (*p)++; // Increment the value at the address stored in p
    cout << *p << endl; // Output the value at the address stored in p after incrementing
    cout << a << endl; // Output the value of a after incrementing through p
    return 0;
}