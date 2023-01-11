#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define dd double
#define ld long double
#define PQ priority_queue
#define pii pair<int,int>
#define pcc pair<char, char>
#define pll pair<ll,ll>
#define S second
#define F first
#define MP make_pair
#define dpp(arr,val) memset(arr,val,sizeof(arr))
#define endl "\n"
using namespace std;

int main() { IOS
    int l1{}, r1{}, l2{}, r2{}; cin >> l1 >> r1 >> l2 >> r2;
    if((l1<l2 && r1<l2) || (l1>r2 && r1>r2)) {cout << -1; return 0;}

    if(l1 <= l2) cout << l2 << " " << min(r1,r2);
    else         cout << l1 << " " << min(r1,r2);
}
