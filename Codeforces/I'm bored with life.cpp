                                                    // problem link: https://codeforces.com/contest/822/problem/A
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define dd double
#define ld long double
#define PQ priority_queue
#define pii pair<int,int>
#define pll pair<ll,ll>
//#define S second
//#define F first
#define MP make_pair
#define dpp(arr,val) memset(arr,val,sizeof(arr))
#define endl "\n"
using namespace std;
int gcd(int a, int b) {
    if(a%b) return gcd(b, a%b);
    return b;
}
int fact(int x) {
    if(x==0 || x==1) return 1;
    else return x * fact(x-1);
}
int main() { IOS
    int a{}, b{}; cin >> a >> b;
    int mini = min(a, b); // there's very small one between them, we get it and that's is our GCD lol
    cout << fact(mini);
}
