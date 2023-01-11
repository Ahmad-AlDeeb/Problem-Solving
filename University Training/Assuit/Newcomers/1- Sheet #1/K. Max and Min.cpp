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
    ll a{}, b{}, c{}; cin >> a >> b >> c;

    ll max{};
    if(a>=b && a>=c) max = a;
    if(b>=a && b>=c) max = b;
    if(c>=a && c>=b) max = c;

    ll min{};
    if(a<=b && a<=c) min = a;
    if(b<=a && b<=c) min = b;
    if(c<=a && c<=b) min = c;

    cout << min << " " << max;
}
