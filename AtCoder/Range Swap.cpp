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
#include<map>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define x first
#define y second
#define dd double
#define ll long long
#define ld long double
#include<unordered_set>

int main() { IOS // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    ll n,p,q,r,s; cin >> n >> p >> q >> r >> s;
    vector<ll>vec(1);
    for(ll i{1}; i<=n; i++) {
        ll num; cin >> num;
        vec.push_back(num);
    }
    vector<ll>b(vec);

    for(ll i{p},j{r}; i<=q; i++,j++)
         b[i] = vec[j];

    for(ll i{r},j{p}; i<=s; i++,j++)
        b[i] = vec[j];

    for(ll i{1}; i<=n; i++) cout << b[i] << " ";
}
