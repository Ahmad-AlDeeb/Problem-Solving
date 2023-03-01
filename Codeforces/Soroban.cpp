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
vector<ll> di {1,-1,1,-1};
vector<ll> dj {1,1,-1,-1};

int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    string s; cin >> s;
    for(ll i=s.size()-1; i>=0; i--) {
        ll dig = s[i]-'0';
        if(dig == 0) cout << "O-|-OOOO";
        else if(dig == 1) cout << "O-|O-OOO";
        else if(dig == 2) cout << "O-|OO-OO";
        else if(dig == 3) cout << "O-|OOO-O";
        else if(dig == 4) cout << "O-|OOOO-";
        else if(dig == 5) cout << "-O|-OOOO";
        else if(dig == 6) cout << "-O|O-OOO";
        else if(dig == 7) cout << "-O|OO-OO";
        else if(dig == 8) cout << "-O|OOO-O";
        else if(dig == 9) cout << "-O|OOOO-";

        cout << endl;
    }

}
