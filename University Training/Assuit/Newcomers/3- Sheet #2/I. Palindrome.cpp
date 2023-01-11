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
    string n{}; cin >> n;
    reverse(n.begin(), n.end());
    int i{};
    while(i<n.size() && n[i]=='0')
        i++;
    for(; i<n.size(); i++)
        cout << n[i];
    cout << endl;

    for(size_t l{}, r{n.size()-1}; l<=n.size()/2; l++, r--)
        if(n[l] != n[r]) {cout << "NO"; return 0;}
    cout << "YES";
}
