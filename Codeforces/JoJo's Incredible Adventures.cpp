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
    ll t; cin >> t;
    while(t--) {
        string s; cin >> s;
        ll maxi{},cnt{};

        for(auto c:s) {
            if(c=='1') cnt++;
            else {
                maxi = max(maxi,cnt);
                cnt = 0;
            }
        }
        maxi = max(maxi,cnt);
        if(maxi == s.size()) {cout << maxi*maxi << endl; continue;}



        if(s.front() == '1' && s.back() == '1') {
            cnt = 0;
            for(auto c:s) {
                if(c=='1') cnt++;
                else {
                    maxi = max(maxi,cnt);
                    break;
                }
            }
            for(ll i=s.size()-1; i>=0; i--) {
                if(s[i]=='1') cnt++;
                else {
                    maxi = max(maxi,cnt);
                    break;
                }
            }
            maxi = max(maxi,cnt);
        }

        if(maxi&1) cout << (maxi/2+1) * (maxi/2+1);
        else cout << (maxi/2) * (maxi/2+1);
        cout << endl;
    }
}
