#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
void encrypt(char text[], int s, char result[])
{
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        if (isupper(text[i]))
            result[i] = (text[i] + s - 65) % 26 + 65;
        else if (islower(text[i]))
            result[i] = (text[i] + s - 97) % 26 + 97;
        else
            result[i] = text[i]; 
    }
    result[i] = '\0';
}

int main()
{
    char text[100];
    int s;
    char result[100];

    printf("Text: ");
    scanf("%s", text);

    printf("Shift: ");
    scanf("%d", &s);

    encrypt(text, s, result);

    printf("Cipher: %s\n", result);
    
    return 0;
}
