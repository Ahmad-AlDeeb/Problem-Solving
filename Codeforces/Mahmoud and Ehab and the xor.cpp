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
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<bitset>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define x first
#define y second
#define dd double
#define ll long long
#define ld long double
const ll pw = pow(2,17);

int main() { IOS // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    ll n,x; cin >> n >> x;
    if(n==2 && x==0) cout << "NO";
    else {
        cout << "YES" << endl;
        if(n==1) cout << x;
        else if(n==2 && x!=0) cout << 0 << " " << x;

        else {
            ll sum{};
            for(ll i{1}; i<=n-3; i++) {
                cout << i << " ";
                sum ^= i;
            }

            ll last1 {(pw)^(2*pw)};
            ll last2 {(sum)^(pw)^(x)};
            if(sum == x) cout << pw << " " << pw*2 << " " << last1;
            else cout << 0 << " " << pw << " " << last2;
        }
    }
}
