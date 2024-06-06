#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
#define ld long double
#define F first
#define S second
#define vll vector<long long>
#define pb push_back
#define all(v) v.begin(), v.end()
///////////////////////////////////////
const ll N = 1e7+7;
const ll M = 998244353;
const ll MAX = 1e18;
const ld EPS = 1e-19;
ll pow(ll x, ll y) {
    ll ans{1};
    while(y) {
        if(y&1) ans *= x;
        x *= x;
        y /= 2;
    }
    return ans;
}
ll big_pow(ll x, ll y) {
    ll ans{1};
    while(y) {
        if(y&1) ans = ((ans%M)*(x%M)) % M;
        x = ((x%M) * (x%M)) %M;
        y/=2;
    }
    return ans;
}
bool is_int(ld num) {
    return num == (ll)num;
}
int cmp_d(ld a, ld b) {
    if(fabs(a-b) <= EPS) return -1;
    return a>b? 1:0;
}
ll mod(ll x, ll m){
    return (x%m +m) % m;
}
///█████████████████████████████████████████████████████ Solution ██████████████████████████████████████████████████████
const vector<int> di {0,0,1,-1};
const vector<int> dj {1,-1,0,0};

int w, h, ans{};
char grid[20][20];
bool vis[20][20];

bool valid(int i, int j) {
    if(i<h && i>=0 && j<w && j>=0 && grid[i][j] == '.')
        return true;
    return false;
}

void dfs(int i, int j) {
    if(vis[i][j]) return;
    vis[i][j] = true;
    ans++;

    for(int k{}; k<4; k++) {
        int i2 = i + di[k];
        int j2 = j + dj[k];

        if(valid(i2, j2))
            dfs(i2, j2);
    }
}

void fast() {
    ans = 0;
    cin >> w >> h;
    int x_prince, y_prince;

    for(int i{}; i<h; i++)
        for(int j{}; j<w; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == '@') {
                x_prince = i;
                y_prince = j;
            }
            vis[i][j] = false;
        }


    dfs(x_prince, y_prince);
    cout << ans;
}
///█████████████████████████████████████████████████████████████████████████████████████████████████████████████████████
int main() { IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ll tc{1};
    cin >> tc;
    for(ll i{1}; i<=tc; i++) {
        cout << "Case " << i << ": ";
        fast();
        cout << endl;
    }
}
