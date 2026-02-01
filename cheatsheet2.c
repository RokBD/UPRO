/********************************************************************************************
FER ZPR – OG COPY-PASTE CHEAT SHEET 2.0 (SITNE PIZDARJE + MINI ALGORITMI +
TRIKOVI)

Kako koristiti:
- CTRL+F: "SCANF", "REALLOC", "FREAD", "2D", "BIT", "TOKEN", "SORT", "SEARCH"
- Kad zapneš: pogledaj section [X] "DEBUG CHECKLIST"

=============================================================================================
[0] 100% osnovne definicije (da ne pucaš na glupostima)
=============================================================================================
- C-string: niz char koji završava s '\0'.
- "prazan string": s[0] = '\0' (NE " ").
- pointer aritmetika: p+i pomiče za i * sizeof(*p).
- razlikuj:
    char *s  -> pokazivač na char (može na literal)
    char s[] -> stvarni niz u memoriji (može se mijenjati)
- NE uspoređuj stringove s != ili == (to uspoređuje adrese).
- rand() “nije random”, nego deterministički niz; srand(seed) postavlja
početak.

=============================================================================================
[A] POINTERI + POLJA – sitne razlike koje ubijaju bodove
=============================================================================================
int a[10];
a        == &a[0] u većini izraza (decay)
&a       != a       (različiti tipovi: &a je pointer na cijelo polje)

a[i]     == *(a+i)
&a[i]    == a+i

Kad funkcija prima polje:
void f(int *p, int n)  // p pokazuje na prvi element

const:
void g(const int *p)   // g ne smije mijenjati p[i]

Pointer na pointer (za realloc koji vraća novi pointer iz funkcije):
int grow(int **pp, int newN) { *pp = realloc(*pp, newN*sizeof(int)); ... }

=============================================================================================
[B] STRINGOVI – mini šablone (bez library i s library)
=============================================================================================
Pristup znaku:
char ch = s[i];
char ch2 = *(s+i);

Ispis podstringa:
printf("%s\n", s+2);  // sve od indeksa 2 do '\0'

Sigurno provjeri “ima li znak”:
#include <string.h>
if (strchr(s, 'x')) { /* postoji */ }

Je li slovo / broj /
    space :
#include <ctype.h>
    if (isalpha((unsigned char)s[i]))... if (
        isdigit((unsigned char)s[i]))... if (isspace((unsigned char)s[i]))...

    SASTAVI STRING RUČNO(bez strcat) – najbrže i najsigurnije : int k = 0;
result[k++] = 'A';
result[k++] = 'B';
result[k] = '\0';

Remove char(in - place) – “read / write pointer”
    : void removeChar(char *s, char c) {
    char *r = s, *w = s;
    while (*r) {
        if (*r != c)
            *w++ = *r;
        r++;
    }
    *w = '\0';
}

Reverse string : void reverse(char *s) {
    int i = 0, j = (int)strlen(s) - 1;
    while (i < j) {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
        i++;
        j--;
    }
}

Count occurrences : int countChar(const char *s, char c) {
    int cnt = 0;
    for (int i = 0; s[i]; i++)
        if (s[i] == c)
            cnt++;
    return cnt;
}

Trim newline from fgets : line[strcspn(line, "\n")] = '\0';

=============================================================================================
[C] SCANF / FGETS – najčešće zamke + rješenja
=============================================================================================
1) scanf("%d", &x) ostavlja '\n' u bufferu.
   - ako poslije čitaš char, koristi " %c"
   - ako poslije čitaš liniju s fgets, napravi jedan getchar() ili “pojedi newline”

2) "pojed razmak" trik:
scanf(" %c", &c);      // taj space preskoči whitespace prije znaka

3) Width specifier (da ne overflowaš):
char s[129];
scanf("%128s", s);

4) fgets + sscanf pattern (najstabilnije):
char line[256];
while (fgets(line, sizeof line, fp)) {
    int x, y;
    if (sscanf(line, "%d %d", &x, &y) == 2) {
        ...
    }
}

5) Separator # (datum#7#15#24#25):
Opcija 1 – ignore datum (bez dummy):
int a1,a2,g1,g2;
while (fscanf(fp, " %*[^#]#%d#%d#%d#%d", &a1, &a2, &g1, &g2) == 4) {
    ...
}

Najčešći bug : fali zarez nakon formata : fscanf(fp, "format" & x)
                                              ->compiler misli da radiš binary &

                                          Ako ti editor prigovara
    : Koristi fgets
    + strtok(bez scanset - a) : char line[256];
while (fgets(line, sizeof line, fp)) {
    char *tok = strtok(line, "#"); // datum ignore
    tok = strtok(NULL, "#");
    if (!tok)
        continue;
    a1 = atoi(tok);
    tok = strtok(NULL, "#");
    if (!tok)
        continue;
    a2 = atoi(tok);
    tok = strtok(NULL, "#");
    if (!tok)
        continue;
    g1 = atoi(tok);
    tok = strtok(NULL, "#");
    if (!tok)
        continue;
    g2 = atoi(tok);
}

