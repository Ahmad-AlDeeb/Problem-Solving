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
#include<map>
#include<unordered_map>
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

const ll mod {1000000007};

int main() { IOS // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    string alphabet{"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz-_"};
    unordered_map<char,int>base64;
    for(int i{}; i<64; i++) base64[alphabet[i]] = i;

    string s; cin >> s;
    ll ans{1};
    for(auto c:s) {
        ll x = base64[c];

        for(ll i{}; i<6; i++)
            if((x & (1<<i)) == 0)
                ans = (ans*3)%mod;
    }
    cout << ans;
}
