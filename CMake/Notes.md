# CMake

## Folder hierarchy

```
root
└───src
└───include
```

- `src`: Should contain files which use libraries. For example, `mian.c` should be placed here.
- `include`: Libraries should be placed inside this folder.

### CMake

Permette di definire i path verso gli include file. 
\
Solitamente si prendono dei template già fatti.

CMake sostanzialmente genera da solo i makefile senza doverli scrivere a mano.

Per compilare:

```shell
make
```

Dopo la compilazione CMake genera la cartella `build` in cui vengono posti l'eseguibile e alcuni altri file generati, tra cui i makefile.

Per includere qualsiasi libreria nel progetto bisogna fare riferimento alla documentazione della stessa che fornirà le istruzioni da inserire nel `CMakeLists.txt`.