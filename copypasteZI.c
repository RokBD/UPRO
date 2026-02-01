/********************************************************************************************
FER ZPR – OGROMAN COPY-PASTE CHEAT SHEET (zadaci + prezentacije + tvoji
patterni)

SADRŽAJ (CTRL+F):
  [A] MENTALNI MODEL MEMORIJE (stack/heap/static), pokazivači, polja
  [B] STRINGOVI (char*, char[]), pristup znaku, strcmp/strcpy/strcat, buffer i
'\0' [C] SCANF/FGETS/SSCANF – whitespace, "pojed razmak", # separator, scanset
%[^#] [D] RAND/SRAND, MOD (%), mapiranje intervala, “zašto uvijek isti brojevi”
  [E] STATIC – zašto radi, toggle redoslijed, kumulativno brojanje
  [F] MALLOC/CALLOC/REALLOC/FREE – kako radi realloc(NULL,...), tmp pattern,
segfault 139 [G] DATOTEKE – tekstne i binarne: fopen modovi, fread/fwrite,
fscanf, fseek/ftell [H] GOTOVI “TEMPLATE” PATTERNI za tipične zadatke: H1
decimalToRoman (romanMap) H2 odigrajKrug (flip smjer + prekid na pobjedniku) H3
pamti5IspisiProsjek (zadnjih 5, ring buffer) H4 uzorkujPolje + napuniPolje H5
dinamički niz s A,C,M do n-tog ponavljanja (realloc po elementu) H6 # linije
(datum#broj#broj...) – ignoriraj datum H7 fread strukture – čitaj jedan zapis /
cijeli file / polje H8 slucajniClan (2D polje -> vrati int*) H9
brojiDjelj3Kumulativno (kumulativno, “u ratama”) H10 delCharFromName (izbaci
znak iz stringa) H11 capitalizeName (title case, space i '-' posebni) H12
compress (pakiranje 4 bita u 1 bajt) H13 playRollTheDice (2 igrača, kockica N
strana) H14 parnepar (binarna -> tekst, prethodni/trenutni/sljedeći) H15 dist2D
(točke, udaljenosti u rez, vrati total) H16 generate(struct point_s...) (rand u
intervalu) H17 zamijeniGlavnaD (glavna dijagonala swap, vrati sporedna suma) H18
podaciZaKatProizv (datoteka s # poljima)

********************************************************************************************/

/* =========================================================================================
[A] MEMORIJA + POLJA + POKAZIVAČI (najbitnije)
=========================================================================================

1) Stack (automatske varijable):
   - lokalne varijable u funkciji
   - nestanu kad funkcija završi

2) Static (globalno ili static lokalno):
   - živi cijeli program
   - static lokalna u funkciji pamti vrijednost između poziva

3) Heap (dinamička memorija):
   - malloc/calloc/realloc
   - živi dok ne free-aš

Pokazivač = varijabla koja sadrži ADRESU.

int x = 5;
int *p = &x;        // p pokazuje na x
*p = 7;             // mijenja x na 7

Polje:
int a[5];
a    -> u izrazu se “pretvara” u &a[0] (pokazivač na prvi element)
&a[i] == a + i
a[i]  == *(a + i)

2D polje:
int b[m][n];
NE MOŽEŠ: int *p = b;            // krivo
MOŽEŠ:   int *p = &b[0][0];      // ok
i pristup:
b[i][j] == *(p + n*i + j)

Ovo je baš tipično s predavanja. (p + n*i + j)
:contentReference[oaicite:3]{index=3}
*/

/* =========================================================================================
[B] STRINGOVI (char*)
=========================================================================================

String u C-u je char polje koje završava s '\0'.

char s[6] = "HELLO";  // zapravo: H E L L O \0
char *ps = "HELLO";   // pokazuje na literal (često read-only!)

Pristup jednom znaku:
  ps[i]        ili *(ps + i)

Ako napišeš:
  printf("%s", ps + 2);
ispisat će od trećeg znaka do kraja (od indeksa 2), jer %s očekuje string.

Usporedba stringova:
  strcmp(a,b) == 0   => jednaki
  strcmp(a,b) < 0    => a “manji”
  strcmp(a,b) > 0    => a “veći”
NE radi:
  if (a != b)  // to uspoređuje adrese, ne sadržaj

Kopiranje/konkatenacija:
  strcpy(dest, src)  // kopira src u dest (mora biti dovoljno velik)
  strcat(dest, src)  // nadoda src na kraj dest-a (dest mora već biti validan
string!)

Zašto strcat radi kad je dest prazan?
  Ako je dest[0] = '\0' -> to je “prazan string”.
  strcat tada traži kraj dest-a (odmah nađe '\0') i kopira src tamo.

ZLATNO pravilo: svaki string buffer mora završiti s '\0' i mora imati prostora.
*/

