                                                    // problem link: https://codeforces.com/problemset/problem/742/A
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
    ll n; cin >> n;
    if(n == 0) { // to handle the special case if input is 0
        cout << 1;
        return 0;
    }
    n %= 4; // 1378 last digit cycle is repeated every 4 numbers
    if (n == 0) n = 4; // when it's 0, it means it was devisable by 4 which means is the 4th number so we set n = 4

    int mod_result{1};// if it's 0, no matter how many we multiply 1378, result would be 0 so we set it to 1
    while(n--) { // we loop n times and multiply last digit by 1378 each time
        mod_result *= 1378;
        mod_result %= 10;
    }
    cout << mod_result;
}
