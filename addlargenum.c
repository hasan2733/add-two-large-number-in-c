#include <stdio.h>
#include <string.h>

void add(char a[], char b[], char sum[]) {
    int len1 = strlen(a);
    int len2 = strlen(b);
    int max;
    if (len1 > len2) {
        max = len1;
    } else {
        max = len2;
    }
    int carry = 0;
    int val;

    int sumindex = max;
    sum[sumindex + 1] = '\0';
    for (int i = 0; i < max; i++) {
        int n1 = 0, n2 = 0;
        if (i < len1) {
            n1 = a[len1 - 1 - i] - '0';
        }
        if (i < len2) {
            n2 = b[len2 - 1 - i] - '0';
        }
        val = n1 + n2 + carry;
        carry = val / 10;
        val = val % 10;
        sum[sumindex--] = val + '0';
    }
    if (carry) {
        sum[sumindex--] = carry + '0';
    }
    if (sumindex >= 0) {
        for (int i = 0; i <= max; i++) {
            sum[i] = sum[i + 1];
        }
    }
}

int main() {
    char a[31];
    char b[31];
    scanf("%30s %30s", a, b);
    char sum[32];
    add(a, b, sum);
    printf("Sum: %s\n", sum);
    return 0;
}
