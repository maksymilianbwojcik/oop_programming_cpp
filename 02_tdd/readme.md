# 02 TDD

## Manual compilation

```bash
mkdir build && cd build
cmake ../
make -j4
```

## Compilation from CLion

```bash
File -> Open... -> [Select directory with CMakeLists.txt]
```

## Google Test

Remember that test libraries need to be also compiled.

```bash
cd ../googletest/
mkdir build && cd build
cmake ../
make -j4
```

