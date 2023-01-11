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
    int x{}; cin >> x;
    if(x!=2 && x%2==0) {cout << "NO"; return 0;}

    int count{};
    for(int i{2}; i<=x/2; i++)
        if(x%i == 0) count++;

    if(count > 0) cout << "NO";
    else cout << "YES";
}
