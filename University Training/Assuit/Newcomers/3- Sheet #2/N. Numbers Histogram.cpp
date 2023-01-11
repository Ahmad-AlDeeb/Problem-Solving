#include <iostream>
#include <sstream>
#define ll long long
using namespace std;
int main() {
    char c; int t{}; cin >> c >> t;
    while(t--) {
        int n{}; cin >> n;
        while(n--) cout << c;
        cout << endl;
    }
}
