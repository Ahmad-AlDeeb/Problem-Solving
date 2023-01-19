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
#include<bitset>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define x first
#define y second
#define dd double
#define ll long long
#define ld long double

int main() { IOS // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    ll t; cin >> t;
    while(t--) {
        string s; cin >> s;
        ll count = pow(2,s.size());

        vector<string>subs;
        for(ll i{}; i<count; i++) {
            string sub;

            bitset<64>bs(i);
            for(int j{}; j<64; j++)
                if(bs[j] & 1)
                    sub += s[j];
            subs.push_back(sub);
        }
        sort(subs.begin(),subs.end());

        ll k; cin >> k;
        cout << subs[k-1] << endl;
    }
}
