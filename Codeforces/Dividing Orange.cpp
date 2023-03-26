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
    ll n,k; cin >>n>>k;
    vector<bool>stat(n*k+1,false);
    vector<vector<ll>>children(k+1);
    for(ll i{1}; i<=k; i++) {
        ll x; cin >> x;
        children[i].pb(x);
        stat[x]=true;
    }
    for(ll i{1}; i<=k; i++)
        for(ll j{1}; j<=n*k && children[i].size()!=n; j++)
            if(!stat[j]) {
                stat[j]=true;
                children[i].pb(j);
            }
    for(ll i{1}; i<=k; i++) {
        for(auto &j:children[i]) cout << j << " ";
        cout << endl;
    }
}
