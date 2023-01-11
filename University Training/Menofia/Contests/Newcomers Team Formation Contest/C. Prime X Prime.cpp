                                        // problem link: https://codeforces.com/group/6FyLsqC8Xx/contest/379621/problem/C
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
    int x{}, y{}; cin >> x >> y;
    vector<int> p {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

    if(x == 47) {cout << "NO"; return 0;}
    for(int i{}; i<p.size(); i++)
        if(x==p.at(i) && y==p.at(i+1)) {cout << "YES"; return 0;}

    cout << "NO";
}
