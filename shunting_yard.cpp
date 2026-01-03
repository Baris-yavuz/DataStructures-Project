#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack Yapýsý
struct Stack {
    int top;
    char items[MAX];
} s;

void push(char item) {
    if (s.top >= MAX - 1) {
        printf("Stack dolu!\n");
        return;
    }
    s.items[++(s.top)] = item;
}

char pop() {
    if (s.top == -1) return -1;
    return s.items[(s.top)--];
}

int priority(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

int main() {
    char exp[MAX];
    char *e, x;
    s.top = -1;

    printf("=== SHUNTING YARD ALGORITMASI ===\n");
    printf("Infix ifadeyi giriniz (bosluksuz, orn: a*b+c): ");
    scanf("%s", exp);

    printf("\nInfix: %s\n", exp);
    printf("Postfix: ");

    e = exp;
    while (*e != '\0') {
        if (isalnum(*e)) {
            printf("%c", *e); // Sayý/Harf ise yaz
        } else if (*e == '(') {
            push(*e);
        } else if (*e == ')') {
            while ((x = pop()) != '(')
                printf("%c", x);
        } else {
            while (s.top != -1 && priority(s.items[s.top]) >= priority(*e))
                printf("%c", pop());
            push(*e);
        }
        e++;
    }
    
    // Stack'te kalanlarý boþalt
    while (s.top != -1)
        printf("%c", pop());
    
    printf("\n");
    return 0;
}
