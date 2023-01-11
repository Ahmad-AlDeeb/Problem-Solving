                                        // problem link: https://codeforces.com/group/jfviGllBoY/contest/379280/problem/D
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define dd double
#define ld long double
#define PQ priority_queue
#define pii pair<int,int>
#define pll pair<ll,ll>
#define S second
#define F first
#define MP make_pair
#define dpp(arr,val) memset(arr,val,sizeof(arr))
#define endl "\n"
using namespace std;
int main() { IOS
    int n{}; cin >> n;
    int ans{};
    if(n>=50) {ans+=(n/50); n%=50;}
    if(n>=25) {ans+=(n/25); n%=25;}
    if(n>=10) {ans+=(n/10); n%=10;}
    if(n>=5) {ans+=(n/5); n%=5;}
    if(n>=1) {ans+=(n/1); n%=1;}

    cout << ans;
}
