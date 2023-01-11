                                                    // problem link: https://codeforces.com/gym/102388/problem/G
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
    int t{}, n{}, a{}, b{}; cin >> t;
    for(int i{}; i<t; i++) { // loop over test cases
        cin >> n >> a >> b; // input for each test case

        if(b>=a && a!=n) cout << -1 << endl; // if we are not one a step away and b is greater than a, snail will keep going down
        else
            for(int days{};; days++) {
                if(n <= 0) {cout << days << endl; break;}
                if(n <= a) {cout << ++days << endl; break;} // if remaining distance less than a, we can make it on one a move
                n -= (a-b);
            }
    }
}
