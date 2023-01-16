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
    string num; cin >> num;
    for(ll i{}; i<num.size(); i++) {
        int n {num[i]-'0'};
        if((n==9 && i==0) or n<5) cout << n;
        else cout << 9-n;
    }
}
