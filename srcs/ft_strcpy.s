; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcpy.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;                                                      #+#    #+#              ;
;                                                     ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

; ------------------------------------------------------------------------------
;    FUNCTION PROTOTYPE (man 3 strcpy)
; char	*ft_strcpy(char *dst, const char *src)
;
;    INPUT
; 1st argument:	rdi -> char *dst
; 2nd argument:	rsi -> const char *src
;
;    OUTPUT
; return:		rax -> char *dst
; ------------------------------------------------------------------------------

	global		ft_strcpy

	section		.text

ft_strcpy:
	mov			rax, rdi			; char *ret = &dst
	mov			rcx, -1				; i = -1

.while_loop:
	inc			rcx					; i++
	mov			dh, byte[rsi + rcx]	; char tmp = src[i]
	mov			byte[rdi + rcx], dh	; dst[i] = tmp
	cmp byte	[rsi + rcx], 0
	jne			.while_loop			; while (s[i] != 0)
	ret								; return (ret)
