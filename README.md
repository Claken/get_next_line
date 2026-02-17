# GET NEXT LINE

A C function that reads a file descriptor line by line, returning one line per call while keeping unread data in a static buffer. </br>
This project is part of the 42 common core curriculum.

## 👩🏻‍🏫 What I gained from the project

- Managing persistent state with `static` variables across function calls.
- Handling low-level I/O with `read` and file descriptors.
- Building robust string/memory utilities and preventing leaks with careful `malloc`/`free` usage.
- Designing logic for edge cases (EOF, empty files, files without trailing newlines, and varying buffer sizes).

## 📦 Prerequisites

- A C compiler (`cc`/`gcc`/`clang`).
- Standard C library headers available on your system.
- Source files:
  - `get_next_line.c`
  - `get_next_line_utils.c`
  - `get_next_line.h`

## 🚀 Usage

This repository includes several sample `main` programs to test `get_next_line` in different scenarios.

### `main_one_file.c` (read one file)
Use this program to read a single file descriptor from start to end.

Compile:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main_one_file.c -o gnl_one
```

Run:
```bash
./gnl_one text_files/some_lines.txt
```

### `main_two_files.c` (read two files one after the other)
Use this one to verify that your implementation can manage multiple file descriptors.

Compile:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main_two_files.c -o gnl_two
```

Run:
```bash
./gnl_two text_files/some_lines.txt text_files/gnl.txt
```

### `main_fd_0.c` (read from standard input)
This program sets `fd = 0`, so `get_next_line` reads from stdin (your keyboard input).

Compile:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main_fd_0.c -o gnl_stdin
```

Run and type lines (use `Ctrl+D` to send EOF):
```bash
./gnl_stdin
```

### `main_1.c` (alternate reads across four files)
This test is useful to stress-check multi-fd behavior by alternating calls between 4 open files.

Compile:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main_1.c -o gnl_four
```

Run:
```bash
./gnl_four text_files/some_lines.txt text_files/gnl.txt text_files/dracula.txt text_files/baudelaire.txt
```

### `test.c` (manual/debug experiment)
`test.c` is a scratch/debug file that manually reproduces parts of the `get_next_line` logic. It is not the recommended main for normal usage but can help when debugging behavior step by step.

### Example output (`main_one_file.c`)
```bash
1 Ligne 1 : 0123
1 Ligne 2 : 01234567
1 Ligne 3 : 0123456789AEBCDF
1 Ligne 4 : 
0 Ligne 5 :
```
