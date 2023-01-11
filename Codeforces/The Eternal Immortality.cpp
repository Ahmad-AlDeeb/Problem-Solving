                                                    // problem link: https://codeforces.com/problemset/problem/869/B
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
    ll a{}, b{}; cin >> a >> b;
    ll diff{b-a}; // diff is the count of numbers b will multiply itself

    ll digit {1};
    for(int i{}; i<diff; i++) {
        digit = (digit * b--) % 10; // we only need last digit
        if(digit == 0) break; // we got 0 no need to continue  multiplying since result will always be 0
    }
    cout << digit;
}
