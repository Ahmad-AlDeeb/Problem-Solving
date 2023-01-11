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
        int n{}; cin >> n; vector<int>vec(n,0);
        for(int i{}; i<n; i++) {
            cin >> vec[i];
            cout << vec[i] << " ";
        }
        int seg{1};
        for(int i{}; i<n; i++) {
            seg++;
            for(int j{}; j+seg-1<n; j++) {

                int max {vec[j]};
                for(int k{j}; k<j+seg; k++)
                    if(vec[k] > max) max = vec[k];
                cout << max << " ";
            }
        }
        cout << endl;
    }
}
