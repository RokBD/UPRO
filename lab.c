// =====Lab 3 Zadatak 1=====
/*
#include <stdio.h>

int main (void) {
    int m, i, zbroj = 0, index[2], sum = 0, j;

    printf("Upisite velicinu polja m > ");
    scanf("%d", &m);
    int polje[m];

    printf("Upisite %d clanova polja m > ", m);

    for (i = 0; i < m; i++) {
        scanf("%d", &polje[i]);
    }

    for (i = 0; i < m; i++) {
        sum = 0;
        for (j = i; j < m; j++) {
            sum += polje[j];

            if (sum > zbroj) {
                zbroj = sum;
                index[0] = i;
                index[1] = j;
            }
        }
    }
    printf("Pronadjeno pod-polje : ");
    for (i = index[0]; i <= index[1]; i++) {
        printf("%d ", polje[i]);
    }
    printf("\nNajveca suma kontinuiranog pod-polja je: %d", zbroj);

    return 0;
} */

// =====Lab 3 Zadatak 2=====
/*
#include <stdio.h>

int main(void) {
    int n, i, j, r, s, sum = 0;

    printf("Upisite broj redaka/stupaca matrice > ");
    scanf("%d", &n);

    int a[n][n];
    printf("Upisite %dx%d clanova > \n", n, n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Upisite redni broj retka > ");
    scanf("%d", &r);

    printf("Upisite redni broj stupca > ");
    scanf("%d", &s);

    for (i = 0; i < n; i++) {
        sum += a[i][s];
        if (i != s) sum += a[r][i];
    }


    printf("Suma brojeva koji se nalaze u retku %d i stupcu %d je %d.", r, s,
sum);

    return 0;
} */

// =====Lab 3 Zadatak 3=====
/*
#include <stdio.h>

int main(void) {
    int n, i, j;

    printf("Unesite n > ");
    scanf("%d", &n);

    int a[n][n], b[n];

    for (i = 0; i < n; i++) {
        b[i] = 0;
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            b[i] += a[j][i];
        }
    }
    printf("Rezultat > ");

    for (i = 0; i < n - 1; i++) {
        printf("%d ", b[i] - b[i + 1]);
    }
    printf("%d", b[n-1] - b[0]);

    return 0;
} */

// =====Lab 3 Zadatak 4====
/*
#include <stdio.h>

int main(void) {
    int n, m, idxi, idxj, i, j, i_smjer = -1, j_smjer = 1, br = 0;

    printf("Upisite brojeve N, M, idxi i idxj > ");
    scanf("%d %d %d %d", &n, &m, &idxi, &idxj);

    int a[n][m];

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            a[i][j] = 0;
        }
    }

    while (a[idxi][idxj] != 1) {
        a[idxi][idxj] = 1;

        if (idxi == 0)
            i_smjer = 1;
        else if (idxi == n - 1)
            i_smjer = -1;

        if (idxj == 0)
            j_smjer = 1;
        else if (idxj == m - 1)
            j_smjer = -1;

        idxi += i_smjer;
        idxj += j_smjer;
        br++;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("Duljina: %d", br);

    return 0;
} */

// =====Lab 3 Zadatak 5====
/*
#include <stdio.h>

int main(void) {
    int n, m, idxi, idxj, i, j, i_smjer = 1, j_smjer = -1, br = 0;

    printf("Upisite brojeve N, M, idxi i idxj > ");
    scanf("%d %d %d %d", &n, &m, &idxi, &idxj);

    int a[n][m];

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            a[i][j] = 0;
        }
    }

    while (a[idxi][idxj] != 1) {
        a[idxi][idxj] = 1;

        if (idxi == 0)
            i_smjer = 1;
        else if (idxi == n - 1)
            i_smjer = -1;

        if (idxj == 0)
            j_smjer = 1;
        else if (idxj == m - 1)
            j_smjer = -1;

        idxi += i_smjer;
        idxj += j_smjer;
        br++;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("Duljina: %d", br);

    return 0;
} */

// =====Lab 3 Zadatak 6====
/*
#include <stdio.h>

int main(void) {
    int n, m, idxi, idxj, i, j, i_smjer = 1, j_smjer = 1, br = 0;

    printf("Upisite brojeve N, M, idxi i idxj > ");
    scanf("%d %d %d %d", &n, &m, &idxi, &idxj);

    int a[n][m];

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            a[i][j] = 0;
        }
    }

    while (a[idxi][idxj] != 1) {
        a[idxi][idxj] = 1;

        if (idxi == 0)
            i_smjer = 1;
        else if (idxi == n - 1)
            i_smjer = -1;

        if (idxj == 0)
            j_smjer = 1;
        else if (idxj == m - 1)
            j_smjer = -1;

        idxi += i_smjer;
        idxj += j_smjer;
        br++;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("Duljina: %d", br);

    return 0;
} */

