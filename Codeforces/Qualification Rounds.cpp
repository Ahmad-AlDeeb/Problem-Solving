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
int bits_count2(ll n) {
    int count{};
    while(n) {
        n &= (n-1);
        count++;
    }
    return count;
}

int main() { IOS // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    ll n,k; cin >> n >> k;
    set<int>problems;
    while(n--) {
        int problem{};
        for(ll i{k-1}; i>=0; i--) {
            int bit; cin >> bit;
            if(bit) problem += pow(2,i);
        }
        problems.insert(problem);
    }

    vector<int>problems_with_two_ones;
    bool success{false};
    for(auto p:problems) {
        if(!p) success=true;
        if(p==1)
            for(auto p2:problems) if((p2 & (1<<0)) == 0) success=true;
        if(p==2)
            for(auto p2:problems) if((p2 & (1<<1)) == 0) success=true;
        if(p==4)
            for(auto p2:problems) if((p2 & (1<<2)) == 0) success=true;
        if(p==8)
            for(auto p2:problems) if((p2 & (1<<3)) == 0) success=true;

        if(bits_count2(p) == 2) problems_with_two_ones.push_back(p);
    }

    for(auto p1:problems_with_two_ones)
        for(auto p2:problems_with_two_ones)
            if((p1 & p2) == 0) success=true;

    if(success) cout << "YES";
    else cout << "NO";
}
