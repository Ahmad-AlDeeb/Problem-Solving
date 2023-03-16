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
    ll n,m,x,y,k; cin >> n >> m >> x >> y >> k;
    ll steps{};
    while(k--) {
        ll a,b; cin >> a >> b;
        ll pos_d1{n-x}, pos_d2{m-y}, neg_d1{x-1}, neg_d2{y-1};

        ll distance1{inf};
        if(a > 0) distance1 = pos_d1 / a;
        else if(a < 0) distance1 = neg_d1 / abs(a);
        ll distance2{inf};
        if(b > 0) distance2 = pos_d2 / b;
        else if(b < 0) distance2 = neg_d2 / abs(b);

        ll cnt = min(distance1, distance2);
        x += cnt*a;
        y += cnt*b;
        steps += cnt;
    }
    cout << steps;
}
