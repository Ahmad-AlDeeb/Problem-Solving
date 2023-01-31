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

int main() { IOS // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n;
//        if(n==1) {cout << 0 << endl; continue;}
        deque<ll>dq;
        for(ll i{}; i<n; i++) {
            ll num; cin >> num;
            dq.push_back(num);
        }

        ll alice{},bob{},cnt{},maxi{};
        while(true) {
            if(alice == bob) {
                maxi = cnt;
                if(dq.size() > 1) {
                    alice += dq.front(); dq.pop_front();
                    bob += dq.back(); dq.pop_back();
                    cnt += 2;
                } else break;
            }
            else if(alice > bob) {
                if(!dq.empty()) {
                    bob += dq.back(); dq.pop_back();
                    cnt++;
                } else break;
            }
            else if(alice < bob) {
                if(!dq.empty()) {
                    alice += dq.front(); dq.pop_front();
                    cnt++;
                } else break;
            }
        }
        cout << maxi << endl;
    }
}
