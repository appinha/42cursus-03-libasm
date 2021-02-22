; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_read.s                                          :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;                                                      #+#    #+#              ;
;                                                     ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

;    FUNCTION PROTOTYPE
; ssize_t	ft_read(int fd, void *buf, size_t count)
; More info: man 2 read

;    INPUT
; 1st argument:	rdi -> int fd
; 2nd argument:	rsi -> const void *buf
; 1rd argument:	rdx -> size_t count

;    OUTPUT
; return:		rax -> ssize_t count

global		ft_read

extern		__errno_location

section		.text

ft_read:
	mov rax, 0				; put 0 (syscall ID of read) into rax
	syscall					; ret = read(fd, buf, count)
	cmp rax, 0				; compare return (in rax) with 0
	jl ret_error			; if ret < 0 then ret_error()
	ret						; return (ret)

ret_error:
	mov rdi, rax			; tmp = ret
	neg rdi					; tmp = -tmp (invert value for positive errno)
	call __errno_location	; ret = &errno (get pointer to errno)
	mov [rax], rdi			; *ret = tmp (put return value into errno)
	mov rax, -1				; ret = -1
	ret						; return (ret)