// =====Lab 3 Zadatak 7====
/*
#include <stdio.h>
#include <stdbool.h>
#define MAX_NIZ 150

int main(void) {
    char niz[MAX_NIZ + 1];
    int i = 0;
    bool printed = false;

    printf("Upisite znakovni niz > ");
    fgets(niz, MAX_NIZ + 1, stdin);
    printf("Izlazni znakovni niz je : ");
    while (niz[i] != '\0') {
        if (niz[i] >= 'A' && niz[i] <= 'Z' || niz[i] >= 'a' && niz[i] <= 'z') {
            printf("%c", niz[i]);
            printed = true;
        }
        i++;
    }
    if (!printed)
        printf("prazan string");
    printf("\n");
    return 0;
} */

// =====Lab 3 Zadatak 8====
/*
#include <stdio.h>
#define MAX 200
#define POMAK ('A' - 'a')

int main(void) {
    char ulaz[MAX + 1], izlaz[MAX + 1];
    int i = 0, j = 0;

    printf("Upisite znakovni niz > ");
    fgets(ulaz, MAX + 1, stdin);

    while (ulaz[i] != '\0') {
        i++;
    }
    izlaz[i] = '\0';
    for (i--; i >= 0; i--) {
        if (ulaz[i] >= 'a' && ulaz[i] <= 'z') {
            ulaz[i] += POMAK;
        }
        izlaz[j] = ulaz[i];
        j++;
    }
    printf("Obrnuti niz: %s\n", izlaz);

    return 0;
} */

// =====Lab 3 Zadatak 9====
/*
#include <stdio.h>
#define MAX 50

int main(void) {
    char s[MAX + 2];
    int i = 0, max = 0;
    int pon[127] = {0};

    printf("Unesite niz > ");
    if (!fgets(s, MAX + 2, stdin))
        return 0;

    while (s[i] != '\0')
        i++;
    if (i > 0 && s[i - 1] == '\n')
        s[--i] = '\0';

    for (int k = 0; k < i; k++) {
        unsigned char c = (unsigned char)s[k];
        if (c >= 32 && c <= 126) {
            if (++pon[c] > max)
                max = pon[c];
        }
    }

    if (max == 0) {
        printf("Znakovi se ne ponavljaju.\n");
        return 0;
    }

    int howMany = 0;
    for (int c = 32; c <= 126; c++)
        if (pon[c] == max)
            howMany++;

    if (howMany == 1) {
        int the = 32;
        while (the <= 126 && pon[the] != max)
            the++;
        printf("Znak \"%c\" se ponavlja %d puta.\n", the, max);
    } else {
        printf("Znakovi ");
        int first = 1;
        for (int c = 32; c <= 126; c++) {
            if (pon[c] == max) {
                if (!first)
                    printf(", ");
                printf("\"%c\"", c);
                first = 0;
            }
        }
        printf(" se ponavljaju %d puta.\n", max);
    }
    return 0;
} */

// =====Lab 4 Zadatak 1====
/*
#include <stdio.h>
#define MAX_LEN 16

int main(void) {
    unsigned short int n;
    printf("Unesite broj > ");
    scanf("%hu", &n);


    int nigga = -1;

    printf("Binarni zapis ucitanog broja: ");



    for (int i = MAX_LEN - 1; i >= 0; i--) {
         unsigned short mask = 1u << i;
        if (mask & n) {
            printf("1");
            if (nigga == -1) {
                nigga = i;
            }
        } else {
            printf("0");
        }
    }


    if (nigga == -1)
        printf("\nNema bita s vrijednosti 1.");
    else
        printf("\nIndeks najznacajnijeg bita s vrijednosti 1: %d", nigga);

    return 0;
} */

// =====Lab 4 Zadatak 2====
/*
#include <stdio.h>
#define MAX_LEN 16

int main(void) {
    unsigned short int n;
    printf("Unesite broj > ");
    scanf("%hu", &n);


    int nigga = -1;

    printf("Binarni zapis ucitanog broja: ");



    for (int i = MAX_LEN - 1; i >= 0; i--) {
         unsigned short mask = 1u << i;
        if (mask & n) {
            printf("1");

        } else {
            printf("0");
            nigga = i;
        }
    }


    if (nigga == -1)
        printf("\nNema bita s vrijednosti 0.");
    else
        printf("\nIndeks najmanje znacajnog bita s vrijednosti 0: %d", nigga);

    return 0;
} */

