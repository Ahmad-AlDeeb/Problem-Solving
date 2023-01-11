                                                    // problem link: https://codeforces.com/group/jfviGllBoY/contest/374705/problem/B
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
    int n{}, m{}, k{}; cin >> n >> m >> k;
    if(n==0 || k==0) {cout << 0; return 0;}
 
    int smallest{n};
    if(m<smallest && m<k) smallest = m;
    if(k<smallest && k<m) smallest = k;
 
    int ans{smallest};
    n -= smallest; m -= smallest; k -= smallest;
    if(n==0 || k==0) {cout << ans; return 0;}
    else ans += min(n/2, k);
    cout << ans;
}
