#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

int main() { IOS
    int t{}; cin >> t;
    while(t--) {
        int n{}; cin >> n;
        vector<int>vec; int evens{}, odds{};
        for(int i{}; i<n; i++) {
            int x{}; cin >> x;
            vec.push_back(x);

            if(x%2 == 0) evens++;
            else         odds++;
        }

        if(n%2 != 0) cout << -1 << endl;
        else         cout << abs(evens-odds)/2 << endl;
    }
}
