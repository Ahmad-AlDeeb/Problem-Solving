                                                    // problem link: https://codeforces.com/problemset/problem/231/A
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

    int x{}, count{}, ans{};
    for(int i{}; i<n; i++) { // loop over problems n
        count = 0; // reset count for how many of them can solve this problem
        for(int j{}; j<3; j++) { // loop over each person to see he did solve it or not (we increment count if she knows)
            cin >> x;
            if(x == 1) count++;
        }
        if(count > 1) ans++; // if 2 or 3 persons knows, then we increment number of ans
    }
    cout << ans;
}
