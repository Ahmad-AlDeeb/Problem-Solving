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
    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        deque<ll>dq;
        while(n--) {
            ll num; cin >> num;
            if(dq.empty() || num < dq.front()) dq.push_front(num);
            else dq.push_back(num);
        }
        for(auto num:dq) cout << num << " ";
        cout << endl;
    }
}
 
