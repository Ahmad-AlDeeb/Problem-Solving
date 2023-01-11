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
    dd a{}, b{}; cin >> a >> b;
    cout << "floor " << a << " / " << b << " = " << floor(a/b) << endl
         << "ceil "  << a << " / " << b << " = " << ceil(a/b) << endl
         << "round " << a << " / " << b << " = " << round(a/b) << endl;
}
