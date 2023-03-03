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

bool is_valid(ld num) {
    ll int_num = num;
    if(num == int_num) return true;
    return false;
}

int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll n,k; cin >> n >> k;
    vector<ll>v(n);
    for(auto &i:v) cin >> i;

    map<ll,ll>wins;
    ll maxi = *max_element(all(v));
    while(true) {
        if(v[0]==maxi or v[1]==maxi) {cout << maxi; break;}
        else {
            if(v[0] > v[1]) {
                wins[v[0]]++;
                if(wins[v[0]] == k) {cout << v[0]; break;}

                v.pb(v[1]);
                v.erase(v.begin()+1);
            }
            else {
                wins[v[1]]++;
                if(wins[v[1]] == k) {cout << v[1]; break;}

                v.pb(v[0]);
                v.erase(v.begin());
            }
        }
    }
}
