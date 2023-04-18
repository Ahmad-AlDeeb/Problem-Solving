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
const ll M = 1e9+7;
ll power(ll x, ll y) {
    ll ans{1};
    while(y) {
        if(y&1) ans = ((ans%M)*(x%M)) % M;
        x = ((x%M) * (x%M)) %M;
        y/=2;
    }
    return ans;
}
vector<ll> di {1,-1,1,-1};
vector<ll> dj {1,1,-1,-1};

int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll tc; cin >> tc;
    while(tc--) {
        ll n,q; cin >> n >> q;
        vector<ll>vec(n);
        ll odds{},evens{},odds_sum{},evens_sum{};
        for(auto &i:vec) {
            cin >> i;
            if(i&1) {odds++; odds_sum += i;}
            else {evens++; evens_sum+=i;}
        }

        while(q--) {
            ll type,x; cin >> type >> x;

            if(type && (x&1) or !type && !(x&1)) {
                if(type) {
                    odds_sum += odds*x;
                    evens_sum += odds_sum;
                    evens += odds;
                    odds = odds_sum = 0;
                }
                else evens_sum += evens*x;
            }
            else {
                if(type) odds_sum += odds*x;
                else {
                    evens_sum += evens*x;
                    odds_sum += evens_sum;
                    odds += evens;
                    evens = evens_sum = 0;
                }
            }
            cout << odds_sum + evens_sum << endl;
        }

    }
}
