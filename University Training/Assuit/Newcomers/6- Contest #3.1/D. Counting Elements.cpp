#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

int main() { IOS
    int n{}; cin >> n;
    vector<int> vec(n, 0);
    for(int i{}; i<n; i++) cin >> vec[i];
    sort(vec.begin(), vec.end());

    int i{}, ans{}, count{};
    for(; i<n-1; i++) {
        int diff {vec[i+1]-vec[i]};

        if(diff==0) ++count;
        else if(diff==1) {
            ans += (count+1);
            count = 0;
        }
        else count = 0;
    }
    cout << ans;
}
