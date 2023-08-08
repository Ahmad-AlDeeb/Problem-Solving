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
    void fast() {
        ll n; cin >> n;
        ll ans{};
        for(ll i{2}; i<n; i++)
            ans += (i*(i+1));
        cout << ans;
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
