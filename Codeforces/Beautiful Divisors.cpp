                                                    // problem link: https://codeforces.com/problemset/problem/893/B
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
bool is_beautiful(int n) { // determine if the number fulfill the beautiful number condition
    double result {1};
    for(int i{1}; result<=n; i++) {
        result = (pow(2,i)-1) * pow(2,i-1);
        if(result == n) return true;
    }
    return false;
}

int main() { IOS
    int n{}; cin >> n;

    vector<int> first, second; // first half divisors and second half divisors
    for(int i{1}; i*i<=n; i++) {
        if(n%i == 0) { // if i is factor then we push i to first half vector and the other number n/i to second half if it's not the same
            first.push_back(i);
            if(i*i != n) second.push_back(n/i);
        }
    }

    for(int fact : second) // we check big divisors first since we want biggest beautiful divisor
        if(is_beautiful(fact)) {cout << fact; return 0;} // we print first beautiful and end the program
    reverse(first.begin(),first.end()); // first half is from small values to big so we need to reverse to get big first
    for(int fact : first)
        if(is_beautiful(fact)) {cout << fact; return 0;} // we print first beautiful also and end the program
}
