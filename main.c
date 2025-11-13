// ===== Vjezba 3 zadatak 1 =====
/*
#include <math.h>
#include <stdio.h>
#define PI 3.14159f

int main(void) {
    float r, v;

    printf("Upisite radijus kugle > ");
    scanf("%f", &r);

    if (r > 0) {
        v = (4.0f / 3.0f) * PI * pow(r, 3);
        printf("Volumen kugle radijusa %.3f je %.3f", r, v);
    } else {
        printf("Neispravan radijus kugle");
    }
    return 0;
}
*/

// ===== Vjezba 3 zadatak 2 =====
/*
#include <stdio.h>

int main(void) {
    int a, b;

    printf("Upisite dva broja > ");
    scanf("%d %d", &a, &b);

    if ((a > 100 && b < 100) || (b > 100 && a < 100)) {
        printf("Jedan je veci, drugi je manji od 100");
    }
    return 0;
}
*/

// ===== Vjezba 3 zadatak 3 =====
/*
#include <stdio.h>

int main(void) {
    int a;
    float c, f;

    printf("Program za konverziju Fahrenheit - Celsius ili obrnuto.\n");
    printf("Za F u C upisite 1, a za C u F bilo koji drugi cijeli broj > ");
    scanf("%d", &a);

    if (a == 1) {

        printf("Upisite temperaturu izrazenu u stupnjevima Fahrenheit > ");
        scanf("%f", &f);

        c = (f - 32.0f) * 5.0f / 9.0f;

        printf("%8.3f st. F = %8.3f st. C ", f, c);
    } else {

        printf("Upisite temperaturu izrazenu u stupnjevima Celsius > ");
        scanf("%f", &c);

        f = c * 9.0f / 5.0f + 32.0f;

        printf("%8.3f st. C = %8.3f st. F ", c, f);
    }
    return 0;
}
*/

// ===== Vjezba 3 zadatak 4 =====
/*
#include <stdio.h>

int main(void) {
    int a, b;

    printf("Upisite dva broja (a i b) > ");
    scanf("%d %d", &a, &b);

    if ((a >= (100 + b)) && (b < 0 || (b%2) == 0)) {
        printf("Istina je");
    }
    return 0;
}
*/

// ===== Vjezba 3 zadatak 5 =====
/*
#include <stdio.h>

int main(void) {
    int a, b;

    printf("Upisite dva broja (a i b) > ");
    scanf("%d %d", &a, &b);

    if (!((a >= (100 + b)) && (b < 0 || (b%2) == 0))) {
        printf("Istina je");
    }
    return 0;
}
*/

// ===== Vjezba 3 zadatak 6 =====
/*
#include <stdio.h>

int main(void) {
    int a, b;

    printf("Upisite dva broja (a i b) > ");
    scanf("%d %d", &a, &b);

    if ((a < b) && ((b >= 5 && b <= 20) || (a >= 5 && a <= 20))) {
        printf("Istina je");
    } else
        printf("Nije istina");
    return 0;
}
*/

// ===== Vjezba 3 zadatak 7 =====
/*
#include <stdio.h>

int main(void) {
    int a, b,c;

    printf("Upisite tri broja > ");
    scanf("%d %d %d", &a, &b, &c);

    if ((a < b && b < c) ||
        (c < b && b < a)) {
        printf("Brojevi su poredani i razliciti");
    } else
        printf("Brojevi nisu poredani ili nisu razliciti");
    return 0;
}
*/

// ===== Vjezba 3 zadatak 8 =====
/*
#include <stdio.h>

int main(void) {
    float a, b, c, d, e;
    int brojac = 0;

    printf("Upisite pet brojeva > ");
    scanf("%f %f %f %f %f", &a, &b, &c, &d, &e);

    if (a > 0.f) brojac += 1;
    if (b > 0.f) brojac += 1;
    if (c > 0.f) brojac += 1;
    if (d > 0.f) brojac += 1;
    if (e > 0.f) brojac += 1;
    if (brojac >= 3) {
        printf("Barem tri su veca od nule");
    } else
        printf("Niti tri nisu veca od nule");
    return 0;
}
 */

// ===== Vjezba 3 zadatak 9 =====
/*
#include <stdio.h>

int main(void) {
   float aa, ba, ab, bb, ac, bc;
   float aTezista, bTezista;

   printf("Upisite koordinate vrha trokuta A > ");
   scanf("%f %f", &aa, &ba);
   printf("Upisite koordinate vrha trokuta B > ");
   scanf("%f %f", &ab, &bb);
   printf("Upisite koordinate vrha trokuta C > ");
   scanf("%f %f", &ac, &bc);

   aTezista = (aa + ab + ac) / 3.0f;
   bTezista = (ba + bb + bc) / 3.0f;

   printf("Teziste trokuta A(%f, %f), B(%f, %f), C(%f, %f) jest T(%f, %f)",
          aa, ba, ab, bb, ac, bc, aTezista, bTezista);
   return 0;
}
 */

