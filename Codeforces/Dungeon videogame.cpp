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
        vll v(n); for(auto &l:v) cin >> l;
        ll score{};
        for(auto &l:v) {
            if(l>=0) score += l;
            else score--;
        }
        cout << score;
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
