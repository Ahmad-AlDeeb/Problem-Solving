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

int main() { IOS // just do it
    int t{}; cin >> t;
    while(t--) {
        int x{}, y{}; cin >> x >> y;
        int i = min(x,y)+1, sum{};
        for(; i<max(x,y); i++)
            if(i%2 != 0) sum += i;
        cout << sum << endl;
    }
}