// ===== Vjezba 3 zadatak 10 =====
/*
#include <stdio.h>

int main(void) {
    float napierConst = 2.71828f;
    float saturnSunDist = 1.43344e12f;
    float planckConst = 6.62607e-34f;

    printf("Napierova konstanta:\n%f\n%6.2f\n%6.3f\n%14.10f\n\n", napierConst,
napierConst, napierConst, napierConst); printf("Srednja udaljenost Saturna i
Sunca:\n%20.6f\n%16.2f\n%12.4e\n\n", saturnSunDist, saturnSunDist,
saturnSunDist, saturnSunDist); printf("Planckova
konstanta:\n%f\n%40.36f\n%.5e\n%19.10e", planckConst, planckConst, planckConst,
planckConst);
}
 */

// ===== Vjezba 4 zadatak 1=====
/*
#include <stdio.h>

int main(void) {
    float a, b, odg;
    int op;

    printf("Upisite dva realna broja > ");
    scanf("%f %f", &a, &b);
    printf("Upisite vrstu operacije (1-zbrajanje, 2-mnozenje) > ");
    scanf("%d", &op);


    switch (op){
        case 1:
            odg = a + b;
            printf("Zbroj je %f", odg);
            break;
        case 2:
            odg = a * b;
            printf("Umnozak je %f", odg);
            break;
        default:
            printf("Neispravan odabir operacije.");
            break;
    }
    return 0;
} */

// ===== Vjezba 4 zadatak 2=====
/*
#include <stdio.h>

int main(void) {
    int a, b, tmp;

    printf("Upisite dva cijela broja > ");
    scanf("%d %d", &a, &b);

    if (a == b) {
        printf("Brojevi su jednaki\n");
        printf("a = b = %d", a);
    } else if (a > b) {
        tmp = a;
        a = b;
        b = tmp;
        printf("Zamjena je obavljena\n");
        printf("a = %d, b = %d", a, b);
    } else {
        printf("Zamjena nije obavljena\n");
        printf("a = %d, b = %d", a, b);
    }
    return 0;
} */

//  ===== Vjezba 4 zadatak 3=====
/*
#include <stdio.h>

int main(void) {
    float a1, a2, b1, b2;

    printf("Upisite granice 1. intervala > ");
    scanf("%f %f", &a1, &a2);
    printf("Upisite granice 2. intervala > ");
    scanf("%f %f", &b1, &b2);

    if (a1 <= a2 &&
        b1 <= b2 &&
        a1 <= b1) {
        if (a2 < b1) printf("Presjek intervala je prazan skup");
        else if (a2 < b2) printf("Presjek intervala je [%.3f, %.3f]", b1, a2);
        else printf("Presjek intervala je [%.3f, %.3f]", b1, b2);
    } else printf("Granice intervala su neispravne");
} */

//  ===== Vjezba 4 zadatak 4=====
/*
#include <stdio.h>
#define PI 3.14159f

int main(void) {
    float a, b, povrsina;
    printf("Upisite duljinu velike poluosi a > ");
    scanf("%f", &a);

    if (a > 0.f) {
        printf("Upisite duljinu male poluosi b > ");
        scanf("%f", &b);

        if (b > 0.f) {
            povrsina = PI * a * b;
            printf("Povrsina elipse a = %.4f, b = %.4f je %.4f", a, b,
povrsina); } else printf("Duljina male poluosi mora biti veca od nule"); } else
        printf("Duljina velike poluosi mora biti veca od nule");

    return 0;
} */

//  ===== Vjezba 4 zadatak 5=====
/*
#include <stdio.h>

int main(void) {
    int dan, mjesec, godina;

    printf("Upisite dan, mjesec i godinu > ");
    scanf("%d %d %d", &dan, &mjesec, &godina);

    printf("%d. ", dan);

    if (mjesec == 1)
        printf("sijecnja");
    else if (mjesec == 2)
        printf("veljace");
    else if (mjesec == 3)
        printf("ozujka");
    else if (mjesec == 4)
        printf("travnja");
    else if (mjesec == 5)
        printf("svibnja");
    else if (mjesec == 6)
        printf("lipnja");
    else if (mjesec == 7)
        printf("srpnja");
    else if (mjesec == 8)
        printf("kolovoza");
    else if (mjesec == 9)
        printf("rujna");
    else if (mjesec == 10)
        printf("listopada");
    else if (mjesec == 11)
        printf("studenog");
    else if (mjesec == 12)
        printf("prosinca");

    printf(" %d.", godina);
    return 0;
} */