/* =========================================================================================
[C] SCANF / FGETS / SSCANF – whitespace, “pojed razmak”, # separator
=========================================================================================

1) scanf("%d", &x); čita int (preskače whitespace)
2) scanf("%s", s);  čita riječ do whitespace (ne čita razmake)
3) scanf(" %c", &c); čita char i preskače prethodne whitespace (bitno!)

Zašto " %c"?
- jer nakon scanf("%d") ostane '\n' u input bufferu
- bez razmaka: scanf("%c",&c) bi pročitao taj '\n'

fgets(buffer, maxLen, stdin):
- čita cijeli red (i razmake) do '\n'
- ako prije toga koristiš scanf, često moraš “pojesti” '\n' (npr. getchar()).

Čitanje linije “datum#7#15#24#25”
Opcija A (fscanf sa separatorima):
  char datum[11+1];
  int a1,a2,g1,g2;
  fscanf(fp, "%11[^#]#%d#%d#%d#%d", datum, &a1,&a2,&g1,&g2);

Opcija B (ignore datum):
  fscanf(fp, "%*[^#]#%d#%d#%d#%d", &a1,&a2,&g1,&g2);

Napomena:
- %*  znači “pročitaj ali NE spremi”
- [^#] znači “bilo što osim #”

U VS Code-u može postati “crveno” zbog IntelliSense-a, ali C kompajleru je
format legit. Bitno je da fscanf vrati 4 (jer imaš 4 %d), ne 5.

Dakle:
while (fscanf(fp, "%*[^#]#%d#%d#%d#%d", &a1,&a2,&g1,&g2) == 4) { ... }
*/

/* =========================================================================================
[D] RAND / SRAND, MOD (%), mapiranje intervala
=========================================================================================

rand() daje pseudoslučajne brojeve.
srand(seed) postavlja sjeme (početno stanje generatora).

Ako svaki put staviš isti seed (npr. srand(0)), dobit ćeš ISTU sekvencu rand()
brojeva. To je normalno i često korisno za testiranje (da rezultat bude
reproducibilan).

Pravilo:
- srand(...) se radi JEDNOM u main-u
- funkcije koje koriste rand() NE rade srand() unutra (osim ako zadatak baš
traži)

MOD (%):
  a % b = ostatak dijeljenja a / b (za int)
Primjer: 17 % 5 = 2

Mapiranje:
1) [0, k-1]:
   r = rand() % k;

2) [1, k]:
   r = rand() % k + 1;

3) [lb, ub] uključivo:
   r = lb + rand() % (ub - lb + 1);

Ovo se stalno traži u zadacima (random pomak 1..5, random indeks, random
koordinate).
*/

/* =========================================================================================
[E] STATIC – zašto radi
=========================================================================================

static lokalna varijabla:
- inicijalizira se jednom
- ne nestaje kad funkcija završi
- pamti vrijednost za sljedeći poziv

Primjeri:
1) flip smjer (odigrajKrug):
   static int flip = 0;
   flip = 1 - flip;

2) kumulativno pretraživanje polja (brojiDjelj3Kumulativno):
   static int idx = 0;
   static int ukupno = 0;
   // svaki poziv pregleda delta elemenata i nastavi dalje

Točno ono što zadatak traži: “mora znati nastaviti gdje je stala”
:contentReference[oaicite:4]{index=4}
*/

/* =========================================================================================
[F] MALLOC/CALLOC/REALLOC/FREE + segfault 139
=========================================================================================

malloc(nBytes):
- rezervira nBytes, sadržaj je nedefiniran (garbage)

calloc(count, size):
- rezervira count*size, sve postavi na 0

realloc(ptr, newSize):
- pokušava promijeniti veličinu bloka
- može vratiti ISTU adresu ili novu (ako mora preseliti blok)
- ako ne uspije: vrati NULL, a stari ptr i dalje vrijedi -> zato tmp pattern

VAŽNO: realloc(NULL, size) == malloc(size)
To znači da možeš krenuti s char *p = NULL; i samo koristiti realloc.

TMP PATTERN:
  tmp = realloc(p, newSize);
  if (!tmp) { free(p); error; }
  p = tmp;

free(ptr):
- oslobađa memoriju

SEGFAULT 139 (najčešći uzroci):
- dereferenciraš NULL ili neinicijalizirani pointer
- pišeš izvan alociranog buffer-a (nema mjesta za '\0')
- koristiš string funkcije na ne-terminated “stringu”
- fscanf/fread u nevalidan pointer / krivi sizeof / krivi count
*/

