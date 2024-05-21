#include<stdio.h>
#include <stdbool.h>
#include <string.h>
bool isPalindrome(const char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - 1 - i]) {
            return false; // 如果任何一对字符不相等，则不是回文
        }
    }
    return true; // 所有对应位置的字符都相等，因此是回文
}

int main() {
    char test[]="level";
    //const char* testString = "level";
    if (isPalindrome(test)) {
        printf("%s 是回文串。\n", test);
    }
    else {
        printf("%s 不是回文串。\n", test);
    }
    return 0;
}