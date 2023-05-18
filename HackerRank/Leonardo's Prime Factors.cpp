#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'primeCount' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts LONG_INTEGER n as parameter.
 */



vector<long long> sieve(long long n) {
    vector<bool>primes(n+1,true);
    primes[0]=primes[1]=false;

    for(long long i{2}; i*i<=n; i++)
        if(primes[i])
            for(long long j{i*i}; j<=n; j+=i)
                primes[j]=false;

    vector<long long>ans;
    for(long long i{2}; i<=n; i++)
        if(primes[i]) ans.push_back(i);
    return ans;
}
vector<long long> primes = sieve(1000006);
long long primeCount(long long n) {

    long long pro{1},cnt{};
    for(auto p:primes) {
        pro *= p;
        if(pro<0 || pro > n) break;
        cnt++;
    }
    return cnt;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string n_temp;
        getline(cin, n_temp);

        long n = stol(ltrim(rtrim(n_temp)));

        int result = primeCount(n);

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
