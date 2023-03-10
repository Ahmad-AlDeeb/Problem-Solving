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

ll n,m,k,t;

int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n >> m >> k >> t;
    vector<pair<ll,ll>>waste;
    while(k--) {
        ll a,b; cin >> a >> b;
        waste.emplace_back(a,b);
    }

    vector<string>plants {"Grapes","Carrots","Kiwis"};
    while(t--) {
        ll a,b; cin >> a >> b;
        pair<ll,ll>query(a,b);

        bool wasteland{false};
        ll count{};
        for(const auto &w:waste) {
            if(query == w) {wasteland=true; break;}
            if(query > w) count++;
        }

        if(wasteland) cout << "Waste";
        else cout << plants[(m*(a-1) + b-count) % 3];
        cout << endl;
    }
}
