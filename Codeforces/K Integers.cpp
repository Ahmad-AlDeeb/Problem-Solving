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
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    vll div(ll x) {
        vll div;
        for(ll i{1}; i*i<=x; i++)
            if(x%i == 0) {
                div.pb(i);
                if(i*i!=x) div.pb(x/i);
            }
        sort(all(div));
        return div;
    }
    void fast() {
        ll n,k; cin >> n >> k;
        vll f = div(n);
        for(auto d:f) {
            if(d==1) continue;
            ll rem {n - (d*(k-1))};
            if(rem>0 && rem%d==0) {cout << "YES"; return;}
        }
        cout << "NO";
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    int main() { IOS
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    #endif
        ll tc {1};
        cin >> tc;
        while(tc--) {
            fast();
            cout << endl;
        }
    }
