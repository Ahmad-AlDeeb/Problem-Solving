#include<string>
#include<iostream>
#include <sstream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<vector>
#include <string.h>
#define  f first
#define  se second
#define dd double
#define ll long long
#define ld long double
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;

int main() { IOS
    int n{}; cin >> n;
    string ans {"ROYGBIV"}; n-=7;
    bool special{true};
    while(n>=4) {
        ans += "ROYG"; n-=4;
        special=false;
    }
    if(special)
        for(int i{3}; n>0; n--,i++)
            ans += ans[i];
    else
        for(int i{4}; n>0; n--,i++)
            ans += ans[i];

    cout << ans;
}
