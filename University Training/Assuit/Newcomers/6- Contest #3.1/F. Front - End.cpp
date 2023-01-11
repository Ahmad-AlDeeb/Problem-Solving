#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

int main() { IOS
    int n{}; cin >> n;
    vector<int>vec(n,0);
    for(int i{}; i<n; i++) cin >> vec[i];

    while(!vec.empty()) {
        cout << vec.front() << " "; vec.erase(vec.begin());
        if(vec.empty()) break;
        cout << vec.back() << " "; vec.pop_back();
    }

}
