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
#define x first
#define y second
#define dd double
#define ll long long
#define ld long double
#include<unordered_set>


int main() { IOS // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    ll a,b; cin >> a >> b;
    ll ans_a{},ans_b{}, draw{};
    for(ll i{1}; i<=6; i++) {
        if(abs(a-i) < abs(b-i)) ans_a++;
        else if(abs(a-i) > abs(b-i)) ans_b++;
        else draw++;
    }
    cout << ans_a << " " << draw << " " << ans_b;
}
