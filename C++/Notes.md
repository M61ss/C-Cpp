# C++

## Classes

Le struct sono strutture dati inefficienti perché non c'è modo di organizzare bene i dati e associarli a dei propri metodi. 
\
Inoltre, non c'è modo di controllarne l'accesso (private o public). 

> [!IMPORTANT]
> 
> Entrati nel corpo del costruttore, in C++ si assume che tutti gli elementi all'interno della classe siano già stati inizializzati.
> \
> Vedi [classi.cpp](./test/src/classi.cpp)

> [!WARNING]
>
> L'assenza di access specifier rende implicitamente tutto il contenuto private!

### Namespace

I namespace sono un modo per organizzare meglio il codice in spazi di nomi. Esso assegna un prefisso a gruppi di funzioni per fare in modo che esse siano facilmente organizzabili e reperibili. 
\
Per esempio, è possibile organizzare funzioni di manipolazione di immagini 2d nel namespace `2d`, mentre metto le funzioni 3d nel namespace `3d`.

Infine, grazie ai namespace è possibile evitare problemi di conflitti tra funzioni aventi lo stesso nome se esse appartengono a namespace diversi.

### `new`

It returns a pointer to the element specified after the keyword.

> [!WARNING]
> 
> Do not confuse with Java! To create an object it is enough to call its constructor without the keyword `new`. 