/* =========================================================================================
[G] DATOTEKE: tekstne i binarne (fopen/fread/fscanf/fseek)
=========================================================================================

fopen:
  "r"  read text
  "w"  write text (briše sadržaj)
  "a"  append text
  "rb" read binary
  "wb" write binary
  "r+b" read/write binary

Tekst:
  fscanf(fp, "%d %s", &x, s)
  fgets(line, sizeof line, fp)
  sscanf(line, "...", ...)

Binarno:
  fread(&record, sizeof(record), 1, fp)  // čitaj 1 zapis u strukturu
  fwrite(&record, sizeof(record), 1, fp)

Čitanje cijelog polja struktura:
  zapis_t a[32];
  fread(a, sizeof *a, 32, fp);     // preporučeno
ILI:
  fread(a, sizeof(a), 1, fp);      // radi jer sizeof(a) = 32*sizeof(zapis_t)
Ali općenito elegantnije je sizeof *a, count=32.

Direktni pristup binarnoj:
  fseek(fp, (long)idx * sizeof(record), SEEK_SET);
  fread(&record, sizeof record, 1, fp);

Ovo je tipični primjer s predavanja (račun prema šifri)
:contentReference[oaicite:5]{index=5}
*/

/* =========================================================================================
[H] TEMPLATE ZADACI (najčešći)
=========================================================================================
*/

/* -----------------------------------------
H1) decimalToRoman (romanMap)
--------------------------------------------

Ideja:
result treba biti string -> prvo result[0]='\0'
onda greedy: prolazi romanMap od najvećeg prema najmanjem:
dok number >= arab: oduzmi i strcat(roman)

Napomena: result mora imati dovoljno mjesta (u main-u obično char roman[10]; je
dosta za <4000).
*/
typedef struct {
    int arab;
    char *roman;
} romanmap_t;
extern romanmap_t romanMap[];

_Bool decimalToRoman(short number, char *result) {
    result[0] = '\0';
    if (number <= 0 || number >= 4000)
        return 0;

    for (int i = 0; i < 13; i++) {
        while (number >= romanMap[i].arab) {
            number -= romanMap[i].arab;
            strcat(result, romanMap[i].roman);
        }
    }
    return 1;
}

/* -----------------------------------------
H2) odigrajKrug (flip smjer + prekid)
--------------------------------------------

Zadatak: jednom uzlazno, drugi put silazno, čim netko dosegne cilj prekini.
Tvoj pattern sa static flip je 100% legit.
*/
int odigrajKrug(int *igraci, int n, int cilj) {
    static int flip = 0; // 0 -> 0..n-1, 1 -> n-1..0

    if (!flip) {
        for (int i = 0; i < n; i++) {
            igraci[i] += rand() % 5 + 1;
            if (igraci[i] >= cilj) {
                flip = 1;
                return i;
            }
        }
    } else {
        for (int i = n - 1; i >= 0; i--) {
            igraci[i] += rand() % 5 + 1;
            if (igraci[i] >= cilj) {
                flip = 0;
                return i;
            }
        }
    }
    flip = 1 - flip;
    return -1;
}

/* -----------------------------------------
H3) pamti5IspisiProsjek (zadnjih 5)
--------------------------------------------

Ring buffer: p[idx%5] = temp
Ako je ukupno unosa <5 -> prosjek od 1..b
Inače -> prosjek od 5 članova.

U tvom kodu tipična bugčina:
for (int i=0; i<=5; i++) je 6 elemenata (0..5), a polje ima 5 (0..4).
*/
void pamti5IspisiProsjek(int temp) {
    static int b = 0;
    static int p[5];
    double sum = 0;

    p[b % 5] = temp;

    int k = (b < 5) ? (b + 1) : 5;

    for (int i = 0; i < k; i++)
        sum += p[i];

    printf("Prosjek: %.2f\n", sum / k);
    b++;
}

