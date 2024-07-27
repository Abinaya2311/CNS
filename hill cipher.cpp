#include <stdio.h>

void encrypt(int plaintext[], int key[2][2], int ciphertext[]) {
    ciphertext[0] = (key[0][0] * plaintext[0] + key[0][1] * plaintext[1]) % 26;
    ciphertext[1] = (key[1][0] * plaintext[0] + key[1][1] * plaintext[1]) % 26;
}

void decrypt(int ciphertext[], int inverse_key[2][2], int plaintext[]) {
    plaintext[0] = (inverse_key[0][0] * ciphertext[0] + inverse_key[0][1] * ciphertext[1]) % 26;
    plaintext[1] = (inverse_key[1][0] * ciphertext[0] + inverse_key[1][1] * ciphertext[1]) % 26;
}

int main() {
    int key[2][2] = {{9, 4}, {5, 7}};
    int plaintext[2] = {12, 4};  // 'm' -> 12, 'e' -> 4
    int ciphertext[2];

    // Encrypt the plaintext
    encrypt(plaintext, key, ciphertext);
    printf("Encrypted text: %d %d\n", ciphertext[0], ciphertext[1]);

    int inverse_key[2][2] = {{7, 22}, {21, 9}}; // Precomputed inverse key
    int decrypted_text[2];

    // Decrypt the ciphertext
    decrypt(ciphertext, inverse_key, decrypted_text);
    printf("Decrypted text: %d %d\n", decrypted_text[0], decrypted_text[1]);

    return 0;
}

