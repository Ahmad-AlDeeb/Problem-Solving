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

ll pos{},neg{};
ll pos_cnt{}, neg_cnt{};
ll valid{};

void print_bits(ll n, ll size) {
    if(!size) return;

    print_bits(n>>1, size-1);
    if(n&1) pos_cnt++;
    else neg_cnt++;
}
void print_all_subsets(ll size) {
    for(int i{}; i<(1<<size); i++) {
        pos_cnt = neg_cnt = 0;
        print_bits(i,size);
        if(pos_cnt==pos and neg_cnt==neg) valid++;
    }
}


int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    string s1,s2; cin >> s1 >> s2;

    for(auto c:s1) {
        if(c == '+') pos++;
        else neg++;
    }
    ll size{};
    for(auto c:s2) {
        if(c == '+') pos--;
        else if(c == '-') neg--;
        else size++;
    }

    if(pos<0 or neg<0) cout << fixed << setprecision(12) << 0;
    else if(pos==0 and neg==0) cout << fixed << setprecision(12) << 1.000000000000;
    else {
        print_all_subsets(size);
        cout << fixed << setprecision(12) << valid / (ld)pow(2,size);
    }
}
