                                                    // problem: Gym - 350741G
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
    int mid{}, n{}; cin >> n;
    if(n%2 == 0) mid = (n/2)-1;
    else mid = (n/2)-1;

    for(int i{}; i<=mid; i++) { // first up half
        for(int j{}; j<i; j++) cout << "  "; // printing spaces before first *
        cout << "* ";

        for(int j{i+1}; j<(n-1)-i; j++) cout << "  "; // printing spaces before second *
        cout << "* " << endl;
    }

    if(n%2 != 0) { // output the middle single * when n is odd
        for(int i{}; i<=mid; i++) cout << "  ";
        cout << "* " << endl;
    }

    for(int i{mid}; i>=0; i--) { // second bottom half
        for(int j{}; j<i; j++) cout << "  "; // printing spaces before first *
        cout <<"* ";

        for(int j{i+1}; j<(n-1)-i; j++) cout << "  "; // printing spaces before second *
        cout << "* " << endl;
    }
}
