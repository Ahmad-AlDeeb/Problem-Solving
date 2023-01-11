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
    int n{}; cin >> n;
    vector<int> vec(n,0);
    for(int i{}; i<n; i++)
        cin >> vec.at(i);

    for(int i{}, j{n-1}; i<=n/2; i++, j--)
        if(vec.at(i) != vec.at(j))
            {cout << "NO"; return 0;}
    cout << "YES";
}
