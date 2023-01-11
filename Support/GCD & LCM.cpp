long long gcd(long long a, long long b) {
    if(b != 0) return gcd(b, a%b);
    else return a;
}
long long lcm(long long a, long long b) {
    return a*b / gcd(a,b);
}
