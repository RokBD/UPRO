// ===== SNIPPET BANK ZA UVOD U PROGRAMIRANJE =====
// Jedan file za sve copy–paste komade koje najčešće koristiš.
// Sve je u komentarima, tako da se file može normalno prevesti ako treba.

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int main(void) {

    // OVDJE RJEŠAVAŠ KONKRETAN ZADATAK NA ISPITU
    //
    // npr:
    // int n, i;
    // printf("Upisite broj elemenata > ");
    // scanf("%d", &n);
    // int polje[n];
    // ...
    //
    // A dolje skrolaš i copy–pasteaš što ti treba.

    return 0;
}

/* =========================================================
   0) DO–WHILE VALIDACIJA UNOSA (iz meduispit zadataka)
   ========================================================= */

/* Učitavanje broja u [1, 100] */
//
// do {
//     scanf("%d", &n);
// } while (!(n >= 1 && n <= 100));

/* =========================================================
   1) UČITAVANJE / ISPIS POLJA
   ========================================================= */

/* Učitavanje n elemenata u polje int */
//
// for (i = 0; i < n; i++) {
//     scanf("%d", &polje[i]);
// }

/* Ispis n elemenata u jednom retku */
//
// for (i = 0; i < n; i++) {
//     printf("%d ", polje[i]);
// }
// printf("\n");

/* Učitavanje dok se ne upiše 0 (broj elemenata ide u n) */
//
// i = 0;
// scanf("%d", &x);
// while (x != 0) {
//     polje[i] = x;
//     i++;
//     scanf("%d", &x);
// }
// n = i;

/* =========================================================
   2) MIN / MAX / SUMA / PROSJEK / BROJANJE
   ========================================================= */

/* Najmanji element u polju */
//
// min = polje[0];
// for (i = 1; i < n; i++) {
//     if (polje[i] < min) {
//         min = polje[i];
//     }
// }

/* Najveći element u polju */
//
// max = polje[0];
// for (i = 1; i < n; i++) {
//     if (polje[i] > max) {
//         max = polje[i];
//     }
// }

/* Suma elemenata polja */
//
// suma = 0;
// for (i = 0; i < n; i++) {
//     suma += polje[i];
// }

/* Prosjek (double) */
//
// suma = 0;
// for (i = 0; i < n; i++) {
//     suma += polje[i];
// }
// prosjek = (double)suma / n;

/* Brojanje pojavljivanja broja x */
//
// brojac = 0;
// for (i = 0; i < n; i++) {
//     if (polje[i] == x) {
//         brojac++;
//     }
// }

/* Brojanje koliko puta se pojavljuje minimum */
//
// min = polje[0];
// for (i = 1; i < n; i++) {
//     if (polje[i] < min) {
//         min = polje[i];
//     }
// }
//
// brojac = 0;
// for (i = 0; i < n; i++) {
//     if (polje[i] == min) {
//         brojac++;
//     }
// }

/* Prvi indeks pojave x ili -1 ako nema */
//
// poz = -1;
// for (i = 0; i < n; i++) {
//     if (polje[i] == x) {
//         poz = i;
//         break;
//     }
// }

/* Zadnji indeks pojave x ili -1 ako nema */
//
// poz = -1;
// for (i = 0; i < n; i++) {
//     if (polje[i] == x) {
//         poz = i;
//     }
// }

/* =========================================================
   3) SORTIRANJE POLJA
   ========================================================= */

/* Bubble sort (uzlazno) */
//
// for (i = 0; i < n - 1; i++) {
//     for (j = 0; j < n - 1 - i; j++) {
//         if (polje[j] > polje[j + 1]) {
//             temp = polje[j];
//             polje[j] = polje[j + 1];
//             polje[j + 1] = temp;
//         }
//     }
// }

/* Selection sort (uzlazno) */
//
// for (i = 0; i < n - 1; i++) {
//     min_i = i;
//     for (j = i + 1; j < n; j++) {
//         if (polje[j] < polje[min_i]) {
//             min_i = j;
//         }
//     }
//     temp = polje[i];
//     polje[i] = polje[min_i];
//     polje[min_i] = temp;
// }

