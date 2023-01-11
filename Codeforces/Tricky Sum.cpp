                                                    // problem link: https://codeforces.com/problemset/problem/598/A
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

ll get_sum_power2(ll an) { // to return the sum of all power of 2 numbers that are smaller than last number
    ll sum{}; ll result{}; // result var is for each power of 2 number
    double exp {0.0};
    while(true) {
        result = pow(2.0, exp++);
        if(result > an) break; // if this power of 2 number bigger than last number, we break the loop and return sum
        sum += result; // if this power of 2 number is smaller than last number, we add it to sum
    }
    return sum;
}
// return special required in the problem
ll get_sum(ll a1, ll an, ll n) {  // a1 is first num, an is the last and n is number of numbers in sequence
    // we get the sum of all numbers using the formula then we subtract the power of 2 numbers sum two times
    // one time subtraction because we added them when we used the formula
    // second time subtraction because problem asked to subtract them
    return ((a1+an)*n / 2) - (2 * get_sum_power2(an));
}

int main() { IOS
    int t{}; ll n{};
    cin >> t;

    for(int i{}; i<t; i++) {
        cin >> n;
        // 1 is the first number always in this problem also the last number would be the same as the number of numbers
        cout << get_sum(1, n, n) << endl;
    }
}
