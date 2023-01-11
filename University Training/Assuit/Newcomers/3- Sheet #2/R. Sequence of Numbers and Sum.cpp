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
    int n{}, m{};

    while(cin >> n >> m) { //wtf
        if(n<1 || m<1) break;

        int i = min(n,m), sum{};
        for(; i<=max(n,m); i++) {
            cout << i << " ";
            sum += i;
        }
        cout << "sum =" << sum << endl;
    }
}
