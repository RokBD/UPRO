// ===== Meduispit 1.2. Zadatak 1 =====
/*
#include <stdio.h>

int main(void) {
    int velicinaPolja;

    printf("Unesite duljinu polja > \n");
    do {
        scanf("%d", &velicinaPolja);
    } while (!(velicinaPolja >= 1 && velicinaPolja <= 100));

    int polje[velicinaPolja], i;

    printf("Unesite clanove polja > \n");

    for (i = 0; i < velicinaPolja; i++) {
        scanf("%d", &polje[i]);
    }

    int indexMAX = 0, duljinaMAX = 0;

    for (i = 0; i < velicinaPolja; i++) {
        int j = i + 1, duljina = 1;
        do {
            if (polje[j] == polje[i]) {
                duljina++;
                j++;
            }
        } while (j < velicinaPolja && polje[j] == polje[i]);

        if (duljina > duljinaMAX) {
            duljinaMAX = duljina;
            indexMAX = i;
        }
    }

    printf("Pocetni indeks: %d\n", indexMAX);
    printf("Duljina niza: %d", duljinaMAX);

    return 0;
} */

// ===== Meduispit 1.2. Zadatak 2 =====
/*
#include <stdio.h>
#define MAKS_OSOBA 20
#define DULJINA_IMENA 20

int main(void) {
    struct ljudi_s {
        char ime[DULJINA_IMENA + 1];
        short godinaRodenja;
        short godinaSmrti;
    };

    struct ljudi_s osobe[MAKS_OSOBA] = {
        {"ElizabetaI", 1533, 1603},
        {"Mozart", 1756, 1791},
        {"Nixon", 1913, 1994},
        {"Lenjin", 1870, 1924},
        {"Kant", 1724, 1804},
        {"Newton", 1643, 1727},
        {"Bismarck", 1815, 1898},
        {"Napoleon", 1769, 1821},
        {"MargaretAnnNeve", 1792, 1903},
        {"EmmaMorano", 1899, 2017},
        {"LujXIV.", 1638, 1715}
    };

    int i = 11;

    do {
        printf("Osoba %d:\n", i + 1);
        printf("Ime i prezime: ");
        scanf("%s", osobe[i].ime);
        if (i < 20 && osobe[i].ime[0] != '.') {
            printf("Rodenje: ");
            scanf("%hd", &osobe[i].godinaRodenja);
            printf("Smrt: ");
            scanf("%hd", &osobe[i].godinaSmrti);
            i ++;
        }
    } while (i < 20 && osobe[i].ime[0] != '.');

    short godinaProvjera;

    printf("\nGodina za provjeru: ");
    scanf("%hd", &godinaProvjera);

    printf("\nSuvremenici:\n");

    int nemaSuvremenika = 1;

    for (int j = 0; j < i; j++) {
        if (godinaProvjera >= osobe[j].godinaRodenja && godinaProvjera <=
osobe[j].godinaSmrti) { printf("%s (%hd - %hd)\n", osobe[j].ime,
osobe[j].godinaRodenja, osobe[j].godinaSmrti); nemaSuvremenika = 0;
        }
    }

    if (nemaSuvremenika == 1) {
        printf("Nema suvremenika.\n");
    }

    return 0;
} */

// ===== Meduispit 1.2. Zadatak 3 =====
/*
#include <stdio.h>
#define MAKS 100

int main (void) {
    char niz1[MAKS + 2];

    fgets(niz1, MAKS + 2, stdin);

    int i = 0, j = 0, k = 0;

    while (niz1[i] != '\0') {
        i++;
    }
    if (niz1[i-1] == '\n') {
        niz1[--i] = '\0';
    }

    char niz2[i];
    niz2[k] = niz1[j];

    while (j < i) {
        int brojac = 1;
        while (niz1[j] == niz1[j + 1]) {
            brojac ++;
            j++;
        }
        k ++;
        if (brojac != 1) {
            niz2[k] = brojac + '0';
        } else {
            j++;
            niz2[k] = niz1[j];
        }
    }

    printf("%s", niz2);

    return 0;
} */

