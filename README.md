# GET NEXT LINE

A C function that reads a file descriptor line by line, returning one line per call while keeping unread data in a static buffer.

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

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main_2.c -o gnl
./gnl
```

You can replace `main_2.c` with your own tester that calls:

```c
int get_next_line(int fd, char **line);
```