//  ===== Vjezba 4 zadatak 6=====

/* #include <stdio.h>

int main(void) {
    int a, b, c;

    printf("Upisite dan, mjesec i godinu > ");
    scanf("%d %d %d", &a, &b, &c);

    switch (b){
        case 1:
            printf("%d. sijecnja %d.", a, c);
            break;
        case 2:
            printf("%d. veljace %d.", a, c);
            break;
        case 3:
            printf("%d. ozujka %d.", a, c);
            break;
        case 4:
            printf("%d. travnja %d.", a, c);
            break;
        case 5:
            printf("%d. svibnja %d.", a, c);
            break;
        case 6:
            printf("%d. lipnja %d.", a, c);
            break;
        case 7:
            printf("%d. srpnja %d.", a, c);
            break;
        case 8:
            printf("%d. kolovoza %d.", a, c);
            break;
        case 9:
            printf("%d. rujna %d.", a, c);
            break;
        case 10:
            printf("%d. listopada %d.", a, c);
            break;
        case 11:
            printf("%d. studenog %d.", a, c);
            break;
        case 12:
            printf("%d. prosinca %d.", a, c);
            break;
    }
    return 0;
} */

//  ===== Vjezba 4 zadatak 7=====
/*
#include <stdio.h>

int main (void) {
    int b;

    printf("Upisite broj bodova > ");
    scanf("%d", &b);

    if (b >= 0 && b <= 9)
        printf("nedovoljan");
    else if (b >= 10 && b <= 13)
        printf("dovoljan");
    else if (b >= 14 && b <= 17)
        printf("dobar");
    else if (b >= 18 && b <= 21)
        printf("vrlo dobar");
    else if (b >= 2 && b <= 25)
        printf("izvrstan");
    else printf("neispravni bodovi");
} */

//  ===== Vjezba 4 zadatak 8=====
/*
#include <stdio.h>

int main(void) {
    int op, a, b;

    printf("1. a + b\n2. a - b\n3. a * b\n4. a / b\n");
    printf("Upisite redni broj operacije > ");
    scanf("%d", &op);

    if (op >=1 && op <= 4){

        printf("Upisite operande > ");
        scanf("%d %d", &a, &b);

        switch (op) {
        case 1:
            printf("%d + %d = %d", a, b, a + b);
            break;
        case 2:
            printf("%d - %d = %d", a, b, a - b);
            break;
        case 3:
            printf("%d * %d = %d", a, b, a * b);
            break;
        case 4:
            if (b != 0)
                printf("%d / %d = %d", a, b, a / b);
            else printf("Neispravni operandi");
            break;
        }
    }
} */

//  ===== Vjezba 4 zadatak 9=====
/*
#include <stdio.h>

int main(void) {
    int brojac = 11, a = 0, suma = 0;

    while (a < 1000) {
        if (brojac % 7 == 0 || (brojac % 100 / 10 + brojac % 10) == 5){
            a ++;
            suma += brojac;
        }
        brojac ++;
    }
    printf("%d", suma);
    return 0;
} */

//  ===== Vjezba 4 zadatak 10=====
/*
#include <stdio.h>

int main(void) {
    int a = 3, ispisanih = 0;

    while (ispisanih < 50) {
        if (a % 7 == 0 || a % 3 == 0) {
            printf("%d", a);
            if (ispisanih % 10 == 9) printf("\n");
            else printf(", ");
            ispisanih ++;
            }
        a ++;
        }
    return 0;
} */

//  ===== Vjezba 5 zadatak 1=====
/*
#include <stdio.h>

int main(void) {
    int i;
    float rez = 0;

    for (i = 1; i <= 1000; i ++) {
        if (i % 2 == 0) {
            rez = rez - 1.f / i;
        } else {
            rez = rez + 1.f / i;
        }
    }
    printf("Suma je: %f", rez);
    return 0;
} */

//  ===== Vjezba 5 zadatak 2=====
/*
#include <stdio.h>

int main(void) {
    int i = 1;
    float rez = 0.f;

    while (i <= 1000) {
        if (i % 2 == 0) {
            rez = rez - 1.f / i;
        } else {
            rez = rez + 1.f / i;
        }
        i ++;
    }
    printf("Suma je: %f", rez);
    return 0;
} */

//  ===== Vjezba 5 zadatak 3=====
/*
#include <stdio.h>

int main(void) {
    int i = 1;
    float rez = 0.f;

    do {
        if (i % 2 == 0) {
            rez = rez - 1.f / i;
        } else {
            rez = rez + 1.f / i;
        }
        i ++;
    } while (i <= 1000);
    printf("Suma je: %f", rez);
    return 0;
} */

