#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 500

// Function to count the frequency of each character
void countFrequency(char *ciphertext, int freq[]) {
    for (int i = 0; i < strlen(ciphertext); i++) {
        if (isalpha(ciphertext[i])) {
            freq[ciphertext[i] - 'A']++;
        }
    }
}

// Function to print the character frequencies
void printFrequency(int freq[]) {
    for (int i = 0; i < 26; i++) {
        printf("%c: %d\n", 'A' + i, freq[i]);
    }
}

// Function to decrypt the ciphertext using the deduced key
void decryptCiphertext(char *ciphertext, char *key, char *plaintext) {
    for (int i = 0; i < strlen(ciphertext); i++) {
        if (isalpha(ciphertext[i])) {
            plaintext[i] = key[ciphertext[i] - 'A'];
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[strlen(ciphertext)] = '\0';
}

int main() {
    char ciphertext[MAX_LEN] = "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;]8*;:‡*8†83(88)5*†;46(;88*96*?;8)*‡(;485);5*†2:*‡(;4956*2(5*—4)8¶8*;4069285);)6†8)4‡‡;1(‡9;48081;8:8‡1;48†85;4)485†528806*81(‡9;48;(88;4(‡?34;48)4‡;161;:188;‡?";
    int freq[26] = {0};
    char key[26] = {0};
    char plaintext[MAX_LEN] = {0};

    // Count the frequency of each character
    countFrequency(ciphertext, freq);
    printFrequency(freq);

    // Deduce the key (for demonstration purposes, we assume certain characters map to 'e', 't', 'a', etc.)
    // This key is based on common frequency analysis and the knowledge that '‡' is the most frequent character in this ciphertext.
    strcpy(key, "ETAOINSHRDLCUMWFGYPBVKJXQZ");

    // Decrypt the ciphertext using the deduced key
    decryptCiphertext(ciphertext, key, plaintext);

    printf("Decrypted message: %s\n", plaintext);

    return 0;
}

