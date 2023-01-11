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
    int t{}; cin >> t;
    while(t--) {
        int n{}; cin >> n;
        string n_bin = bitset<32>(n).to_string();

        int ones{};
        for(char c:n_bin)
            if(c=='1') ones++;
        int ans{};
        for(int i{}; i<ones; i++)
            ans += pow(2,i);

        cout << ans << endl;
    }
}