//  ===== Vjezba 5 zadatak 4=====
/*
#include <stdio.h>

int main(void) {
    int i ,sum = 0;

    scanf("%d", &i);

    while (i % 7 == 0 || i % 3 ==0) {
        sum += i;
        scanf("%d", &i);
    }

    printf("suma = %d", sum);

    return 0;
} */

//  ===== Vjezba 5 zadatak 5=====
/*
#include <stdio.h>

int main(void) {
    int i ,sum = 0;

    scanf("%d", &i);

    for (;i % 7 == 0 || i % 3 ==0; scanf("%d", &i)) {
        sum += i;
    }

    printf("suma = %d", sum);

    return 0;
} */

//  ===== Vjezba 5 zadatak 6=====
/*
#include <stdio.h>

int main(void) {
    int i = 7, sum = 0;

    while (i % 7 == 0 || i % 3 == 0) {
        scanf("%d", &i);
        sum += i;
    }

    printf("suma = %d", sum);

    return 0;
} */

//  ===== Vjezba 5 zadatak 7=====
/*
#include <stdio.h>

int main(void) {
    int i, sum = 0;

    do {
        scanf("%d", &i);
        sum += i;
    } while (i % 7 == 0 || i % 3 == 0);

    printf("suma = %d", sum);

    return 0;
} */

//  ===== Vjezba 5 zadatak 8===== - ima bolji nacin
/*
#include <stdio.h>
#include <math.h>

int main(void) {
    int n, i;

    scanf("%d", &n);

    if (n >= 1 && n <= 31) {
        int b, sum = 0;

        for (i = n - 1; i >= 0; i --) {
            scanf("%d", &b);
            sum = sum + (b * pow(2, i));
        }

        printf("%d", sum);
    } else printf("Broj znamenki je neispravan");

    return 0;
} */

//  ===== Vjezba 5 zadatak 9=====
/*
#include <stdio.h>

int main(void) {
    int n, i, okt = 0, znam;

    scanf("%d", &n);

    if (n <= 1 || n >= 10) {
        printf("Broj znamenki je neispravan");
    } else {
        for (i = 0; i < n; i++) {
            scanf("%d", &znam);
            okt = okt * 8 + znam;
        }
        printf("%d", okt);
    }

    return 0;
} */

//  ===== Vjezba 5 zadatak 10=====
/*
#include <stdio.h>

int main(void) {
    int m, n, i, br, nz = 1;

    printf("Upisite m i n > ");
    scanf("%d %d", &m, &n);

    if (m < 0 || n < 0 || m < n) {
        printf("m ili n su neispravni");
    } else if (m == n) {
        printf("%d povrh %d = %d", m, n, (m / n));
    } else {
        br = m;
        for (i = m - n; i > 1; i--) {
            br = br * (m + 1 - i);
            nz = nz * i;
        }

        printf("%d povrh %d = %d", m, n, (br / nz));
    }

    return 0;
} */

//  ===== Vjezba 5 zadatak 11=====
/*
#include <stdio.h>

int main(void) {
    int n, i, j;

    printf("Upisite red matrice > ");
    scanf("%d", &n);
    if (n < 1 || n > 10) printf("Red matrice je neispravan");
    else {for (i = 0; i < n; i ++ ) {
        for (j = 0; j < n; j ++ ) {
            if (i == j) printf(" 1");
            else printf(" 0");
            }
        printf("\n");
        }
    }


    return 0;
} */

//  ===== Vjezba 5 zadatak 12=====
/*
#include <stdio.h>

int main(void) {
    int n, i, j, b = 0;

    printf("Upisite broj > ");
    scanf("%d", &n);
    if (n < 1 || n > 10)
        printf("Broj je neispravan");
    else {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (j >= i) {
                    b++;
                    printf("%4d", b);
                } else
                    printf("    ");
            }
            printf("\n");
        }
    }

    return 0;
} */

//  ===== Vjezba 5 zadatak 13=====
/*
#include <stdio.h>

int main(void) {
    int n, m, i, j;

    printf("Upisite m, n > ");
    scanf("%d %d", &m, &n);

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%4d", n + i - j);
        }
        printf("\n");
    }

    return 0;
} */

//  ===== Vjezba 5 zadatak 14=====
/*
#include <stdio.h>

int main(void) {
    int min = 0, max = 0, a;

    printf("Upisite brojeve > ");

    do {
        scanf("%d", &a);

        if (a > max) {
            max = a;
        } else if (a < min) {
            min = a;
        }

    } while (a != 0);

    if (min == 0)
        printf("Nije upisan niti jedan negativni broj\n");
    else
        printf("Najmanji negativan = %d\n", min);
    if (max == 0)
        printf("Nije upisan niti jedan pozitivni broj\n");
    else
        printf("Najveci pozitivan = %d\n", max);

    return 0;
} */

