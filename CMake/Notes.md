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

CMake is a tool which automates makefile creation process. It allows to define paths to libraries included into the project.
\
CMake output is saved inside the `build` folder. Inside it we can find a lot of file, especially the makefile and the executable.

A general rule is to take templates of existing CMake files and customize them for specific uses.

To include specific C++ libraries inside the project, we should refer to its documentation; it will provide the instruction to add to our `CMakeLists.txt`.

Per compilare:

```shell
make
```
