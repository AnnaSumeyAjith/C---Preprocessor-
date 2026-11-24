# C Preprocessor Implementation in C

## Project Overview

This project implements a basic C preprocessor using the C programming language. It takes a C source file as input, performs preprocessing operations, and generates a new file with the `.i` extension containing the preprocessed code.

The project is developed using modular programming, with separate source files for comment removal, file inclusion, and macro substitution.

## Features

The preprocessor supports the following operations:

- **Comment Removal:** Removes single-line (`//`) and multi-line (`/* ... */`) comments from the source code while preserving newline characters.
- **File Inclusion:** Reads user-defined header files specified using `#include <filename>` and replaces the include directive with the contents of the header file.
- **Object-like Macros:** Supports simple macro definitions using `#define` and replaces macro names with their corresponding values.
- **Function-like Macros:** Supports function-like macros with a single argument, such as `#define SQUARE(x) ((x)*(x))`.

## Technologies Used

- C Programming Language
- GCC Compiler
- Makefile
- Visual Studio Code
- Git and GitHub

## Project Structure

```text
C-Preprocessor/
│
├── main.c
├── preprocessor.h
├── comment_removal.c
├── file_inclusion.c
├── macro_handler.c
├── Makefile
├── input.c
├── myheader.h
├── .gitignore
└── README.md
```

### File Description

| File | Description |
|---|---|
| `main.c` | Main program that controls the preprocessing sequence and generates the output file. |
| `preprocessor.h` | Contains function declarations and required header files. |
| `comment_removal.c` | Implements comment removal. |
| `file_inclusion.c` | Handles user-defined header file inclusion. |
| `macro_handler.c` | Handles macro definitions and substitutions. |
| `Makefile` | Automates compilation and linking of the source files. |
| `input.c` | Sample C source file used for testing. |
| `myheader.h` | Sample user-defined header file. |

## Compilation

Make sure GCC and GNU Make are installed.

Open the project directory in the terminal and execute:

```bash
make
```

This compiles the source files and generates the executable `mypreprocessor`.

## Execution

Run the executable by providing the input C filename as a command-line argument:

```bash
./mypreprocessor input.c
```

On Windows PowerShell, use:

```powershell
.\mypreprocessor.exe input.c
```

The preprocessor generates an output file named `input.i` containing the preprocessed code.

## Sample Input

```c
#include <myheader.h>

#define PI 3.14
#define MAX 100
#define SQUARE(x) ((x)*(x))

// Single-line comment

int main()
{
    /* Multi-line comment */

    int limit = MAX;
    float area = PI * SQUARE(5);
    int result = SQUARE(10);

    return 0;
}
```

## Limitations

- Supports user-defined header files available in the current working directory.
- Does not support automatic searching of standard system header directories.
- Function-like macro support is limited to a single argument.
- Does not implement all features of the standard C preprocessor.

## Learning Outcomes

- Understanding the basic working of a C preprocessor.
- Implementing file handling operations in C.
- Working with macros and string manipulation.
- Applying modular programming using multiple C source and header files.
- Using Makefile for compilation and linking.
- Managing source code using Git and GitHub.
