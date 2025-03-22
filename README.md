# UBSAN for Custom Usage

This project implements a custom version of Undefined Behavior Sanitizer (UBSAN) for specialized environments such as MUSL, embedded systems, and kernel modules. The implementation is based on the original UBSAN code and is intended to detect undefined behaviors like integer overflows, null pointer dereferencing, misaligned memory accesses, and more.

## Features

- Custom UBSAN implementation for specialized environments.
- Error reporting for various types of undefined behaviors.
- Includes support for:
  - Integer overflow (addition, subtraction, multiplication).
  - Division by zero or overflow.
  - Null pointer dereferencing.
  - Misaligned memory accesses.
  - Array index out-of-bounds.
  - Type mismatches.

## Directory Structure

```
/
├── include/
│   ├── linux/
│   │   ├── align.h
│   │   ├── atomic-gcc.h
│   │   ├── bits.h
│   │   └── ffs.h
│   └── uapi/
│       └── linux/
│           └── const.h
├── helper.h
├── main.c
├── Makefile
├── ubsan.c
├── ubsan.h
```

### Key Files

- **main.c**: The main program to test the UBSAN implementation. It demonstrates memory allocation and pointer manipulation, triggering undefined behavior that is caught by UBSAN.
- **ubsan.c**: Contains the core UBSAN error-handling functions. These functions are responsible for reporting various types of undefined behavior.
- **ubsan.h**: Header file that defines necessary structures and functions for UBSAN.
- **helper.h**: Contains helper functions used by the UBSAN error reporting.
- **Makefile**: A build system file for compiling the project.

## How to Build

1. Clone the repository or download the project files.
2. Navigate to the project directory.
3. Run the following command to build the project:

   ```bash
   make
   ```

4. This will compile the source code and generate the `main` executable and other object files (`ubsan.o`, etc.).

## How to Test

The `main.c` file contains a simple test case that triggers undefined behavior by performing pointer manipulation. When you run the `main` executable, UBSAN will catch the undefined behavior and print out error messages, such as:

```bash
Test!
UBSAN: signed-integer-overflow in main.c:10:5
```

To run the test, use:

```bash
./main
```

## Error Reporting

When UBSAN detects undefined behavior, it reports the error with details such as:

- The type of error (e.g., integer overflow, null pointer dereference).
- The file and line number where the error occurred.
- Additional information about the error (e.g., the values involved in the overflow or invalid load).

The reports are printed to `stderr` and provide useful diagnostics to help track down and fix the issues.

## Supported Environments

This implementation is designed to work in the following environments:

- **MUSL**: A lightweight C standard library for Linux-based systems.
- **Embedded Systems**: Custom applications in embedded environments where detecting undefined behavior is crucial.
- **Kernel Modules**: It can be integrated into Linux kernel modules to catch undefined behavior in kernel space.

## Acknowledgements

This implementation is based on the original UBSAN code in the Linux kernel, with modifications for custom environments. Special thanks to the authors and maintainers of the Linux kernel UBSAN code.
