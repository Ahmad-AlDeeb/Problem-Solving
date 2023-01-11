                                                    // problem link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3671
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define dd double
#define ld long double
#define PQ priority_queue
#define pii pair<int,int>
#define pll pair<ll,ll>
//#define S second
//#define F first
#define MP make_pair
#define dpp(arr,val) memset(arr,val,sizeof(arr))
#define endl "\n"
using namespace std;

int binary_mod_exp(int x, int y, int n) {
    int ans {1};

    while(y > 0) {
        if(y % 2 == 1)
            ans = ((ans%n) * (x%n)) % n; // using modular arithmetic multiplication rule
        x = ((x%n) * (x%n)) % n;
        y /= 2;
    }
    return ans;
}

int main() { IOS
    int i{}, x{}, y{}, n{}; cin >> i;
    while(i--) {
        cin >> x >> y >> n;
        cout << binary_mod_exp(x, y, n) << endl;
    }
}
