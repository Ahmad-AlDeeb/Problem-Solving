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

vector<vector<ll>>multiples(M+1);
void init() {
    for(ll fact{1}; fact<M; fact++)
        for(ll multi{fact}; multi<M; multi+=fact)
            multiples[multi].pb(fact);
}


int main() { IOS // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    init();
    ll t; cin >> t;
    while(t--) {
        ll n,m; cin >> n >> m;
        vector<ll>students(n); for(auto &i:students) cin >> i;
        sort(all(students));

        map<ll,ll>freq;
        ll count{},mini_d{inf},j{};
        for(ll i{}; i<n; i++) {

            for(auto multi : multiples[students[i]]) {
                if(multi > m) break;
                if(!freq[multi]++) count++;
            }

            while(count == m) {
                ll d = students[i] - students[j];
                if(d < mini_d) mini_d = d;

                for(auto multi : multiples[students[j]]) {
                    if(multi > m) break;
                    if(--freq[multi] == 0) count--;
                }
                j++;
            }
        }
        cout << (mini_d==inf? -1 : mini_d) << endl;
    }
}
