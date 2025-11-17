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
/*
#include <stdio.h>
#define MAKS 50
#define CLANOVI 5

int main(void) {
    struct lego_s {
        char ime[MAKS + 1];
        int p[CLANOVI];
    };

    struct lego_s lego[MAKS] = {
        {"FireworkGuy", {14822018, 13562018, 43222017, 52112017, 34222018}},
        {"WrestlingChampion",
         {93212015, 34122015, 34772012, 22222014, 13452013}},
        {"CactusGirl", {32332018, 93212015, 34772012, 52112017, 34882016}},
        {"Dobby", {98762018, 97652018, 34772018, 32452016, 34212017}},
        {"Cheerleader", {12322010, 14562010, 32462010, 23762010, 98792010}},
        {"Zombie", {56432010, 76482010, 47822010, 78652010, 45322010}},
        {"Forestman", {23652010, 34762009, 64832008, 57532010, 54882009}},
        {"Mariachi/MaracaMan",
         {23672010, 93212010, 32452016, 54882010, 34672010}}};

    int i = 8;

    do {
        printf("Unos %d. figure:\n", i + 1);
        printf("Naziv: ");
        scanf("%50s", lego[i].ime);
        if (i < MAKS && lego[i].ime[0] != '-') {
            printf("Serijski brojevi: ");
            for (int j = 0; j < 5; j++) {
                scanf("%d", &lego[i].p[j]);
            }
            i++;
        }
    } while (i < MAKS && lego[i].ime[0] != '-');

    int provjera, nemaFigure = 1;

    printf("Serijski broj dijela za provjeru: ");
    scanf("%d", &provjera);
    printf("Figure koje sadrze dio %d su:", provjera);

    for (int j = 0; j < i; j++) {
        for (int k = 0; k < CLANOVI; k++) {
            if (provjera / 10000 == lego[j].p[k] / 10000) {
                nemaFigure = 0;
                printf("\n%s", lego[j].ime);
            }
        }
    }

    if (nemaFigure == 1)
        printf("\nNema figura!");

    return 0;
} */

// ===== Meduispit 1.1. Zadatak 4 =====
/*
#include <stdio.h>
#define MAKS 32

unsigned obrnuti(unsigned broj) {
    unsigned obrnuti = 0;

    for (int i = 0; i < MAKS; i++) {
        unsigned mask = 1u << i;
        if (broj & mask) {
            unsigned pomak = 1u << (MAKS - 1 - i);
            obrnuti = obrnuti | pomak;
        }
    }

    return obrnuti;
}

int main(void) {
    unsigned n;

    printf("Unesite broj > ");
    scanf("%u", &n);

    printf("\nBroj binarno: ");
    for (int i = MAKS - 1; i >= 0; i--) {
        unsigned mask = 1u << i;
        if (mask & n) {
            printf("1");
        } else {
            printf("0");
        }
    }

    unsigned b;
    b = obrnuti(n);

    printf("\nObrnuti binarno: ");
    for (int i = MAKS - 1; i >= 0; i--) {
        unsigned mask = 1u << i;
        if (mask & b) {
            printf("1");
        } else {
            printf("0");
        }
    }

    printf("\nObrnuti dekadski: %u", b);

    return 0;
} */

// ===== Meduispit 2.1. Zadatak 1 =====
/*
#include <stdio.h>

int main(void) {
    int z, n, i, sum = 0;

    printf("Upisite znamenku > ");
    scanf("%d", &z);
    int prvi = 0;
    for (n = 999; n >= 100; n--) {
        int prost = 1;
        for (i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                prost = 0;
            }
        }
        if (prost == 1 && (n / 100 == z || n / 10 % 10 == z || n % 10 == z)) {
            if (prvi == 0) {
                printf("%d", n);
            } else {
                printf(" %d", n);
            }
            sum += n;
            prvi = 1;
        }
    }

    printf("\nZbroj: %d", sum);

    return 0;
} */

