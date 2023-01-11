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
    vector<int>vec;
    while(n--) {
        int x{}; cin >> x;
        if(x==0 && !vec.empty())
            reverse(vec.begin(),vec.end());
        vec.push_back(x);
    }
    for(int num:vec) cout << num << " ";
    cout << endl;
}
