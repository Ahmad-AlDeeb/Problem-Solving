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

const double pi = 3.14159265358979323846;
int main() { IOS // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    dd d,h,v,e; cin >> d >> h >> v >> e;
    dd area = pow(0.5*d,2) * pi;
    dd speed = v/area;
    if(speed > e) {
        cout << "YES" << endl;
        cout << fixed << setprecision(12) << h / (speed-e);
    } else cout << "NO";
}
