// ===== Meduispit 1.1. Zadatak 1 =====

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
}
