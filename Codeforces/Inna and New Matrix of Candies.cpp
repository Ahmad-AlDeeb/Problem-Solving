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
    ll n,m; cin >> n >> m;
    vector<vector<char>>matrix(n,vector<char>(m));
    set<ll>s;
    for(auto &row:matrix) {
        ll cnt{};
        bool found_G{false}, found_S{false};

        for(auto &col:row) {
            cin >> col;
            if(found_G && !found_S) cnt++;

            if(col=='S') {
                found_S=true;
                if(!found_G) {cout << -1; return 0;}
            }
            if(col == 'G') found_G=true;
        }
        s.insert(cnt);
    }
    cout << s.size();
}
