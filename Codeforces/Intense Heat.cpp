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
int comp_double(ld a, ld b) {
    if(fabs(a-b) <= 1e-10) return -1;
    return a>b? 1:0;
}

int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll n,k; cin >> n >> k;
    vector<ll>vec(n); for(auto &i:vec) cin >> i;
    for(ll i{1}; i<n; i++) vec[i] += vec[i-1];

    ld maxi{};
    for(ll i{k}; i<=n; i++) {
        if(!comp_double(maxi,vec[i-1]/(ld)i)) maxi = vec[i-1]/(ld)i;
        for(ll start{1},end{i}; end<n; start++,end++) {
            ld avg = (vec[end]-vec[start-1])/(ld)i;
            if(!comp_double(maxi,avg)) maxi = avg;
        }
    }
    cout << fixed << setprecision(15) << maxi;
}
