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
    int n{}; cin >> n;
    for(int i{}; i<n/2; i++) { // upper half
        for(int j{}; j<i; j++) cout << "*"; cout << "\\";
        for(int j{}; j<n-2-(i*2); j++) cout << "*"; cout << "/";
        for(int j{}; j<i; j++) cout << "*"; cout << endl;
    }

    for(int j{}; j<n; j++) { // middle part
        if(j==n/2) cout << "X";
        else cout << "*";
    }
    cout << endl;

    for(int i{n/2-1}; i>=0; i--) { // down half
        for(int j{}; j<i; j++) cout << "*"; cout << "/";
        for(int j{}; j<n-2-(i*2); j++) cout << "*"; cout << "\\";
        for(int j{}; j<i; j++) cout << "*"; cout << endl;

    }

}
