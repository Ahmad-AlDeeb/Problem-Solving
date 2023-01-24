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
#define start first
#define endd second
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
    vector<ll>powers{1};
    while(powers.back() < 2*10e9) powers.push_back(powers.back()*2);

    ll n; cin >> n;
    vector<ll>vec(n); for(auto &i:vec) cin >> i; sort(vec.begin(),vec.end());

    ll invalid{};
    for(ll i{}; i<n; i++) {
        bool success{false};

        for(auto power:powers) {
            ll tar {power-vec[i]};
            if(tar > 0) {
                auto it = lower_bound(vec.begin(),vec.end(),tar);
                if(it!=vec.end() && *it==tar) {
                    if(i != it-vec.begin()) success=true;
                    else {
                        it++;
                        if(it!=vec.end() && *it==tar) success=true;
                    }
                }
            }

        }

        if(!success) invalid++;
    }
    cout << invalid;
}
