ORG 100h

JMP proc_main
section .data
	_constant0 db 'Error: Start number cannot be greater than end number.', '$'
	_constant1 db 'Numbers from ', '$'
	_constant2 db '%d', '$'
	_constant3 db ' to ', '$'
	_constant4 db ': ', '$'
	_constant5 db ' ', '$'
	_constant6 db 'Enter two numbers: ', '$'
	_constant7 db 'Menu:', '$'
	_constant8 db '1. Calculate square', '$'
	_constant9 db '2. Print numbers between them', '$'
	_constant10 db 'Enter your choice: ', '$'
	_constant11 db 'Invalid choice. Please enter 1 or 2: ', '$'
	_constant12 dw 2
	_constant13 dw 1
	_constant14 db 'Square of ', '$'
	_newline db 13, 10, '$'
section .bss
	calculate_square_num: resb 4
	print_numbers_start: resb 4
	print_numbers_end: resb 4
	print_numbers_1_i: resb 4
	main_2_square1: resb 4
	main_2_square2: resb 4
	main_choice: resb 4
	main_num1: resb 4
	main_num2: resb 4

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
proc_calculate_square:
	PUSH bp
	MOV bp, sp
	MOV ax, [bp + 4]
	MOV [calculate_square_num], ax
	MOV ax, [calculate_square_num]
	PUSH ax
	MOV ax, [calculate_square_num]
	MOV bx, ax
	POP ax
	MUL bx
	POP bp
	RET
proc_print_numbers:
	PUSH bp
	MOV bp, sp
	MOV ax, [bp + 4]
	MOV [print_numbers_end], ax
	MOV ax, [bp + 6]
	MOV [print_numbers_start], ax
	MOV ax, [print_numbers_start]
	PUSH ax
	MOV ax, [print_numbers_end]
	MOV bx, ax
	POP ax
	CMP ax, bx
	JG _expre0_jump
	MOV ax, 0
	JMP _expre0_end
_expre0_jump:
	MOV ax, 1
_expre0_end:
	CMP ax, 1
	JNE _statement_label_0_jump1
	LEA ax, [_constant0]
	CALL _proc_print_string
	CALL _proc_print_new_line
	POP bp
	RET
_statement_label_0_jump1:
	LEA ax, [_constant1]
	CALL _proc_print_string
	MOV ax, [print_numbers_start]
	CALL _proc_print_number
	LEA ax, [_constant3]
	CALL _proc_print_string
	MOV ax, [print_numbers_end]
	CALL _proc_print_number
	LEA ax, [_constant4]
	CALL _proc_print_string
	CALL _proc_print_new_line
	MOV ax, [print_numbers_start]
	MOV bx, ax
	MOV [print_numbers_1_i], bx
_statement_label_1_cmp:
	MOV ax, [print_numbers_1_i]
	PUSH ax
	MOV ax, [print_numbers_end]
	MOV bx, ax
	POP ax
	CMP ax, bx
	JLE _expre1_jump
	MOV ax, 0
	JMP _expre1_end
_expre1_jump:
	MOV ax, 1
_expre1_end:
	CMP ax, 1
	JNE _statement_label_1_exit
	MOV ax, [print_numbers_1_i]
	CALL _proc_print_number
	LEA ax, [_constant5]
	CALL _proc_print_string
	CALL _proc_print_new_line
_statement_label_1:
	MOV ax, [print_numbers_1_i]
	INC ax
	MOV [print_numbers_1_i], ax
	JMP _statement_label_1_cmp
_statement_label_1_exit:
	POP bp
	RET
proc_main:
	LEA ax, [_constant6]
	CALL _proc_print_string
	CALL _proc_print_new_line
	CALL _proc_scan_number
	MOV [main_num1], ax
	CALL _proc_print_new_line
	CALL _proc_scan_number
	MOV [main_num2], ax
	CALL _proc_print_new_line
	LEA ax, [_constant7]
	CALL _proc_print_string
	CALL _proc_print_new_line
	LEA ax, [_constant8]
	CALL _proc_print_string
	CALL _proc_print_new_line
	LEA ax, [_constant9]
	CALL _proc_print_string
	CALL _proc_print_new_line
	LEA ax, [_constant10]
	CALL _proc_print_string
	CALL _proc_print_new_line
	CALL _proc_scan_number
	MOV [main_choice], ax
	CALL _proc_print_new_line
_statement_label_2:
	MOV ax, [main_choice]
	PUSH ax
	MOV ax, [_constant13]
	MOV bx, ax
	POP ax
	CMP ax, bx
	JL _expre2_jump
	MOV ax, 0
	JMP _expre2_end
_expre2_jump:
	MOV ax, 1
_expre2_end:
	PUSH ax
	MOV ax, [main_choice]
	PUSH ax
	MOV ax, [_constant12]
	MOV bx, ax
	POP ax
	CMP ax, bx
	JG _expre3_jump
	MOV ax, 0
	JMP _expre3_end
_expre3_jump:
	MOV ax, 1
_expre3_end:
	MOV bx, ax
	POP ax
	OR ax, bx
	CMP ax, 1
	JNE _statement_label_2_exit
	LEA ax, [_constant11]
	CALL _proc_print_string
	CALL _proc_print_new_line
	CALL _proc_scan_number
	MOV [main_choice], ax
	CALL _proc_print_new_line
	JMP _statement_label_2
_statement_label_2_exit:
	MOV ax, [main_choice]
	PUSH ax
	MOV ax, [_constant13]
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
	JNE _statement_label_3_jump1
	MOV ax, [main_num1]
	PUSH ax
	CALL proc_calculate_square
	MOV bx, ax
	MOV [main_2_square1], bx
	MOV ax, [main_num2]
	PUSH ax
	CALL proc_calculate_square
	MOV bx, ax
	MOV [main_2_square2], bx
	LEA ax, [_constant14]
	CALL _proc_print_string
	MOV ax, [main_num1]
	CALL _proc_print_number
	LEA ax, [_constant4]
	CALL _proc_print_string
	MOV ax, [main_2_square1]
	CALL _proc_print_number
	CALL _proc_print_new_line
	LEA ax, [_constant14]
	CALL _proc_print_string
	MOV ax, [main_num2]
	CALL _proc_print_number
	LEA ax, [_constant4]
	CALL _proc_print_string
	MOV ax, [main_2_square2]
	CALL _proc_print_number
	CALL _proc_print_new_line
	JMP _statement_label_3_jump2
_statement_label_3_jump1:
	MOV ax, [main_num1]
	PUSH ax
	MOV ax, [main_num2]
	PUSH ax
	CALL proc_print_numbers
_statement_label_3_jump2:
	MOV ah, 4ch
	INT 21h
	; ^^The program will terminate here.
