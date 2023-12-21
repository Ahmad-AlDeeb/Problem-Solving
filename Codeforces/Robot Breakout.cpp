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
bool sort_for_y(pair<pair<ll,ll>, ll> &lhs, pair<pair<ll,ll>, ll> &rhs) {
    return lhs.F.S > rhs.F.S;
}
void fast() {
    ll n; cin >> n;
    vector<pair<pair<ll,ll>, ll>> loc(n);
    vector<vll> moves(n,vll(4));
    for(ll i{}; i<n; i++) {
        cin >> loc[i].F.F >> loc[i].F.S;
        loc[i].S = i;
        cin >> moves[i][0] >> moves[i][1] >> moves[i][2] >> moves[i][3];
    }


    ////////////////// Handling the X-Axis //////////////////
    bool cool_x{true};
    auto loc_x{loc};
    ll X {loc_x.front().F.F};
    // checking if all X are equal
    for(auto p:loc_x)
        if(p.F.F != X) cool_x=false;
    if(!cool_x) {
        X=MAX;
        cool_x=true;
        sort(all(loc_x));
        bool L{false}, x_fixed{false};

        for(ll i{}; i<n; i++) {
            // If you can move left and right
            if(moves[loc_x[i].S][0] && moves[loc_x[i].S][2]) continue;

            // If you can't move left and right
            else if(!moves[loc_x[i].S][0] && !moves[loc_x[i].S][2]) {
                if(L or x_fixed)
                    if(loc_x[i].F.F != X) cool_x=false;

                x_fixed=true;
                X = loc_x[i].F.F;
            }
            // If you can move right only
            else if(moves[loc_x[i].S][2]) {
                if(L or x_fixed)
                    if(loc_x[i].F.F != X) cool_x=false;
            }

            // If you can move left only
            else if(moves[loc_x[i].S][0]) {
                if(!L and !x_fixed) X = loc_x[i].F.F;
                L=true;
            }
        }
        if(X==MAX) X = loc_x.back().F.F;
    }


    ////////////////// Handling the Y-Axis //////////////////
    bool cool_y{true};
    auto loc_y{loc};
    ll Y{loc_y.front().F.S};
    // checking if all Y are equal
    for(auto p:loc_y)
        if(p.F.S != Y)
            cool_y=false;

    if(!cool_y) {
        Y=MAX;
        cool_y=true;
        sort(all(loc_y),sort_for_y);
        bool U{false}, y_fixed{false};

        for(ll i{}; i<n; i++) {
            // If you can move up and down
            if(moves[loc_y[i].S][1] && moves[loc_y[i].S][3]) continue;

            // If you can't move up and down
            else if(!moves[loc_y[i].S][1] && !moves[loc_y[i].S][3]) {
                if(U or y_fixed)
                    if(loc_y[i].F.S != Y) cool_y=false;
                y_fixed=true;
                Y = loc_y[i].F.S;
            }
            // If you can move down only
            else if(moves[loc_y[i].S][3]) {
                if(U or y_fixed)
                    if(loc_y[i].F.S != Y) cool_y=false;
            }
            // If you can move up only
            else if(moves[loc_y[i].S][1]) {
                if(!U and !y_fixed) Y = loc_y[i].F.S;
                U=true;
            }
        }
        if(Y==MAX) Y = loc_y.back().F.S;
    }

    ////////////////// Finalizing //////////////////
    if(!cool_x or !cool_y) cout << 0;
    else cout << 1 << " " << X << " " << Y;
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


