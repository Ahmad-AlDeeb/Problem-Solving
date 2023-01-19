// Int to binary conversion
string binary = bitset<32>(n).to_string(); // 1st way
// or by dividing n by 2 and pushing back the remainder till n becomes 0 (2nd way)
// or (3rd way)
void print_bits(ll n, ll size) {
    if(!size) return;

    print_bits(n>>1, size-1);
    cout << (n&1);
}
////////////////////////////

// count 0s and 1s in binary
pair<ll,ll> bits_count(ll n) {
    ll ones{},zeros{};
    while(n) {
        if(n&1) ones++; else zeros++;
        n >>= 1;
    }
    pair<ll,ll> ans{zeros,ones};
    return ans;
}
