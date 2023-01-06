# BetterString
Better String is a C library to improve dinamically allocated string handling. It provides a `BtrStr` structure that contains a c string and the lenght of the string. (More string related info might be added later)

## Installation

1. Clone the repository:
```sh
git clone https://github.com/RuiFPB/betterStringC.git
```

2. Change to the directory:
```sh
cd betterStringC
```

3. Compile and install using make:
```sh
make
sudo make install
```

To change the install location you can use `PREFIX=/your/install/location` to specify the location. (default is /usr/local)
  
To change the C compiler used: `CC=clang` (default is gcc)
  
To change compiler arguments: `CFLAGS="-Wall -Wextra -Werror -pedantic -std=c99 -O3"` (These are the defaults)
  
(Example: `sudo make install CC=clang PREFIX=~/.local/`)
  
Run `make help` to see all available make commands

## Usage
To use Better String on a C project, you will need to include the `btrString.h` header file and link with the `btrString` library.

Example:

```c
// FILE : main.c
#include <stdio.h>
#include <btrString.h>

int main() {
    BtrStr *s = btrStr_new("Hello, World!");
    
    printf("%s\n", btrStr_cstr(s));
    // or
    printf("%s\n", s->str);
    
    // Do not forget to delete the string if it is no longer needed
    btrStr_delete(s);
    return 0;
}
```

Compile with:
```sh
gcc main.c -o helloworld -lbtrString
```
or, if you installed the library on a different location:
```sh
gcc main.c -o helloworld -L/your/install/location -lbtrString
```
 
For more info about the functions, check the `btrString.h` header file
