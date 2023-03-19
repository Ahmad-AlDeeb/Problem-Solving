#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<unordered_set>
#include<map>
#include<bitset>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define F first
#define S second
#define dd double
#define ll long long
#define ld long double
#define pb push_back
#define all(v) v.begin(), v.end()
const ll inf = 1e17;
const ll M = 1e9+7;
ll power(ll x, ll y) {
    ll ans{1};
    while(y) {
        if(y&1) ans = ((ans%M)*(x%M)) % M;
        x = ((x%M) * (x%M)) %M;
        y/=2;
    }
    return ans;
}
vector<ll> di {1,-1,1,-1};
vector<ll> dj {1,1,-1,-1};


int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        vector<ll>vec(n); ll zeros{}; map<ll,ll>m; set<ll>s; ll maxi{};
        for(auto &i:vec) {
            cin >> i;
            if(!i) zeros++;
            m[i]++;
            s.insert(i);
            maxi = max(maxi,i);
        }
        if(zeros-1 <= (n-zeros)) cout << 0;
        else {
            if(m.size() == 1) cout << 1;
            else if(m.size() == 2){
                ll i{}; bool success{false};
                for(auto it{s.begin()}; it!=s.end(); it++,i++)
                    if(*it != i) {cout << i; success=true; break;}

                if(!success) cout << maxi+1;
            }
            else cout << 1;
        }
        cout << endl;
    }
}
