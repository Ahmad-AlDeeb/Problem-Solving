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
        int n{}; cin >> n;
        vector<int> vec(n,0);
        for(int i{}; i<n; i++)
            cin >> vec.at(i);

        ll mini {vec[0] + vec[1] + 1};
        for(int i{}; i<n; i++)
            for(int j{i+1}; j<n; j++)
                if((vec[i]+vec[j]+j-i) < mini)
                    mini = (vec[i]+vec[j]+j-i);
        cout << mini << endl;
    }
}
