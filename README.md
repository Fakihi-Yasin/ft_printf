# ft_printf
# ft_printf

*This project has been created as part of the 42 curriculum by [Your Name], [Collaborator Name if any].*

---

## Description

**ft_printf** is a custom implementation of the standard C library function `printf`. The goal of this project is to understand and implement variadic functions, format string parsing, and output formatting at a low level.

The project requires implementing a function that mimics the behavior of `printf` by:
- Accepting a variable number of arguments using variadic functions (`...`)
- Parsing a format string to identify conversion specifiers
- Converting and printing arguments according to their type
- Returning the total number of characters printed

### Mandatory Conversions

The following conversions must be implemented:

| Specifier | Description |
|-----------|-------------|
| `%c` | Print a single character |
| `%s` | Print a string |
| `%p` | Print a pointer address in hexadecimal format |
| `%d` | Print a signed decimal integer |
| `%i` | Print a signed integer (same as `%d`) |
| `%u` | Print an unsigned decimal integer |
| `%x` | Print a number in lowercase hexadecimal |
| `%X` | Print a number in uppercase hexadecimal |
| `%%` | Print a literal percent sign |

---


### Compilation

To compile the library:

```bash
make
```

This will generate `libftprintf.a`.

### Compilation Flags

The project is compiled with:
```bash
cc -Wall -Wextra -Werror
```
### Example Usage

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Character: %c\n", 'A');
    ft_printf("String: %s\n", "Hello, World!");
    ft_printf("Pointer: %p\n", &main);
    ft_printf("Decimal: %d\n", 42);
    ft_printf("Integer: %i\n", -42);
    ft_printf("Unsigned: %u\n", 4294967295u);
    ft_printf("Hex (lower): %x\n", 255);
    ft_printf("Hex (upper): %X\n", 255);
    ft_printf("Percent: %%\n");
    
    return 0;
}
```

### Makefile Rules

- `make` or `make all`: Compile the library
- `make clean`: Remove object files
- `make fclean`: Remove object files and the library
- `make re`: Recompile everything from scratch

---



---

## Understanding Variadic Functions (Technical Deep Dive)

### What is a Variadic Function?

A variadic function accepts a variable number of arguments:

```c
int ft_printf(const char *format, ...);
```

The `...` syntax indicates that additional arguments may follow.

### How Arguments are Passed (x86-64 Architecture)

On x86-64 Linux, arguments are passed in:

**Integer/Pointer Arguments:**
1. RDI (1st argument)
2. RSI (2nd argument)
3. RDX (3rd argument)
4. RCX (4th argument)
5. R8 (5th argument)
6. R9 (6th argument)
7. Stack (7th+ arguments)

**Floating-Point Arguments:**
1. XMM0 (1st float/double)
2. XMM1 (2nd float/double)
3. ... through XMM7 (8th float/double)
4. Stack (9th+ floats)

### The va_list Structure (x86-64)

```c
typedef struct {
    unsigned int gp_offset;      // Offset for integer registers
    unsigned int fp_offset;      // Offset for float registers
    void *overflow_arg_area;     // Pointer to stack arguments
    void *reg_save_area;         // Pointer to saved registers
} va_list[1];
```

### Register Save Area Explained

When a variadic function is called, the compiler automatically saves register arguments to memory:

```assembly
ft_printf:
    ; Save integer registers to stack
    mov [rbp-48], rdi    ; Save 1st arg
    mov [rbp-40], rsi    ; Save 2nd arg
    mov [rbp-32], rdx    ; Save 3rd arg
    mov [rbp-24], rcx    ; Save 4th arg
    mov [rbp-16], r8     ; Save 5th arg
    mov [rbp-8],  r9     ; Save 6th arg
    
    ; Save float registers
    movaps [rbp-176], xmm0   ; Save 1st float
    ; ... etc
```

This creates `reg_save_area` - a memory copy of register values that persists even when registers get overwritten by other function calls.

---

## Resources

### Official Documentation
- [printf man page](https://man7.org/linux/man-pages/man3/printf.3.html) - Standard printf documentation
- [stdarg.h documentation](https://en.cppreference.com/w/c/variadic) - Variadic function macros

### Video Tutorials
- [Printf Implementation Explained](https://www.youtube.com/watch?v=Hb2m7htiKWM) - Visual walkthrough of printf implementation
- [Variadic Functions in C](https://www.youtube.com/watch?v=GUMlTlKvQq4) - Detailed video explanation of va_list, va_start, va_arg

---

## AI Usage

AI tools were used for the following purposes in this project:

### 1. **Understanding Variadic Functions**
- **Tools Used**: Claude (Anthropic) and ChatGPT (OpenAI)
- **Purpose**: Deep explanations of `va_list`, `va_start`, `va_arg`, and `va_end`
- **Specific Topics**:
  - x86-64 calling conventions and register usage
  - Register vs stack argument passing mechanisms
  - Type promotion rules (char→int, float→double)
  - Memory layout of va_list structure
  - Why everything becomes 8 bytes in registers
  - How reg_save_area works and why registers are copied to memory


---

## Project Structure

```
ft_printf/
├── ft_printf.c          # Main function and format parsing
├── ft_printf.h          # Header with function prototypes
├── ft_printf_utilis.c   # Helper functions
├── ft_putstr.c          # String output
├── ft_putnbr.c          # Decimal number output
├── ft_putnbr_unsigned.c # Unsigned number output
├── ft_puthex.c          # Hexadecimal conversion
├── ft_putptr.c          # Pointer address output
├── Makefile             # Compilation rules
└── README.md            # This file
```


## Bonus Features (If Implemented)

If bonus features are implemented, document them here:

- [ ] Field width (e.g., `%10d`)
- [ ] Precision (e.g., `%.5s`)
- [ ] Flags (`-`, `0`, `+`, ` `, `#`)
- [ ] Additional conversions

---

## License

This project is part of the 42 school curriculum and follows the school's academic policies.