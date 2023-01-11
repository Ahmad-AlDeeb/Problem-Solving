                                                    // problem link: https://codeforces.com/problemset/problem/284/A
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
    int p{}, count{}; cin >> p;

    for(int x{1}; x<p; x++) { // we try all numbers before prime p
        ll result {1}; // Multiplicative Identity

        for(int i{1}; i<p; i++) {
            result *= x; // we get all powers of x to check if every one of them is congruent to a Coprime of p
            result %= p; // to prevent data type overflow
            if(result==1 && i != p-1) break; // if result is 1 and we didn't reach to p-1 means this num is not primitive root
            if(result==1 && i == p-1) count++; // if result is 1 and we reach to p-1 means this num is primitive root
        }
    }
    cout << count;
}
