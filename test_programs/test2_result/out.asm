ORG 100h

JMP proc_main
section .data
	_constant0 db 'Using for-loop:', '$'
	_constant1 dw 1
	_constant2 dw 0
	_constant3 dw 2
	_constant4 db '%d', '$'
	_constant5 db ' ', '$'
	_constant6 db 'Using while-loop:', '$'
	_constant7 db 'Using do-while-loop:', '$'
	_constant8 db 'Enter a limit to print odd numbers below it: ', '$'
	_newline db 13, 10, '$'
section .bss
	printOddNumbers_limit: resb 4
	printOddNumbers_0_i: resb 4
	printOddNumbers_k: resb 4
	printOddNumbers_j: resb 4
	main_limit: resb 4

section .text
_proc_print_string:
	MOV dx, ax
	MOV ah, 09h
	INT 21h
	RET
_proc_print_number:
	MOV cx, 0
	MOV dx, 0
_print_number_label:
	CMP ax, 0
	JE _print_number_print
	MOV bx, 10
	DIV bx
	PUSH dx
	INC cx
	XOR dx, dx
	JMP _print_number_label
_print_number_print:
	CMP cx, 0
	JE _print_number_exit
	POP dx
	ADD dx, 48
	MOV ah, 02h
	INT 21h
	DEC cx
	JMP _print_number_print
_print_number_exit:
	RET
_proc_print_new_line:
	LEA ax, _newline
	MOV dx, ax
	MOV ah, 09h
	INT 21h
	RET
_proc_scan_number:
	MOV dx, 0
_scan_number_label:
	MOV ah, 01h
	INT 21h
	CMP al, 0dh
	JE _scan_number_exit
	CMP al, ' '
	JE _scan_number_exit
	MOV ah, 0
	SUB al, 48
	MOV bx, ax
	MOV ax, dx
	MOV dx, 10
	MUL dx
	ADD ax, bx
	MOV dx, ax
	JMP _scan_number_label
_scan_number_exit: 
	MOV ax, dx
	RET
proc_printOddNumbers:
	PUSH bp
	MOV bp, sp
	MOV ax, [bp + 4]
	MOV [printOddNumbers_limit], ax
	LEA ax, [_constant0]
	CALL _proc_print_string
	CALL _proc_print_new_line
	MOV ax, [_constant1]
	MOV bx, ax
	MOV [printOddNumbers_0_i], bx
_statement_label_0_cmp:
	MOV ax, [printOddNumbers_0_i]
	PUSH ax
	MOV ax, [printOddNumbers_limit]
	MOV bx, ax
	POP ax
	CMP ax, bx
	JLE _expre0_jump
	MOV ax, 0
	JMP _expre0_end
_expre0_jump:
	MOV ax, 1
_expre0_end:
	CMP ax, 1
	JNE _statement_label_0_exit
	MOV ax, [printOddNumbers_0_i]
	PUSH ax
	MOV ax, [_constant3]
	MOV bx, ax
	POP ax
	MOV dx, 0
	DIV bx
	MOV ax, dx
	PUSH ax
	MOV ax, [_constant2]
	MOV bx, ax
	POP ax
	CMP ax, bx
	JE _expre1_jump
	MOV ax, 0
	JMP _expre1_end
_expre1_jump:
	MOV ax, 1
_expre1_end:
	CMP ax, 1
	JNE _statement_label_1_jump1
	JMP _statement_label_0
_statement_label_1_jump1:
	MOV ax, [printOddNumbers_0_i]
	CALL _proc_print_number
	LEA ax, [_constant5]
	CALL _proc_print_string
	CALL _proc_print_new_line
_statement_label_0:
	MOV ax, [printOddNumbers_0_i]
	INC ax
	MOV [printOddNumbers_0_i], ax
	JMP _statement_label_0_cmp
