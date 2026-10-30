#include <stdio.h>

int n;
char s[1000];

void skobki(int pos, int open, int close)
{
    if (pos == 2 * n)
    {
        s[pos] = '\0';
        printf("%s\n", s);
        return;
    }

    if (open < n)
    {
        s[pos] = '(';
        skobki(pos + 1, open + 1, close);
    }

    if (close < open)
    {
        s[pos] = ')';
        skobki(pos + 1, open, close + 1);
    }
}

int main()
{
    printf("Введите N: ");

    if (scanf("%d", &n) != 1 || n <= 0 || n > 499)
    {
        printf("Ошибка, введите натуральное число от 1 до 499.");
        return 0;
    }

    skobki(0, 0, 0);

    return 0;
}
/*
pos-место в массиве(куда ставить след. скобку)
open-количество открытых скобок
close-закрытых
