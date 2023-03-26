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
const ll M = 1e9+7;
ll power(ll x, ll y) {
    ll ans{1};
    while(y) {
        if(y&1) ans = ((ans%M)*(x%M)) % M;
        x = ((x%M) * (x%M)) %M;
        y/=2;
    }
    return ans;
}
vector<ll> di {1,-1,1,-1};
vector<ll> dj {1,1,-1,-1};

int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    string vow {"aeiou"};
    bool success{true};

    string line1;
    getline(cin,line1);
    ll cnt{};
    for(auto c:line1) if(vow.find(c) != string::npos) cnt++;
    if(cnt != 5) success=false;

    string line2;
    getline(cin,line2);
    cnt = 0;
    for(auto c:line2) if(vow.find(c) != string::npos) cnt++;
    if(cnt != 7) success=false;

    string line3;
    getline(cin,line3);
    cnt = 0;
    for(auto c:line3) if(vow.find(c) != string::npos) cnt++;
    if(cnt != 5) success=false;

    if(success) cout << "YES"; else cout << "NO";
}
