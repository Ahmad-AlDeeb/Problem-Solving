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

int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll n; cin >> n;
    string num; cin >> num;
    vector<ll>f(10); for(ll i{1}; i<=9; i++) cin >> f[i];

    bool success{false};
    ll start,end;
    for(ll i{}; i<n; i++) {
        ll dig = num[i]-'0';
        if(f[dig] > dig) {
            success=true;
            start = i; end = i;
            for(ll j{i+1}; j<n; j++) {
                ll dig2 = num[j]-'0';
                if(f[dig2] >= dig2) end=j;
                else break;
            }
        }
        if(success) break;
    }

    if(success)
        for(ll index{}; index<n; index++) {
            ll dig = num[index]-'0';
            if(index>=start && index<=end) cout << f[dig];
            else cout << dig;
        }
    else cout << num;

}
