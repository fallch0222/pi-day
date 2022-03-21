#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int main() {
    struct timeval  tv1, tv2;
    gettimeofday(&tv1, NULL);

    int r[2000];
    int i, k;
    int b, d;
    int c = 0;

    for (i = 0; i < 340; i++) {
        r[i] = 2000;
    }




    for (k = 340; k > 0; k -= 14) {
        d = 0;

        i = k;
        for (;;) {
            d += r[i] * 10000;
            b = 2 * i - 1;

            r[i] = d % b;
            d /= b;
            i--;
            if (i == 0) break;
            d *= i;
        }
        printf("%.4d", c + d / 10000);
        c = d % 10000;
    }
    gettimeofday(&tv2, NULL);

    double runtime =  (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
    (double) (tv2.tv_sec - tv1.tv_sec);

    runtime *= 1000;
    printf ("\nTotal runtime Is %f ms",runtime
    );

    return 0;
}