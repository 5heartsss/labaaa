#include <stdio.h>
#include <math.h>

int main()
{
    float x, y, u;
    float xn = 0, xk = 1, hx = 0.4;
    float yn = 1, yk = 2, hy = 0.3;

    printf("       ");

    for (y = yn; y <= yk + 0.001; y = y + hy)   //+ 0.001 чтобы избежать проблем с погрешностью
    {
        printf("%8.2f", y);
    }

    printf("\n");

    for (x = xn; x <= xk + 0.001; x = x + hx)
    {
        printf("x=%.2f ", x);

        for (y = yn; y <= yk + 0.001; y = y + hy)
        {
            if (x * y <= -1)
            {
                float a = exp(2) * sqrt(log(pow(x, 4) + 2));
                float b = x * acos(x / y);

                if (a > b)
                    u = a;
                else
                    u = b;
            }
            else if (x * y < 2)
            {
                u = 0;
            }
            else
            {
                float a = sqrt(fabs(x * x - y));
                float b = cos(pow(x, 3) * sqrt(y - 1));

                if (a < b)
                    u = a;
                else
                    u = b;
            }

            printf("%8.2f", u);
        }

        printf("\n");
    }

    return 0;
}
//в таблице нули т.к. 0≤x≤1 и 1≤y≤2 значит 0≤xy≤2 но при наших конкретных значениях x и y произведение меньше 2, например: 
//0 · 1   = 0
//0.4 · 1 = 0.4
//0.8 · 1 = 0.8
//0.8 · 1.9 = 1.52
//Поэтому первая ветка не срабатывает, а третья тоже практически не срабатывает, потому что для неё нужно xy≥2 соответсвенно остаётся тоолько 2-ая строчка, где u=0
