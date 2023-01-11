#include <iostream>
#include <sstream>
#define ll long long
using namespace std;
int main() {
    int a{}, b{}; cin >> a >> b;
    bool success{false};
    for(; a<=b; a++) {
        stringstream ss;
        ss << a;
        string s; ss >>  s;

        for(char c:s)
            if(c!='4' && c!='7') goto end;
        success = true;
        cout << s << " ";
            end:;
    }
    if(!success) cout << "-1";
}
