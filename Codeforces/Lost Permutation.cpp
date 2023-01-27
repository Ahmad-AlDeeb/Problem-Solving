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
    string yes{"Yes"};
    ll t;  cin >> t;
    while(t--) {
        ll m,s; cin >> m >> s;
        ll biggest{};
        vector<ll>vec(m); for(auto &i:vec) {cin >> i; biggest = max(biggest,i);}
        sort(all(vec));

        ll i{1};
        for(; i<=s; i++)
            if(!binary_search(all(vec),i)) {s-=i; vec.pb(i); sort(all(vec));}

        sort(all(vec));
        if(s==0 && vec.size()==vec.back()) cout << "YES";
        else cout << "NO";
        cout << endl;
    }

}
