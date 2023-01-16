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
    ll t; cin >> t;
    while(t--) {
        string s; cin >> s;
        string a,b,c;

        if((s[0]=='a'&&s[1]=='a') or (s[0]=='b'&&s[1]=='b') or (s[0]=='b'&&s[1]=='a')) cout << s[0] << " " << s[1] << " " << s.substr(2);
        else if(s[0]=='a' && s[1]=='b')
            cout << s[0] << " " << s.substr(1,s.size()-2) << " " << s.back();
        cout << endl;
    }

}
