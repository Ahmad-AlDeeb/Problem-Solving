                                                    // problem link: https://atcoder.jp/contests/abc220/tasks/abc220_a?lang=en
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
    int a{}, b{}, c{}; cin >> a >> b >> c;
    for(int i{a}; i<=b; i++)
        if(i%c == 0) {cout << i; return 0;}
    cout << -1;
}
