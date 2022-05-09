# A basic Compile Demo

## Makefile编译

### 直接通过目标文件生成

```bash
mkdir libs
gcc -c ./files1/max_score.cc -o ./libs/max_score.o -Iincludes1 -Ibase // -I表示头文件所在的目录
gcc -c ./files2/mean.cc -o ./libs/mean.o -Iincludes2 -Ibase
g++ main.cc -o ./bin/main -Iincludes1 -Iincludes2 -Ibase ./libs/max_score.o ./libs/mean.o
```

### 以静态库方式编译

把`.o`文件归档为静态库，在demo下运行命令

```bash
ar -crv ./libs/libtools.a ./libs/*.o
```

编译成可执行文件

```bash
mkdir bin
// -L表示库所在的目录，-l表示要链接的库名字
g++ main.cpp -o ./bin/main -Iincludes1 -Iincludes2 -Ibase -L./libs/ -ltools

// 上面是缩写，编译器会自动查找，下面是全写
g++ main.cpp -o ./bin/main -Iincludes1 -Iincludes2 -Ibase ./libs/libtools.a
```

### 编译动态库并调用

```bash
// PIC(procedure independent code)
gcc --share -fPIC -o ./libs/libtools.so ./files1/*.cc ./files2/*.cc -Iincludes2 -Iincludes1 -Ibase

export LD_LIBRARY_PATH=./libs:$LD_LIBRARY_PATH  // 指定动态库路径，未指定会导致ldd找不到动态库

// libtools.a 和 libtools.so 同时存在时，编译可执行文件的时候，会默认自动调用libs下的动态库
g++ main.cc -o ./bin/main -Iincludes1 -Iincludes2 -Ibase -L./libs/ -ltools

// 强制使用静态库加上-static
g++ main.cpp -o ./bin/main -Iincludes1 -Iincludes2 -Ibase -static -L./libs/ -ltools
```

## CMake编译

见CMakeLists.txt的注释