== == == == == == == == == == == == == == == == == == == == == == == == == == ==
    == == == == == == == == == == == == == == == == == == ==
    = [D] RAND / SRAND / MOD – mapiranja i “zašto mi je uvijek isto” == == == ==
      == == == == == == == == == == == == == == == == == == == == == == == == ==
      == == == == == == == == == == == == == == == == ==
    = srand(seed) se radi JEDNOM(u main - u)
              .rand() se zove kad trebaš broj
              .

          Ako je seed isti
          -> sekvenca ista(to je normalno i često traženo u zadacima)
              .

          MOD
    : a % b je ostatak.b mora biti !=
      0.

          Mapiranja : 0..k -
          1 : r = rand() % k 1..k : r = rand() % k + 1 lb..ub
    : r = lb + rand() % (ub - lb + 1)

                            Random indeks u polju duljine n : int idx =
              rand() % n;

=============================================================================================
[E] STATIC – algoritmi koji traže “pamćenje” između poziva
=============================================================================================
static lokalna varijabla:
- inicijalizira se jednom
- pamti vrijednost između poziva

Primjeri:
1) Toggle smjer (0..n-1 pa n-1..0):
static int flip = 0;
flip = 1 - flip;

2) Ring buffer zadnjih K vrijednosti:
static int buf[5];
static int count = 0;
buf[count % 5] = x;
count++;

== == == == == == == == == == == == == == == == == == == == == == == == == == ==
    == == == == == == == == == == == == == == == == == == ==
    = [F] MALLOC / REALLOC – najbolji “ispit” patterni + optimizacije == == ==
      == == == == == == == == == == == == == == == == == == == == == == == == ==
      == == == == == == == == == == == == == == == == == ==
    = Osnovno : p = malloc(n * sizeof *p);
p = calloc(n, sizeof *p); // sve 0
p = realloc(p, newN * sizeof *p);

realloc(NULL, size) == malloc(size) // možeš krenuti s NULL

    TMP PATTERN(obavezno kad provjeravaš)
    : tmp = realloc(p, newSize);
if (!tmp) {
    free(p);
    return;
}
p = tmp;

BRZINA : realloc u petlji po 1 element =
             sporo.Dobar pattern : capacity doubling : int cap = 0,
                               len = 0;
int *a = NULL;
if (len == cap) {
    cap = cap ? cap * 2 : 8;
    a = realloc(a, cap * sizeof *a);
}
a[len++] = x;

Za string koji raste : int cap = 0, len = 0;
char *s = NULL;
if (len + 1 >= cap) {
    cap = cap ? cap * 2 : 16;
    s = realloc(s, cap);
}
s[len++] = 'A';
s[len] = '\0';

Najčešći segfault 139
    : -zaboravio si +
      1 za '\0' -
      koristiš strcat na neinicijaliziran dest(nema dest[0] = '\0') -
      pišeš izvan alociranog bloka - fread / fscanf upisuje u krivu adresu

    == == == == == == == == == == == == == == == == == == == == == == == == ==
    == == == == == == == == == == == == == == == == == == == == ==
    = [G] BITOVI – maske,
    set / clear / test / toggle == == == == == == == == == == == == == == == ==
        == == == == == == == == == == == == == == == == == == == == == == == ==
        == == == == == ==
    = Test bit k : if (x & (1u << k)) { /* bit je 1 */ }

Set bit k : x |= (1u << k);

Clear bit k : x &= ~(1u << k);

Toggle bit k : x ^= (1u << k);

Maska za n bitova : mask = (1u << n) - 1; // n<32

Pakiranje 2 nibble - a(4 bita + 4 bita) u jedan byte
    : unsigned char out = ((a & 0x0F) << 4) | (b & 0x0F);

== == == == == == == == == == == == == == == == == == == == == == == == == == ==
    == == == == == == == == == == == == == == == == == == ==
    = [H] DATOTEKE – tekstne i binarne,
    fread / fseek,
    cijeli file == == == == == == == == == == == == == == == == == == == == ==
        == == == == == == == == == == == == == == == == == == == == == == == ==
        ==
    = fopen mode : "r"
                   "w"
                   "a" tekst "rb"
                   "wb" binarno

                       Tekst
    : fscanf /
      fgets / sscanf Binarno : fread(&rec, sizeof rec, 1, fp) ==
      1                                    // čita 1 zapis
          fread(arr, sizeof arr[0], N, fp) // čita N zapisa

          ČITANJE CIJELOG FILE -
          A(ako je niz structova istog tipa) : fseek(fp, 0, SEEK_END);
long bytes = ftell(fp);
rewind(fp);
int n = bytes / sizeof(zapis_t);
zapis_t *a = malloc(n * sizeof *a);
fread(a, sizeof *a, n, fp);

