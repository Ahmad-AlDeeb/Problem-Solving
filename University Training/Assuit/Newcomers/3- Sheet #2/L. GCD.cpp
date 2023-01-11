#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    int a{}, b{}; cin >> a >> b;
    int small = min(a,b);
    for(; small >= 1; small--)
        if(a%small==0 && b%small==0)
            break;
    cout << small;
}
