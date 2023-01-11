                                                    // problem link: https://codeforces.com/problemset/problem/682/A
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
    int n{}, m{}; cin >> n >> m;

    int start{}, diff{};
    ll count{};
    for(int x{1}; x<=n; x++) {
        start = 5 - (x%5); // to get the first number from m list that is sum of 5 with x
        if(start > m) continue; // if the first number from m list is larger than last number in m then we move on to next x
        else count++; // if it's not then we have our first pair so we increment count

        diff = m - start; // to know the distance till we reach to m on m list
        count += diff/5; // to get number of numbers in m that is sum of 5 with x then we add it to count
    }
    cout << count;
}
