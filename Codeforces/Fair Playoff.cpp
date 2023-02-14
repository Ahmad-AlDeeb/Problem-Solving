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
        ll one,two,three,four; cin >> one >> two >> three >> four;
        vector<ll>vec{one,two,three,four}; sort(all(vec));
        ll big{vec[3]}, sec_big{vec[2]};

        ll finalist1,finalist2;
        if(one > two) finalist1 = one; else finalist1 = two;
        if(three > four) finalist2 = three; else finalist2 = four;

        if((finalist1==big || finalist1==sec_big) and (finalist2==big || finalist2==sec_big))
            cout << "YES"; else cout << "NO";
        cout << endl;
    }
}
