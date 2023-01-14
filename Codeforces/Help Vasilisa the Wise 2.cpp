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

ll r1,r2,c1,c2,d1,d2;
//bool valid(ll i, ll j, ll k, ll m)

int main() { IOS // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
    unordered_set<ll>s;
    for(ll i{1}; i<=9; i++) {
        vector<ll>ans{i,r1-i,c1-i,d1-i};
        s.insert({i,r1-i,c1-i,d1-i});

        bool success{true};
        if(r1-i+c1-i==d2 and c1-i+d1-i==r2 and r1-i+d1-i==c2 and s.size() == 4) {
            for(auto num:s)
                if(num>9 || num<1) {success=false; break;}
            if(success) {
                for(ll j{}; j<4; j++) {
                    if(j!=2) cout << ans[j] << " ";
                    else cout << endl << ans[j] << " ";
                }
                return 0;
            }
        }
        ans.clear();
        s.clear();
    }
    cout << -1;
}
