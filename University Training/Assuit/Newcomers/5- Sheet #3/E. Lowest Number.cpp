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

    int mini_i{}, mini{106};
    for(int i{1}; i<=n; i++) {
        int x{}; cin >> x;
        if(x < mini) {mini = x; mini_i = i;}
    }
    cout << mini << " " << mini_i;
}
