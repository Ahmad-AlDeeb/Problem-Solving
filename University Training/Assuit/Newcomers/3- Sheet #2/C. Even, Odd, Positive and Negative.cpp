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
    int pos{}, neg{}, even{}, odd{};
    for(int i{}; i<n; i++) {
        int num; cin >> num;
        if(num>0) pos++;
        if(num<0) neg++;
        if(num%2==0) even++;
        if(num%2!=0) odd++;
    }
    cout << "Even: " << even << endl
         << "Odd: " << odd << endl
         << "Positive: " << pos << endl
         << "Negative: " << neg << endl;
}
