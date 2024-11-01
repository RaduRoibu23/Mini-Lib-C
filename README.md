# Project Overview

This project is a simple C library implementation that provides basic system call wrappers, memory management, process control, and I/O operations. The codebase is organized into several directories, each focusing on a specific aspect of the library.

## Directory Structure

- `crt/`: Contains the C runtime startup code.
  - `__libc_start_main.c`: Initializes the library and calls the main function.
  - `start.asm`: Assembly code for the entry point of the program.

- `include/`: Contains header files for various functionalities.
  - `errno.h`: Defines error codes.
  - `fcntl.h`: Defines file control options.
  - `internal/`: Internal headers for architecture-specific and essential definitions.
    - `arch/x86_64/`: Architecture-specific syscall definitions.
    - `mm/`: Memory management headers.z
  - `sys/`: System-specific headers.
  - `stdlib.h`: Standard library functions like `malloc`, `free`, etc.

- `io/`: Contains I/O related functions.
  - `open.c`, `close.c`, `read_write.c`, `puts.c`, etc.

- `mm/`: Contains memory management functions.
  - `malloc.c`, `mmap.c`, `mem_list.c`, etc.

- `process/`: Contains process control functions.
  - `exit.c`, `sleep.c`, etc.

- `stat/`: Contains file status functions.
  - `fstat.c`, `fstatat.c`, `stat.c`, etc.

- `string/`: Contains string manipulation functions.
  - `string.c`

- `syscall.c`: Contains the syscall wrapper function.

## Key Components

### System Calls

System calls are wrapped in the function [`__syscall`](include/internal/arch/x86_64/syscall_arch.h) which is defined in the architecture-specific header file.

### Memory Management

Memory management functions like `malloc`, `free`, `mmap`, and `munmap` are implemented in the [`mm`](mm) directory. These functions use system calls to allocate and manage memory.

### Process Control

Process control functions like `exit` and `sleep` are implemented in the [`process`](process) directory. These functions also use system calls to interact with the operating system.

### I/O Operations

I/O operations like `open`, `close`, `read`, `write`, and `puts` are implemented in the [`io`](io) directory. These functions provide basic file and console I/O capabilities.

## Build Instructions

To build the project, use the provided `Makefile`. The main target is `libc.a`, which is the static library containing all the compiled object files.
