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
    map<string,string>m;
    while(n--) {
        string s1,s2; cin >> s1 >> s2;
        bool found{false};
        for(auto &map:m)
            if(m[map.x] == s1) {m[map.x]=s2; found=true; break;}
        if(!found) m[s1]=s2;
    }
    cout << m.size() << endl;
    for(auto &map:m) cout << map.x << " " << map.y << endl;
}
