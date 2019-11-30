In acest program construit mai intii 3 structuri, toate fiind niste liste simplu inlantuita.

Una pentru a memora toata istoria unui card:
```c
typedef struct s_history { 
int succes;
 char *operation; 
struct s_history *next;
 } history;
```
`succes` - daca operatia nu a dat FAIL `operatia` - pentru a memora operatia facuta 

`next` - pentru a face legatura cu urmatorul nod

A doua lista am construit-o pentru a memora toata informatia a unui card: 

```c
typedef struct s_card { 
char card_number[17]; 
char pin[5]; 
char first_pin[5]; // pinul initial char exp_data[6]; char cvv[4];
int balance; 
char status[7]; 
int block; // if is blocked (3) history *history; 
struct s_card *next; 
} card
```
`card_number` - numarul cardului 
`pin` - pinul first_pin - pinul initial exp_data - data de expirare 
`cvv` - cvv 
`balance` - balanta contului 
`status` - statusul 
`block` - numarul de introducere gresita a pinului 
`history` - memorarea primului nod din lista de istorie a cardului 
`next` - legatura cu cardul urmator

A treia lista este pentru a memora lista LSC: 
```c
typedef struct s_lsc { 
card *card; 
struct s_lsc *next; 
} lsc; 
```
`card` - memorarea adresei primului card din lista de carduri a lsc 
`next` - pentru a construi legatura cu urmatorul lsc.

Am 4 variabile globale: - `NR_MAX_CARDURI` - numarul maxim de carduri(prima linie a fisierui de intrare) - `NR_CARD` - numarul de carduri introduse din intreaga baza de date - `LSC` - adresa primului nod din baza de date - `FPW` - fisierul unde se scrie informatia returnata (output)

In `main` am declarat variabilele globale si am apelat functia `citire()` , practic principala care face legatura cu toate celelalte. Aceasta citeste fiecare linie cu operatia cu care trebuie facuta si apeleaza functia respectiva.

 Fiecare functie e in fisier aparte, dar toate sunt unite intr-un header `atm.h`. Datele de intrare se dau intrun fisier `input.in` , si rezultatul este scris in fisierul `output.out` .
