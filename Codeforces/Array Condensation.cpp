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
        ll n,m,k; cin >> n >> m >> k;
        vll v(n); for(auto &i:v) cin >> i; sort(all(v),greater<>());
        if(m==1) {
            ll sum{};
            for(ll i{}; i<n and k; i++,k--)
                sum += v[i];
            cout << sum;
        }
        else {
            ll i{}, sum{};
            for(; i<m; i++) sum+=v[i];
            k--;

            for(ll cnt{1}; i<n-m and k; i++) {
                sum += v[i];
                cnt++;
                if(cnt==m) cnt=1,k--;
            }
            cout << sum;
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
