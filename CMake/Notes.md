# CMake

## Folder hierarchy

```
root
└───src
└───include
```

- `src`: Should contain files which use libraries. For example, `main.c` should be placed here.
- `include`: Libraries should be placed inside this folder.

## CMake

CMake is a tool which automates makefile creation process. It allows to define paths to libraries included into the project.
\
CMake output is saved inside the `build` folder. Inside it we can find a lot of file, especially the makefile to create the executable.

A general rule is to take templates of existing CMake files and customize them for specific uses.

To include specific C++ libraries inside the project, we should refer to its documentation; it will provide the instruction to add to our `CMakeLists.txt`.

### Build

You can build from the root folder using:

```shell
# DO NOT DO THIS
cmake .
```

Anyway, it is a bad practice because all output files will be dropped inside the root folder.
\
It is possible to set an output folder and, optionally, a source folder:

```shell
cmake [<options>] -B <path-to-build> [-S <path-to-source>]
```

Basically, `<path-to-build>` is the `build` folder and `<path-to-source>` is the `src` folder.

> [!WARNING] Rebuild
>
> Before rebuild, delete the build folder since `CMakeCache.txt` could produce conflicts.

### Create the executable

Move to the `build` folder, then use regularly the utility make:

```shell
make
```

To clean from make output:

```shell
make clean
```

Alternately you could use:

```shell
cmake --build <build-folder>
```
