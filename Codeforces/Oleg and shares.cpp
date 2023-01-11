                                                    // problem link: https://codeforces.com/problemset/problem/793/A
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
    ll n{}, k{}; cin >> n >> k;

    vector<ll> prices (n, 0);
    ll smallest{1000000001}, current{};
    for(int i{}; i<n; i++) {
        cin >> current;
        prices[i] = current;
        if(current < smallest) // to detect smallest price between them
            smallest = current;
    }
    ll count{};
    for(ll price: prices) {
        ll diff {price-smallest};
        if(diff%k == 0) // if the difference is not devisable by k, then we can't make all prices equal and we print -1
            count += diff/k; // if it's devisable, then we store how many seconds we need to make current price as smallest price
        else {cout << -1; return 0;}
    }
    cout << count;
}
