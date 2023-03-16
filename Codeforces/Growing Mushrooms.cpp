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

int comp_double(ld a, ld b) {
    if(fabs(a-b) <= 1e-10) return -1;
    return a>b? 1:0;
}

bool cmp(pair<ld,ll>&lhs, pair<ld,ll>&rhs) {
    int cmp_result = comp_double(lhs.F,rhs.F);
    if(cmp_result != -1)
        return cmp_result;
    return lhs.S < rhs.S;
}

int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll n,t1,t2,k; cin >> n >> t1 >> t2 >> k;
    vector<pair<ld,ll>>con;
    for(ll i{1}; i<=n; i++) {
        ll a,b; cin >> a >> b;

        ld size1 = b*t1;
        size1 -= ((ld)(k/100.0) * size1);
        size1 += a*t2;

        ld size2 = a*t1;
        size2 -= ((ld)(k/100.0) * size2);
        size2 += b*t2;

        con.emplace_back(max(size1,size2),i);
    }

    sort(all(con),cmp);
    for(auto c:con)
        cout << c.S << " " << fixed << setprecision(2) << c.F << endl;
}
