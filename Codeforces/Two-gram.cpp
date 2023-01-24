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
    ll n; string s; cin >> n >> s;
    if(n==2) {cout << s; return 0;}
    
    vector<string>vec;
    for(ll i{}; i<n-1; i++) {
        string str; str.push_back(s[i]); str.push_back(s[i+1]);
        vec.push_back(str);
    }
    sort(vec.begin(),vec.end());


    vector<pair<ll,string>> grams;
    ll count{1}; string gram{vec.front()};
    for(ll i{1}; i<vec.size(); i++) {
        if(vec[i] == gram) {
            count++;
            if(i==vec.size()-1) grams.emplace_back(count, gram);
        }
        else {
            grams.emplace_back(count, gram);
            gram=vec[i]; count=1;
        }
    }

    sort(grams.begin(),grams.end());
    cout << grams.back().y;
}
