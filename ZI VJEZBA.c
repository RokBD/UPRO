// =====Završni ispit 2024/25 - drugi termin Zadatak 1 =====
/*
#include <stdio.h>
#include <string.h>

typedef struct {
    int arab;
    char *roman;
} romanmap_t;

romanmap_t romanMap[] = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
                         {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
                         {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"},
                         {1, "I"}};

_Bool decimalToRoman(short number, char *result) {
    result[0] = '\0';
    if (number <= 0 || number >= 4000) {
        return 0;
    } else {
        for (int i = 0; i < 13; i++) {
            while (number >= romanMap[i].arab) {
                number -= romanMap[i].arab;
                strcat(result, romanMap[i].roman);
            }
        }

        return 1;
    }
}

int main() {
    unsigned short number;
    char roman[10];

    printf("Unesite arapski broj> ");
    scanf("%hu", &number);

    _Bool x = decimalToRoman(number, roman);

    if (x) {
        printf("Rimski broj> %s", roman);
    } else {
        printf("Broj nije ispravan");
    }
    return 0;
}
*/

// =====Završni ispit 2024/25 - drugi termin Zadatak 2 =====
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int odigrajKrug(int *igraci, int n, int cilj) {
    static int flip = 0;
    int pobjednik = -1, pomak;

    if (flip == 0) {
        for (int i = 0; i < n && pobjednik == -1; i++) {
            pomak = (rand() % 5) + 1;
            *(igraci + i) += pomak;

            if (*(igraci + i) >= cilj && pobjednik == -1) {
                pobjednik = i;
            }
        }
    } else {
        for (int i = n - 1; i >= 0 && pobjednik == -1; i--) {
            pomak = (rand() % 5) + 1;
            *(igraci + i) += pomak;

            if (*(igraci + i) >= cilj && pobjednik == -1) {
                pobjednik = i;
            }
        }
    }

    flip = 1 - flip;

    return pobjednik;
}

int main(void) {
    int n, cilj, igraci[10] = {0};
    srand(100);
    printf("Broj igraca (<=10)> ");
    scanf("%d", &n);
    printf("Cilj (<=100)> ");
    scanf("%d", &cilj);
    int pobjednik;
    do {
        pobjednik = odigrajKrug(igraci, n, cilj);
        printf("\n");
        for (int i = 0; i < n; i++) {
            printf("%3d", igraci[i]);
        }
    } while (pobjednik == -1);
    printf("\nPobjednik je igrac %d\n", 1 + pobjednik);
    return 0;
} */

// =====Završni ispit 2024/25 - drugi termin Zadatak 3 =====
/*
#include <stdio.h>
#include <stdlib.h>

int brojPonavljanja(int x, int *brojevi, int i) {
    int brojac = 0;
    for (int j = 0; j < i; j++) {
        if (*(brojevi + j) == x) {
            brojac++;
        }
    }
    return brojac;
}

void index(int x, int *brojevi, int i) {
    for (int j = 0; j < i; j++) {
        if (*(brojevi + j) == x) {
            printf(" %d", j);
        }
    }
}

int main(void) {
    int A, C, M, n, *brojevi = NULL, *noviBrojevi = NULL, brojElemenata = 0, Xi;

    printf("Upisite cijele brojeve A, C, M, n > ");
    scanf("%d %d %d %d", &A, &C, &M, &n);

    do {
        if (brojElemenata == 0) {
            Xi = 0;
        } else {
            Xi = (A * *(brojevi + brojElemenata - 1) + C) % M;
        }

        noviBrojevi = realloc(brojevi, (brojElemenata + 1) * sizeof(int));
        if (noviBrojevi == NULL) {
            printf("Greska u alokaciji memorije.\n");
            free(brojevi);
            return 1;
        }
        brojevi = noviBrojevi;


        *(brojevi + brojElemenata) = Xi;
        brojElemenata++;

    } while (brojPonavljanja(Xi, brojevi, brojElemenata) != n);

    printf("Vrijednost zadnjeg clana nalazi se na indeksima:");
    index(Xi, brojevi, brojElemenata);

    free(brojevi);
    return 0;
} */