/* -----------------------------------------
H4) uzorkujPolje + napuniPolje
--------------------------------------------

uzorkujPolje: uzmi duljinaUzorak puta slučajni indeks i zbroji
napuniPolje: popuni s rand u [dg, gg] i vrati točan prosjek
*/
double uzorkujPolje(int *polje, long duljinaPolje, int duljinaUzorak) {
    double s = 0;
    for (int i = 0; i < duljinaUzorak; i++) {
        s += polje[rand() % duljinaPolje];
    }
    return s / duljinaUzorak;
}
double napuniPolje(int *polje, long duljinaPolje, int dg, int gg) {
    double s = 0;
    for (long i = 0; i < duljinaPolje; i++) {
        polje[i] = dg + rand() % (gg - dg + 1);
        s += polje[i];
    }
    return s / duljinaPolje;
}

/* -----------------------------------------
H5) dinamički niz X_i = (A*X_{i-1}+C)%M
Stop kad se zadnji član pojavio ukupno n puta.
(realloc po elementu – kako zadatak traži)
-------------------------------------------- */

int count_occ(int *arr, int len, int x) {
    int c = 0;
    for (int i = 0; i < len; i++)
        if (arr[i] == x)
            c++;
    return c;
}

/* Skeleton:
int *arr=NULL; int len=0; int Xi=0;
do {
   Xi = (len==0)?0 : (A*arr[len-1]+C)%M;
   tmp=realloc(arr,(len+1)*sizeof(int));
   if(!tmp){free(arr);...}
   arr=tmp; arr[len++]=Xi;
} while(count_occ(arr,len,Xi) != n);

print all indices where arr[i]==Xi
free(arr);
*/

/* -----------------------------------------
H6) Čitanje “datum#7#15#24#25” i ignoriranje datuma
--------------------------------------------

Format string:
"%*[^#]#%d#%d#%d#%d"  -> skip datum, uzmi 4 broja
fscanf mora vratiti 4
*/
void parse_line(FILE *fp) {
    int a1, a2, g1, g2;
    while (fscanf(fp, "%*[^#]#%d#%d#%d#%d", &a1, &a2, &g1, &g2) == 4) {
        /* koristi a1,a2,g1,g2 */
    }
}

/* -----------------------------------------
H7) fread strukture – 3 najčešća patterna
-------------------------------------------- */

typedef struct {
    int sifDrzava;
    char nazivDrzava[21];
    int ukGolPostigao;
    int ukGolPrimio;
} zapis_t;

void read_one_by_one(FILE *bin) {
    zapis_t z;
    while (fread(&z, sizeof z, 1, bin) == 1) {
        /* koristi z */
    }
}

void read_array(FILE *bin) {
    zapis_t a[32];
    size_t n =
        fread(a, sizeof *a, 32, bin); /* n = koliko je stvarno pročitano */
    /* a[0..n-1] validno */
}

void read_whole_as_one_block(FILE *bin) {
    zapis_t a[32];
    fread(a, sizeof(a), 1, bin); /* radi ako file ima baš 32 zapisa */
}

/* Česta greška:
   fread(&a[i], sizeof(a[i]), 4, bin);
- to čita 4 zapisa u a[i], a nema mjesta (prepisuje memoriju) ->
crash/korupcija.
*/

/* -----------------------------------------
H8) slucajniClan (2D int polje)
Zadatak iz 2..txt :contentReference[oaicite:6]{index=6}
-------------------------------------------- */

int *slucajniClan(int *p0, int m, int n) {
    int r = rand() % m;
    int c = rand() % n;
    return p0 + r * n + c; /* pointer na polje[r][c] */
}

/* U main-u kad imaš int polje[m][n]:
   int *p = slucajniClan(&polje[0][0], m, n);

Kako iz pointera dobiješ r,c:
   int idx = (int)(p - &polje[0][0]);
   r = idx / n;
   c = idx % n;
*/

/* -----------------------------------------
H9) brojiDjelj3Kumulativno (kumulativno, “u ratama”)
Zadatak iz 2..txt :contentReference[oaicite:7]{index=7}
-------------------------------------------- */

int brojiDjelj3Kumulativno(int *p, int n, int delta) {
    static int idx = 0;
    static int ukupno = 0;

    int kraj = idx + delta;
    if (kraj > n)
        kraj = n;

    for (int i = idx; i < kraj; i++) {
        if (p[i] % 3 == 0)
            ukupno++;
    }
    idx = kraj;
    return ukupno;
}

