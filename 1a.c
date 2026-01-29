#include <stdio.h>

// Function to calculate the nth Fibonacci term recursively
long long fibonacci_recursive(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int main() {
    int n = 10; // Change 'n' to calculate a different term
    // The sequence starts from n=0, n=1, n=2... (0, 1, 1, 2, ...)
    printf("Fibonacci term %d (recursive): %lld\n", n, fibonacci_recursive(n));
    return 0;
}

