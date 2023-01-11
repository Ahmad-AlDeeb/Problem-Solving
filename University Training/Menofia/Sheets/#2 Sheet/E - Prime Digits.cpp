                                                    // problem: Gym - 350741H
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
    string n; cin >> n;
    int num{}, ans{};
    for(int i{}; i<n.size(); i++) {
        num = n[i]-48;
        if(num==2 || num==3 || num==5 || num==7) ans++;
    }
    cout << ans;
}
