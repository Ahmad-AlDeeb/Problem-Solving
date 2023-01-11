                                                    // problem link: https://atcoder.jp/contests/abc216/tasks/abc216_a?lang=en
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define dd double
#define ld long double
#define PQ priority_queue
#define pii pair<int,int>
#define pll pair<ll,ll>
#define S second
#define F first
#define MP make_pair
#define dpp(arr,val) memset(arr,val,sizeof(arr))
#define endl "\n"
using namespace std;

int main() { IOS
    dd n{}; cin >> n;
    int int_n = n*10;
    int y = int_n % 10; // mod 10 get us the last digit which is y
    int x = n; // casting from double to int to get x

    if(y <= 2) cout << x << "-";
    else if(y <= 6) cout << x;
    else cout << x << "+";
}
