#include<stdio.h>
#include <stdbool.h>
#include <string.h>
bool isPalindrome(const char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - 1 - i]) {
            return false; // ����κ�һ���ַ�����ȣ����ǻ���
        }
    }
    return true; // ���ж�Ӧλ�õ��ַ�����ȣ�����ǻ���
}

int main() {
    char test[]="level";
    //const char* testString = "level";
    if (isPalindrome(test)) {
        printf("%s �ǻ��Ĵ���\n", test);
    }
    else {
        printf("%s ���ǻ��Ĵ���\n", test);
    }
    return 0;
}