// ===== Meduispit 2.1. Zadatak 2 =====
/*
#include <stdio.h>

int main(void) {
    int n, i;
    printf("Upisi kapacitet (velicinu) polja > ");
    scanf("%d", &n);

    printf("Upisi %d brojeva 0-9 > ", n);

    int polje[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &polje[i]);
    }

    int min = polje[0];
    int imax, imin;
    for (i = 1; i < n; i++) {
        if (polje[i] < min) {
            min = polje[i];
            imin = i;
        }
    }

    int max = polje[0];
    for (i = 1; i < n; i++) {
        if (polje[i] > max) {
            max = polje[i];
            imax = i;
        }
    }
    if (imin > imax) {
        for (i = imin; i >= imax; i--) {
            printf("%d", polje[i]);
        }
    } else {
        for (i = imin; i <= imax; i++) {
            printf("%d", polje[i]);
        }
    }

    return 0;
} */

// ===== Meduispit 2.1. Zadatak 3 =====
/*
#include <stdio.h>
#define MAKS 100

int main(void) {
    char s1[MAKS + 1], s2[MAKS + 1];

    printf("Upisite s1 > ");
    fgets(s1, MAKS + 1, stdin);

    printf("Upisite s2 > ");
    fgets(s2, MAKS + 1, stdin);

    int i = 0, j = 0;

    while (s1[i] != '\0')
        i++;
    if (i > 0 && s1[i - 1] == '\n')
        s1[--i] = '\0';

    while (s2[j] != '\0')
        j++;
    if (j > 0 && s2[j - 1] == '\n')
        s2[--j] = '\0';

    int isti = 1, i1 = 0, i2 = 0;
    char print1[MAKS + 1], print2[MAKS + 1];
    i = 0;
    while (s1[i] != '\0') {
        print1[i] = s1[i];
        i++;
    }
    print1[i] = '\0';
    i = 0;
    while (s2[i] != '\0') {
        print2[i] = s2[i];
        i++;
    }
    print2[i] = '\0';

    while ((s1[i1] != '\0' || s2[i2] != '\0') && isti == 1) {
        while (s1[i1] == ' ')
            i1++;
        while (s2[i2] == ' ')
            i2++;

        if (s1[i1] >= 'A' && s1[i1] <= 'Z') {
            s1[i1] += 32;
        }
        if (s2[i2] >= 'A' && s2[i2] <= 'Z') {
            s2[i2] += 32;
        }

        if (s1[i1] > s2[i2]) {
            isti = 0;
            printf("(%s)>(%s)", print1, print2);
            printf("\nRazlika na indeksima: (s1:%d, s2:%d)", i1, i2);
        }

        if (s1[i1] < s2[i2]) {
            isti = 0;
            printf("(%s)<(%s)", print1, print2);
            printf("\nRazlika na indeksima: (s1:%d, s2:%d)", i1, i2);
        }

        if (s1[i1] != '\0')
            i1++;
        if (s2[i2] != '\0')
            i2++;
    }

    if (isti == 1) {
        printf("(%s)=(%s)", print1, print2);
    }

    return 0;
} */

// ===== Meduispit 2.1. Zadatak 4 =====
/*
#include <stdio.h>

int main(void) {
    int n, i, j, poz = 0, neg = 0;

    do {
        printf("Ucitajte red matrice> ");
        scanf("%d", &n);
    } while (!(n >= 1 && n <= 10));

    int polje[n][n];

    printf("Ucitajte %d elemenata cjelobrojne matrice> ", n * n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &polje[i][j]);
            if (polje[i][j] > 0)
                poz++;
            else if (polje[i][j] < 0)
                neg++;
        }
    }

    printf("\nUcitana matrica:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%4d", polje[i][j]);
        }
        printf("\n");
    }

    printf("Matrica rotirana ulijevo:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%4d", polje[j][n - i - 1]);
        }
        printf("\n");
    }

    printf("Pozitivnih: %d", poz);
    printf("\nNegativnih: %d", neg);

    return 0;
} */
