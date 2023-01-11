                                                    // problem link: https://atcoder.jp/contests/abc067/tasks/abc067_a?lang=en
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
    int a{}, b{}; cin >> a >> b;

    if((a+b)%3 == 0 || a%3==0 || b%3==0) cout << "Possible";
    else cout << "Impossible";
}
