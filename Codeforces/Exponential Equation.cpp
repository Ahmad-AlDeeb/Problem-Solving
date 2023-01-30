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

vector<ll> get_factors(ll n) {
    vector<ll>factors;
    for(int i{1}; i*i <= n; i++)
        if(n % i == 0) {
            factors.push_back(n);
            if(i*i != n) factors.push_back(n / i);
        }
    return factors;
}

int main() { IOS // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        if(n%2 == 0) cout << 1 << " " << n/2;
        else cout << -1;
        cout << endl;
    }
}
