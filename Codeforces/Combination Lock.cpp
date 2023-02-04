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

int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll n; cin >> n;
    string s1,s2; cin >> s1 >> s2;
    ll ans{};
    for(ll i{}; i<n; i++) {
        ll dig1{s1[i]-'0'}, dig2{s2[i]-'0'};

        if(dig1 > dig2) {
            ans += min(dig1-dig2, 9-dig1+1+dig2);
        } else ans += min(dig2-dig1, 9-dig2+1+dig1);
    }
    cout << ans;
}
