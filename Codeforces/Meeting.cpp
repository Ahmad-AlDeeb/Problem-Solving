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
    return sqrt(pow((x1-x2),2) + pow((y1-y2),2));
}

int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
    ll n; cin >> n;
    vector<vector<ll>> rad (n,vector<ll>(3));
    for(auto &i:rad) for(auto &val:i) cin >> val;

    ll blankets{};
    /////////////// Down Side ///////////////
    for(ll i=min(x1,x2); i<=max(x1,x2); i++) {
        ll j = min(y1,y2);
        bool success{false};
        for(auto r:rad)
            if(distance(i,j,r[0],r[1]) <= r[2])
                {success=true; break;}
        if(!success) blankets++;
    }
    /////////////// Up Side ///////////////
    for(ll i=min(x1,x2); i<=max(x1,x2); i++) {
        ll j = max(y1,y2);
        bool success{false};
        for(auto r:rad)
            if(distance(i,j,r[0],r[1]) <= r[2])
            {success=true; break;}
        if(!success) blankets++;
    }
    /////////////// Left Side ///////////////
    for(ll j=min(y1,y2); j<=max(y1,y2); j++) {
        ll i = min(x1,x2);
        bool success{false};
        for(auto r:rad)
            if(distance(i,j,r[0],r[1]) <= r[2])
            {success=true; break;}
        if(!success) blankets++;
    }
    /////////////// Right Side ///////////////
    for(ll j=min(y1,y2); j<=max(y1,y2); j++) {
        ll i = max(x1,x2);
        bool success{false};
        for(auto r:rad)
            if(distance(i,j,r[0],r[1]) <= r[2])
                {success=true; break;}
        if(!success) blankets++;
    }
    /////////////// Corner 1 ///////////////
    bool success{false};
    for(auto r:rad) {
        if(distance(x1,y1,r[0],r[1]) <= r[2])
            {success=true; break;}
    } if(!success) blankets--;
    /////////////// Corner 2 ///////////////
    success = false;
    for(auto r:rad) {
        if(distance(x2,y2,r[0],r[1]) <= r[2])
            {success=true; break;}
    } if(!success) blankets--;
    /////////////// Corner 3 ///////////////
    success = false;
    for(auto r:rad) {
        if(distance(x1,y2,r[0],r[1]) <= r[2])
            {success=true; break;}
    } if(!success) blankets--;
    /////////////// Corner 4 ///////////////
    success = false;
    for(auto r:rad) {
        if(distance(x2,y1,r[0],r[1]) <= r[2])
            {success=true; break;}
    } if(!success) blankets--;


    cout << blankets << endl;
}
