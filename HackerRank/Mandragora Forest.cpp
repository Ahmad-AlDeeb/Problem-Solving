#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'mandragora' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY H as parameter.
 */

long long mandragora(vector<int> H) {
    long long n = H.size(); 
    vector<long long>pre(n+1);
    for(long long i{}; i<n; i++)
        pre[i+1] = H[i];
    
    sort(pre.begin(),pre.end());
    for(long long i{1}; i<=n; i++) pre[i] += pre[i-1];

    long long ans{};
    for(long long i{1}; i<=n; i++) {
        long long xp = i * (pre.back()-pre[i-1]);
        ans = max(ans, xp);
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string H_temp_temp;
        getline(cin, H_temp_temp);

        vector<string> H_temp = split(rtrim(H_temp_temp));

        vector<int> H(n);

        for (int i = 0; i < n; i++) {
            int H_item = stoi(H_temp[i]);

            H[i] = H_item;
        }

        long result = mandragora(H);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
