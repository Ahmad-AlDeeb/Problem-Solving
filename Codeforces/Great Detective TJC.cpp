#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<bitset>
#include<sstream>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cin.tie(0);
#define endl "\n"
#define F first
#define S second
#define dd double
#define ll long long
#define ld long double
#define pb push_back
#define all(v) v.begin(),v.end()
const ll inf = 1e17;
const ll M = 1e9+7;
string letters(" abcdefghijklmnopqrstuvwxyz");

ll power(ll x, ll y) {
    ll ans{1};
    while(y) {
        if(y&1) ans = ((ans%M)*(x%M)) % M;
        x = ((x%M)*(x%M)) % M;
        y /= 2;
    }
    return ans;
}
ll gcd(ll a, ll b) {
    if(b!=0) return gcd(b,a%b);
    else return a;
}
ll lcm(ll a, ll b) {
    return a*b / gcd(a,b);
}

int main() { IOS // freopen("tabs.in","r",stdin);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        set<int> s;

        bool success{false};
        while(n--) {
            int i; cin >> i;

            int num {i};
            if(num&1 && num!=1) num--;
            int before = s.size();
            s.insert(num);
            if(before == s.size()) success=true;
        }

        if(success) cout << "Yes"; else cout << "No";
        cout << endl;

    }
}