_statement_label_0_exit:
	CALL _proc_print_new_line
	LEA ax, [_constant6]
	CALL _proc_print_string
	CALL _proc_print_new_line
	MOV ax, [_constant1]
	MOV bx, ax
	MOV [printOddNumbers_j], bx
_statement_label_2:
	MOV ax, [printOddNumbers_j]
	PUSH ax
	MOV ax, [printOddNumbers_limit]
	MOV bx, ax
	POP ax
	CMP ax, bx
	JLE _expre2_jump
	MOV ax, 0
	JMP _expre2_end
_expre2_jump:
	MOV ax, 1
_expre2_end:
	CMP ax, 1
	JNE _statement_label_2_exit
	MOV ax, [printOddNumbers_j]
	PUSH ax
	MOV ax, [_constant3]
	MOV bx, ax
	POP ax
	MOV dx, 0
	DIV bx
	MOV ax, dx
	PUSH ax
	MOV ax, [_constant2]
	MOV bx, ax
	POP ax
	CMP ax, bx
	JE _expre3_jump
	MOV ax, 0
	JMP _expre3_end
_expre3_jump:
	MOV ax, 1
_expre3_end:
	CMP ax, 1
	JNE _statement_label_3_jump1
	MOV ax, [printOddNumbers_j]
	INC ax
	MOV [printOddNumbers_j], ax
	JMP _statement_label_2
_statement_label_3_jump1:
	MOV ax, [printOddNumbers_j]
	CALL _proc_print_number
	LEA ax, [_constant5]
	CALL _proc_print_string
	CALL _proc_print_new_line
	MOV ax, [printOddNumbers_j]
	INC ax
	MOV [printOddNumbers_j], ax
	JMP _statement_label_2
_statement_label_2_exit:
	CALL _proc_print_new_line
	LEA ax, [_constant7]
	CALL _proc_print_string
	CALL _proc_print_new_line
	MOV ax, [_constant1]
	MOV bx, ax
	MOV [printOddNumbers_k], bx
_statement_label_4_do:
	MOV ax, [printOddNumbers_k]
	PUSH ax
	MOV ax, [_constant3]
	MOV bx, ax
	POP ax
	MOV dx, 0
	DIV bx
	MOV ax, dx
	PUSH ax
	MOV ax, [_constant2]
	MOV bx, ax
	POP ax
	CMP ax, bx
	JE _expre4_jump
	MOV ax, 0
	JMP _expre4_end
_expre4_jump:
	MOV ax, 1
_expre4_end:
	CMP ax, 1
	JNE _statement_label_5_jump1
	MOV ax, [printOddNumbers_k]
	INC ax
	MOV [printOddNumbers_k], ax
	JMP _statement_label_4
_statement_label_5_jump1:
	MOV ax, [printOddNumbers_k]
	CALL _proc_print_number
	LEA ax, [_constant5]
	CALL _proc_print_string
	CALL _proc_print_new_line
	MOV ax, [printOddNumbers_k]
	INC ax
	MOV [printOddNumbers_k], ax
_statement_label_4:
	MOV ax, [printOddNumbers_k]
	PUSH ax
	MOV ax, [printOddNumbers_limit]
	MOV bx, ax
	POP ax
	CMP ax, bx
	JLE _expre5_jump
	MOV ax, 0
	JMP _expre5_end
_expre5_jump:
	MOV ax, 1
_expre5_end:
	CMP ax, 1
	JE _statement_label_4_do
_statement_label_4_exit:
	CALL _proc_print_new_line
	POP bp
	RET
proc_main:
	LEA ax, [_constant8]
	CALL _proc_print_string
	CALL _proc_print_new_line
	CALL _proc_scan_number
	MOV [main_limit], ax
	CALL _proc_print_new_line
	MOV ax, [main_limit]
	PUSH ax
	CALL proc_printOddNumbers
	MOV ah, 4ch
	INT 21h
	; ^^The program will terminate here.
