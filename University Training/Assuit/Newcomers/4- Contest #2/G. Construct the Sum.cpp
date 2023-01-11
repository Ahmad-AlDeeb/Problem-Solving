#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define dd double
#define ld long double
#define PQ priority_queue
#define pii pair<int,int>
#define pcc pair<char, char>
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
        ll n{}, s{}; cin >> n >> s;
        ll sum {(1+n)*(n)/2};
        if(sum < s) cout << -1 << endl;

        else {
            int i{};
            while(s >= n-i) {
                s -= (n-i);
                cout << n-i << " ";
                i++;
            }
            cout << s << endl;
        }
    }
}
