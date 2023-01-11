                                                    // problem link: https://codeforces.com/problemset/problem/263/A
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
    int x{}, row{1}, col{1};
    for(; row<=5; row++)  {
        col=1;  // reset col index to the first column each time we move into new row
        for(; col<=5; col++) {
            cin >> x;
            if(x == 1) goto found;
        }
    }
    found: cout << abs(row-3) + abs(col-3);
}
