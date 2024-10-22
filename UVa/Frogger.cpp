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
const ll N = 2000;
const ll M = 998244353;
const ll MAX = 60 + 1;
const ld EPS = 1e-19;
ll pow(ll x, ll y) {
    ll ans{1};
    while (y) {
        if (y & 1) ans *= x;
        x *= x;
        y /= 2;
    }
    return ans;
}

ll big_pow(ll x, ll y) {
    ll ans{1};
    while (y) {
        if (y & 1) ans = ((ans % M) * (x % M)) % M;
        x = ((x % M) * (x % M)) % M;
        y /= 2;
    }
    return ans;
}

bool is_int(ld num) {
    return num == (ll) num;
}

int cmp_d(ld a, ld b) {
    if (fabs(a - b) <= EPS) return -1;
    return a > b ? 1 : 0;
}

ll mod(ll x, ll m) {
    return (x % m + m) % m;
}

///█████████████████████████████████████████████████████ Solution ██████████████████████████████████████████████████████
struct Stone {
    ld x, y;
};
vector<Stone> stones;
vector<vector<ld>> minMax;
int n;

void fillWithDistances() {
    for(int i{}; i < n; ++i)
        for(int j{}; j < n; ++j) {
            ld x1 = stones[i].x;
            ld y1 = stones[i].y;

            ld x2 = stones[j].x;
            ld y2 = stones[j].y;

            minMax[i][j] = sqrt( pow(abs(x1-x2), 2) + pow(abs(y1-y2), 2));
        }
}

void printAnswer(int scenarioCount) {
    cout << "Scenario #" << scenarioCount << endl;
    cout << "Frog Distance = " << fixed << setprecision(3) << minMax[0][1] << endl << endl;
}

void floyd() {
    for(int k{}; k < n; ++k)
        for(int i{}; i < n; ++i) {
            for(int j{}; j < n; ++j) {
                ld relax = max(minMax[i][k], minMax[k][j]);
                minMax[i][j] = min(minMax[i][j], relax);
            }
        }


}

void fast() {
    int scenarioCount{};

    while (cin >> n && n) {
        scenarioCount++;
        stones.clear();
        minMax.clear();
        minMax.resize(n, vector<ld>(n));


        for (int i{}; i < n; ++i) {
            int x, y;
            cin >> x >> y;

            Stone stone;
            stone.x = x;
            stone.y = y;

            stones.push_back(stone);
        }

        fillWithDistances();
        floyd();
        printAnswer(scenarioCount);
    }
}

///█████████████████████████████████████████████████████████████████████████████████████████████████████████████████████
int main() {
    IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll tc{1};
    // cin >> tc;
    for (ll i{1}; i <= tc; i++) {
        // cout << "Case " << i << ": ";

        fast();

        // cout << endl;
        // if (i != tc) cout << endl;
    }
}
