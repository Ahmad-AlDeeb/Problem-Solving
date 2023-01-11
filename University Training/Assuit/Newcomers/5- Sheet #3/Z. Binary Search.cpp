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

bool binary_search(vector<int>&vec, int x, int left, int right) {
    if(left > right) return false;
    int mid {(left+right)/2};
    if(vec[mid] == x) return true;
    else if(x < vec[mid]) return binary_search(vec, x, left, mid-1);
    else binary_search(vec, x, mid+1, right);
}

int main() { IOS
    int n{}, q{}; cin >> n >> q;
    vector<int>vec(n,0);
    for(int i{}; i<n; i++) cin >> vec[i];
    sort(vec.begin(),vec.end());

    while(q--) {
        int x{}; cin >> x;
        if (binary_search(vec, x, 0, n - 1))
             cout << "found" << endl;
        else cout << "not found" << endl;
    }
}
