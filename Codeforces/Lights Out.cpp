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
#include<map>
#include<bitset>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define F first
#define S second
#define dd double
#define ll long long
#define ld long double
#define pb push_back
#define all(v) v.begin(), v.end()
const ll inf = 1e17;
const ll M = 1e5;
vector<ll> di {1,-1,1,-1};
vector<ll> dj {1,1,-1,-1};

bool is_valid(ld num) {
    ll int_num = num;
    if(num == int_num) return true;
    return false;
}

int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    vector<vector<bool>>grid(3,vector<bool>(3,true));
    for(ll i{}; i<3; i++)
        for(ll j{}; j<3; j++) {
            ll x; cin >> x;
            if(x&1) {
                grid[i][j] = !grid[i][j];
                if(j+1<3)
                    grid[i][j+1] = !grid[i][j+1];

                if(i+1<3)
                    grid[i+1][j] = !grid[i+1][j];


                if(j-1>=0)
                    grid[i][j-1] = !grid[i][j-1];


                if(i-1>=0)
                    grid[i-1][j] = !grid[i-1][j];
            }
        }
    for(auto &r:grid) {
        for(auto c:r) cout << c;
        cout << endl;
    }
}
