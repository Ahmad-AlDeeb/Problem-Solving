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
#include<unordered_set>
#include<map>
#include<bitset>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define F first
#define S second
#define dd double
#define ll long long
#define ld long double
#define pb push_back
#define all(v) v.begin(), v.end()
const ll inf = 1e17;
const ll M = 1e5;

int main() { IOS // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        vector<vector<ll>>freq(n+1,vector<ll>(n));
        for(ll i{1}; i<=n; i++)
            for(ll j{1}; j<n; j++) {
                ll num; cin >> num;
                freq[num][j]++;
            }


        vector<ll>ans(n+1);
        ll last{};
        for(ll i{1}; i<=n; i++)
            if(freq[i].back() == n-1)
                {last = i; break;}
        ans.back() = last;


        for(ll i{1}; i<=n; i++) {
            if(i == last) continue;
            ll maxi{};
            for(ll j{1}; j<n; j++)
                if(freq[i][j]) maxi=j;
            ans[maxi] = i;
        }
        for(ll i{1}; i<=n; i++) cout << ans[i] << " ";
        cout << endl;
    }
}
