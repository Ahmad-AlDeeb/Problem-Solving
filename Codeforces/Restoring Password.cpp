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
    vector<string>pass;
    for(ll i{}; i<8; i++) {
        string digit;
        for(ll j{}; j<10; j++) {
            char c; cin >> c;
            digit.push_back(c);
        }
        pass.push_back(digit);
    }

    vector<string>keys(10); for(auto &i:keys) cin >> i;
    for(auto s1:pass)
        for(ll i{}; i<keys.size(); i++)
            if(s1==keys[i]) cout << i;
}
