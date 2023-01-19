#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define x first
#define y second
#define dd double
#define ll long long
#define ld long double
#include<unordered_set>

int main() { IOS // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        vector<ll>vec(n);
        ll k{};
        for(auto &i:vec) {
            cin >> i;
            while(i%2 == 0) {i/=2; k++;}
        }
        sort(vec.begin(),vec.end());
        vec.back()*= pow(2,k);

        ll ans{};
        for(auto num:vec) ans += num;
        cout << ans << endl;
    }
}
