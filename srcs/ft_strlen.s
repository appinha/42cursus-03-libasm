; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strlen.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;                                                      #+#    #+#              ;
;                                                     ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

;    FUNCTION PROTOTYPE
; size_t	ft_strlen(const char *s)
; More info: man 3 strlen

;    INPUT
; 1st argument:	rdi -> const char *s

;    OUTPUT
; return:		rax -> size_t len

global		ft_strlen

section		.text

ft_strlen:
	mov rax, -1				; i = -1

while_loop:
	inc rax					; i++
	cmp byte [rdi + rax], 0	; compare s[i] with 0
	jne while_loop			; while (s[i] != 0)
	ret						; return (i)
