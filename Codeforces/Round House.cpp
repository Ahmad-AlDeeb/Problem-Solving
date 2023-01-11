                                                    // problem link: https://codeforces.com/problemset/problem/659/A
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
    int n{}, a{}, b{}; cin >> n >> a >> b;
    while (b < 0) b += n; // to remove negative values
    int result = (b%n) + a;
    if(result > n)
        cout << result % n; // because when we add +a we may get bigger than n so we do mod of result to re-start the cycle
    else
        cout << result;
}
