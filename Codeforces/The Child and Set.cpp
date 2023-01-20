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
    ll sum,limit; cin >> sum >> limit;
    vector<ll>values(limit+1);
    for(ll i{1}; i<=limit; i++)
        values[i] = (i&~(i-1));

    vector<ll>ans;
    for(ll i{limit}; i>0; i--)
        if(values[i] <= sum) {
            sum -= values[i];
            ans.push_back(i);
        }
    if(sum == 0) {
        cout << ans.size() << endl;
        for(auto num:ans) cout << num << " ";
    } else cout << -1;
}
