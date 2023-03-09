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
const ll M = 1e5;
vector<ll> di {1,-1,1,-1};
vector<ll> dj {1,1,-1,-1};

bool is_valid(ld num) {
    ll int_num = num;
    if(num == int_num) return true;
    return false;
}

int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll n,a; cin >> n >> a; a--;
    vector<ll>v(n); for(auto &i:v) cin >> i;
    ll ans{};
    if(v[a]) ans++;
    ll i{a-1},j{a+1};
    for(; i>=0 && j<n; i--,j++)
        if(v[i] && v[j]) ans += 2;
    for(; i>=0; i--) if(v[i]) ans++;
    for(; j<n; j++) if(v[j]) ans++;

    cout << ans;
}
