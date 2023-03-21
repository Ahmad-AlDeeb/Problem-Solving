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
    ll n; cin >> n;
    vector<ll>vec(n); for(auto &i:vec) cin >> i;
    ll dis1,dis2; bool cond1{true}, cond2{true};
    for(ll i{},j=n-1; i<n; i++,j--) {
        if((vec[i]==1 || vec[i]==n) && cond1) {dis1 = i; cond1=false;}
        if((vec[j]==1 || vec[j]==n) && cond2) {dis2 = j; cond2=false;}
    }
    if(dis1 > (n-1-dis2)) cout << dis2;
    else cout << n-1-dis1;

}
