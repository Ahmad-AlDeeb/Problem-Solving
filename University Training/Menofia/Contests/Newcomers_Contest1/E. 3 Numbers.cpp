                                        // problem link: https://codeforces.com/group/jfviGllBoY/contest/374705/problem/E
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define dd double
#define ld long double
#define PQ priority_queue
#define pii pair<int,int>
#define pll pair<ll,ll>
#define S second
#define F first
#define MP make_pair
#define dpp(arr,val) memset(arr,val,sizeof(arr))
#define endl "\n"
using namespace std;

int main() { IOS
    ll x{}, y{}, z{}; cin >> x >> y >> z;
    ll ans1{x*y+z}, ans2{x*y-z}, ans3{x+y*z}, ans4{x-y*z}, ans5{x+y-z}, ans6{x-y+z}, ans7{x*y*z}, ans8{x+y+z}, ans9{x-y-z};
    vector<ll> answers {ans1, ans2, ans3, ans4, ans5, ans6, ans7, ans8, ans9};

    ll max{ans1}, min{ans1};
    for(ll ans: answers) {
        if(ans > max) max = ans;
        if(ans < min) min = ans;
    }
    cout << max << " " << min;
}
