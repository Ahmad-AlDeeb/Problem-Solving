                                                    // problem link: https://atcoder.jp/contests/abc103/tasks/abc103_c
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
    int current{}, sum{};
    for(int i{}; i<n; i++) {
        cin >> current;
        sum += current-1; // max value for each term will give us the max value for f(m)
    }
    cout << sum;
}