/* =========================================================
   4) ZNAMENKE BROJA
   ========================================================= */

/* Zbroj znamenaka broja n (n >= 0) */
//
// suma = 0;
// x = n;
// while (x > 0) {
//     suma += x % 10;
//     x /= 10;
// }

/* Broj znamenaka broja n (n >= 0) */
//
// br = 0;
// x = n;
// if (x == 0) br = 1;
// while (x > 0) {
//     br++;
//     x /= 10;
// }

/* Okreni znamenke broja (123 -> 321) */
//
// r = 0;
// x = n;
// while (x > 0) {
//     r = r * 10 + (x % 10);
//     x /= 10;
// }

/* Provjera palindroma */
//
// x = n;
// r = 0;
// while (x > 0) {
//     r = r * 10 + (x % 10);
//     x /= 10;
// }
// if (r == n) {
//     /* palindrom */
// } else {
//     /* nije palindrom */
// }

/* =========================================================
   5) FAKTORIJEL / NZD / SAVRŠEN KVADRAT / PROSTI
   ========================================================= */

/* Faktorijel n (n >= 0) */
//
// f = 1;
// for (i = 1; i <= n; i++) {
//     f *= i;
// }

/* Najveći zajednički djelitelj (Euclid) */
//
// a1 = a;
// b1 = b;
// while (b1 != 0) {
//     t = b1;
//     b1 = a1 % b1;
//     a1 = t;
// }
// nzd = a1;

/* Provjera je li broj savršen kvadrat */
// (potreban #include <math.h>)
//
// korijen = (int)sqrt(n);
// if (korijen * korijen == n) {
//     /* savrsen kvadrat */
// } else {
//     /* nije savrsen kvadrat */
// }

/* Provjera je li broj prost */
//
// prost = 1;
// if (n <= 1) prost = 0;
// for (i = 2; i * i <= n; i++) {
//     if (n % i == 0) {
//         prost = 0;
//     }
// }

/* =========================================================
   6) BINARNI ISPIS POMOĆU MASKE (što si radio u labovima)
   ========================================================= */

/* Binarni ispis 16-bitnog unsigned short n (MAX_LEN = 16) */
//
// #define MAX_LEN 16
// unsigned short int n;
// printf("Unesite broj > ");
// scanf("%hu", &n);
//
// printf("Binarni zapis ucitanog broja: ");
// for (int i = MAX_LEN - 1; i >= 0; i--) {
//     unsigned short mask = 1u << i;   /* ili 0x1 << i */
//     if (mask & n) {
//         printf("1");
//     } else {
//         printf("0");
//     }
// }

/* Binarni ispis 32-bitnog unsigned a (MAKS = 32) */
//
// #define MAKS 32
// unsigned a;
// scanf("%u", &a);
// for (int i = MAKS - 1; i >= 0; i--) {
//     unsigned mask = 1u << i;
//     if (mask & a) {
//         printf("1");
//     } else {
//         printf("0");
//     }
// }
// printf("\n");

/* =========================================================
   7) RUKOVANJE BITOM: ČITANJE / POSTAVLJANJE / GAŠENJE
   ========================================================= */

/* Provjera je li bit na zadanom indexu postavljen (0..15) */
//
// unsigned short n;
// int index;
// scanf("%hu %d", &n, &index);
// mask = 1u << index;
// if (n & mask) {
//     /* bit je 1 */
// } else {
//     /* bit je 0 */
// }

/* Postavi/ugasi bit na indexu ovisno o vrijednost (0 ili 1)
   (doslovno tvoj lab zadatak) */
//
// unsigned short n;
// int index, vrijednost;
// scanf("%hu", &n);
//
// do {
//     printf("Unesite indeks i vrijednost bita > ");
//     scanf("%d %d", &index, &vrijednost);
//
//     if (vrijednost == 1) {
//         n = n | (0x1 << index);       /* postavi bit */
//     } else if (vrijednost == 0) {
//         n = n & ~(0x1 << index);      /* ugasi bit */
//     }
// } while (index >= 0 && index <= 15 && (vrijednost == 1 || vrijednost == 0));
//
// printf("Dekadski i binarni zapis izmijenjenog broja: %hu ", n);
// for (int i = 15; i >= 0; i--) {
//     unsigned short mask = 0x1 << i;
//     if (mask & n) printf("1");
//     else printf("0");
// }

