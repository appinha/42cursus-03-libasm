<h1 align="center">
	42cursus' libasm
</h1>

<p align="center">
	<b><i>Development repo for 42cursus' libasm project</i></b><br>
	For further information about 42cursus and its projects, please refer to <a href="https://github.com/appinha/42cursus"><b>42cursus repo</b></a>.
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/appinha/42cursus-03-libasm?color=blueviolet" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/appinha/42cursus-03-libasm?color=blueviolet" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/appinha/42cursus-03-libasm?color=blue" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/appinha/42cursus-03-libasm?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/appinha/42cursus-03-libasm?color=brightgreen" />
</p>

<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#-index">Index</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Usage</a>
	<span> · </span>
	<a href="#-testing">Testing</a>
	<span> · </span>
	<a href="#-useful-links">Useful Links</a>
	<span> · </span>
	<a href="#-study-summary">Study Summary</a>
</h3>

---

## 🗣️ About

> _The aim of this project is to get familiar with assembly language._

For detailed information, refer to the [**subject of this project**](https://github.com/appinha/42cursus/tree/master/_PDFs).

> 🚀 **tldr:** this project consists of coding basic functions (see below) in _Linux x86-64 Assembly (Intel syntax)_, which are then compiled into a library for use in C language code.

**Mandatory:**
```C
size_t		ft_strlen(const char *s);
char		*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t		ft_write(int fd, const void *buf, size_t count);
ssize_t		ft_read(int fd, void *buf, size_t count);
char		*ft_strdup(const char *s1);
```

**Bonus:**
```C
typedef struct	s_list
{
	void		*data;
	struct s_list	*next;
}		t_list;

int		ft_atoi_base(char const *str, char const *base);
void		ft_list_push_front(t_list **begin_list, void *data);
int		ft_list_size(t_list *begin_list);
void		ft_list_sort(t_list **begin_list,int (*cmp)());
void		ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void*));
```

## 📑 Index

`@root`

* [**Makefile**](Makefile) - contains instructions for compiling the library and testing it.

`@/includes/`

* [**libasm.h**](includes/libasm.h) - library header.
* [**tests.h**](includes/tests.h) - header for the test suit.

`@/srcs/`

* [**\*.s**](srcs/) - source code (in assembly language).

`@/tests/`

* [**\*.c**](tests/) - source code (in C language) for testing the library.
* [**\*.txt**](tests/) - auxiliary files for outputting the test.

## 🛠️ Usage

### Requirements

**1. Check system specification**

Each assembly language is specific to a particular computer architecture. In this project, we write **`64 bits ASM`** code. Thus, a **`x86_64 GNU/Linux`** system is required. To print all system information and check if your system specification fits, run `uname -a`.

```shell
$ uname -a
Linux APPinha-092019 4.4.0-18362-Microsoft #1049-Microsoft Thu Aug 14 12:01:00 PST 2020 x86_64 x86_64 x86_64 GNU/Linux
```
_Usage example_

**2. Install requirements**

To compile assembly code, an _assembler_ is required. To install the `nasm` assembler, run:

```shell
$ sudo apt-get install nasm
```

### Instructions

**1. Compiling the library**

To compile the library, run:

```shell
$ make
```

**2. Using it in your code**

To use the library functions in your code, simply include its header:

```C
#include "libasm.h"
```

and, when compiling your code, add the required flags:

```shell
-lasm -L path/to/libasm.a -I path/to/libasm.h
```

## 📋 Testing

After compiling the library with `make`, you can either run:

```shell
$ make test_all
```

or, for single function testing, run:

```shell
$ make <function name>
```

## 📌 Useful Links

* [NASM Tutorial](https://cs.lmu.edu/~ray/notes/nasmtutorial/)
* [Tutorial playlist: x86_64 Linux Assembly](https://www.youtube.com/playlist?list=PLetF-YjXm-sCH6FrTz4AQhfH6INDQvQSn)
* [X86 64 Register and Instruction Quick Start](https://wiki.cdot.senecacollege.ca/wiki/X86_64_Register_and_Instruction_Quick_Start)
* [x86_64 NASM Assembly Quick Reference ("Cheat Sheet")](https://www.cs.uaf.edu/2017/fall/cs301/reference/x86_64.html)
* [Linux System Call Table for x86 64](https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/)
* [NASM - The Netwide Assembler (Official Documentation)](https://www.nasm.us/doc/)

## 🤓 Study Summary

The **Netwide Assembler (NASM)** is an assembler and disassembler for the _Intel x86 architecture_. It can be used to write 16-bit, 32-bit (IA-32) and 64-bit (x86-64) programs. NASM is considered to be one of the most popular assemblers for Linux. - _Source: [Wikipedia](https://en.wikipedia.org/wiki/Netwide_Assembler#:~:text=The%20Netwide%20Assembler%20(NASM)%20is,most%20popular%20assemblers%20for%20Linux.)_

### Structure of a NASM Program

NASM is **line-based**. Most programs consist of **directives** followed by one or more **sections**. Lines can have an optional **label**. Most lines have an **instruction** followed by zero or more **operands**.

The sections are:

* **`.data` section** - where all data is defined before compilation.
* **`.bss` section** - where data is allocated for future use.
* **`.text` section** - where the actual code goes.

**Basic example file**

```asm
#LABELS		#INSTRUCTIONS	#OPERANDS

		global		start

		section		.text
start:
		mov		rax, 1		; syscall ID for sys_write
		mov		rdi, 1		; ARG1 #fd
		mov		rsi, text	; ARG2 $buffer
		mov		rdx, 14		; ARG3 #count
		syscall
		mov		rax, 60		; syscall ID for sys_exit
		mov		rdi, 0		; ARG1 #errcode
		syscall

		section		.data
text		db		"Hello, world!",10
```

_Notes:_

* _`text` - label of address in memory where data is located in._
* _`db` - "define bytes", a pseudo-instruction that declares bytes that will be in memory when the program runs_
* _`,10` - \n_

### Operands

There are three kinds of operands used in instructions:

* **register operands** - read more in the next section.
* **memory operands** - for manipulating data stored in memory.
* **immediate operands** - immediate values, can be written in many ways (decimal, hex, octal, binary).

### Registers

Registers are a part of the processor that temporarily holds memory. In the x86_64 architecture, registers hold 64 bits.

The 64-bit versions of the 'original' x86 registers are named:

* `rax` - register a extended; stores syscall IDs and return values.
* `rbx` - register b extended.
* `rcx` - register c extended; some instructions use it as a counter.
* `rdx` - register d extended.
* `rbp` - register base pointer; start of stack (stack's base).
* `rsp` - register stack pointer; current location in stack (stack's top), growing downwards.
* `rsi` - register source index; source for data copies; used to pass function argument #2.
* `rdi` - register destination index; destination for data copies; used to pass function argument #1.

The registers added for 64-bit mode are named in numbered sequence: `r8`, `r9`, `r10`, `r11`, `r12`, `r13`, `r14`, `r15`

**Types of Registers**

There are two types of registers: _"scratch"_ and _"preserved"_. **Scratch** registers may be used by any function and are allowed to be overwritten. **Preserved** registers can also be used by functions, but their content must be saved and restored afterwards.

| Name	| Type		| 64-bit long	| 32-bit int	| 16-bit short	| 8-bit char
|:-:	|:-:						|:-:			|:-:			|:-:			|:-:
| `rax`	| scratch / syscall ID and return	| rax	| eax	| ax	| ah and al
| `rbx`	| preserved					| rbx	| ebx	| bx	| bh and bl
| `rcx`	| scratch / 4th argument or counter	| rcx	| ecx	| cx	| ch and cl
| `rdx`	| scratch / 3rd argument	| rdx	| edx	| dx	| dh and dl
| `rsp`	| preserved / stack's top	| rsp	| esp	| sp	| spl
| `rbp`	| preserved / stack's base	| rbp	| ebp	| bp	| bpl
| `rsi`	| scratch / 2nd argument	| rsi	| esi	| si	| sil
| `rdi`	| scratch / 1st argument	| rdi	| edi	| di	| dil
| `r8`	| scratch / 5th argument	| r8	| r8d	| r8w	| r8b
| `r9`	| scratch / 6th argument	| r9	| r9d	| r9w	| r9b
| `r10`	| scratch					| r10	| r10d	| r10w	| r10b
| `r11`	| scratch					| r11	| r11d	| r11w	| r11b
| `r12`	| preserved					| r12	| r12d	| r12w	| r12b
| `r13`	| preserved					| r13	| r13d	| r13w	| r13b
| `r14`	| preserved					| r14	| r14d	| r14w	| r14b
| `r15`	| preserved					| r15	| r15d	| r15w	| r15b

### Memory

These are the basic forms of addressing with memory operands:

* `[ number ]`
* `[ reg ]`
* `[ reg + reg*scale ]` - scale is 1, 2, 4, or 8 only
* `[ reg + number ]`
* `[ reg + reg*scale + number ]`

The number is called the **displacement**; the plain register is called the **base**; the register with the scale is called the **index**.

**Defining Data and Reserving Space / Memory Access**

| C datatypeBits	| Bytes	| Register	| Access Memory	| Allocate Memory
|:-:				|:-:	|:-:		|:-:			|:-:
| char				| 8		| 1			| al			| BYTE [ptr] db
| short				| 16	| 2			| ax			| WORD [ptr] dw
| int				| 32	| 4			| eax			| DWORD [ptr] dd
| long				| 64	| 8			| rax			| QWORD [ptr] dq

### Instructions

Most of the basic instructions have the following form:

* `add REG, REG`
* `add REG, MEM`
* `add REG, IMM`
* `add MEM, REG`
* `add MEM, IMM`

> Note: Instructions with two memory operands are extremely rare.

**Most used instructions**

* `mov DEST, SRC` - move data between registers, move data between registers and memory.
* `mov DEST, VAL` - load immediate data into registers.
* `movsx DEST, SRC` - writes to whole register.

_Examples:_ `mov rdx,rax` | `mov rdx,[123]` | `mov rax,4` | `movsx rax, ch`

* `push SRC` - insert onto the stack; useful for passing arguments, saving registers, etc.
* `pop DEST` - remove topmost value from the stack onto given register. Equivalent to `mov DEST, [rsp]`; `add 8, rsp`.

_Examples:_ `push rbp` | `pop rbp`

* `inc REG` - increment value in register (`i++`).
* `dec REG` - decrease value in register (`i--`).

_Examples:_ `inc rcx` | `dec rcx`

* `add DEST, SRC` - sum: _DEST = DEST + SRC_
* `sub DEST, SRC` - subtraction: _DEST = DEST - SRC_

_Examples:_ `add rax, rdx` | `add rax, 4` | `sub rax, rdx` | `sub rax, 4`

* `mul SRC` - multiplication (unsigned integers): _`rax` = `rax` * src_. High 64 bits of product (usually zero) go into `rdx`.
* `div src`	division: _`rax` = `rax` / src_ (ratio into `rax`, and the remainder into `rdx`). Bizarrely, on input rdx must be zero, or you get a SIGFPE.

 _Examples:_ `mul rdx` | `mul 6` | `mov rdx,0`; `div rcx` | `div 3`

* `and DEST, SRC` - bitwise AND operator: _DEST = DEST & SRC_
* `xor DEST, SRC` - bitwise XOR operator: _DEST = DEST ^ SRC_
* `xor REG, REG` - used for initializing register with 0. Same as `mov REG, 0` (but faster).

_Examples:_ `and rax, rdx` | `xor rax, rdx` | `xor rax, rax`

* `shr VAL, BITS` - bitshift a value right by a constant, or the low 8 bits of rcx ("cl"). Shift count MUST go in `rcx`, no other register will do.

 _Examples:_ `add rcx,4`; `shr rax,cl`

* `cmp A, B` - compare two values, setting flags that are used by the conditional jumps (below).
* `j* LABEL` - go to _label_ depending on result of previous comparison. Conditionals available: `je` (==), `jne` (!=), `jl` (<), `jle` (<=), `jge` (>=), `jg` (>), `jz` (= 0), `jnz` (!= 0), and many others. Also available in unsigned comparisons: `jb` (<), `jbe` (<=), `ja` (>), `jae` (>=).
* `jmp LABEL` - Go to the instruction _label_. Skips anything else in the way.

 _Examples:_ `cmp rax,10`; `jl loop_start` | `jmp post_mem`

* `call FT` - function call. Push the address of the next instruction and start executing function.
* `ret` - return. Pop the return program counter, and jump there. Ends a subroutine.

 _Examples:_ `call print_int` | `ret`

> _Note: for the `mov` instruction, a suffix can be appended indicating the _amount of data to be moved_ - e.g., `q` for **quadword** (64 bits), `d` for **doubleword** (32 bits), `w` for **word** (16 bits), or `b` for **byte** (8 bits)._

**Explained examples**

`mov #99,%r10` - load constant value 99 into r10
`mov %r10,%r11` - move data from r10 to r11
`mov %r10,(%r11)` - move data from r10 to address pointed to by r11
`mov (%r10),%r11` - move data from address pointed to by r10 to r10

`push %r10` - push r10 onto the stack
`pop %r10` - pop r10 off the stack

`inc %r10` - increment r10

`add %r10,%r11` - add r10 and r11, put result in r11
`add #5,%r10` - add 5 to r10, put result in r10

`mul %r10` - multiplies rax by r10, places result in rax and overflow in rdx

`div %r10` - divide rax by the given register (r10), places quotient into rax and remainder into rdx (rdx must be zero before this instruction)

`cmp %r10,%r11` - compare register r10 with register r11. The comparison sets flags in the processor status register which affect conditional jumps.
`cmp #99,%r11` - compare the number 99 with register r11. The comparison sets flags in the processor status register which affect conditional jumps.

`jmp label` - jump to label
`je label` - jump to label if equal
`jne label` - jump to label if not equal
`jl label` - jump to label if less
`jg label` - jump to label if greater

`ret` - routine from subroutine (counterpart to call)

`call label ` - call a subroutine / function / procedure

`syscall` - invoke a syscall

> _Note the syntax:_
>
> * _Register names are prefixed by %_
> * _Immediate (number) values are prefixed by #_
> * _Indirect memory access is indicated by (parenthesis)._
> * _Hexadecimal values are indicated by a 0x prefix._
> * _Character values are indicated by quotation marks. Escapes (such as '\n') are permitted._
> * _Data sources are given as the first argument (mov %r10,%r11 moves FROM r10 INTO r11)._

### System Call

A system call, or **syscall**, or function call, is when a program requests a service from the kernel. System calls will differ by operating system because different operating systems use different kernels. All syscalls have an ID (a number) associated with them. Syscalls also take arguments, i.e. a list of inputs.

Usage of **registers** in syscalls: a 64 bit Linux machine passes **function parameters** in `rdi`, `rsi`, `rdx`, `rcx`, `r8`, and `r9` (in this order). Any additional parameters get pushed on the stack. In summary:

* `rax` - **syscall ID**.
* `rdi`, `rsi`, `rdx`, `rcx`, `r8`, `r9` - first **six arguments** (in order); remaining arguments are on the stack.
* `rax` - **return value** (after syscall is finished).

**Linux x86-64 Syscall List** (non exaustive)

| syscall	| ID	| ARG1		| ARG2		| ARG3
|:--		|:-:	|:--		|:--		|:--
| sys_read	| 0		| #fd		| $buffer	| #count
| sys_write	| 1		| #fd		| $buffer	| #count
| sys_open	| 2		| $filename	| #flags	| #mode
| sys_close	| 3		| #fd		| -			| -
| sys_exit	| 60	| #errcode	| -			| -

> _Note the syntax:_
>
> * _Immediate (number) values are prefixed by #_
> * _Memory address to the data (stored in the register) are prefixed by $_

For more syscalls: [Linux System Call Table for x86 64](https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/)

### Calling Conventions

When writing code for 64-bit Linux that integrates with a C library, you must follow the calling conventions explained in the [AMD64 ABI Reference](http://www.x86-64.org/documentation/abi.pdf).

A brief summary:

>The caller uses registers to pass the first 6 arguments to the callee.  Given the arguments in left-to-right order, the order of registers used is: `%rdi`, `%rsi`, `%rdx`, `%rcx`, `%r8`, and `%r9`.  Any remaining arguments are passed on the stack in reverse order so that they can be popped off the stack in order.
>
>The callee is responsible for perserving the value of registers `%rbp` `%rbx`, and `%r12-r15`, as these registers are owned by the caller.  The remaining registers are owned by the callee.
>
>The callee places its return value in `%rax` and is responsible for cleaning up its local variables as well as for removing the return address from the stack.
>
>The `call`, `enter`, `leave` and `ret` instructions make it easy to follow this calling convention.

_\- Source: [X86-64 Architecture Guide](http://6.s081.scripts.mit.edu/sp18/x86-64-architecture-guide.html)_