//  =====Vjezba 5 zadatak 15=====
/*
#include <stdio.h>

int main (void) {
    int a, b, c, brojac = 0;

    for (a = 1; a <= 100; a ++){
        for (b = 1; b <= 100; b ++){
            for (c = 1; c <= 100; c ++){
                if (a * a + b * b == c * c){
                    brojac ++;
                    printf("%d. trojka: %d^2 + %d^2 = %d^2\n", brojac, a, b, c);
                }
            }
        }
    }

    return 0;
} */

//  =====Vjezba 6 zadatak 2=====
/*
#include <stdio.h>
#define GRANICA_1 10
#define GRANICA_2 30

int main(void) {
    int m, n;
    printf("Upisite m, n > ");
    scanf("%d %d", &m, &n);
    do {
        m = m - 1;
        n = n + 1;
        printf("\nm=%d, n=%d\n", m, n);
        if (m < n) {
            printf("prekidam\n");
        } else {
            printf("%d + %d = %d\n", m, n, m + n);
            if (m % 2 == 0 || n % 5 == 0) {
                printf("nastavljam\n");
            } else {
                printf("%d * %d = %d\n", m, n, m * n);
            }
        }
    } while (m > GRANICA_1 && n < GRANICA_2 && m >= n);
    return 0;
} */

//  =====Vjezba 6 zadatak 3=====
/*
#include <stdio.h>

int main (void) {
    int a[10];

    printf("Upisite 10 cijelih brojeva > ");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 9; i != 0 ; i--) {
        printf("%d, ", a[i]);
    }
    printf("%d", a[0]);

    return 0;
} */

//  =====Vjezba 6 zadatak 4=====
/*
#include <stdio.h>

int main (void) {
    int a[10], b[10];

    printf("Upisite 10 cijelih brojeva > ");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < 10 ; i++) {
        b[i] = a[10-i-1];
    }

    for (int i = 0; i < 10 ; i++) {
        printf("%d", b[i]);
        if (i != 10-1)
            printf(", ");
    }

    return 0;
} */

//  =====Vjezba 6 zadatak 5=====
/*
#include <stdio.h>
#define MAX_BIN 32

int main (void) {
    int n, i, j;

    printf("Upisite cijeli broj > ");
    scanf("%d", &n);

    int bin[MAX_BIN];

    for (i = 0; n > 0; i++) {
        bin[i] = n % 2;
        n = n / 2;
    }

    for (j = i-1; j >= 0; j--) {
        printf("%d", bin[j]);
    }

    return 0;
} */

//  =====Vjezba 6 zadatak 6=====
/*
#include <stdio.h>
#define MAX_LEN 40

int main (void) {
    int a[MAX_LEN] = {1,1,};
    printf("%d\n%d\n", a[0], a[1]);

    for (int i = 2; i < 40; i ++) {
        a[i] = a[i-1] + a[i - 2];
        printf("%d\n", a[i]);
    }

    return 0;
} */

//  =====Vjezba 6 zadatak 7=====
/*
#include <stdbool.h>
#include <stdio.h>
#define MAX_LEN 500

int main(void) {
    int a[MAX_LEN] = {2}, i = 1, j = 3, z;
    bool prim = true;

    while (i < MAX_LEN) {
        z = i;
        prim = true;
        while (prim == true && z > 0) {
            if (j % a[z - 1] == 0) {
                prim = false;
            } else {
                z--;
            }
        }
        if (prim == true) {

            a[i] = j;
            i++;
        }
        j = j + 2;
    }

    for (int k = 0; k < MAX_LEN; k++) {
        printf("%d.  %4d\n", k + 1, a[k]);
    }

    return 0;
} */

//  =====Vjezba 6 zadatak 8=====
/*
#include <stdio.h>

int main(void) {
    int n = 0;

    while (n < 3 || n > 20) {
        printf("Upisite broj iz intervala [3, 20] > ");
        scanf("%d", &n);
    }

    printf("Upisite cijele brojeve (%d) > ", n);
    int a[n], i;

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Ulaz: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\nParni: ");
    for (i = 0; i < n; i++) {
        if (a[i] % 2 == 0)
            printf("%d ", a[i]);
    }
    printf("\nNeparni: ");
    for (i = 0; i < n; i++) {
        if (a[i] % 2 != 0)
            printf("%d ", a[i]);
    }

    return 0;
} */

