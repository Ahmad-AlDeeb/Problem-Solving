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
    int n{}; cin >> n; if(n==1) {cout << 0; return 0;}
    vector<ll> fib{0, 1};
    for(int i{2}; i<=n; i++)
        fib.push_back(fib[i-2]+fib[i-1]);
    cout << fib[n-1];
}
