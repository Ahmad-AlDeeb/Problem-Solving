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


int main() { IOS // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    string line,l,r; cin >> line;
    bool after{false};
    for(ll i{}; i<line.size(); i++) {
        if(line[i]=='|') {after=true; continue;}
        if(after) r.push_back(line[i]);
        else l.push_back(line[i]);
    }

    char c;
    while(cin >> c) {
        if(l.size() <= r.size()) l.push_back(c);
        else r.push_back(c);
    }

    if(l.size() == r.size()) cout << l << '|' << r;
    else cout << "Impossible";
}
