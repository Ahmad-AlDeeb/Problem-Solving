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
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define x first
#define y second
#define dd double
#define ll long long
#define ld long double
#include<unordered_set>

int main() { IOS // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    ll n; cin >> n;
    vector<ll>vec(n),ans;
    for(auto &i:vec) cin >> i;

    vector<bool>exist(1001);
    for(ll i{n-1}; i>=0; i--)
        if(!exist[vec[i]]) {ans.push_back(vec[i]); exist[vec[i]]=true;}

    cout << ans.size() << endl;
    reverse(ans.begin(),ans.end());
    for(auto num:ans) cout << num << " ";


}
 
