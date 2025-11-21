/* #include <stdio.h>

int main(void) {
    int prosli, n, duljina = 1, index = 1, indexMAX = 0, duljinaMAX = 0;
    printf("Upisite niz cijelih brojeva > ");
    scanf("%d", &prosli);

    if (prosli != 0) {
        do {
            index++;
            scanf("%d", &n);

            if (n > prosli) {
                duljina++;
            }else {
                duljina = 1;
            }
            if (duljina >= duljinaMAX) {
            duljinaMAX = duljina;
            indexMAX = index;
            }
            prosli = n;
        } while (n != 0);

        printf(
            "Najdulji strogo rastuci podniz duljine %d zapoceo je na %d.
clanu.\n", duljinaMAX, indexMAX + 1 - duljinaMAX);

    } else {
        printf(
            "Najdulji strogo rastuci podniz duljine %d zapoceo je na %d.
clanu.\n", 1, 1);
    }

    return 0;
} */
/*
#include <stdio.h>

int main(void) {
    int m, n, i, j;

    do {
        printf("Unesite m i n: ");
        scanf("%d %d", &m, &n);
    } while (m * n > 100);

    int a[m][n];
    printf("Unesite elemente matrice:\n");

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    int maksimum = 1;
    printf("Matrica:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            maksimum = 1;
            if (maksimum == 1) {
                if (i - 1 > 0 && a[i][j] <= a[i - 1][j]) {
                    maksimum = 0;
                }
            }
            if (maksimum == 1) {
                if (i + 1 < m && a[i][j] <= a[i + 1][j]) {
                    maksimum = 0;
                }
            }
            if (maksimum == 1) {
                if (j - 1 > 0 && a[i][j] <= a[i][j - 1]) {
                    maksimum = 0;
                }
            }
            if (maksimum == 1) {
                if (j + 1 < n && a[i][j] <= a[i][j + 1]) {
                    maksimum = 0;
                }
            }
            if (maksimum == 1) {
                printf("%4d*", a[i][j]);
            } else {
                printf("%5d", a[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
} */

/* #include <stdio.h>
#define MAX_LEN 32

int binarni_palindrom(unsigned int n) {
    int palindorm = 1, len = 0, a, b;
    for (int i = MAX_LEN - 1; len == 0 && i >= 0; i--) {
        unsigned short mask = 1u << i;
        if (mask & n) {
            len = i;
        }
    }

    for (int i = len; i > len - i && palindorm == 1; i--) {
        unsigned short mask = 1u << i;
        unsigned short mask2 = 1u << (len - i);
        if (mask & n) {
            a = 1;
        } else {
            a = 0;
        }
        if (mask2 & n) {
            b = 1;
        } else {
            b = 0;
        }
        if (a != b) {
            palindorm = 0;
        }
    }

    return palindorm;
}

int main(void) {
    unsigned int n;
    printf("Upisite broj > ");
    scanf("%u", &n);

    if (binarni_palindrom(n) == 1) {
        printf("Broj je binarni palindrom.\n");
    } else {
        printf("Broj nije binarni palindrom.\n");
    }
    return 0;
} */

#include <math.h>
#include <stdio.h>
#define MAKS 50

int main(void) {
    printf("Unos podataka:\n");

    struct bodovi_s {
        int maticni;
        int indt;
        int edgar;
        int nastavnik;
    };

    struct bodovi_s bodovi[50];
    int i = 0;
    do {
        scanf("%d", &bodovi[i].maticni);
        if (i <= 50 && bodovi[i].maticni != 0) {
            scanf("%d %d %d", &bodovi[i].indt, &bodovi[i].edgar,
                  &bodovi[i].nastavnik);
        }
        i++;
    } while (i <= 50 && bodovi[i - 1].maticni != 0);

    int id;

    printf("Unesite ID pitanja za analizu: ");
    scanf("%d", &id);

    int j, brojstd = 0, uke = 0, ukn = 0, razlikai[50];
    float prz = 0, var = 0, nerazlikai = 0;

    for (j = 0; j < i - 1; j++) {
        if (id == bodovi[j].indt) {

            uke += bodovi[j].edgar;
            ukn += bodovi[j].nastavnik;
            razlikai[brojstd] = bodovi[j].edgar - bodovi[j].nastavnik;
            brojstd++;
        }
    }
    float n = 0;
    for (j = 0; j < brojstd; j++) {
        n += razlikai[j];
    }
    nerazlikai = 1.f / n;
    n = 0;

    for (j = 0; j < brojstd; j++) {
        n += (razlikai[j] - nerazlikai) * (razlikai[j] - nerazlikai);
    }

    var = 1.f / (n - 1.f);
    prz = fabsf(uke - ukn) / brojstd;

    printf("\nRezultati:\n");
    printf("Broj studenata: %d", brojstd);
    printf("\nProsjecna razlika: %0.2f", prz);
    printf("\nVarijanca: %0.2f", var);

    return 0;
}
