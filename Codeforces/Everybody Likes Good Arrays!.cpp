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
    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n; vector<ll>vec(n); for(auto &i:vec) cin >> i;
        ll count{};
        for(ll i{}; i<vec.size()-1; i++) {
            if((vec[i]%2==0 && vec[i+1]%2==1) or (vec[i]%2==1 && vec[i+1]%2==0)) continue;

            count++;
        }
        cout << count << endl;
    }
}
