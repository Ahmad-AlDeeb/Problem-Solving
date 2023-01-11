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
    int n{}, k{}; cin >> n >> k;
    int counter{}, mini{1000000000};

    for(int i{}; i<n; i++) {
        int num{}; cin >> num;
        if(num < mini) mini = num;
        if(++counter==k || i==n-1) {
            cout << mini << " ";
            counter = 0;
            mini = 1000000000;
        }
    }

}
