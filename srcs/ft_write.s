; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_write.s                                         :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;                                                      #+#    #+#              ;
;                                                     ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

; ------------------------------------------------------------------------------
;    FUNCTION PROTOTYPE (man 2 write)
; ssize_t	ft_write(int fd, const void *buf, size_t count)
;
;    INPUT
; 1st argument:	rdi -> int fd
; 2nd argument:	rsi -> const void *buf
; 1rd argument:	rdx -> size_t count
;
;    OUTPUT
; return:		rax -> ssize_t count
; ------------------------------------------------------------------------------

	global	ft_write

	extern	__errno_location

	section	.text

ft_write:
	mov		rax, 1				; put 1 (syscall ID of write) into rax
	syscall						; ret = write(fd, buf, count)
	cmp		rax, 0				; compare return (in rax) with 0
	jl		ret_error			; if ret < 0 then ret_error()
	ret							; return (ret)

ret_error:
	mov		rdi, rax			; tmp = ret
	neg		rdi					; tmp = -tmp (invert value for positive errno)
	call	__errno_location	; ret = &errno (get pointer to errno)
	mov		[rax], rdi			; *ret = tmp (put return value into errno)
	mov		rax, -1				; ret = -1
	ret							; return (ret)
