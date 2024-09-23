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
ll memory[MAX][MAX];
string word;

ll getCount(int left, int right) {
    if(left > right)
        return 0;

    ll &answer = memory[left][right];
    if(answer != -1)
        return answer;
    answer = 0;

    if(word[left] == word[right])
        answer += 1 + getCount(left + 1, right - 1);

    ll removeLeft = getCount(left + 1, right);
    ll removeRight = getCount(left, right - 1);
    ll duplicateCount = getCount(left + 1, right - 1);

    return answer += removeLeft + removeRight - duplicateCount;
}

void fast() {
    memset(memory, -1, sizeof(memory));
    cin >> word;
    cout << getCount(0, word.size() - 1);
}
///█████████████████████████████████████████████████████████████████████████████████████████████████████████████████████
int main() {
    IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll tc{1};
    cin >> tc;
    for (ll i{1}; i <= tc; i++) {
        // cout << "Case " << i << ": ";

        fast();

        cout << endl;
        // if (i != tc) cout << endl;
    }
}
