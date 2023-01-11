                                                    // problem link: https://codeforces.com/problemset/problem/797/A
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

int main() { IOS
    int n{}, k{}; cin >> n >> k;
    if(k == 1) {cout << n; return 0;} // special case k=1 then input is the answer

    vector<int> fact;
    for(int i{2}; i*i<=n; i++) {
        while(n%i == 0) {
            n /= i; // we keep dividing as long as i divides n
            fact.push_back(i); // and we push to factors vector
            if(fact.size()==k-1 && n!=1) goto success; // if n is not 1 and we still need one more number then we can add n
        }
    }
    success: // if we are here because it was prime number then we may not succeed if the size is not equal to k-1
    if(fact.size()==k-1 && n!=1) {
        fact.push_back(n); // we add last num and print them
        for(int p:fact) cout << p << " ";
    }
    else cout << -1;
}
