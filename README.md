## Usage
```sh
git submodule init
git submodule update

# Windows:
cmake . -B build -T ClangCL

# Linux:
CC=clang CXX=clang++ cmake . -B build -G Ninja
```
