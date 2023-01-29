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
    ll n; cin >> n;

    ll count{};
    for(int j{1}; j<=n; j++) {
        set<ll>primes;
        for(int i{2}; i*i<=j; i++) {
            if(j%i == 0) {
                if(is_prime(i)) primes.insert(i);
                if(i*i != j && is_prime(j/i)) primes.insert(j/i);
            }
        }
        if(is_prime(j)) primes.insert(j);
        if(primes.size() == 2) count++;
    }
    cout << count;
}