/* Napomena:
   - idx i ukupno ostaju između poziva
   - ne smije preći granice polja
*/

/* -----------------------------------------
H10) delCharFromName (izbaci znak iz stringa)
Zadatak iz 2..txt :contentReference[oaicite:8]{index=8}
-------------------------------------------- */

void delCharFromName(char *name, char c) {
    char *r = name; /* read */
    char *w = name; /* write */
    while (*r) {
        if (*r != c) {
            *w = *r;
            w++;
        }
        r++;
    }
    *w = '\0';
}

/* -----------------------------------------
H11) capitalizeName (title case, space i '-' kao separatori)
Zadatak iz 2..txt :contentReference[oaicite:9]{index=9}
-------------------------------------------- */

#include <ctype.h>
#include <stdbool.h>

bool capitalizeName(char *name) {
    if (name[0] == '\0')
        return false;

    int newWord = 1;
    for (int i = 0; name[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)name[i];

        if (isalpha(ch)) {
            if (newWord)
                name[i] = (char)toupper(ch);
            else
                name[i] = (char)tolower(ch);
            newWord = 0;
        } else if (ch == ' ' || ch == '-') {
            newWord = 1;
        }
    }
    return true;
}

/* -----------------------------------------
H12) compress (pakiranje 4 bita u 1 bajt)
Zadatak iz 2..txt
-------------------------------------------- */

void compress(unsigned char *p, int len) {
    int out = 0;
    for (int i = 0; i < len; i += 2) {
        unsigned char hi = (p[i] & 0x0F) << 4;
        unsigned char lo = 0;
        if (i + 1 < len)
            lo = (p[i + 1] & 0x0F);
        p[out++] = (unsigned char)(hi | lo);
    }
    /* ostatak polja ne diraj */
}

/* -----------------------------------------
H13) playRollTheDice (2 igrača)
Zadatak iz 2..txt :contentReference[oaicite:11]{index=11}
-------------------------------------------- */

int playRollTheDice(int noOfDiceSides, int diceStartNumber, int noOfRolls) {
    int sum1 = 0, sum2 = 0;

    for (int i = 0; i < noOfRolls; i++) {
        int side = rand() % noOfDiceSides + 1; /* 1..noOfDiceSides */
        sum1 += side * diceStartNumber;
    }
    for (int i = 0; i < noOfRolls; i++) {
        int side = rand() % noOfDiceSides + 1;
        sum2 += side * diceStartNumber;
    }

    if (sum1 > sum2)
        return 1;
    if (sum2 > sum1)
        return 2;
    return 0;
}

/* -----------------------------------------
H14) parnepar (binarna -> tekst) – ideja algoritma
Zadatak iz 2..txt
--------------------------------------------

struct zapis_s { char naziv[11]; int sifra; };

Za svaki “trenutni” zapis trebaš nekad ispisati:
- ako je sifra parna: prethodni pa trenutni
- ako je sifra neparna: trenutni pa sljedeći
Ako prethodni/sljedeći ne postoje -> samo trenutni.

Minimalna šema bez “velikih polja”:
- čitaš jedan po jedan, ali moraš znati prethodni i moći “peekati” sljedeći.
- Tipično držiš:
    prevValid (bool), prev (record)
    curr (record)
    next (record) -> pročitaš unaprijed (lookahead)

Pseudo:
  read curr; if fail -> napravi praznu izlaznu
  prevValid=false;
  while (true):
      save file position before reading next
      if fread(next) ok -> nextValid=true else nextValid=false
      fseek back if treba? (ili koristi “buffer” curr/next rotaciju)
      odluči što upisuješ ovisno o parnosti curr.sifra
      zatim pomakni: prev=curr; curr=next; continue

U praksi najčišće: “lookahead” pristup s tri varijable.
*/

/* -----------------------------------------
H15) dist2D (točke, rez[i], vrati ukupno)
Zadatak iz 2..txt :contentReference[oaicite:13]{index=13}
-------------------------------------------- */

#include <math.h>

double dist2D(double *mat, double *rez, int vel) {
    double total = 0;
    double prevx = 0, prevy = 0;

    for (int i = 0; i < vel; i++) {
        double x = mat[2 * i];
        double y = mat[2 * i + 1];

        double dx = x - prevx;
        double dy = y - prevy;
        rez[i] = sqrt(dx * dx + dy * dy);
        total += rez[i];

        prevx = x;
        prevy = y;
    }
    return total;
}

