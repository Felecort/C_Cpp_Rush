#include "is_prime.h"

typedef unsigned long long *ull_ptr;
typedef unsigned long long ull;

// 10.5
static ull power(ull x, ull y, ull p)
{
    ull result = 1;
    x %= p;
    while(y){
        if (y & 1) result = (result * x) % p;
        y >>= 1;
        x = (x * x) % p;
    }
    return result;
}

static bool miller_rabin_test(ull d, ull n)
{
    ull a = 2 + rand() % (n - 4);
    ull x = power(a, d, n);

    if (x == 1 || x == n - 1) return true;
    while (d != n - 1){
        x = (x * x) % n;
        d *= 2;

        if (x == 1) return false;
        if ( x == n - 1) return false;
    }
    return false;
}

// 10.6
bool is_prime(ull n, unsigned int k)
{
    if (n <= 1 || n == 4) return false;
    if (n <= 3) return true;

    ull d = n - 1;
    while(d % 2 == 0) d /= 2;
    for(; k != 0; --k){
        if (!miller_rabin_test(d, n)) return false;
    }
    return true;
}