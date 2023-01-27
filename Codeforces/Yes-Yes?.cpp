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


int main() { IOS // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    string yes{"Yes"};
    ll t;  cin >> t;
    while(t--) {
        string s; cin >> s;

        bool success{true};
        if(s.front() == 'Y') {
            ll index{};
            for(auto c:s) {
                if(c != yes[index%3]) success=false;
                index++;
            }
        }
        else if(s.front() == 'e') {
            ll index{1};
            for(auto c:s) {
                if (c!=yes[index%3]) success = false;
                index++;
            }
        }
        else if(s.front() == 's') {
            ll index{2};
            for(auto c:s) {
                if (c!=yes[index%3]) success=false;
                index++;
            }
        }
        else success=false;

        if(success) cout << "YES";
        else cout << "NO";
        cout << endl;
    }

}
