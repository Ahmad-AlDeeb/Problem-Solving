                                                    // problem link: https://vjudge.net/problem/AtCoder-abc207_a/origin
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
    int a{}, b{}, c{}; cin >> a >> b >> c;
    int sum1 {a+b}, sum2{a+c}, sum3{b+c};
    if(sum1 >= sum2 && sum1 >= sum3) cout << sum1;
    else if(sum2 >= sum1 && sum2 >= sum3) cout << sum2;
    else cout << sum3;
}
