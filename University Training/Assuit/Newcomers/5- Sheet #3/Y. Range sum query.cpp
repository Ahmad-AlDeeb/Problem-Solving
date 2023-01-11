// problem: Gym - 351820D
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
    int n{}, q{}; cin >> n >> q;
    vector<int>vec(n,0);
    vector<ll>sum(n,0);

    for(int i{}; i<n; i++) {
        cin >> vec[i];
        if(i==0) sum[i] = vec[i];
        else     sum[i] = sum[i-1]+vec[i];
    }

    while(q--) {
        int l{}, r{}; cin >> l >> r; l--; r--;
        if(l==0) cout << sum[r] << endl;
        else cout << sum[r]-sum[l-1] << endl;
    }
}
