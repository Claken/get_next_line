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

Compile the executable with this line:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main_2.c -o gnl
```
Choose a file among the `.txt` files inside the project:
```bash
./gnl some_lines.txt
```
The output will be this:
```bash
1 Ligne 1 : 0123
1 Ligne 2 : 01234567
1 Ligne 3 : 0123456789AEBCDF
1 Ligne 4 : 
0 Ligne 5 :
```
You can replace `main_2.c` with your own tester that calls:

```c
int get_next_line(int fd, char **line);
```
