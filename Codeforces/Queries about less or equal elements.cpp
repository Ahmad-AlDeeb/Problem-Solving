#include<string>
#include<iostream>
#include <sstream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#define  f first
#define  se second
#define dd double
#define ll long long
#define ld long double
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
 
int main() { IOS
    int n,m; cin >> n >> m;
    vector<int>a(n),b(m);
    for(int i{}; i<n; i++) cin >> a[i];
    for(int i{}; i<m; i++) cin >> b[i];
    sort(a.begin(),a.end());
 
    for(auto num:b) cout << upper_bound(a.begin(),a.end(),num)-a.begin() << " ";
}
