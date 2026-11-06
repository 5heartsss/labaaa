#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int N, M;

    printf("Введите N (строки): ");
    if (scanf("%d", &N) != 1) {
        printf("Ошибка ввода: нужно целое число.\n");
        return 1;
    }
    printf("Введите M (столбцы): ");
    if (scanf("%d", &M) != 1) {
        printf("Ошибка ввода: нужно целое число.\n");
        return 1;
    }

    // Побочная диагональ определена для квадратной матрицы.
    if (N != M) {
        printf("Матрица должна быть квадратной (N = M).\n");
        return 1;
    }

    // Матрица должна быть не меньше 3 на 3,
    // потому что в формуле используется элемент a32 и третий столбец.
    if (N < 3) {
        printf("Матрица должна быть не меньше 3 на 3.\n");
        return 1;
    }

    double *Matrix = malloc(M * N * sizeof(*Matrix));
    if (Matrix == NULL) {
        printf("Ошибка выделения памяти.\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("Введите элемент [%d][%d]: ", i, j);
            if (scanf("%lf", &Matrix[i * M + j]) != 1) {
                printf("Ошибка ввода: нужно число.\n");
                free(Matrix);
                return 1;
            }
        }
    }

    printf("\nИсходная матрица:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("| %f |", Matrix[i * M + j]);
        }
        printf("\n");
    }

    // Находим минимальный элемент побочной диагонали
    double min = Matrix[M - 1];
    for (int i = 0; i < N; i++) {
        double v = Matrix[i * M + (M - 1 - i)];
        if (v < min) {
            min = v;
        }
    }
    printf("\nМинимальный элемент побочной диагонали: %f\n", min);

    // Вычисляем сумму по формуле: ctg(a32) + сумма exp(a[i][3])
    // a32 — это строка 3, столбец 2, то есть Matrix[2 * M + 1]
    double t = tan(Matrix[2 * M + 1]);
    if (fabs(t) < 1e-9) {
        printf("Ошибка: котангенс не определён (tan(a32) = 0).\n");
        free(Matrix);
        return 1;
    }

    double S = 1 / t;
    for (int i = 0; i < N; i++) {
        S = S + exp(Matrix[i * M + 2]);
    }
    printf("Сумма S = %f\n", S);

    free(Matrix);
    return 0;
}
