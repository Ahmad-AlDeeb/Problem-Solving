                                        // problem link: https://codeforces.com/group/6FyLsqC8Xx/contest/379621/problem/E
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
        vector<int> a (n, 0);
        for(int i{}; i<n; i++)
            cin >> a.at(i);

        sort(a.begin(), a.end());
        for(int i{}; i<n-1; i++)
            if(abs(a.at(i)-a.at(i+1)) > 1)
                {cout << "NO" << endl; goto t_end;}
        cout << "YES" << endl;
        t_end:;
    }
}
