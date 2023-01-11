                                                    // problem link: https://atcoder.jp/contests/abc133/tasks/abc133_c
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
    ll l{}, r{}; cin >> l >> r;
    ll current{}, smallest = (l*r) % 2019;

    for(ll i{l}; i<r; i++) // we simply try all possible combination
        for(ll j{i+1}; j<=r; j++) {
            current = (i*j) % 2019;
            if(current == 0) {cout << 0; return 0;} // if we got 0, we can't get any smaller value so we stop the loop
            if(current < smallest) smallest = current;
        }
    cout << smallest;
}
