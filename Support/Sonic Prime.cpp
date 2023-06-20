// Source: CP-4 Book Part (2) Page (19)
bool isPrime(ll N) { // good enough prime test
  if (N < _sieve_size) return bs[N]; // O(1) for small primes

  for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
    if (N%p[i] == 0)
      return false;
  return true; // slow if N = large prime
} // note: only guaranteed to work for N <= (last prime in vll p)^2
