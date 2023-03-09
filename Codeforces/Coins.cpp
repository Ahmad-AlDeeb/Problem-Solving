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

vector<ll>freq(3);
void count_f(string s) {
    if(s[1]=='>')
        freq[s[0]-'A']++;
    else freq[s[2]-'A']++;
}

int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    string line1,line2,line3; cin >> line1 >> line2 >> line3;
    count_f(line1); count_f(line2); count_f(line3);

    bool success{false};
    for(auto val:freq)
        if(!val) success=true;

    if(success) {
        for(ll i{}; i<3; i++)
            if(freq[i]==0) cout << char(i+'A');
        for(ll i{}; i<3; i++)
            if(freq[i]==1) cout << char(i+'A');
        for(ll i{}; i<3; i++)
            if(freq[i]==2) cout << char(i+'A');
    }
    else cout << "Impossible";


}
