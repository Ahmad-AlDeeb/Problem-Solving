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
    ll n,k; cin >> n >> k;
    vector<ll>vec1(n),vec2(n),f1(10e5+1),f2(10e5+1);
    for(auto &num:vec1) {
        cin >> num;
        f1[num]++;
    }
    ll mahmoud{};
    for(auto &num:vec1) {
        f1[num]--;
        if(k>num) mahmoud += f1[k-num];
    }


    for(auto &num:vec2) {
        cin >> num;
        f2[num]++;
    }
    ll bashar{};
    for(auto &num:vec2) {
        f2[num]--;
        if(k>num) bashar += f2[k-num];
    }

    if(mahmoud > bashar) cout << "Mahmoud";
    else if(bashar > mahmoud) cout << "Bashar";
    else cout << "Draw";
}
