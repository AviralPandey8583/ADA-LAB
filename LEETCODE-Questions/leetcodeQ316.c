#include <stdio.h>
#include <string.h>

void removeDuplicateLetters(char* s, char* result) {
    int count[26] = {0};
    int visited[26] = {0};

    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        count[s[i] - 'a']++;
    }

    int top = -1;

    for (int i = 0; i < len; i++) {
        char ch = s[i];

        count[ch - 'a']--;

        if (visited[ch - 'a'])
            continue;

        while (top >= 0 &&
               result[top] > ch &&
               count[result[top] - 'a'] > 0) {

            visited[result[top] - 'a'] = 0;
            top--;
        }

        result[++top] = ch;
        visited[ch - 'a'] = 1;
    }

    result[top + 1] = '\0';
}

int main() {
    char s[] = "cbacdcbc";
    char result[100];

    removeDuplicateLetters(s, result);

    printf("Result: %s\n", result);

    return 0;
}
