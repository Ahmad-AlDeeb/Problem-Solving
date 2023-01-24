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
bool check_range(int l, int r, vector<int>&starts, vector<int>&ends) {
    int index = lower_bound(ends.begin(),ends.end(),r) - ends.begin();
    if(index==ends.size()) return false;
    else {
        if(l>=starts[index]) return true;
        else return false;
    }
}
int main() { IOS
    int n,m; cin >> n >> m;
    vector<pair<int,int>>ranges;
    while(n--) {
        int l,r; cin >> l >> r;
        ranges.emplace_back(l,r);
    }
    sort(ranges.begin(),ranges.end());
    vector<pair<int,int>>acc{ranges.front()};
    for(auto range:ranges) { // Merging Ranges 
        if(range.x > acc.back().y) acc.push_back(range);
        else if(range.y > acc.back().y) acc.back().y = range.y;
    }
    vector<int>starts,ends;
    for(auto range:acc) {starts.push_back(range.x); ends.push_back(range.y);}

    int q; cin >> q;
    while(q--) {
        int l,r; cin >> l >> r;
        if(l>r) swap(l,r);
        if(check_range(l,r,starts,ends)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
