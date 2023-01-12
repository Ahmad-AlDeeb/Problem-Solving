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
#define occ first
#define v second
#define dd double
#define ll long long
#define ld long double

struct Rec {
    ll x1,y1,x2,y2;
    Rec(ll x1, ll y1, ll x2, ll y2) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }
};

int main() { IOS // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    ll t; cin >> t;
    while(t--) {
        ll x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        Rec r1 {x1,y1,x2,y2};
        cin >> x1 >> y1 >> x2 >> y2;
        Rec r2 {x1,y1,x2,y2};

        if(max(r1.x1,r2.x1) < min(r1.x2,r2.x2) and max(r1.y1,r2.y1) < min(r1.y2,r2.y2)) {
            vector<ll>vec_x{r1.x1,r1.x2,r2.x1,r2.x2}, vec_y{r1.y1,r1.y2,r2.y1,r2.y2};
            sort(vec_x.begin(),vec_x.end()); sort(vec_y.begin(),vec_y.end());
            cout << vec_x[1] << " " << vec_y[1] << " " << vec_x[2] << " " << vec_y[2] << endl;
        }
        else cout << "No Overlap" << endl;

        if(t!=0) cout << endl;
    }
}
