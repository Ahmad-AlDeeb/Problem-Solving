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
int n {};
int pathsCount[30][30];

void floyd() {
    for(int k{}; k < n; ++k) {
        for(int i{}; i < n; ++i) {
            for(int j{}; j < n; ++j) {
                int relaxCount = pathsCount[i][k] * pathsCount[k][j];
                pathsCount[i][j] += relaxCount;
            }
        }
    }

    for(int k{}; k < n; ++k) {
        if(pathsCount[k][k]) {
            for(int i{}; i < n; ++i) {
                for(int j{}; j < n; ++j) {
                    if(pathsCount[i][k] && pathsCount[k][j])
                        pathsCount[i][j] = -1;
                }
            }
        }
    }
}

void printAnswer(int cityNumber) {
    cout << "matrix for city " << cityNumber << endl;
    for(int i{}; i < n; ++i) {
        for(int j{}; j < n; ++j) {
            cout << pathsCount[i][j];
            if(j != n - 1)  cout << " ";
        }
        cout << endl;
    }
}

void fast() {
    int edges, cityNumber {-1};
    while(cin >> edges) {
        n = 0;
        cityNumber++;
        memset(pathsCount, 0, sizeof(pathsCount));

        while(edges--) {
            int i,j;
            cin >> i >> j;
            pathsCount[i][j]++;
            n = max({n, i, j});
        }
        n++;

        floyd();
`
        printAnswer(cityNumber);
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
