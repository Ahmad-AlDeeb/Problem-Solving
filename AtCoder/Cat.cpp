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
    ll n; cin >> n;
    string s; cin >> s;
    if(n==1) {cout << s; return 0;}

    for(size_t i{}; i<s.size();) {
        if(i!=s.size()-1 and s[i]=='n' and s[i+1]=='a') {cout << "nya"; i+=2;}
        else {
            cout << s[i];
            i++;
        }
    }
}
