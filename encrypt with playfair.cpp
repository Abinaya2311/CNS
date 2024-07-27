#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

void generateKeyTable(char key[], char keyTable[SIZE][SIZE]) {
    int dict[26] = {0};
    int i, j, k, flag = 0, row = 0, col = 0;

    for (i = 0; key[i] != '\0'; ++i) {
        if (key[i] != 'J' && !dict[key[i] - 'A']) {
            keyTable[row][col++] = key[i];
            dict[key[i] - 'A'] = 1;
            if (col == SIZE) {
                col = 0;
                ++row;
            }
        }
    }

    for (i = 0; i < 26; ++i) {
        if (i != 9 && !dict[i]) {
            keyTable[row][col++] = (char) (i + 'A');
            if (col == SIZE) {
                col = 0;
                ++row;
            }
        }
    }
}

void formatText(char text[]) {
    int i, j;
    for (i = 0; text[i] != '\0'; ++i) {
        if (text[i] == 'J') {
            text[i] = 'I';
        }
    }

    for (i = 0; text[i] != '\0'; i += 2) {
        if (text[i + 1] == '\0') {
            text[i + 1] = 'X';
            text[i + 2] = '\0';
        } else if (text[i] == text[i + 1]) {
            for (j = strlen(text) + 1; j > i + 1; --j) {
                text[j] = text[j - 1];
            }
            text[i + 1] = 'X';
        }
    }
}

void encrypt(char text[], char keyTable[SIZE][SIZE]) {
    int i, pos[4];
    for (i = 0; text[i] != '\0'; i += 2) {
        search(keyTable, text[i], text[i + 1], pos);

        if (pos[0] == pos[2]) {
            text[i] = keyTable[pos[0]][(pos[1] + 1) % SIZE];
            text[i + 1] = keyTable[pos[2]][(pos[3] + 1) % SIZE];
        } else if (pos[1] == pos[3]) {
            text[i] = keyTable[(pos[0] + 1) % SIZE][pos[1]];
            text[i + 1] = keyTable[(pos[2] + 1) % SIZE][pos[3]];
        } else {
            text[i] = keyTable[pos[0]][pos[3]];
            text[i + 1] = keyTable[pos[2]][pos[1]];
        }
    }
}

int main() {
    char key[] = "MFHIKUNOPQVWXZVWRGLDSTBC";
    char text[] = "MUSTSEEYOUOVERCADOGANWESTCOMINGATONCE";
    char keyTable[SIZE][SIZE];

    generateKeyTable(key, keyTable);
    formatText(text);
    encrypt(text, keyTable);

    printf("Encrypted text: %s\n", text);

    return 0;
}

