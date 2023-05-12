////////////////////////////////// Factors //////////////////////////////////////
vector<ll>divisors;
for(int i{1}; i*i<=x; i++) 
    if(x%i == 0) {
        divisors.push_back(i);
        if(i*i != x) divisors.push_back(x/i);
    }
///////////////////////////////////  Multiples /////////////////////////////////////////
vector<vector<ll>>multiples(MAX+1);
for(ll div{}; div<MAX; div++)
    for(ll multi{div}; multi<=MAX; multi+=div)
        multiples[multi].pb(div);




