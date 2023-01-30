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

int main() { IOS // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    ll t; cin >> t;
    while(t--) {
        ll n,k; cin >> n >> k;
        ll odd_rem{n-k+1}, even_rem{n-2*k+2};
        if(odd_rem>0 and (odd_rem&1)) {
            cout << "YES" << endl;
            for(ll i{}; i<k-1; i++) cout << 1 << " ";
            cout << odd_rem << endl;
        }
        else if(even_rem>0 and (even_rem%2==0)) {
            cout << "YES" << endl;
            for(ll i{}; i<k-1; i++) cout << 2 << " ";
            cout << even_rem << endl;
        }
        else cout << "NO" << endl;

    }

}
