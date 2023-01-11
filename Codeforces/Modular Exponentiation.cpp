                                                    // problem link: https://codeforces.com/problemset/problem/913/A
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
int binary_exp(int x, int n) {
    int result {1};

    while(n > 0) {
        if(n%2 == 1) result *= x; // to minus the odd number n by one, we multiply the base x in result
        // equals (x^2)^n/2
        x *= x;
        n /= 2;
    }
    return result;
}

int main() { IOS
    int n{}, m{}; cin >> n >> m;
    if(n >= 30) cout << m; // any such n bigger than n would make the left side of mod smaller hence it's the ans :)
    else        cout << m % binary_exp(2, n);
}
