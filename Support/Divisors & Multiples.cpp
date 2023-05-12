////////////////////////////////// Factors //////////////////////////////////////
vector<ll>divisors;
for(int i{1}; i*i<=x; i++) 
    if(x%i == 0) {
        divisors.push_back(x);
        if(i*i != x) divisors.push_back(x/i);
    }
///////////////////////////////////  Multiples /////////////////////////////////////////
vector<vector<ll>>multiples(MAX);
void init() {
    for(ll fact{}; fact<MAX; fact++)
        for(ll multi{fact}; multi<MAX; multi+=fact)
            multiples[multi].pb(fact);
}



