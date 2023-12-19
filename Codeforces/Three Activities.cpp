#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
#define ld long double
#define F first
#define S second
#define vll vector<long long>
#define pb push_back
#define all(v) v.begin(), v.end()
///////////////////////////////////////
const ll N = 1e7+7;
const ll M = 998244353;
const ll MAX = 1e18;
const ld EPS = 1e-19;
ll pow(ll x, ll y) {
    ll ans{1};
    while(y) {
        if(y&1) ans *= x;
        x *= x;
        y /= 2;
    }
    return ans;
}
ll big_pow(ll x, ll y) {
    ll ans{1};
    while(y) {
        if(y&1) ans = ((ans%M)*(x%M)) % M;
        x = ((x%M) * (x%M)) %M;
        y/=2;
    }
    return ans;
}
bool is_int(ld num) {
    return num == (ll)num;
}
int cmp_d(ld a, ld b) {
    if(fabs(a-b) <= EPS) return -1;
    return a>b? 1:0;
}
ll mod(ll x, ll m){
    return (x%m +m) % m;
}
///█████████████████████████████████████████████████████ Solution ██████████████████████████████████████████████████████
void fast() {
    ll n; cin >> n;
    map<ll,vll> a,b,c;

    //////////////////////////
    for(ll i{}; i<n; i++) {
        ll x; cin >> x;
        a[x].pb(i);
    }
    vector<pair<ll,ll>> ski;
    for (auto rit = a.rbegin(); rit != a.rend() && ski.size()<3; ++rit) {
        ll friends{rit->first};
        vll index{rit->second};
        for(auto i:index) {
            ski.emplace_back(friends,i);
            if(ski.size()==3) break;
        }
    }
    //////////////////////////
    for(ll i{}; i<n; i++) {
        ll x; cin >> x;
        b[x].pb(i);
    }
    vector<pair<ll,ll>> movie;
    for (auto rit = b.rbegin(); rit != b.rend() && movie.size()<3; ++rit) {
        ll friends{rit->first};
        vll index{rit->second};
        for(auto i:index) {
            movie.emplace_back(friends,i);
            if(movie.size()==3) break;
        }
    }

    //////////////////////////
    for(ll i{}; i<n; i++) {
        ll x; cin >> x;
        c[x].pb(i);
    }
    vector<pair<ll,ll>> game;
    for (auto rit = c.rbegin(); rit != c.rend() && game.size()<3; ++rit) {
        ll friends{rit->first};
        vll index{rit->second};
        for(auto i:index) {
            game.emplace_back(friends,i);
            if(game.size()==3) break;
        }
    }

    //////////////////////////////////////////////
    ll ans{};
    for(ll i{}; i<3; i++) {
        ll f1 = ski[i].F;
        for(ll j{}; j<3; j++)
            if(movie[j].S != ski[i].S) {
                ll f2 = movie[j].F;
                for(ll k{}; k<3; k++)
                    if(game[k].S!=movie[j].S and game[k].S!=ski[i].S) {
                        ll f3 = game[k].F;
                        ans = max(ans, f1+f2+f3);
                    }
            }
    }
    cout << ans;

}
///█████████████████████████████████████████████████████████████████████████████████████████████████████████████████████
int main() { IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ll tc{1};
    cin >> tc;
    for(ll i{1}; i<=tc; i++) {
//        cout << "Case " << i << ": ";
        fast();
        cout << endl;
    }

}


