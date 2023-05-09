# mergeResultOfFEMTIC
By this program, you can merge result files (.csv) of [FEMTIC](https://github.com/yoshiya-usui/femtic.git).

# this is a cmake version
```
cd src
cmake -B build 
cmake --build build
```
executable file outputs at the bin dir.

## src file tree
```
src
├── CMakeLists.txt
├── main
│   ├── CMakeLists.txt
│   └── main.cpp
└── mergeResultLib
    ├── CMakeLists.txt
    ├── include
    │   └── mergeResultLib
    │       └── mergeResult.h
    └── src
        ├── definitions.cpp
        └── mergeResult.cpp
```