// =====Završni ispit 2024/25 - drugi termin Zadatak 4 =====
/*
typedef struct {
    char datum[11 + 1];      // Datum boravka kruzera u formatu DD.MM.GGGG
    char imeKruzera[30 + 1]; // Naziv kruzera
    char luka[30 + 1];       // Luka u koju uplovljava
    int brojGostiju;         // Broj gostiju na kruzeru
} uplovljavanje_t;

typedef struct {
    char nazivLuke[31]; // Naziv luke (nema bjelina u nazivu)
    int maksBrGostiju;  // Maksimalni dnevni broj gostiju
} lukaLimit_t;

#include <stdio.h>
#include <string.h>

int main(void) {
    char imeTxt[129], imeBin[129], datum[12], imeLuke[31];
    int ukGosti = 0, evidencija = 0;

    printf("Naziv tekstne datoteke> ");
    scanf("%s", imeTxt);

    printf("Naziv binarne datoteke> ");
    scanf("%s", imeBin);

    printf("Datum (DD.MM.GGGG.)> ");
    scanf("%s", datum);

    printf("Luka> ");
    scanf("%s", imeLuke);

    FILE *bin = fopen(imeBin, "rb");
    FILE *tekst = fopen(imeTxt, "r");

    uplovljavanje_t uplovljavanje;

    while (fread(&uplovljavanje, sizeof(uplovljavanje), 1, bin) == 1) {
        if (strcmp(uplovljavanje.datum, datum) == 0 &&
            strcmp(uplovljavanje.luka, imeLuke) == 0) {
            printf("\n  Kruzer: %s, Broj gostiju: %d", uplovljavanje.imeKruzera,
                   uplovljavanje.brojGostiju);
            ukGosti += uplovljavanje.brojGostiju;
        }
    }
    lukaLimit_t limit;

    while (fscanf(tekst, "%s %d", limit.nazivLuke, &limit.maksBrGostiju) == 2 &&
           evidencija == 0) {
        if (strcmp(limit.nazivLuke, imeLuke) == 0) {
            evidencija = 1;
            printf("\nUkupno gostiju: %d", ukGosti);
            if (ukGosti > limit.maksBrGostiju) {
                printf("\nKvota premasena (maksimalno %d)!",
                       limit.maksBrGostiju);
            } else {
                printf("\nKvota nije premasena (maksimalno %d).",
                       limit.maksBrGostiju);
            }
        }
    }

    if (evidencija == 0) {
        printf("\nLuka '%s' nije u evidenciji.", imeLuke);
    }

    fclose(bin);
    fclose(tekst);

    return 0;
}




// CHATGPT RJESENJE ISTOG ZADATKA
#include <stdio.h>
#include <string.h>

int main(void) {
    char imeTxt[129], imeBin[129], datum[12], luka[31];
    printf("Naziv tekstne datoteke> "); scanf("%128s", imeTxt);
    printf("Naziv binarne datoteke> "); scanf("%128s", imeBin);
    printf("Datum (DD.MM.GGGG.)> ");    scanf("%11s", datum);
    printf("Luka> ");                   scanf("%30s", luka);

    FILE *t = fopen(imeTxt, "r");
    FILE *b = fopen(imeBin, "rb");
    if (!t || !b) { if (t) fclose(t); if (b) fclose(b); return 1; }

    // 1) nađi limit za luku
    lukaLimit_t lim;
    int found = 0;
    while (fscanf(t, "%30s %d", lim.nazivLuke, &lim.maksBrGostiju) == 2)
        if (!strcmp(lim.nazivLuke, luka)) { found = 1; break; }
    fclose(t);

    printf("\n");

    if (!found) {
        printf("Luka '%s' nije u evidenciji.\n", luka);
        fclose(b);
        return 0;
    }

    // 2) prođi binarnu i ispiši kruzere + zbroji goste
    uplovljavanje_t u;
    int ukupno = 0;
    while (fread(&u, sizeof u, 1, b) == 1)
        if (!strcmp(u.datum, datum) && !strcmp(u.luka, luka)) {
            printf("  Kruzer: %s, Broj gostiju: %d\n", u.imeKruzera,
u.brojGostiju); ukupno += u.brojGostiju;
        }
    fclose(b);

    printf("Ukupno gostiju: %d\n", ukupno);
    printf(ukupno > lim.maksBrGostiju
           ? "Kvota premasena (maksimalno %d)!\n"
           : "Kvota nije premasena (maksimalno %d).\n",
           lim.maksBrGostiju);

    return 0;
}
 */

