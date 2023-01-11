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

struct Shape {
    dd x1,y1,x2,y2;
    Shape(dd x1, dd y1, dd x2, dd y2) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }
};
bool inside(dd x, dd y, dd x1, dd y1, dd x2, dd y2) {
    if(x>x1 && y<y1 and x<x2 && y>y2) return true;
    return false;
}

int main() { IOS // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    char s; dd x1,y1,x2,y2;
    vector<Shape>shapes;
    while(cin >> s) {
        if(s == '*') break;
        cin >> x1 >> y1 >> x2 >> y2;
        shapes.emplace_back(x1,y1,x2,y2);
    }

    dd x,y; ll count{1};
    while(cin >> x >> y) {
        if(x == 9999.9) break;

        bool success{false};
        for(ll i{}; i<shapes.size(); i++) {
            Shape sh = shapes[i];
            if(inside(x,y,sh.x1,sh.y1,sh.x2,sh.y2)) {
                success=true;
                cout << "Point " << count << " is contained in figure "  << i+1 << endl;
            }
        }
        if(!success) cout << "Point " << count << " is not contained in any figure" << endl;

        count++;
    }
}
