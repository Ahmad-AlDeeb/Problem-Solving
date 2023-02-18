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
    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        map<ll,ll>f;
        set<ll>s;
        while(n--) {
            ll x; cin >> x; f[x%10]++; s.insert(x%10);
        }
        bool success{false};
        for(auto num1:s)
            for(auto num2:s)
                for(auto num3:s)
                    if((num1+num2+num3)%10 == 3) {
                        bool mini_s{true};
                        f[num1]--;
                        f[num2]--;
                        f[num3]--;
                        for(auto freq:f) if(freq.S < 0) mini_s=false;
                        f[num1]++;
                        f[num2]++;
                        f[num3]++;
                        if(mini_s) success=true;
                    }
        if(success) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}