// =====Završni ispit 2024/25 - prvi termin Zadatak 1 =====
/*
#include <stdio.h>

void pamti5IspisiProsjek(int temp) {
    static int b = 0;
    static int p[5] = {0};
    float zbroj = 0;
    p[b % 5] = temp;
    if (b < 5) {
        for (int i = 0; i <= b; i++) {
            zbroj += (float)p[i];
        }
        printf("Prosjek: %.2f\n", (zbroj / (b + 1.)));
    } else {
        for (int i = 0; i < 5; i++) {
            zbroj += (float)p[i];
        }
        printf("Prosjek: %.2f\n", (zbroj / 5));
    }

    b++;
}

int main(void) {
    int tmp;

    do {
        printf("Unesite temperaturu> ");
        scanf("%d", &tmp);
        if (tmp != -1000) {
            pamti5IspisiProsjek(tmp);
        }
    } while (tmp != -1000);

    return 0;
} */

// ===== Završni ispit 2024/25 - prvi termin Zadatak 2 =====
/*
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double uzorkujPolje(int *polje, long duljinaPolje, int duljinaUzorak) {
    double s = 0;

    for (int i = 0; i < duljinaUzorak; i++) {
        s += *(polje + rand() % duljinaPolje);
    }

    return s / (double)duljinaUzorak;
}

double napuniPolje(int *polje, long duljinaPolje, int donjaGranica,
                   int gornjaGranica) {
    double s = 0;
    for (int i = 0; i < duljinaPolje; i++) {
        *(polje + i) =
            (rand() % (gornjaGranica - donjaGranica + 1)) + donjaGranica;
        s += *(polje + i);
    }

    return s / (double)duljinaPolje;
}

int main(void) {
    int d, dg, gg, dUzorak;
    scanf("%d %d %d", &d, &dg, &gg);
    int polje[d];
    srand(0);
    double as = napuniPolje(polje, d, dg, gg);
    for (int post = 5; post <= 25; post += 5) {
        dUzorak = d * post / 100;
        double procjArSr = uzorkujPolje(polje, d, dUzorak);
        double greska = fabs(as - procjArSr) / fabs(as) * 100;
        printf("%d%% (%d): tocno: %.2f procjena: %.2lf greska= %.2f%%\n", post,
               dUzorak, as, procjArSr, greska);
    }
    return 0;
} */

// ===== Završni ispit 2024/25 - prvi termin Zadatak 3 =====

/* #include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;

    printf("Duljina polja > ");
    if (scanf("%d", &n) != 1 || n <= 0)
        return 1;

    int *b = malloc(n * sizeof(int));
    char *z = malloc(n + 1);
    if (!b || !z) {
        free(b);
        free(z);
        return 1;
    }

    printf("Znakovi (bez razmaka) > ");
    for (int i = 0; i < n; i++)
        scanf(" %c", &z[i]);
    z[n] = '\0';

    printf("Brojevi > ");
    long total = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        total += b[i];
    }

    char *niz = malloc(total + 1);
    if (!niz) {
        free(b);
        free(z);
        return 1;
    }

    long k = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i]; j++)
            niz[k++] = z[i];

    niz[k] = '\0';

    printf("\nGenerirani niz: %s", niz);

    free(b);
    free(z);
    free(niz);
    return 0;
} */

// ===== Završni ispit 2024/25 - prvi termin Zadatak 4 =====
/*
typedef struct {
    int sifDrzava;            // Šifra države (1–32)
    char nazivDrzava[20 + 1]; // Naziv države (maks. 20 znakova)
    int ukGolPostigao;        // Ukupan broj postignutih golova, inicijalno 0
    int ukGolPrimio;          // Ukupan broj primljenih golova, inicijalno 0
} zapis_t;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char t[128 + 1], b[128 + 1];

    printf("Naziv tekstne datoteke > ");
    scanf("%s", t);
    printf("Naziv binarne datoteke > ");
    scanf("%s", b);

    printf("Statistika za drzave:\n");

    FILE *txt = fopen(t, "r"), *bin = fopen(b, "rb");

    zapis_t a[32];

    fread(a, sizeof(a), 1, bin);

    int a1, a2, g1, g2;
    char dummy[11];

    while (fscanf(txt, "%10s#%d#%d#%d#%d", dummy, &a1, &a2, &g1, &g2) == 5) {
        a[a1 - 1].ukGolPostigao += g1;
        a[a1 - 1].ukGolPrimio += g2;
        a[a2 - 1].ukGolPostigao += g2;
        a[a2 - 1].ukGolPrimio += g1;
    }

    for (int i = 0; i < 32; i++) {
        if (a[i].ukGolPostigao != 0 || a[i].ukGolPrimio != 0) {
            printf("%2d%21s%4d%4d\n", a[i].sifDrzava, a[i].nazivDrzava,
                   a[i].ukGolPostigao, a[i].ukGolPrimio);
        }
    }

    fclose(txt);
    fclose(bin);

    return 0;
} */