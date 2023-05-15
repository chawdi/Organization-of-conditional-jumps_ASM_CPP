; nasm -f elf64 name.asm
; ld -o name name.o
; lab 2, variant 18, unsigned word version
; (a + 6) / b    , a > b
; 6              , a = b
; (12 + a) / b   , a < b
section .data
extern a, b, result

section .text
global calculate_asm

calculate_asm:
	mov ax, [a]
	mov bx, [b]
	cmp ax, bx
	jb less
	ja greater
	je equal
less:
	add ax, 12
	jmp proceed
greater:
	add ax, 6
proceed:
	xor dx,dx
	div bx
	mov [result], ax
	jmp exit
equal:
	mov [result], word 6
	jmp exit
exit:	
	ret ; ret returns to main()
