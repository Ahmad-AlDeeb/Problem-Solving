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
bool is_prime(ll x) {

    for(ll i{2}; i*i<=x; i++)
        if(x%i == 0) return false;
    return true;
}

int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        map<ll,ll>f;
        vector<ll>vec(n); for(auto &i:vec) {cin >> i; f[i]++;}
        if(f.size()==1) {cout << "YES" << endl; continue;}

        ll cnt{};
        bool down{false},up{false};
        for(ll i{}; i<n-1; i++) {
            if(vec[i+1] < vec[i] && !down) {down=true; up=false;}
            if(vec[i+1] > vec[i] && !up) {
                up = true; down=false;
                cnt++;
            }
        }
        if(down) cnt++;
        if(cnt > 1) cout << "NO"; else cout << "YES";
        cout << endl;
    }
}
