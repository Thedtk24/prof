#include <iostream>
#include <cmath>
#include <chrono>

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= std::sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

long long sum_of_squares_of_primes(int limit) {
    long long sum = 0;
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            sum += static_cast<long long>(i) * i;
        }
    }
    return sum;
}

int main() {
    int limit = 1000000;
    
    auto start = std::chrono::high_resolution_clock::now();
    long long result = sum_of_squares_of_primes(limit);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Sum of squares of primes up to " << limit << ": " << result << "\n";
    std::cout << "Execution time: " << elapsed.count() << " seconds\n";

    return 0;
}
