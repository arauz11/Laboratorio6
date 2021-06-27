#include<stdio.h>

/* La cola de prioridad contendrá dos enteros (int), uno es el valor y 
el otro es el que le da prioridad a ese valor.*/ 
struct Node{
int node;
int priority;
};

// Este es el puntero al último índice de la cola.
int sz = -1;

/* Creando una matriz (array) de tipo nodo que contendrá dos elementos, valor y prioridad,
esta matriz almacenará ambos valores.*/ 
struct Node pr_q[200000];

// Definiendo la función de inserción.
void insert(int node, int priority){

// Aumentando el tamaño de la cola en 1. 
sz++;
  
// Insertando el valor del nodo en la matriz (array).
pr_q[sz].node = node;

// Insertando la prioridad del nodo en la matriz (array).
pr_q[sz].priority = priority;
}

int get_Highest_Priority(){
// El int index almacenará el índice del elemento que tiene la prioridad más alta. 
int index = -1;
  
/* El int high_priority almacenará la prioridad más alta del elemento cuyo índice 
está almacenado en index.*/
int highest_priority = -1;
  
/* Ahora recorre todos los elementos que tienes hasta ahora
como sz ha almacenado el tamaño de la cola, iteraremos hasta sz.*/ 
for(int i=0; i<=sz; i++){

/* Si los dos elementos tienen la misma prioridad, elija el que tenga el 
valor más alto.*/
if((highest_priority == pr_q[i].priority) && (index > -1) && (pr_q[index].node > pr_q[i].node)){
index = i;
highest_priority = pr_q[i].priority;
}
  
// El else, elija el que tenga más prioridad
else if(highest_priority<pr_q[i].priority){
index = i;
highest_priority = pr_q[i].priority;
}
}
/* El return, devuelve el índice del elemento que tiene la prioridad 
más alta.*/
return index;
}

/* Definir delete_Highest_Priority para eliminar el nodo 
que tiene la prioridad más alta en la cola.*/
void delete_Highest_Priority(){

// Almacene el índice cuyo elemento desea eliminar.
int index = get_Highest_Priority();
  
for(int i=index; i<sz; i++){
/* Para todos los elementos, asigne el siguiente elemento a eliminar
el elemento en una posición particular.*/
pr_q[i] = pr_q[i+1];
}
  
/* Como hemos eliminado el elemento de la cola, 
tenemos que disminuir el tamaño de la cola en 1.*/
sz--;
}

int main(){
// La operación de insert insertará elementos en la cola de prioridad.
printf("Insertar 25 con prioridad en 5, en la cola de prioridad\n");
insert(25, 5);
printf("Insertar 42 con prioridad en 3, en la cola de prioridad\n");
insert(42, 3);
printf("Insertar 2 con prioridad en 4, en la cola de prioridad\n");
insert(2, 4);
printf("Insertar 10 con prioridad en 1, en la cola de prioridad\n");
insert(10, 1);
printf("Insertar 16 con prioridad en 2, en la cola de prioridad\n");
insert(16, 2);
  
/* Llamamos a la función get_Highest_Priority que devolverá el elemento
que tiene la máxima prioridad .*/
  
int index = get_Highest_Priority();
int value = pr_q[index].node;
printf("En este momento,%d tiene la prioridad más alta en la cola..\n", value);
  
/* Llamamos a delete_Highest_Priority para eliminar el nodo 
que tiene la prioridad más alta en la cola.*/
printf("Eliminando el elemento con mayor prioridad ...\n");
delete_Highest_Priority();
  
index = get_Highest_Priority();
value = pr_q[index].node;
printf("Ahora %d tiene la prioridad más alta en la cola.\n", value);
  
return 0;
  
}
