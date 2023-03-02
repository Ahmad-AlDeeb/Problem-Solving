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

bool success{false};
void rotate(vector<ll>v, ll i, ll degree) {
    if(i == v.size()) {
        if(!degree) success=true;
        return;
    }
    rotate(v,i+1,(degree+v[i])%360);
    rotate(v,i+1,(degree-v[i])%360);
}

int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll n; cin >> n;
    vector<ll>v(n); for(auto &i:v) cin >> i;
    rotate(v,0,0);
    if(success) cout << "YES";
    else cout << "NO";
}
