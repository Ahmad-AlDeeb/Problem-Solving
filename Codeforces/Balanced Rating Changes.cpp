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
    vector<ll>vec(n);
    bool up{true};
    for(ll i{}; i<n; i++) {
        ll rate; cin >> rate;
        if(rate >= 0) {
            if(rate%2 == 1) {
                if(up) vec[i]=rate/2+1;
                else vec[i]=rate/2;
                up=!up;
            } else vec[i]=rate/2;
        }
        else {
            if((rate*-1)%2 == 1) {
                if(up) vec[i]=rate/2;
                else vec[i]=rate/2-1;
                up=!up;
            } else vec[i]=rate/2;
        }

    }
    for(auto rate:vec) cout << rate << endl;
}

