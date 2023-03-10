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

int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll n; cin >> n;
    vector<ll>vec(n); for(auto &i:vec) cin >> i;
    vector<ll>vec_sor(vec); sort(all(vec_sor));

    if(vec == vec_sor) cout << "yes" << endl << 1 << " " << 1;
    else {
        ll l,r;
        for(ll i{}; i<n; i++)
            if(vec[i] != vec_sor[i]) {l=i; break;}
        for(ll i{n-1}; i>=0; i--)
            if(vec[i] != vec_sor[i]) {r=i; break;}

        reverse(vec.begin()+l,vec.begin()+r+1);
        for(ll i{}; i<n; i++)
            if(vec[i] != vec_sor[i]) {cout << "no"; return 0;}
        cout << "yes" << endl << l+1 << " " << r+1;
    }

}
