#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define dd double
#define ld long double
#define PQ priority_queue
#define pii pair<int,int>
#define pcc pair<char, char>
#define pll pair<ll,ll>
#define S second
#define F first
#define MP make_pair
#define dpp(arr,val) memset(arr,val,sizeof(arr))
#define endl "\n"
using namespace std;

int main() { IOS
    dd n{}; cin >> n;
    if(n>=0 && n<=25) cout << "Interval " << "[0,25]";
    else if(n>25 && n<=50) cout << "Interval " << "(25,50]";
    else if(n>50 && n<=75) cout << "Interval " << "(50,75]";
    else if(n>75 && n<=100) cout << "Interval " << "(75,100]";
    else
        cout << "Out of Intervals";
}
