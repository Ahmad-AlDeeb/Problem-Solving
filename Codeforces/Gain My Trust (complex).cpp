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

void print_bits(ll n, int size, string &sub) {
    if(!size) return;

    print_bits(n>>1, size-1, sub);
    sub += to_string(n&1);
}
vector<string> print_all_subsets(int size) {
    vector<string>vec;
    for(int i{}; i<(1<<size); i++) {
        string sub;
        print_bits(i,size,sub);

        reverse(sub.begin(),sub.end());
        vec.push_back(sub);
    }
    return vec;
}

int main() { IOS // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    ll t; cin >> t;
    while(t--) {
        string s; cin >> s;
        vector<string> ans = print_all_subsets(s.size());

        vector<string> subs;
        for(ll i{}; i<ans.size(); i++) {
            string sub;
            for(ll j{}; j<s.size(); j++)
                if(ans[i][j] == '1') sub += s[j];
            subs.push_back(sub);
        }
        sort(subs.begin(),subs.end());

        ll k; cin >> k;
        cout << subs[k-1];
        cout << endl;
    }
}
