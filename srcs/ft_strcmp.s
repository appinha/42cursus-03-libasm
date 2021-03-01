; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcmp.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;                                                      #+#    #+#              ;
;                                                     ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

; ------------------------------------------------------------------------------
;    FUNCTION PROTOTYPE (man 3 strcmp)
; int	ft_strcmp(const char *s1, const char *s2);
;
;    INPUT
; 1st argument:	rdi -> const char *s1
; 2nd argument:	rsi -> const char *s2
;
;    OUTPUT
; return:		rax -> int diff
; ------------------------------------------------------------------------------

	global		ft_strcmp

	section		.text

ft_strcmp:
	mov			rcx, -1					; i = -1

while_loop:
	inc			rcx						; i++;
	mov			r8b, byte[rdi + rcx]	; char tmp_1 = s1[i]
	mov			r9b, byte[rsi + rcx]	; char tmp_2 = s2[i]
	cmp			r8b, r9b
	jne			.return					; while ((s1[i] == s2[i]) && ...
	cmp			r8b, 0
	je			.return					; ... (s1[i] != '\0') && ...
	cmp			r9b, 0
	je			.return					; ... (s2[i] != '\0'))
	jmp			while_loop

.return:
	sub			r8b, r9b				; char tmp  = s1[i] - s2[i]
	movsx		rax, r8b				; ret = tmp
	ret
