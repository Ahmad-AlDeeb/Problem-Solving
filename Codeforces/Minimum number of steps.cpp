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

bool is_prime(ll n) {
    for(ll i{2}; i*i<=n; i++)
        if(n%i == 0) return false;
    return true;
}


int main() { IOS // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    string s; cin >> s;
    ll i=s.size()-1;
    for(; i>=0; i--) if(s[i]=='b') break;

    ll b{},count{};
    for(; i>=0; i--) {
        if(s[i]=='a') {
            count += b; count %= 1000000007;
            b *= 2; b %= 1000000007;
        }
        else b++;
    }
    cout << count;
}