// =====Lab 4 Zadatak 3====
/* 
#include <stdio.h>
#define MAX_LEN 16

int main(void) {
    unsigned short broj1, broj2, udaljenost;
    printf("Unesite dva broja > ");
    scanf("%hu %hu", &broj1, &broj2);

    udaljenost = broj1 ^ broj2;
    int brojac = 0;

    for (int i = MAX_LEN - 1; i >= 0; i--) {
         unsigned short mask = 1u << i;
        if (mask & udaljenost) {
            brojac ++;
        } 
    }

    printf("Hammingova udaljenost: %d", brojac);

    return 0;
} */

// =====Lab 4 Zadatak 4====
/* 
#include <stdio.h>
#define MAX_LEN 16

int main(void) {
    unsigned short int n;
    printf("Unesite broj > ");
    scanf("%hu", &n);

    printf("Binarni zapis broja: ");

    for (int i = MAX_LEN - 1; i >= 0; i--) {
         unsigned short mask = 0x1 << i;
        if (mask & n) {
            printf("1");
        } else {
            printf("0");
        }
    }

    printf("\n");

    int index, vrijednost;

    do {
        printf("Unesite indeks i vrijednost bita > ");
        scanf("%d %d", &index, &vrijednost);

        if (vrijednost == 1) {
            n = n | (0x1 << index);
        } else if (vrijednost == 0) {
            n = n & ~(0x1 << index);
        }
    } while (index >= 0 && index <= 15 && (vrijednost == 1 || vrijednost == 0));

    printf("\n");

    printf("Dekadski i binarni zapis izmijenjenog broja: %hu ", n);

    for (int i = MAX_LEN - 1; i >= 0; i--) {
         unsigned short mask = 0x1 << i;
        if (mask & n) {
            printf("1");
        } else {
            printf("0");
        }
    }

    return 0;
} */

// =====Lab 4 Zadatak 5====
/* 
#include <stdio.h>
#include <math.h>

double e_approx(int n) {
    double sum = 1;

    for (int i = 1; i <= n; i++) {
        double faktorijel = 1;
        
        for (int j = 2; j <= i; j++) {
            faktorijel *= j;
        }

        sum += 1.0 / faktorijel;
    }

    return sum;
}

int main (void) {
    int n;

    printf("Upisite broj n: ");
    scanf("%d", &n);

    printf("Aproksimacija e: %.12lf\n", e_approx(n));
    printf("Razlika: %.12lf", e_approx(n)-exp(1));

    return 0;
} */

// =====Lab 4 Zadatak 6====
/* 
#include <stdio.h>
#include <math.h>

float median (float a, float b, float c) {
    if (a > b && a < c ||
        a < b && a > c) {
        return a;
    } else if (b > a && b < c ||
               b < a && b > c) {
        return b;
    } else if (c > a && c < b ||
               c < a && c > b) {
        return c;
    }
}

int main (void) {
    float a, b, c, razlika;

    printf("Upisite tri realna broja > ");
    scanf("%f %f %f", &a, &b, &c);

    razlika = fabsf(median(a, b ,c) - ((a + b + c) / 3.f));
    
    printf("Apsolutna vrijednost razlike mediana i srednje vrijednosti je: %.3f", razlika);

    return 0;
} */

// =====Lab 4 Zadatak 7====
/* 
#include <stdio.h>

int djelitelj(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void reduciraj(int brojnik, int nazivnik) {
    int d = djelitelj(brojnik, nazivnik);
    brojnik /= d;
    nazivnik /= d;

    if (nazivnik == 1)
        printf("Reduciran: %d", brojnik);
    else
        printf("Reduciran: %d/%d", brojnik, nazivnik);
}

int main(void) {
    int brojnik, nazivnik;
    printf("Upisite brojnik i nazivnik: ");
    scanf("%d %d", &brojnik, &nazivnik);

    printf("Razlomak: %d/%d\n", brojnik, nazivnik);
    reduciraj(brojnik, nazivnik);

    return 0;
} */

// =====Lab 4 Zadatak 8====
/* 
#include <stdio.h>
#include <math.h>

int savrsen_kvadrat(int n) {
    int korijen = (int)sqrt(n);  
    return (korijen * korijen == n); 
}

int factorial(int n) {
    int rezultat = 1;
    for (int i = 2; i <= n; i++)
        rezultat *= i;
    return rezultat;
}

int zbroj_znamenaka(int n) {
    int suma = 0;
    while (n > 0) {
        suma += n % 10;
        n /= 10;
    }
    return suma;
}

int main(void) {
    int broj;
    printf("Upisite prirodni broj > ");
    scanf("%d", &broj);

    int fakt = factorial(broj);
    int suma = zbroj_znamenaka(fakt);

    if (savrsen_kvadrat(suma))
        printf("Suma znamenaka od %d! je savrsen kvadrat.", broj);
    else
        printf("Suma znamenaka od %d! nije savrsen kvadrat.", broj);

    return 0;
} */