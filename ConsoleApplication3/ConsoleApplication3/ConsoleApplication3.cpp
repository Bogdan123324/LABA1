#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
char* my_strrchr(char* s, int c) {
    char* last = NULL;
    char* original_s = s;

    while (*s != '\0') {
        if (*s == (char)c) {
            last = s;
        }
        s++;
    }
    if (c == '\0') {
        return s;
    }

    return last;
}
int main() {
    system("chcp 65001 > nul");
    setlocale(LC_ALL, "");

    char str[] = "Hello, world!";
    int c1 = 'o';
    int c2 = '!';
    int c3 = 'x';
    printf("Стандартная strrchr:\n");
    fflush(stdout);
    char* result1 = strrchr(str, c1);
    printf("Символ '%c': %s\n", c1, result1 ? result1 : "не найден");
    fflush(stdout);
    char* result2 = strrchr(str, c2);
    printf("Символ '%c': %s\n", c2, result2 ? result2 : "не найден");
    fflush(stdout);
    char* result3 = strrchr(str, c3);
    printf("Символ '%c': %s\n", c3, result3 ? result3 : "не найден");
    fflush(stdout);
    printf("\nМоя strrchr:\n");
    fflush(stdout);
    char* my_result1 = my_strrchr(str, c1);
    printf("Символ '%c': %s\n", c1, my_result1 ? my_result1 : "не найден");
    fflush(stdout);
    char* my_result2 = my_strrchr(str, c2);
    printf("Символ '%c': %s\n", c2, my_result2 ? my_result2 : "не найден");
    fflush(stdout);
    char* my_result3 = my_strrchr(str, c3);
    printf("Символ '%c': %s\n", c3, my_result3 ? my_result3 : "не найден");
    fflush(stdout);
    printf("\nНажмите Enter для выхода...");
    fflush(stdout);
    getchar();
    return 0;
}