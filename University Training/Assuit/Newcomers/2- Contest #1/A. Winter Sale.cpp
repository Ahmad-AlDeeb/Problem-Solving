#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define dd double
using namespace std;

int main() { IOS
    dd p{}, x{}; cin >> p >> x;
    cout << fixed << setprecision(2) << dd (100*x) / (100-p);
}
