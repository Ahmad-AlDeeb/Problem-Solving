                                                    // problem link: https://codeforces.com/problemset/problem/405/A
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
    int n{}; cin >> n;
    vector<int> col(n ,0);
    for(int i{}; i<n; i++) // we store cubes in vectors 
        cin >> col[i];

    for(int i{n-1}; i>0; i--) { // we start loop from the last col
        int max{i}; // assume the highest col is the last one
        for(int j{i-1}; j>=0; j--) // loop from last to start to find the highest col if not the last col is the highest
            if(col[j] > col[max])
                max = j; // we keep updating max  till we have the highest one

        int diff = col[max]-col[i]; // we get the difference between the last col and the highest one
        col[i] += diff; // give the diff to the last col 
        col[max] -= diff; // and minus it from the highest col
    }
    for(int cubes: col) cout << cubes << " ";
}
