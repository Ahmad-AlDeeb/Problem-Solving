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

bool is_prime(ll x) {

    for(ll i{2}; i*i<=x; i++)
        if(x%i == 0) return false;
    return true;
}


int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll a,b,x; cin >> a >> b >> x;
    string ans;
    while(x>1) {
        if(ans.empty()) {
            if(a>=b) ans.pb('0'),a--;
            else ans.pb('1'),b--;
            continue;
        }
        if(ans.back() == '0') ans.pb('1'),b--;
        else ans.pb('0'),a--;

        x--;
    }

    if(ans.back() == '0') {
        while(a--) ans.pb('0');
        while(b--) ans.pb('1');
    }
    else {
        while(b--) ans.pb('1');
        while(a--) ans.pb('0');
    }
    cout << ans;
}
