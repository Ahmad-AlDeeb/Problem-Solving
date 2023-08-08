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
    map<char,vector<vector<char>>> block;
    void ini() {
        vector<vector<char>> A(5,vector<char>(3,'*')), B(A),C(A),D(A),E(A);
        A[1][1]=A[3][1]=A[4][1]='.';
        B[1][1]=B[3][1]='.';
        C[1][1]=C[1][2]=C[2][1]=C[2][2]=C[3][1]=C[3][2]='.';
        D[1][1]=D[2][1]=D[3][1]='.';
        E[1][1]=E[1][2]=E[3][1]=E[3][2]='.';

        block['A']=A;
        block['B']=B;
        block['C']=C;
        block['D']=D;
        block['E']=E;
    }
    void fast() {
        ll n; string s; cin >> n >> s;
        vector<vector<char>> ans(5,vector<char>(n*3+3));

        for(ll i{}; i<5; i++)
            for(ll j{}; j<n*3; j++){
                for(auto c:s)
                    for(ll k{}; k<3; k++)
                        ans[i][j] = block[c][i][j%3], j++;
            }

        for(ll i{}; i<5; i++) {
            for(ll j{}; j<n*3; j++)
                cout << ans[i][j];
            cout << endl;
        }
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    int main() { IOS
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    #endif
        ini();
        ll tc {1};
//        cin >> tc;
        for(ll i{1}; i<=tc; i++) {
//            cout << "Case " << i << ": ";
            fast();
//            cout << endl;
        }
    }