/* =========================================================
   8) BINARNI / OKTALNI / HEX FORMAT (scanf/printf)
   ========================================================= */

/* Ispis zadanog int u raznim bazama */
// int broj;
// scanf("%d", &broj);
// printf("Dekadski: %d\n", broj);
// printf("Oktalni: %o\n", broj);
// printf("Heksadekadski: %X\n", broj);

/* Učitavanje u oktalnom zapisu i ispis u dekadskom */
// scanf("%o", &broj);
// printf("%d\n", broj);

/* Učitavanje u heksadekadskom zapisu i ispis u dekadskom */
// scanf("%x", &broj);
// printf("%d\n", broj);

/* Oktalni zapis (znamenke u polju oct[], n znamenaka) -> decimalni */
// dec = 0;
// for (i = 0; i < n; i++) {
//     dec = dec * 8 + oct[i];
// }

/* =========================================================
   9) STRINGOVI: fgets + makni '\n', filtriranje, obrtanje, pomak
   ========================================================= */

/* fgets + makni '\n' (pattern iz labova) */
//
// #define MAX 200
// char s[MAX + 2];
// int i = 0;
// printf("Unesite niz > ");
// if (!fgets(s, MAX + 2, stdin))
//     return 0;
// while (s[i] != '\0')
//     i++;
// if (i > 0 && s[i - 1] == '\n')
//     s[--i] = '\0';

/* Ispis samo slova iz niza (iz tvog zadatka) */
//
// #define MAX_NIZ 150
// char niz[MAX_NIZ + 1];
// int i = 0;
// printf("Upisite znakovni niz > ");
// fgets(niz, MAX_NIZ + 1, stdin);
// printf("Izlazni znakovni niz je : ");
// while (niz[i] != '\0') {
//     if ((niz[i] >= 'A' && niz[i] <= 'Z') ||
//         (niz[i] >= 'a' && niz[i] <= 'z')) {
//         printf("%c", niz[i]);
//     }
//     i++;
// }

/* Obrni znakovni niz ulaz -> izlaz (pattern iz labova) */
//
// #define MAX 200
// char ulaz[MAX + 1], izlaz[MAX + 1];
// int i = 0, j = 0;
// fgets(ulaz, MAX + 1, stdin);
// while (ulaz[i] != '\0') {
//     i++;
// }
// if (i > 0 && ulaz[i - 1] == '\n')
//     ulaz[--i] = '\0';
// izlaz[i] = '\0';
// for (i--; i >= 0; i--) {
//     izlaz[j] = ulaz[i];
//     j++;
// }
// printf("Obrnuti niz: %s\n", izlaz);

/* Pomak malih slova za POMAK (npr. Caesar) */
//
// #define POMAK 3
// for (i = 0; ulaz[i] != '\0'; i++) {
//     if (ulaz[i] >= 'a' && ulaz[i] <= 'z') {
//         ulaz[i] += POMAK;
//     }
// }
// printf("%s\n", ulaz);

/* =========================================================
   10) FREKVENCIJE ZNAKOVA (pon[127]) – Lab 3 zad. 9
   ========================================================= */

/* Brojanje koliko se puta koji ASCII znak pojavljuje u stringu,
   pronalazak najčešćih i ispis svih s istom frekvencijom. */
