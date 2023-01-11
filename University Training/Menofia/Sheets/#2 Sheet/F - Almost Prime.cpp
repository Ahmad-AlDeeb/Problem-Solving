                                                    // problem: Gym - 350741F
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
    int n{}; cin >> n;// counter to count factors and determine if the n is prime or not

    int count{}, big{}; // we get the equal or bigger closest prime
    for(int i{n};;i++) {
        count = 0; // reset the counter for each number we check if it's prime
        for(int j{2}; j*j <= i; j++)
            if(i % j == 0) {count++; break;} // if there's any number that divides i then that's not prime
        if(count == 0) {big = i; break;} // only if the count is 0, this i is prime so we have noe the bigger prime
    }

    int small{};
    for(int i{n}; i>1; i--) {
        count = 0; // reset the counter for each number we check if it's prime
        for(int j{2}; j*j <= i; j++)
            if(i % j == 0) {count++; break;} // if there's any number that divides i then that's not prime
        if(count == 0) {small = i; break;} // only if the count is 0, this i is prime so we have noe the smaller prime
    }

    if(big == small) cout << big; // this is when the given n number was already prime (we can print small or big)
    else if((big-n) < (n-small)) cout << big; // if the biggest prime is closer to n, we print big
    else if((big-n) > (n-small)) cout << small; // if the smaller prime is closer to n, we print small
    else cout << small << " " << big; // if the small and big prime are close to n by same distance, we print both
}
