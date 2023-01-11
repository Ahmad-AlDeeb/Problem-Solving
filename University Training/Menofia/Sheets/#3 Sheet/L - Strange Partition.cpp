                                                    // problem link: https://codeforces.com/problemset/problem/1471/A
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

ll get_beauty(ll num, ll x) { // get the beauty number by dividing by x and ceiling
    return ceil((ld)num/x);
}

int main() { IOS
    int t{}; cin >> t;
    while(t--) { // loop over test cases
        ll n{}, x{}; cin >> n >> x;
        vector<ll>vec(n,0); bool is_equal{true}; // max and mix are equal if all values % x == 0
        for(int i{}; i<n; i++) {
            cin >> vec[i];
            if(vec[i]%x != 0) is_equal = false;
        }
        ll max{};
        for(ll num: vec) max += get_beauty(num, x); // max would be without any operations
        // we don't waste time on calculating min if all values are devisable by x hence, min and max are the same
        if(is_equal) {cout << max << " " << max << endl; continue;}

        ll total{}; // min would be with getting the sum of all of them which can minimize the beauty number as possible
        for(ll num: vec) total += num;
        ll min = get_beauty(total,x);
        cout << min << " " << max << endl;
    }
}
