                                                    // problem link: https://atcoder.jp/contests/abc175/tasks/abc175_c
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

int main() { IOS
    ll x{}, k{}, d{}; cin >> x >> k >> d;
    x = abs(x); // we can work only on the positive as they are identical to negative numbers

    ll steps{x/d}; // steps needed to reach 0 or get near 0
    if(k >= steps) { // if we have more k than the steps needed to get near 0, we subtract only distance by those steps
        k -= steps;
        x -= steps*d;

        if(k%2==0) cout << x; // if the remaining k are even we will end up going back and fourth till we hit the same number
        else cout << abs(x-d); // if the remaining k are odd we will just subtract it from x and output result
    }
    else cout << x - (k*d); // if we don't have k more than steps, then we just subtract total distance since we won't pass 0
}
