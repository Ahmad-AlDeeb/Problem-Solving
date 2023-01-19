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
    ll n,m,k; cin >> n >> m >> k;
    vector<string>players(m);
    while(m--) {
        ll player; cin >> player;
        players.push_back(bitset<64>(player).to_string());
    }
    ll fedor_num; cin >> fedor_num;
    string fedor = bitset<64>(fedor_num).to_string();

    ll ans{};
    for(auto &player:players) {
        ll count{};
        for(ll i{}; i<64; i++)
            if(player[i]!=fedor[i]) count++;
        if(count <= k) ans++;
    }
    cout << ans;
}
