#include<string>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<deque>
#include<set>
#include<unordered_set>
#define x first
#define y second
#define dd double
#define ll long long
#define ld long double
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int main() { IOS
    ll n; cin >> n;
    multimap<ll,string>m;
    for(ll i{}; i<n; i++) {
        string s; cin >> s;
        m.emplace(s.size(),s);
    }
    vector<string>vec; for(auto &i:m) vec.push_back(i.y);

    for(ll i{}; i<vec.size()-1; i++) {
        string cur=vec[i], next=vec[i+1];

        if(cur.size() == next.size()) {
            if(cur == next) continue;
            else {cout << "NO"; return 0;}
        }
        else {
            if(next.find(cur) != string::npos) continue;
            else {cout << "NO"; return 0;}
        }
    }
    cout << "YES" << endl;
    for(auto str:vec) cout << str << endl;
}
