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

ld distance(ll x1, ll y1, ll x2, ll y2) {
    return sqrt( pow((x1-x2),2) + pow((y1-y2),2) );
}

int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    string s; cin >> s;
    char maxi{'a'};
    vector<ll>f(26);
    for(auto c:s) {
        if(c > maxi) maxi = c;
        f[c-'a']++;
    }
    for(ll i{}; i<f[maxi-'a']; i++)
        cout << maxi;
}
