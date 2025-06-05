#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

long long sum_of_squares_of_primes(int limit) {
    long long sum = 0;
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            sum += (long long)i * i;
        }
    }
    return sum;
}

int main(int argc, char *argv[]) {
    int limit = 1000000;
    long long result = sum_of_squares_of_primes(limit);
    printf("Sum of squares of primes up to %d: %lld\n", limit, result);
    return 0;
}
