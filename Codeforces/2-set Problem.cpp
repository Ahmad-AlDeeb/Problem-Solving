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
        vll s(n),t(n);
        map<ll,ll> m1,m2;
        for(auto &i:s) cin >> i, m1[i]++;
        for(auto &i:t) cin >> i, m2[i]++;

        bool cool{true};
        for(auto p:m1)
            if(t.size()-m2[p.F] < p.S)
                cool=false;
        if(cool) cout << "YES";
        else cout << "NO";
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
