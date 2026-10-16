#include <stdio.h>
#include <math.h>

int main()
{
    float x, y, u;
    float xn = 0, xk = 10, hx = 0.4;
    float yn = 1, yk = 8, hy = 0.3;

    printf("       ");

    for (y = yn; y <= yk; y = y + hy)
    {
        printf("%f", y);
    }

    printf("n");

    for (x = xn; x <= xk; x = x + hx)
    {
        printf("x=%f ", x);

        for (y = yn; y <= yk; y = y + hy)
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

            printf("%f", u);
        }

        printf("\n");
    }

    return 0;
}