//  =====Vjezba 6 zadatak 9=====
/*
#include <stdio.h>
#include <stdbool.h>
#define MAX 20000
#define MIN 1
#define INTERVAL_NUM 200

int main (void) {

    int brojPonavljanja[INTERVAL_NUM] = {0}, n, max = 0, i;
    bool intervalPronaden;

    printf("Upisite brojeve [%d, %d] > ", MIN, MAX);
    scanf("%d", &n);

    while (n >= MIN && n <= MAX) {
        i = 0;
        intervalPronaden = false;
        while (intervalPronaden == false && i < INTERVAL_NUM) {
            if (n >= (1 + i * 100) && n <= (100 + i * 100)) {
                intervalPronaden = true;
                brojPonavljanja[i] ++;
                if (brojPonavljanja[i] > max) {
                    max = brojPonavljanja[i];
                }
            } else {
                i ++;
            }
        }
        scanf("%d", &n);
    }

    for (i = 0; i < INTERVAL_NUM; i++) {
        if (brojPonavljanja[i] == max) {
            printf("[%d, %d]: %d\n", 1 + i * 100, 100 + i * 100, max);
        }
    }
} */

//  =====Vjezba 6 zadatak 10=====
/*
#include <stdio.h>
#define MAX 10

int main (void) {
    int brojevi[MAX], i,j;

    printf("Upisite 10 pozitivnih brojeva > ");
    for (i = 0; i < MAX; i ++) {
        scanf("%d", &brojevi[i]);
    }
    for (i = 0; i < MAX; i ++) {
        for (j = 0; j < MAX; j ++) {
            if (brojevi[j] % 10 == i)
                printf("%d ", brojevi[j]);
        }
    }

    return 0;
} */

//  =====Vjezba 6 zadatak 11=====
/*
#include <stdio.h>

int main (void) {
    int n, i;

    printf("Upisite cijeli broj [5, 20] > ");
    scanf("%d", &n);
    int len = 2 * n - 1;
    printf("Upisite cijele brojeve (6) > ");

    int a[len];

    for (i = 0; i < n; i ++) {
        scanf("%d", &a[i]);
    }

    for (i = n - 1; i >= 0; i --) {
        a[i * 2] = a[i];
        a[i * 2 - 1] = a[i] + a[i-1];
    }

    for (i = 0; i < len; i ++) {
        printf("%d ", a[i]);
    }

    return 0;
} */

//  =====Vjezba 6 zadatak 12=====
/*
#include <stdio.h>

int main (void) {
    int n, i;

    printf("Upisite cijeli broj [5, 20] > ");
    scanf("%d", &n);
    int len = n / 2;
    printf("Upisite cijele brojeve (%d) > ", n);

    int a[n];

    for (i = 0; i < n; i ++) {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < len; i ++) {
        a[i] = a[2*i + 1];
    }

    for (i = 0; i < len; i ++) {
        printf("%d ", a[i]);
    }

    return 0;
} */
//  =====Vjezba 6 zadatak 13=====
/*
#include <stdio.h>

int main (void) {
    int nMax, i, brojac, n, max = 0;

    printf("Upisite broj iz intervala [1, 10000] > ");
    scanf("%d", &nMax);

    int tst[nMax];

    for (i = 0; i < nMax; i++) {
        brojac = 0;
        n = i + 1;

        while (n != 1) {
            if (n % 2 == 0) {
                n = n / 2;
            } else {
                n = 3 * n + 1;
            }
            brojac ++;
        }

        tst[i] = brojac;
    }
    for (i = 0; i < nMax; i++) {
        if (tst[i] >= max) {
            max = tst[i];
        }
    }
    printf("U intervalu [1, %d] najveci tst(=%d) imaju nizovi za n =", nMax,
max); for (i = 0; i < nMax; i++) { if (tst[i] == max) { printf(" %d", i + 1);
        }
    }

    return 0;
} */

//  =====Vjezba 7 zadatak 1=====
/*
#include <stdio.h>
#define REDOVI 5
#define STUPCI 7

int main(void) {
    float a[REDOVI][STUPCI] = {{[5] = 0.9f},
                             {0.f},
                             {31.1f, 32.2f, 33.3f, 34.2f},
                             {1.0f, 4.0f, [6] = 7.7}};
    for (int i = 0; i < REDOVI; i++) {
        for (int j = 0; j < STUPCI; j++) {
            printf("%5.1f", a[i][j]);
        }
        printf("\n");
    }

    return 0;
} */