DIRECT ACCESS : fseek(fp, (long)idx * sizeof(zapis_t), SEEK_SET);
fread(&rec, sizeof rec, 1, fp);

VAŽNO:
Ako u datoteci nisu sva 4 polja iz strukture, NE smiješ fread cijelu strukturu.
Onda čitaš field-by-field ili definiraš “kraću” strukturu.

=============================================================================================
[I] MINI ALGORITMI (česti na zadacima)
=============================================================================================

[I1] Suma retka i stupca oko pointera u 2D matrici:
- Ako imaš int mat[m][n] i dobiješ int *p = &mat[0][0] + r*n + c:
  idx = p - &mat[0][0]
  r = idx / n
  c = idx % n
  sumRow = Σ mat[r][j]
  sumCol = Σ mat[i][c]

[I2] Greedy “razlaganje” (Roman):
- ideš od najvećeg prema najmanjem, dok možeš oduzimati.

[I3] Prekid “čim prvi dosegne cilj”:
- u for petlji nakon update: if (pos>=cilj) return i;

[I4] Uklanjanje whitespace -
    a s kraja inputa : -nakon fgets : strip newline -
                                      za string tokenizaciju
    : strtok

          [I5] Prebrojavanje ponavljanja u nizu : int count = 0;
for (i = 0; i < len; i++)
    if (a[i] == x)
        count++;

[I6] Ispis svih indeksa gdje je vrijednost x
    : for (i = 0; i < len; i++) if (a[i] == x) printf(" %d", i);

[I7] “zadnjih K”(moving window) prosjek : -ring buffer K -
                                          count<K => prosjek od count -
                                          else prosjek od K

                                          Brži prosjek zadnjih K
    : static int buf[K];
static int count = 0;
static long sum = 0;
idx = count % K;
if (count < K) {
    sum += x;
    buf[idx] = x;
    count++;
    avg = sum / count;
} else {
    sum -= buf[idx];
    buf[idx] = x;
    sum += x;
    count++;
    avg = sum / K;
}

[I8] Uzorkovanje polja:
for i in 0..sample-1: sum += polje[rand()%N];

[I9] Parsiranje “x#y#z”:
- fgets line
- strtok po "#"
- atoi/atof

[I10] Bubble/Selection/Insertion sort (osnove)
Bubble:
for i=0..n-2
  for j=0..n-2-i
    if(a[j]>a[j+1]) swap

Selection:
for i=0..n-2
  min=i; for
    j = i + 1..n - 1 if (a[j] < a[min]) min = j;
  swap(a[i], a[min])

Insertion:
for i=1..n-1
  key=a[i];
  j = i - 1;
  while (j >= 0 && a[j] > key)
      a[j + 1] = a[j], j--;
  a[j + 1] = key;

  [I11] Linear search : for (i = 0; i < n; i++) if (a[i] == x) {
      found = i;
      break;
  }

  [I12] Binary search(sorted) : lo = 0, hi = n - 1;
  while (lo <= hi) {
      mid = (lo + hi) / 2;
      if (a[mid] == x)
          return mid;
      if (a[mid] < x)
          lo = mid + 1;
      else
          hi = mid - 1;
  }

  [I13] qsort template : int cmpInt(const void *A, const void *B) {
      int a = *(const int *)A, b = *(const int *)B;
      return (a > b) - (a < b);
  }
  qsort(a, n, sizeof a[0], cmpInt);

=============================================================================================
[J] FORMATIRANJE ISPISA – sitnice koje se pojavljuju u primjerima
=============================================================================================
%3d   -> širina 3, desno poravnato (tablični ispisi)
%.2f  -> float/double na 2 decimale
%hu   -> unsigned short
%ld   -> long
%lf   -> double u scanf (u printf je %f i za double)

puts(s)  -> ispiše string + newline
fputs(s, fp) -> ispiše string u datoteku, NE dodaje newline

=============================================================================================
[X] DEBUG CHECKLIST (kad “ne radi”, a ne znaš zašto)
=============================================================================================
1) Petlja se ne izvršava:
   - provjeri povratnu vrijednost fscanf/fread (ispiši ju)
   - provjeri da format stvarno matcha (print line s fgets)
2) Sve vrijednosti 0:
   - uvjet if nikad true? (strcmp==0, datum točan, luka točna)
   - while nikad nije ušao
3) Segfault:
   - pointer NULL? (malloc/realloc fail, fopen fail)
   - buffer premali? (nema mjesta za '\0')
   - indeks out-of-range? (a[a1-1] kad a1=0 ili >32)
4) Garbage u struct nakon fread:
   - file nije pisan tim struct layoutom
   - sizeof mismatch / padding
5) “Format string crven u VSCode”:
   - to je editor, ne compiler
   - ako te živcira, prebaci na fgets+strtok

=============================================================================================
KRAJ
********************************************************************************************/
