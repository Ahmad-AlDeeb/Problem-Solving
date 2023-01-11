                                                    // problem link: https://codeforces.com/problemset/problem/160/A
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
    int total{}, n{}; cin >> n;
    int coins[n];
    for(int i{}; i<n; i++) { // store all coins values in array and calculate their total
        cin >> coins[i];
        total += coins[i];
    }
    // sort array in descending order as we need bigger values first to take less coins
    sort(coins, coins+n, greater<int>()); 

    int my_sum{},  ans{}; // initially we assume he has all the coins and we start taking one coin by one coin
    for(int coin: coins) {
        my_sum += coin; // we take first big coin and add it to my sum
        total -= coin; // we also minus same coin from total as we already took it 
        ans++; // increment the number of coins we took
        if(my_sum > total) {cout << ans; break;} // if we now has more than the rest of coins we print and break
    }
}
