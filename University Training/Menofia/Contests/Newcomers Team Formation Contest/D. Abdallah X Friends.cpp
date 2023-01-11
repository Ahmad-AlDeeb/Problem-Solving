                                        // problem link: https://codeforces.com/group/6FyLsqC8Xx/contest/379621/problem/D
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
    int n{}, m{}; cin >> n >> m;

    for(int i{1};; i++) {
        if(i>n) i = 1;
        if(m < i) break;
        m -= i;
    }
    cout << m;
}