//
// #define MAX 50
// char s[MAX + 2];
// int i = 0, max = 0;
// int pon[127] = {0};
//
// printf("Unesite niz > ");
// if (!fgets(s, MAX + 2, stdin))
//     return 0;
//
// while (s[i] != '\0') i++;
// if (i > 0 && s[i - 1] == '\n')
//     s[--i] = '\0';
//
// for (int k = 0; k < i; k++) {
//     unsigned char c = (unsigned char)s[k];
//     if (c < 127) {
//         pon[c]++;
//         if (pon[c] > max)
//             max = pon[c];
//     }
// }
//
// if (max > 0) {
//     int first = 1;
//     for (int c = 32; c <= 126; c++) {
//         if (pon[c] == max) {
//             if (!first)
//                 printf(", ");
//             printf("\"%c\"", c);
//             first = 0;
//         }
//     }
//     printf(" se ponavljaju %d puta.\n", max);
// }

/* =========================================================
   11) MATRIce (n x n)
   ========================================================= */

/* Učitavanje kvadratne matrice n x n */
//
// for (i = 0; i < n; i++) {
//     for (j = 0; j < n; j++) {
//         scanf("%d", &a[i][j]);
//     }
// }

/* Ispis kvadratne matrice n x n */
//
// for (i = 0; i < n; i++) {
//     for (j = 0; j < n; j++) {
//         printf("%d ", a[i][j]);
//     }
//     printf("\n");
// }

/* Suma glavne dijagonale */
//
// suma = 0;
// for (i = 0; i < n; i++) {
//     suma += a[i][i];
// }

/* Suma sporedne dijagonale */
//
// suma = 0;
// for (i = 0; i < n; i++) {
//     suma += a[i][n - 1 - i];
// }

/* =========================================================
   12) STRUCT + NIZ STRUKTURA (pattern suvremenici)
   ========================================================= */

/* Niz osoba s imenom i godinama rođenja/smrti, ispis suvremenika
   za zadanu godinu (inspirirano tvojim meduispit zadatkom). */
//
// #define MAKS_OSOBA 20
// #define DULJINA_IMENA 20
//
// struct ljudi_s {
//     char ime[DULJINA_IMENA + 1];
//     short godinaRodenja;
//     short godinaSmrti;
// };
//
// struct ljudi_s osobe[MAKS_OSOBA] = {
//     {"ElizabetaI", 1533, 1603},
//     {"Mozart", 1756, 1791},
//     {"Nixon", 1913, 1994},
//     {"Lenjin", 1870, 1924},
//     {"Kant", 1724, 1804},
//     {"Newton", 1643, 1727},
//     {"Bismarck", 1815, 1898},
//     {"Napoleon", 1769, 1821},
//     /* ... ostale osobe po potrebi ... */
// };
//
// int godinaProvjera;
// int nemaSuvremenika = 1;   /* 1 = još nismo našli nikog */
//
// printf("Unesite godinu > ");
// scanf("%d", &godinaProvjera);
//
// for (i = 0; i < MAKS_OSOBA; i++) {
//     if (godinaProvjera >= osobe[i].godinaRodenja &&
//         godinaProvjera <= osobe[i].godinaSmrti) {
//         printf("%s (%hd - %hd)\n",
//                osobe[i].ime,
//                osobe[i].godinaRodenja,
//                osobe[i].godinaSmrti);
//         nemaSuvremenika = 0;
//     }
// }
//
// if (nemaSuvremenika == 1) {
//     printf("Nema suvremenika.\n");
// }

/* =========================================================
   13) FORMATIRANJE FLOATOVA (Napierova konstanta itd.)
   ========================================================= */

/* Primjer raznih formata ispisa float vrijednosti */
// float napierConst = 2.71828f;
// float saturnSunDist = 1.43344e12f;
// float planckConst = 6.62607e-34f;
//
// printf("Napierova konstanta:\n%f\n%6.2f\n%6.3f\n%14.10f\n\n", napierConst,
// napierConst,
//        napierConst, napierConst);
//
// printf("Udaljenost Saturna od Sunca:\n%f\n%e\n%10.2e\n\n",
//        saturnSunDist, saturnSunDist, saturnSunDist);
//
// printf("Planckova konstanta:\n%e\n%10.3e\n%10.4e\n",
//        planckConst, planckConst, planckConst);

// KOPIRANJE STRINGA

// i = 0;
// while (src[i] != '\0') {
//     dest[i] = src[i];
//     i++;
// }
// dest[i] = '\0';
