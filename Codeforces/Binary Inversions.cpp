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
        vector<ll>vec(n); for(auto &i:vec) cin >> i;
        vector<ll>vec0(vec); for(auto &i:vec0) if(!i) {i=1; break;}
        vector<ll>vec1(vec); for(ll i{n-1}; i>=0; i--) if(vec[i]) {vec1[i]=0; break;}

        ll ans{},ones{}, ans0{},ones0{}, ans1{},ones1{};
        for(ll i{}; i<n; i++) {
            if(vec[i]) ones++;
            else ans += ones;

            if(vec0[i]) ones0++;
            else ans0 += ones0;

            if(vec1[i]) ones1++;
            else ans1 += ones1;
        }
        cout << max({ans,ans0,ans1}) << endl;
    }
}
