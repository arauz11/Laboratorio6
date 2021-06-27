#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct user
{
    char username[100];
    int id;
    int register_year;
};

struct user server[] = 
{
    "jesse", 2312, 2021,
    "annk", 4331, 2021,
    "oroboros", 3952, 2017,
    "dokuro", 4316, 2019,
    "kkjus", 5332, 2011,
    "marvest", 9912, 2010,
    "eillek", 1092, 2020,
    "tuomas", 1292, 2015,
    "marko", 4131, 2016,
    "tarja", 1314, 2014,
     "jesse", 2312, 2021, 
};


/*
TODO
@function compare_username
@desc compares username of two user records.
*/
int compare_username(const void *a, const void *b)
{

/* La función de comparación debe devolver un número entero menor, 
igual o mayor que cero si el primer argumento se considera 
respectivamente menor, igual o mayor que el segundo.*/
  
// Un tipo de puntero para struct*
struct user* stra = (struct user*)a;
struct user* strb = (struct user*)b;

/* Usa la función strcmp para calcular y devolver comparación de ambos,
devuelve strcmp:
- 0, si s1 y s2 son iguales;
- Un valor negativo si s1 es menor que s2;
- Un valor positivo si s1 es mayor que s2. */
	return strcmp(stra->username, strb->username);
}

/*
TODO
@function compare_id
@desc compares id of two user records.
*/
int compare_id(const void *a, const void *b)
{
// Un tipo de puntero para struct*
struct user* stra = (struct user*)a;
struct user* strb = (struct user*)b;

/* return stra-> id - strb-> id, si a es menor que b, 
entonces regresará en un valor negativo, 
de lo contrario será un valor positivo.*/
	return stra->id - strb->id;
}

/*
TODO
@function compare_register_year
@desc compares register date of two user records.
*/
int compare_register_year(const void *a, const void *b)
{
// Un tipo de puntero para struct*
struct user* stra = (struct user*)a;
struct user* strb = (struct user*)b;

/* return stra-> register_year - strb-> register_year, si a es menor que b, 
entonces devolverá un valor negativo, 
de lo contrario será un valor positivo.*/
	return stra->register_year - strb->register_year;
}

/*
@function printrec
@desc prints user record
*/
void printrec(void *prec, void *arg)
{
    struct user *pstud = (struct user *)prec;
    printf("%-20s %d %d\n", pstud->username, pstud->id, pstud->register_year);
}

/*!
@function apply
@desc applies
*/
void apply(struct user *sarr, int nrec, void (*fp)(void *prec, void *arg), void *arg)
{
    int i = 0;
    for (i = 0; i < nrec; i++)
    {
        /*callback*/
        fp(&sarr[i], arg);
    }
}

/*
@function isolder
@desc prints user record only if the user register is older than *((int*)arg)
*/
void isolder(void *prec, void *arg)
{
    struct user *pstud = (struct user *)prec;
    if (pstud->register_year > *((int*)arg))
        printf("%-20s %d %d\n", pstud->username, pstud->id, pstud->register_year);
}

int main()
{
    int nusers = sizeof(server) / sizeof(struct user);
  //  int n;

    puts("Todos los registros de usuario:");
    puts("-------------------------------");
    apply(server, nusers, printrec, NULL);

    /*Ordenar por el nombre de usuario.*/
    puts("Ordenado por nombre de usuario:");
    puts("-------------------------------");
    qsort(server, nusers, sizeof(struct user), compare_username);
    apply(server, nusers, printrec, NULL);

    /*Ordenar por el ID.*/
    puts("Ordenado por el ID:");
    puts("-------------------------------");
    qsort(server, nusers, sizeof(struct user), compare_id);
    apply(server, nusers, printrec, NULL);

    /*Ordenar según la fecha de registro.*/
    puts("Ordenado según la fecha de registro:");
    puts("-------------------------------");
    qsort(server, nusers, sizeof(struct user), compare_register_year);
    apply(server, nusers, printrec, NULL);

    /*print las personas mayores de n.*/
    puts("Personas mayores que n:");
    int age;
    scanf("%d", &age); // Ingrese la edad.
    puts("-------------------------------");
 //   n = 0;
    apply(server, nusers, isolder, &age);
    return 0;
}
