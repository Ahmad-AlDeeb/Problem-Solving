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

int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        if(n%2 == 0) cout << n/2 << " " << n/2;
        else {
            bool first{true};
            string s = to_string(n);
            string x,y;
            for(auto digit:s) {
                ll dig = digit-'0';
                if(dig%2 == 0) {x+= to_string(dig/2); y+=to_string(dig/2);}
                else {
                    string digit1,digit2;
                    if(first) {
                        digit1 = to_string(dig/2+1);
                        digit2 = to_string(dig/2);
                        first = false;
                    }
                    else {
                        digit2 = to_string(dig/2+1);
                        digit1 = to_string(dig/2);
                        first = true;
                    }
                    x+=digit1; y+=digit2;
                }
            }
            cout << stoi(x) << " " << stoi(y);
        }
        cout << endl;
    }
}
