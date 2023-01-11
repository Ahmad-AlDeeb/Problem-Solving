                                    // Problem link: https://codeforces.com/group/jfviGllBoY/contest/379280/problem/E
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

int main() { IOS
    int n{}, k{}; cin >> n >> k;

    vector<int> vec(n, 0);
    for(int i{}; i<n; i++)
        cin >> vec[i];

//    sort(vec.begin(), vec.end()); // sorting to have the bigger elements at the end of the vector
    sort(vec.begin(), vec.end());

    ll sum{};
    for(int i{n-1}; i>=n-k; i--) { // summing the biggest k numbers from the back of the vector
        if(vec.at(i) <= 0) break; // we break if we are going to add minus number which will reduce total
        sum += vec.at(i);
    }

    cout << sum;
}
