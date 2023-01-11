#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

int main() { IOS
    int n{}; cin >> n;
    vector<int> vec1, vec2;
    for(int i{}; i<n; i++) {
        int x{}; cin >> x;
        vec1.push_back(x); vec2.push_back(x);
    } vec2[0] *= -1;

    int ans{}, ans1{}, ans2{1};
    for(int i{}; i<n-1; i++) {
        int cur1{vec1[i]}, cur2{vec2[i]}, nex1{vec1[i+1]}, nex2{vec2[i+1]};
        if(cur1>0 && nex1>0 || cur1<0&&nex1<0)
            {vec1[i+1] = nex1*-1; ans1++;}
        if(cur2>0&&nex2>0 || cur2<0&&nex2<0)
            {vec2[i+1] = nex2*-1; ans2++;}
    }
    if(ans1 < ans2) cout << ans1;
    else cout << ans2;
}