//  =====Vjezba 7 zadatak 2=====
/*
#include <stdio.h>

#define SLOJ 4
#define RED 3
#define STUP 6

int main (void) {
    int p[SLOJ][RED][STUP];
    for (int i = 0; i < SLOJ; i++) {
        for (int j = 0; j < RED; j++) {
            for (int k = 0; k < STUP; k++) {
                p[i][j][k] = (i + 1) * 100 + (j + 1) * 10 + k + 1;
            }
        }
    }

    for (int i = 0; i < SLOJ; i++) {
        printf("%d. sloj\n", i + 1);
        for (int j = 0; j < RED; j++) {
            for (int k = 0; k < STUP; k++) {
                printf("%5d", p[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
} */

//  =====Vjezba 7 zadatak 3=====
/*
#include <stdio.h>

int main(void) {
    int m, n, i, j;

    printf("Upisite m, n > ");
    scanf("%d %d", &m, &n);

    int p[m][n];

    printf("Upisite %d x %d clanova >\n", m, n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &p[i][j]);
        }
    }

    int min[n];

    for (j = 0; j < n; j++) {
        min[j] = p[0][j];
        for (i = 0; i < m; i++) {
            if (p[i][j] < min[j]) {
                min[j] = p[i][j];
            }
        }
    }
    int prviPar;
    for (j = 0; j < n; j++) {
        prviPar = 1;
        printf("%d. stupac:", j + 1);
        for (i = 0; i < m; i++) {
            if (p[i][j] == min[j]) {
                if (prviPar == 1) {
                    prviPar = 0;
                } else {
                    printf(",");
                }
                printf(" (%d, %d)", i, j);
            }
        }
        printf("\n");
    }

    return 0;
} */

//  =====Vjezba 7 zadatak 4=====
/*
#include <stdio.h>

int main(void) {
    int m, n, i, j, pomocni;

    printf("Upisite m, n > ");
    scanf("%d %d", &m, &n);

    int p[m][n];

    printf("Upisite %d x %d clanova >\n", m, n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &p[i][j]);
        }
    }

    for (j = 0; j < n; j++) {
        pomocni = p[0][j];
        for (i = 0; i < m - 1; i++) {
            p[i][j] = p[i+1][j];
        }
        p[m-1][j] = pomocni;
    }

    printf("Nakon posmaka:\n");
    for (i = 0; i < m; i++){
        for(j = 0; j < n; j++) {
            printf("%4d", p[i][j]);
        }
        printf("\n");
    }

    return 0;
} */

//  =====Vjezba 7 zadatak 5=====
/*
#include <stdio.h>
#define VELICINA 11

int main (void) {
    int p[VELICINA][VELICINA], i, j;

    for (i = 0; i < VELICINA; i++) {
        for (j = 0; j < VELICINA; j++) {
            if (i == j ||
                i == VELICINA - 1 - j ||
                i == 0 ||
                j == 0 ||
                j == VELICINA - 1 ||
                i == VELICINA - 1) {
                    p[i][j] = 1;
                } else {
                    p[i][j] = 8;
                }
        }
    }
    printf("Generirana kvadratna matrica:\n");
    for (i = 0; i < VELICINA; i++){
        for(j = 0; j < VELICINA; j++) {
            printf(" %d", p[i][j]);
        }
        printf("\n");
    }

    return 0;
} */

//  =====Vjezba 7 zadatak 6=====
/*
#include <stdio.h>

int main (void) {
    int i,j,m,n;

    do {
        printf("Upisite m [4, 8] > ");
        scanf("%d", &m);
    } while (m < 4 || m > 8);

    do {
        printf("Upisite n [5, 10] > ");
        scanf("%d", &n);
    } while (n < 5 || n > 10);

    int p[m][n];

    printf("Upisite %d x %d clanova >\n", m, n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &p[i][j]);
        }
    }

    printf("Sume po stupcima:\n");

    int sumaPoStupcima[n];

    for (j = 0; j < n; j++) {
        sumaPoStupcima[j] = 0;
        for (i = 0; i < m; i++) {
            sumaPoStupcima[j] += p[i][j];
        }
    }

    for ( i = 0; i < n; i++)
    {
        printf("%5d", sumaPoStupcima[i]);
    }

    return 0;
} */

//  =====Vjezba 7 zadatak 7=====
/*
#include <stdio.h>

int main(void) {
    int m, n, i, j, pomocni, k;

    printf("Upisite m, n > ");
    scanf("%d %d", &m, &n);

    int p[m][n];

    printf("Upisite %d x %d clanova >\n", m, n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &p[i][j]);
        }
    }

    for (j = 0; j < n; j++) {
        for (i = 0; i < m - 1; i++) {
            for (k = 0; k < m - 1 - i; k++) {
                if (p[k][j] > p[k + 1][j]) {
                    pomocni = p[k][j];
                    p[k][j] = p[k + 1][j];
                    p[k + 1][j] = pomocni;
                }
            }
        }
    }

    printf("Nakon sortiranja stupaca:\n");
    for (i = 0; i < m; i++){
        for(j = 0; j < n; j++) {
            printf("%4d", p[i][j]);
        }
        printf("\n");
    }

    return 0;
} */

