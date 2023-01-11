                                                    // problem: Gym - 351820E 
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

    for(int i{}; i<n; i++) {
        int x{}; cin >> x;
        if(x <= 10) cout << "A[" << i << "] " << "= " << x << endl;
    }
}
