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
    vll loc, PF_cnt(N);
    vector<bool> Prime(N,true);
    void sieve() {
        Prime[0]=Prime[1]=false;
        for(ll i{2}; i<N; i++) if(Prime[i]) {
            for(ll com{i+i}; com<N; com+=i) {
                Prime[com]=false;
                ll tmp {com};
                while(tmp%i==0) tmp/=i, PF_cnt[com]++;
            }
        }
    }

//    vll PF(ll n) {
//        for(ll i{2}; i*i<N; i++)
//            while(n%i == 0) n/=i, PF_cnt[i]++;
//        if(n!=1) PF_cnt[n]++;
////        for(ll i{2}; i*i<N; i++)
////            if(!PF_cnt[i])
////                for(ll j{i+i}; j<N; j+=i)
////                    ++PF_cnt[j];
////        for(ll i{4}; i<N; i++)
////            if(PF_cnt[i]==2) loc.pb(i);
//    }
    void fast() {
        ll n; cin >> n;
        if(PF_cnt[n]==2) {cout << 0; return;}

        auto it = lower_bound(all(loc),n);

        ll ans1{MAX};
       if(it!=loc.end()) ans1 = abs(*it-n);


        ll ans2{MAX};
        if(it!=loc.begin()) it--, ans2 = abs(n-*it);


        cout << min(ans1,ans2);
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    int main() { IOS
        sieve();
        for(ll i{4}; i<N; i++)
            if(PF_cnt[i]==2) loc.pb(i);

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