//  =====Vjezba 8 zadatak 15=====
/*
#include <stdio.h>

int main(void) {
    int broj;

    do {
        printf("Upisite dekadski cijeli broj > ");
        scanf("%d", &broj);
        if (broj != 0) {
            printf("%o\n", broj);
            printf("%X\n", broj);
        }
    } while (broj != 0);

        return 0;
} */

//  =====Vjezba 8 zadatak 16=====
/*
#include <stdio.h>

int main(void) {
    unsigned int broj;

    do {
        printf("Upisite heksadekadski nenegativni cijeli broj > ");
        scanf("%x", &broj);
        if (broj != 0) {
            printf("%11u\n", broj);
        }
    } while (broj != 0);

        return 0;
} */

//  =====Vjezba 8 zadatak 17=====
/*
#include <stdio.h>

int main(void) {
    char a, b;

    printf("Upisite dva znaka > ");
    scanf("%c %c", &a, &b);

    for (int i = a; i <= b; i++) {
        printf("%c", i);
    }

    return 0;
} */
//  =====Vjezba 8 zadatak 18=====
/*
#include <stdio.h>

int main (void) {
    int broj;

    do {
        printf("Upisite cijeli broj > ");
        scanf("%d", &broj);

        if (broj >= '0' && broj <= '9' ||
            broj >= 'a' && broj <= 'z' ||
            broj >= 'A' && broj <= 'Z' ) {
                printf("%d %c\n", broj, broj);
            }

    } while (broj >= '0' && broj <= '9' ||
            broj >= 'a' && broj <= 'z' ||
            broj >= 'A' && broj <= 'Z' );

    return 0;
} */

//  =====Vjezba 8 zadatak 19=====
/*
#include <stdio.h>

int main(void) {
    char i, j;

    for (i = 'a'; i < 'v'; i++) {
        printf("%c. ", i - 32);
        for (j = i; j < i + 6; j++) {
            printf("%c ", j);
        }
        printf(".%c\n", j - 33);
    }

    return 0;
} */

//  =====Vjezba 8 zadatak 20=====
/*
#include <stdio.h>
#define DULJINA 10

int main(void) {
    char rijec[DULJINA + 1];
    int i, j, min;

    printf("Upisite %d znakova > ", DULJINA);

    for (i = 0; i < DULJINA + 1; i++) {
        scanf("%c", &rijec[i]);
    }
    rijec[DULJINA] = '\0';

    printf("Original :%s\n", rijec);

    for (i = 0; i < DULJINA - 1; i++) {
        min = i + 1;
        for (j = i + 2; j < DULJINA; j++) {
            if (rijec[j] < rijec[min]) {
                min = j;
            }
        }

        if (rijec[min] < rijec[i]) {
            char pomocna = rijec[i];
            rijec[i] = rijec[min];
            rijec[min] = pomocna;
        }
    }

    printf("Sortirani:%s", rijec);

    return 0;
} */

//  =====Vjezba 8 zadatak 21=====
/*
#include <stdio.h>

int main(void) {
    char c;
    c = 'A' + '0';
    printf("%d\n", c);
    printf("%c\n", c);
    printf("%c\n", 'D' - 'A' + '0');
    printf("%d\n", 'D' - 'A' + '0');
    printf("%d\n", '7' - '5');
    printf("%d\n", '7' - 5);
    printf("%c\n", '7' - 5);
    printf("%d\n", '0' % 10);
    return 0;
} */

//  =====Vjezba 8 zadatak 22=====
/*
#include <stdio.h>

int main(void) {
    unsigned long long n;

    printf("Upisite prirodni broj u granicama [1, 4250000000] > ");
    scanf("%llu", &n);

    printf("%llu * %llu = %llu", n, n, n * n);

    return 0;
} */

//  =====Vjezba 8 zadatak 23=====
/*
#include <stdio.h>
#define MAKS 20

int main(void) {
    char niz[MAKS + 1];
    int i, najveci = 0;

    printf("Upisite niz > ");
    fgets(niz, MAKS + 1, stdin);

    printf("Niz: %s", niz);

    for (i = 1; i < MAKS; i++) {
        if (niz[i] > niz[najveci]) {
            najveci = i;
        }
    }

    printf("\nNajveca ASCII vrijednost: %d", niz[najveci]);

    return 0;
} */

//  =====Vjezba 8 zadatak 24=====
