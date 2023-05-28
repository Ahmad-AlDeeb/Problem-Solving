string alpha{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
map<char,ll> val;
void ini_val() {
    for(ll i{},v{10}; v <= 35; v++,i++)
        val[alpha[i]] = v;
}
ll calc_in_base(string n, ll b) { // O( n.size() )
    ll sz = n.size();
    ll res{};
    for(ll i{sz-1},p{}; i>=0; i--,p++) {
        if(isalpha(n[i]))
             res += val[n[i]] * (ll)pow(b,p);
        else res += (n[i]-'0') * (ll)pow(b,p);
    }
    return res;
}
