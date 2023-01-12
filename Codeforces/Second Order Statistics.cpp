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
#define occ first
#define v second
#define dd double
#define ll long long
#define ld long double


int main() { IOS // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    ll n; cin >> n;
    vector<ll>vec(n); for(auto &i:vec) cin >> i;
    sort(vec.begin(),vec.end());
    for(auto &i:vec)
        if(i != vec.front()) {cout << i; return 0;}
    cout << "NO";
}