// ===== Meduispit 1.2. Zadatak 4 =====
/*
#include <stdio.h>
#define MAKS 32

void podudarni(unsigned a, unsigned b) {
    int brojac = 0, slijed = 1, x, y;

    for (int i = MAKS - 1; i >= 0 && slijed != 0; i--) {
        unsigned mask = 1u << i;
        if (mask & a) {
            x = 1;
        } else {
            x = 0;
        }

        if (mask & b) {
            y = 1;
        } else {
            y = 0;
        }

        if (x == y) {
            brojac++;
        } else {
            slijed = 0;
        }
    }

    if (brojac == 0) {
        printf("Nema podudarnog slijeda.");
    } else {
        printf("Podudarni slijed:\n");
        for (int i = MAKS - 1; i >= MAKS - brojac; i--) {
            unsigned mask = 1u << i;
            if (mask & a) {
                printf("1");
            } else {
                printf("0");
            }
        }
    }
}

int main(void) {
    unsigned a, b;
    printf("Unesite dva broja > ");
    scanf("%u %u", &a, &b);

    printf("\n1. i 2. broj binarno:\n");

    for (int i = MAKS - 1; i >= 0; i--) {
        unsigned mask = 1u << i;
        if (mask & a) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");

    for (int i = MAKS - 1; i >= 0; i--) {
        unsigned mask = 1u << i;
        if (mask & b) {
            printf("1");
        } else {
            printf("0");
        }
    }

    printf("\n");

    podudarni(a, b);

    return 0;
} */

// ===== Meduispit 1.1. Zadatak 1 =====
/*
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int brojParova = 0, najmanjiRazmak, i , j, n;

    printf("upisite velicinu polja > ");
    scanf("%d", &n);

    int p[n];

    printf("upisite elemente polja > ");
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    najmanjiRazmak = abs(p[0] - p[1]);
    brojParova = 0;

    for (i = 0; i < n - 1; i ++) {
        for (j = i + 1; j < n; j++) {
            if (abs(p[i] - p[j]) == najmanjiRazmak) {
                brojParova ++;
            } else if (abs(p[i] - p[j]) < najmanjiRazmak) {
                najmanjiRazmak = abs(p[i] - p[j]);
                brojParova = 1;
            }
        }
    }

    printf("najmanji razmak: %d", najmanjiRazmak);
    printf("\nbroj parova: %d", brojParova);

    return 0;
} */

// ===== Meduispit 1.1. Zadatak 2 =====
/* 
#include <stdio.h>

int main(void) {
    int n, sum, i, j, sumMAX, iMAX, jMAX;

    printf("Upisite red n > ");
    scanf("%d", &n);

    int p[n][n];

    printf("Upisite elemente >\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &p[i][j]);
            sum = p[i][j];

            if (i - 1 >= 0 && j - 1 >= 0) {
                sum += p[i - 1][j - 1];
            }

            if (i - 1 >= 0 && j + 1 < n) {
                sum += p[i - 1][j + 1];
            }

            if (i == 0 && j == 0) {
                sumMAX = sum;
                iMAX = i;
                jMAX = j;
            }
            if (sum > sumMAX) {
                sumMAX = sum;
                iMAX = i;
                jMAX = j;
            } else if (sum == sumMAX && i > iMAX) {
                iMAX = i;
                jMAX = j;
            } else if (sum == sumMAX && i == iMAX && j > jMAX) {
                jMAX = j;
            }
        }
    }

        printf("Najveci zbroj gornje-dijagonalnih elemenata je %d za element "
               "(%d, %d)",
               sumMAX, iMAX, jMAX);

        return 0;
} */

// ===== Meduispit 1.1. Zadatak 3 =====

