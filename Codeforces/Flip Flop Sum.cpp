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
    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        ll sum{};
        vector<ll>vec(n); for(auto &i:vec) {cin >> i; sum+=i;}

        bool con1{false},con2{false};
        for(ll i{}; i<n-1; i++)  {
            if(vec[i]+vec[i+1] == -2) con1=true;
            if(vec[i]+vec[i+1] == 0) con2=true;
        }
        if(con1) cout << sum+4;
        else if(con2) cout << sum;
        else cout << sum-4;
        cout << endl;
    }
}
