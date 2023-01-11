                                                    // problem link: https://codeforces.com/problemset/problem/495/B
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ll a{}, b{}; cin>>a>>b;
    ll target {a-b}; // to get the number of divisors for target as those divisors will always leave b as remainder

    int count{};
    for(int i{1}; i*i<=target; i++) { // the last i that is (i*i <= target) is the middle
        if(target % i == 0) { // if i divisor that divide target
            if(i > b) count++; // and if i divisor greater than b remainder then we increment count
            if(target/i>b && i*i!=target) count++; // and if result of division is greater than b remainder we increment count
            // if (i*i == target) condition is true we would count same number twice ! :D
        }
    }
    if(a==b) cout << "infinity"; // any number bigger than a would get b
    else cout << count;
}
