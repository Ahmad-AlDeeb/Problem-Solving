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
        ll n,m; cin >> n >> m;

        bool zero{false}; ll neg{};
        vector<ll>freq(101);

        vector<vector<ll>>mat(n,vector<ll>(m));
        for(auto &i:mat) for(auto &j:i) {
            cin >> j;
            if(!j) zero=true;
            if(j<0) neg++;

            ll copy = j;
            freq[abs(copy)]++;
        }

        ll maxi{};
        if(zero or !(neg&1)) {
            for(ll i{1}; i<=100; i++)
                if(freq[i]) maxi += i*freq[i];
        }
        else {
            for(ll i{1}; i<=100; i++)
                if(freq[i]) {maxi-=i; freq[i]--; break;}
            for(ll i{1}; i<=100; i++)
                if(freq[i]) maxi += i*freq[i];
        }
        cout << maxi << endl;
    }
}
