                                                    // Problem link: https://codeforces.com/problemset/problem/363/B
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
    ll n{}, k{}; cin >> n >> k;
    if(k == n) {    // if k==n we have on sum thus it's the minimal sum so we input the first index which is 1
        cout << 1;
        return 0; //  as we have the got the answer already
    }
    int h{}; // h for height values that user will input
    vector<int> height; // to store user input values of h
    for(ll i{}; i<n; i++) { // to store each h in height
        cin >> h;
        height.push_back(h);
    }

    // second item is  sum for comparing to other sum and determine smallest
    // First item is index of the sum so that when we detect the smallest sum, we have its index to return it
    vector< pair<ll,ll> > sum;
    int first_sum {}; // we need only the first sum as the next sum is got from the previous one
    for(ll i{}; i<k; i++) // we loop k times over height to add each h in range k thus we get the first sum
        first_sum += height[i];
    sum.emplace_back(0, first_sum); // we make our first pair of the sum and its index and insert it to sum vector

    for(ll i{k}; i<n; i++) { // we loop over height vector but we start from k since we stop before k in last loop
        int new_h { height[i] },
            old_h { height[sum.back().first] }; // first h index from previous sum is the first item in each pair
        ll last_sum { sum.back().second }, // previous sum
            next_i {sum.back().first+1}; // the index of the next sum
        // we get all remaining sums by removing first h from previous sum & adding new h to previous sum
        sum.emplace_back(next_i,last_sum - old_h + new_h);
    }

    ll j {}, smallest {sum.front().second}; // j which is the index of the smallest sum and we take first sum as smallest
    for(auto pair : sum) // we compare each sum to smallest till we the index of the smallest which is j
        if (pair.second < smallest) {
            smallest = pair.second;
            j = pair.first;
        }
    cout << j+1; // we print j since it's the answer :)
}
