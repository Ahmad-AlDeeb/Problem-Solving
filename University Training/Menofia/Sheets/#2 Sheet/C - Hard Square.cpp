                                                    // problem: Gym - 350741E
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
    for(int i{1}; i<=n; i++) {
        if(i==1 || i==n) { // print only the first and last line
            for(int j{1}; j<=n; j++) cout << "* ";
            cout << endl;
            if(i==1) continue;
            if(i==n) break;
        }
        for(int j{1}; j<=n; j++) { // print all lines except the first and last line
            if(j==1 || j==n) cout << "* ";
            else cout << "  ";
        }
        cout << endl;
    }
}
