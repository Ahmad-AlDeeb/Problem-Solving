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
    ll n; string road; cin >> n >> road;
    ll s,t;
    if(road[road.find_first_not_of('.')] == 'R') {
        s = road.find_first_not_of('.');
        t = road.find_last_of('R');
        if(!count(road.begin(),road.end(),'L')) t++;
        cout << s+1 << " " << t+1;
    }
    else {
        s = road.find_last_of('L');
        t = road.find_first_of('L');
        if(!count(road.begin(),road.end(),'R')) t--;
        cout << s+1 << " " << t+1;
    }
}
