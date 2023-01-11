                                                    // problem link: https://codeforces.com/problemset/problem/1537/A
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
    int t{}; cin >> t;
    while(t--) {
        int n{}; cin >> n;

        ll sum{};
        for(int i{}; i<n; i++) {
            ll num{}; cin >> num;
            sum += num;
        }

        if(sum > n) cout << sum-n << endl; // we add zeros which will make n equal to sum without changing sum
        else if(sum < n) cout << 1 << endl; // we add just one number which is n-sum+1
        else cout << 0 << endl; // otherwise they already equal so we don't need any operations
    }
}
