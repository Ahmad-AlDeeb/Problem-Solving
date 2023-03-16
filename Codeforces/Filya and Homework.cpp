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
    map<ll,ll>m;
    while(n--) {
        ll x; cin >> x; m[x] = x;
    }

    if(m.size()==1 || m.size()==2) cout << "YES";
    else if(m.size() == 3) {
        vector<ll>num;
        for(auto p:m) num.pb(p.F);

        if((num[1]-num[0]) == (num[2]-num[1])) cout << "YES";
        else cout << "NO";
    }
    else cout << "NO";
}
