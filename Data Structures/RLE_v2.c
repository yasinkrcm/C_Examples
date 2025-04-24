//Rle_v2.c

#include <stdio.h>
#include <string.h>

void rle_encode(const char* input, char* output) {
    int count, i, j = 0;
    int len = strlen(input);
    for (i = 0; i < len; i++) {
        count = 1;
        while (i < len - 1 && input[i] == input[i + 1]) {
            count++;
            i++;
        }
        output[j++] = input[i];
        output[j++] = count + '0'; // sayı karaktere dönüştürülüyor
    }
    output[j] = '\0';
}

void rle_decode(const char* input, char* output) {
    int i, j = 0;
    int len = strlen(input);
    for (i = 0; i < len; i += 2) {
        char ch = input[i];
        int count = input[i + 1] - '0';
        for (int k = 0; k < count; k++) {
            output[j++] = ch;
        }
    }
    output[j] = '\0';
}

int main() {
    char input[100], encoded[200], decoded[100];
    printf("Metin girin (sadece harfler): ");
    scanf("%s", input);
    rle_encode(input, encoded);
    printf("Sıkıştırılmış (RLE): %s\n", encoded);
    rle_decode(encoded, decoded);
    printf("Açılmış: %s\n", decoded);
    return 0;
}