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


int main() { IOS // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    dd x1,y1,x2,y2,x3,y3,x4,y4;
    while(cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4) {
        pair<dd,dd> p1{x1,y1}, p2{x2,y2}, p3{x3,y3}, p4{x4,y4}, common;
        vector<pair<dd,dd>> vec{p1,p2,p3,p4};
        std::sort(vec.begin(), vec.end());
        for(ll i{}; i<3; i++) {
            if(vec[i]==vec[i+1]) {
                common = vec[i];
                vec.erase(vec.begin()+i);
                vec.erase(vec.begin()+i);
                break;
            }
        }
        cout << fixed << setprecision(3) << vec[0].x + vec[1].x - common.x << " " << vec[0].y + vec[1].y - common.y << endl;
    }
}
