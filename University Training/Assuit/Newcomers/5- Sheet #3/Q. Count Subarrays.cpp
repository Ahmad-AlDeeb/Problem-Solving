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
    int t{}; cin >> t;
    while(t--) {
        int ans{}, n{}; cin >> n; vector<int>vec(n,0);
        for(int i{}; i<n; i++)
            {cin >> vec[i]; ans++;}


        for(int seg{2}; seg<=n; seg++) {
            for(int i{}; i+seg<=n; i++) {

                bool success{true};
                for(int j{i}; j<i+seg-1; j++)
                    if(vec[j] > vec[j+1])
                        {success=false; break;}
                if(success) ans++;
            }
        }
        cout << ans << endl;
    }
}
