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
#define cor first
#define val second
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
    vector<pair<ll,ll>>city(n); for(auto &i:city) cin >> i.cor >> i.val;
    map<ll,ll>loc;
    for(ll i{}; i<n; i++) loc[city[i].cor] = i + 1;
    sort(city.begin(),city.end());

    vector<ll>r_NGE(n,n);
    stack<pair<ll,ll>>s1;
    for(ll i{}; i<n; i++) {
        while(!s1.empty() && s1.top().val < city[i].val)
            {r_NGE[s1.top().first] = i; s1.pop();}
        s1.push(make_pair(i, city[i].val));
    }

    vector<ll>l_NGE(n, -1);
    stack<pair<ll,ll>>s2;
    for(ll i{n-1}; i>=0; i--) {
        while(!s2.empty() && s2.top().val < city[i].val)
            {l_NGE[s2.top().first] = i; s2.pop();}
        s2.push(make_pair(i, city[i].val));
    }

    vector<ll>ans(n+1);
    for(ll i{}; i<n; i++) {
        ll cur {city[i].cor};
        ll left_i = l_NGE[i], right_i = r_NGE[i];

        if(left_i==-1 && right_i==n) ans[loc[cur]] = -1;
        else if(left_i == -1)
            ans[loc[cur]] = loc[city[right_i].cor];
        else if(right_i == n)
            ans[loc[cur]] = loc[city[left_i].cor];
        else {
            ll left = city[l_NGE[i]].cor, right = city[r_NGE[i]].cor;
            if(cur-left < right-cur)
                ans[loc[cur]] = loc[left];
            else if(cur-left > right-cur)
                ans[loc[cur]] = loc[right];
            else {
                if(city[right_i].val > city[left_i].val)
                    ans[loc[cur]] = loc[right];
                else
                    ans[loc[cur]] = loc[left];
            }
        }
    }
    for(ll i{1}; i<ans.size(); i++) cout << ans[i] << " ";
}
