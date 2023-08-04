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
    void fast() {
        ll n; cin >> n;
        vector<pair<ll,ll>> v(n);
        for(auto &i:v) cin >> i.F;
        for(auto &i:v) cin >> i.S;

        ll s1{},s2{},mn{1000000000};
        vector<pair<ll,ll>> neg;
        for(auto p:v) {
            if(p.S==1) s1+=p.F, s2++;
            else neg.pb(p), mn=min(mn,p.F);
        }

        sort(all(neg),greater<>());
        ll ans {s1*s2};
        for(auto p:neg) {
            s1+=p.F, s2--;
            ans = max(ans,s1*s2);
        }

        if(ans) cout << ans;
        else    cout << -mn;
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
