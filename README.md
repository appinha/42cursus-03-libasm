# 42cursus' libasm

![Code size in bytes](https://img.shields.io/github/languages/code-size/appinha/42cursus-03-libasm?color=blueviolet)
![Number of lines of code](https://img.shields.io/tokei/lines/github/appinha/42cursus-03-libasm?color=blueviolet)
![Code language count](https://img.shields.io/github/languages/count/appinha/42cursus-03-libasm?color=blue)
![GitHub top language](https://img.shields.io/github/languages/top/appinha/42cursus-03-libasm?color=blue)
![GitHub last commit](https://img.shields.io/github/last-commit/appinha/42cursus-03-libasm?color=brightgreen)

_Development repo for 42cursus' **libasm** project_

For further information about **42cursus** and its projects, please refer to [42cursus repo](https://github.com/appinha/42cursus).

## Table of contents

1. [About](#about)
1. [Index](#index)
2. [Usage](#usage)
3. [Testing](#testing)
4. [Useful Links](useful-links)
5. [Study Summary](study-summary)

---

## About

> _The aim of this project is to get familiar with assembly language._

📃 Detailed information: [subject of this project](https://github.com/appinha/42cursus/tree/master/_PDFs)

**tldr:** recoding `libc` functions in Linux x86-64 Intel Assembly

## Index

`@root`

* [**Makefile**](Makefile) - contains instructions for compiling the library and testing it.

`@/includes/`

* [**libasm.h**](includes/libasm.h) - library header.

`@/srcs/`

* **\*.s** - source code (in assembly language).

`@/tests/`

* [**main.c**](main.c) - source code (in C language) for testing the library.

## Usage

### Requirements

**1. Check system specification**

Each assembly language is specific to a particular computer architecture. In this project, we write **`64 bits ASM`** code. Thus, a **`x86_64 GNU/Linux`** system is required. To print all system information and check if your system specification fits, run `uname -a`.

```shell
$ uname -a
Linux APPinha-092019 4.4.0-18362-Microsoft #1049-Microsoft Thu Aug 14 12:01:00 PST 2020 x86_64 x86_64 x86_64 GNU/Linux
```
_Usage example_

**2. Install requirements**

To compile assembly code, an _assembler_ is required. To install `nasm` assembler, run:

```shell
$ sudo apt-get install nasm
```

### Instructions

**1. Compiling the library**

To compile, run:

```shell
$ make
```

### Testing

After compiling the library with `make`, simply run:

```shell
$ make test
```

---

## Useful Links

* [Tutorial playlist: x86_64 Linux Assembly](https://www.youtube.com/playlist?list=PLetF-YjXm-sCH6FrTz4AQhfH6INDQvQSn)
* [X86 64 Register and Instruction Quick Start](https://wiki.cdot.senecacollege.ca/wiki/X86_64_Register_and_Instruction_Quick_Start)
* [x86_64 NASM Assembly Quick Reference ("Cheat Sheet")](https://www.cs.uaf.edu/2017/fall/cs301/reference/x86_64.html)

## Study Summary

### Registers

Registers are a part of the processor that temporarily holds memory. In the x86_64 architecture, registers hold 64 bits.

The 64-bit versions of the 'original' x86 registers are named:

* `rax` - register a extended; stores syscall IDs and return values.
* `rbx` - register b extended.
* `rcx` - register c extended; some instructions use it as a counter.
* `rdx` - register d extended.
* `rbp` - register base pointer; start of stack.
* `rsp` - register stack pointer; current location in stack (stack's top), growing downwards.
* `rsi` - register source index; source for data copies; used to pass function argument #2.
* `rdi` - register destination index; destination for data copies; used to pass function argument #1.

The registers added for 64-bit mode are named in numbered sequence: `r8`, `r9`, `r10`, `r11`, `r12`, `r13`, `r14`, `r15`

**Types of Registers**

There are two types of registers: _"scratch"_ and _"preserved"_. **Scratch** registers may be used by any function and are allowed to be overwritten. **Preserved** registers can also be used by functions, but their content must be saved and restored afterwards.

| Name	| Type		| 64-bit long	| 32-bit int	| 16-bit short	| 8-bit char
|:-:	|:-:		|:-:			|:-:			|:-:			|:-:
| `rax`	| scratch	| rax	| eax	| ax	| ah and al
| `rbx`	| preserved	| rbx	| ebx	| bx	| bh and bl
| `rcx`	| scratch	| rcx	| ecx	| cx	| ch and cl
| `rdx`	| scratch	| rdx	| edx	| dx	| dh and dl
| `rsp`	| preserved	| rsp	| esp	| sp	| spl
| `rbp`	| preserved	| rbp	| ebp	| bp	| bpl
| `rsi`	| scratch	| rsi	| esi	| si	| sil
| `rdi`	| scratch	| rdi	| edi	| di	| dil
| `r8`	| scratch	| r8	| r8d	| r8w	| r8b
| `r9`	| scratch	| r9	| r9d	| r9w	| r9b
| `r10`	| scratch	| r10	| r10d	| r10w	| r10b
| `r11`	| scratch	| r11	| r11d	| r11w	| r11b
| `r12`	| preserved	| r12	| r12d	| r12w	| r12b
| `r13`	| preserved	| r13	| r13d	| r13w	| r13b
| `r14`	| preserved	| r14	| r14d	| r14w	| r14b
| `r15`	| preserved	| r15	| r15d	| r15w	| r15b

### System Call

A system call, or **syscall**, or function call, is when a program requests a service from the kernel. System calls will differ by operating system because different operating systems use different kernels. All syscalls have an ID (a number) associated with them. Syscalls also take arguments, i.e. a list of inputs.

Usage of **registers** in syscalls: a 64 bit Linux machine passes **function parameters** in `rdi`, `rsi`, `rdx`, `rcx`, `r8`, and `r9`. Any additional parameters get pushed on the stack.

* `rax` - **syscall ID**.
* `rdi`, `rsi`, `rdx`, `rcx`, `r8`, `r9` - first **six arguments**; remaining arguments are on the stack.
* `rax` - **return value** (after syscall is finished).

**Syscall List**

| syscall	| ID	| ARG1		| ARG2		| ARG3
|:--		|:-:	|:--		|:--		|:--
| sys_read	| 0		| #fd		| $buffer	| #count
| sys_write	| 1		| #fd		| $buffer	| #count
| sys_open	| 2		| $filename	| #flags	| #mode
| sys_close	| 3		| #fd		| -			| -
| sys_exit	| 60	| #errcode	| -			| -

_Note the syntax:_

* _Immediate (number) values are prefixed by #_
* _Memory address to the data (stored in the register) are prefixed by $_

### Instructions

| Mnemonic	| Purpose	| Examples
|:--		|:--		|:--
| mov _dest,src_	| Move data between registers, load immediate data into registers, move data between registers and memory.	| `mov rax,4`</br>`mov rdx,rax`</br>`mov rdx,[123]`
| push _src_	| Insert a value onto the stack. Useful for passing arguments, saving registers, etc.	| `push rbp`
| pop _dest_	| Remove topmost value from the stack. Equivalent to "mov _dest_, [rsp]; add 8,rsp"	| `pop rbp`
| add _dest,src_	| _dest = dest + src_	| `add rax,rdx`
| mul _src_	| Multiply rax and _src_ as unsigned integers, and put the result in rax. High 64 bits of product (usually zero) go into rdx.	| `mul rdx`
| div _src_	| Divide rax by _src_, and put the ratio into rax, and the remainder into rdx. Bizarrely, on input rdx must be zero, or you get a SIGFPE.	| `mov rdx,0`</br>`div rcx`
| shr _val,bits_	| Bitshift a value right by a constant, or the low 8 bits of rcx ("cl"). Shift count MUST go in rcx, no other register will do!	| `add rcx,4`</br>`shr rax,cl`
| jmp _label_	| Go to the instruction _label_. Skips anything else in the way.	| `jmp post_mem`
| cmp _a,b_	| Compare two values. Sets flags that are used by the conditional jumps (below).	| `cmp rax,10`
| jl _label_	| Go to _label_ if previous comparison came out as less-than. Other conditionals available are: jle (<=), je (==), jge (>=), jg (>), jne (!=), and many others. Also available in unsigned comparisons: jb (<), jbe (<=), ja (>), jae (>=).	| `jl loop_start`
| call _func_	| Push the address of the next instruction and start executing func.	| `call print_int`
| ret	| Pop the return program counter, and jump there. Ends a subroutine.	| `ret`

**Note:** for the `mov` instruction, a suffix can be appended indicating the _amount of data to be moved_ -- e.g., `q` for **quadword** (64 bits), `d` for **doubleword** (32 bits), `w` for **word** (16 bits), or `b` for **byte** (8 bits).

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

`div %r10` - divide rax by the given register (r10), places quotient into rax and remainder into rdx (rdx must be zero before this instruction)

`mul %r10` - multiplies rax by r10, places result in rax and overflow in rdx

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

_Note the syntax:_

* _Register names are prefixed by %_
* _Immediate (number) values are prefixed by #_
* _Indirect memory access is indicated by (parenthesis)._
* _Hexadecimal values are indicated by a 0x prefix._
* _Character values are indicated by quotation marks. Escapes (such as '\n') are permitted._
* _Data sources are given as the first argument (mov %r10,%r11 moves FROM r10 INTO r11)._

### Memory access

| C datatype| Bits	| Bytes	| Register	| Access memory	| Allocate memory
|:-:		|:-:	|:-:	|:-:		|:-:			|:-:
| char		| 8		| 1		| al		| BYTE [ptr]	| db
| short		| 16	| 2		| ax		| WORD [ptr]	| dw
| int		| 32	| 4		| eax		| DWORD [ptr]	| dd
| long		| 64	| 8		| rax		| QWORD [ptr]	| dq

### Sections

All x86_64 assembly files have three sections:

* `.data` section - where all data is defined before compilation.
* `.bss` section - where data is allocated for future use.
* `.text` section - where the actual code goes.

**Basic example file**

```asm
section	.data
	text	db	"Hello, world!",10

section	.text
	global	_start

_start:
	mov rax, 1		; syscall ID for sys_write
	mov rdi, 1		; ARG1 #fd
	mov rsi, text	; ARG2 $buffer
	mov rdx, 14		; ARG3 #count
	syscall

	mov rax, 60		; syscall ID for sys_exit
	mov rdi, 0		; ARG1 #errcode
	syscall
```

_Notes:_

* _`text` - label of address in memory where data is located in._
* _`db` - define bytes_
* _`,10` - \n_