/* Ako je mat zapravo 2D mat[vel][2], a funkcija dobije double*:
   &mat[0][0] je pointer, i koristiš mat[2*i + j].
*/

/* -----------------------------------------
H16) generate(struct point_s *s, ...) – random koordinate
Zadatak iz 2..txt :contentReference[oaicite:14]{index=14}
-------------------------------------------- */

struct point_s {
    int x;
    int y;
};

void generate(struct point_s *s, int n, int lb, int ub) {
    for (int i = 0; i < n; i++) {
        s[i].x = lb + rand() % (ub - lb + 1);
        s[i].y = lb + rand() % (ub - lb + 1);
    }
}

/* -----------------------------------------
H17) zamijeniGlavnaD – swap glavna dijagonala zrcalno, vrati sumu sporedne
Zadatak iz 2..txt :contentReference[oaicite:15]{index=15}
--------------------------------------------

Ako dobiješ float *p i n (matrica n*n):
  element(i,j) = *(p + i*n + j)

Swap glavna dijagonala:
  for i=0..n/2-1: swap (i,i) i (n-1-i, n-1-i)

Suma sporedne:
  sum += element(i, n-1-i)
*/

/* -----------------------------------------
H18) podaciZaKatProizv – # datoteka, min/max/koliko
Zadatak iz 2..txt :contentReference[oaicite:16]{index=16}
--------------------------------------------

Datoteka:
sifra#kategorija#naziv#cijena

Pattern:
  FILE *fp=fopen(...)
  while (fscanf(fp, "%d#%20[^#]#%50[^#]#%f", &sifra, kat, naziv, &cij) == 4) {
... } strcmp(kat, trazenaKat)==0 -> count++, min/max
*/

/* =========================================================================================
[I] MINI “FAQ” (stvari koje su te mučile)
=========================================================================================

1) “Imam char *result, kako ubacujem znakove?”
   - Ako result pokazuje na buffer (char roman[10] u main-u), u funkciji radiš:
       result[0]='\0';  // inicijalizacija praznog stringa
       strcat(result, "M"); ...
   - Ne radiš *result += ... (to mijenja prvi znak ASCII-sumom, nema smisla)

2) “Zašto treba zvjezdica kod romanMap[i].roman?”
   - romanMap[i].roman je char* (pointer na prvi znak stringa).
   - romanMap[i].roman[0] je prvi znak (char).
   - *romanMap[i].roman je isto prvi znak (dereferencira pointer).
   - Nema “zvjezdice u pozivu” jer kod stringa obično šalješ pointer (adresa).

3) “decimalToRoman(number, roman[0]) jel dobro?”
   - NE. roman[0] je char (jedan znak), a funkcija traži char*.
   - Ispravno: decimalToRoman(number, roman);  // roman se pretvori u &roman[0]

4) “realloc radi na NULL?”
   - DA. realloc(NULL, size) == malloc(size). (zato je p=NULL + realloc pattern
legit)

5) “Zašto strcat radi kad je prvi znak '\0'?”
   - To je definicija praznog stringa. strcat pronađe '\0' kao kraj i kopira od
tamo.

6) “Zašto mi je rand uvijek isti?”
   - Jer koristiš isti seed (npr. srand(100)).
   - To je normalno. Ako želiš “svaki put drukčije”, seedaj s vremenom:
       srand((unsigned)time(NULL));
     Ali u Edgar zadacima često eksplicitno traže da je seed zadan/učitan.

7) “Kako provjerit je li jedan znak u stringu?”
   - prolaz:
       for(i=0; s[i]; i++) if(s[i]==ch) ...
   - ili:
       if (strchr(s, ch) != NULL) ...

8) “Zašto mi puca (segfault) kod dinamičkog stringa?”
   - najčešće: nisi alocirao +1 za '\0'
   - ili: koristiš strcat na neinicijaliziran dest (nema dest[0]='\0')
   - ili: realloc u petlji previše puta (sporo) pa Edgar ubije program (TLE),
ali to nije segfault nego time/memory limit.

9) “Je li puts isto što i printf("%s\n", s)?”
   - puts(s) ispiše string i doda newline automatski.
   - printf("%s", s) ne doda newline osim ako ga staviš.

=========================================================================================
*/
