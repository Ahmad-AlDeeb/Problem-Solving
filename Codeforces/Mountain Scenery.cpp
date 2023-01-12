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
    ll n,k; cin >> n >> k;
    vector<ll>vec(2*n+1); for(auto &i:vec) cin >> i;

    for(ll i{1}; k>0; i+=2)
        if((vec[i]-vec[i-1])>1 and (vec[i]-vec[i+1])>1) {vec[i]--; k--;}

    for(auto &i:vec) cout << i << " ";
}
