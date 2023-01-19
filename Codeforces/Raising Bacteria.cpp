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
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define x first
#define y second
#define dd double
#define ll long long
#define ld long double

int bits_count2(ll n) {
    int count{};
    while(n) {
        n &= (n-1);
        count++;
    }
    return count;
}

int main() { IOS // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    ll x; cin >> x;
    cout << bits_count2(x);
}
