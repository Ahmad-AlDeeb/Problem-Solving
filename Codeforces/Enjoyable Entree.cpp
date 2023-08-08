    #include <bits/stdc++.h>
    #define ll long long
    #define ld long double
    #define vll vector<long long>
    #define pb push_back
    #define endl "\n"
    #define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
    #define F first
    #define S second
    #define ld long double
    #define all(v) v.begin(), v.end()
    using namespace std;
    const ll MAX = 1e18;
    const ll N = 2e6+1;
    ll M;
    ll big_pow(ll x, ll y) {
        ll ans{1};
        while(y) {
            if(y&1) ans = ((ans%M)*(x%M)) % M;
            x = ((x%M) * (x%M)) % M;
            y /= 2;
        }
        return ans;
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    ld GP(ll a, ld r, ll n) {
        return a*(pow(r,n)-1)/(r-1);
    }
    void fast() {
        ll n; cin >> n;
        if(n==1) cout << "100 0";
        else {
            ll sz = (n-1)/2;
            ld neg = -GP(100,0.25,n-1-sz);
            ld pos = GP(50,0.25,sz);
            ld ans1 = 100 + (neg+pos);
            cout << fixed << setprecision(6) << ans1 << " " << 100-ans1;
        }
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    int main() { IOS
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    #endif
        ll tc {1};
//        cin >> tc;
        for(ll i{1}; i<=tc; i++) {
//            cout << "Case " << i << ": ";
            fast();
//            cout << endl;
        }
    }
