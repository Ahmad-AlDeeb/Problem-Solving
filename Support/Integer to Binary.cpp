string binary = bitset<32>(n).to_string(); // 1st way
// or by dividing n by 2 and pushing back the remainder till n becomes 0 (2nd way)
// or (3rd way)
void print_bits(ll n, ll size) {
    if(!size) return;

    print_bits(n>>1, size-1);
    cout << (n&1);
}
