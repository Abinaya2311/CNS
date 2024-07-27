#include <stdio.h>
#include <math.h>

int main() {
    // Calculate the total number of keys ignoring duplicate keys
    long total_keys = 1;
    for (int i = 26; i > 0; i--) {
        total_keys *= i;
    }
    printf("Total possible keys: %.0f\n", (double) total_keys);
    printf("Approximate power of 2: %.2f\n", log2((double) total_keys));

    // Considering the fact that some keys produce the same encryption results
    long unique_keys = total_keys / 2;
    printf("Effectively unique keys: %.0f\n", (double) unique_keys);
    printf("Approximate power of 2 for unique keys: %.2f\n", log2((double) unique_keys));

    return 0;
}

