ORG 100h

JMP proc_main
section .data
	_constant0 dw 1
	_constant1 db 'Enter two integers: ', '$'
	_constant2 db '%d', '$'
	_constant3 db ' ', '$'
	_constant4 db 'Choose an operation to perform:', '$'
	_constant5 db '0. Exit', '$'
	_constant6 db '1. Addition', '$'
	_constant7 db '2. Subtraction', '$'
	_constant8 db '3. Multiplication', '$'
	_constant9 db '4. Division', '$'
	_constant10 db '5. Factorial of the first number', '$'
	_constant11 db 'Enter your choice (1-5): ', '$'
	_constant12 db 'Invalid choice.', '$'
	_constant13 db 'Factorial of ', '$'
	_constant14 db ' is: ', '$'
	_constant15 dw 5
	_constant16 db 'Error: Division by zero is not allowed.', '$'
	_constant17 db 'Result: ', '$'
	_constant18 dw 0
	_constant19 dw 4
	_constant20 dw 3
	_constant21 dw 2
	_newline db 13, 10, '$'
section .bss
	add_a: resb 4
	add_b: resb 4
	subtract_a: resb 4
	subtract_b: resb 4
	multiply_a: resb 4
	multiply_b: resb 4
	divide_a: resb 4
	divide_b: resb 4
	factorial_n: resb 4
	factorial_0_i: resb 4
	factorial_result: resb 4
	main_num1: resb 4
	main_result: resb 4
	main_choice: resb 4
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
proc_add:
	PUSH bp
	MOV bp, sp
	MOV ax, [bp + 4]
	MOV [add_b], ax
	MOV ax, [bp + 6]
	MOV [add_a], ax
	MOV ax, [add_a]
	PUSH ax
	MOV ax, [add_b]
	MOV bx, ax
	POP ax
	ADD ax, bx
	POP bp
	RET
proc_subtract:
	PUSH bp
	MOV bp, sp
	MOV ax, [bp + 4]
	MOV [subtract_b], ax
	MOV ax, [bp + 6]
	MOV [subtract_a], ax
	MOV ax, [subtract_a]
	PUSH ax
	MOV ax, [subtract_b]
	MOV bx, ax
	POP ax
	SUB ax, bx
	POP bp
	RET
proc_multiply:
	PUSH bp
	MOV bp, sp
	MOV ax, [bp + 4]
	MOV [multiply_b], ax
	MOV ax, [bp + 6]
	MOV [multiply_a], ax
	MOV ax, [multiply_a]
	PUSH ax
	MOV ax, [multiply_b]
	MOV bx, ax
	POP ax
	MUL bx
	POP bp
	RET
proc_divide:
	PUSH bp
	MOV bp, sp
	MOV ax, [bp + 4]
	MOV [divide_b], ax
	MOV ax, [bp + 6]
	MOV [divide_a], ax
	MOV ax, [divide_a]
	PUSH ax
	MOV ax, [divide_b]
	MOV bx, ax
	POP ax
	MOV dx, 0
	DIV bx
	POP bp
	RET
proc_factorial:
	PUSH bp
	MOV bp, sp
	MOV ax, [bp + 4]
	MOV [factorial_n], ax
	MOV ax, [_constant0]
	MOV bx, ax
	MOV [factorial_result], bx
	MOV ax, [_constant0]
	MOV bx, ax
	MOV [factorial_0_i], bx
_statement_label_0_cmp:
	MOV ax, [factorial_0_i]
	PUSH ax
	MOV ax, [factorial_n]
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
	MOV ax, [factorial_0_i]
	MOV bx, ax
	MOV ax, factorial_result
	IMUL bx
	MOV bx, ax
	MOV [factorial_result], bx
_statement_label_0:
	MOV ax, [factorial_0_i]
	INC ax
	MOV [factorial_0_i], ax
	JMP _statement_label_0_cmp
_statement_label_0_exit:
	MOV ax, [factorial_result]
	POP bp
	RET
proc_main:
	LEA ax, [_constant1]
	CALL _proc_print_string
	CALL _proc_print_new_line
	CALL _proc_scan_number
	MOV [main_num1], ax
	CALL _proc_print_new_line
	CALL _proc_scan_number
	MOV [main_num2], ax
	CALL _proc_print_new_line
	LEA ax, [_constant4]
	CALL _proc_print_string
	CALL _proc_print_new_line
	LEA ax, [_constant5]
	CALL _proc_print_string
	CALL _proc_print_new_line
	LEA ax, [_constant6]
	CALL _proc_print_string
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
	LEA ax, [_constant11]
	CALL _proc_print_string
	CALL _proc_print_new_line
	CALL _proc_scan_number
	MOV [main_choice], ax
	CALL _proc_print_new_line
_statement_label_1:
	MOV ax, [main_choice]
	PUSH ax
	MOV ax, [_constant18]
	MOV bx, ax
	POP ax
	CMP ax, bx
	JNE _expre1_jump
	MOV ax, 0
	JMP _expre1_end
_expre1_jump:
	MOV ax, 1
_expre1_end:
	CMP ax, 1
	JNE _statement_label_1_exit
	MOV ax, [main_choice]
	PUSH ax
	MOV ax, [_constant0]
	MOV bx, ax
	POP ax
	CMP ax, bx
	JE _expre2_jump
	MOV ax, 0
	JMP _expre2_end
_expre2_jump:
	MOV ax, 1
_expre2_end:
	CMP ax, 1
	JNE _statement_label_2_jump1
	MOV ax, [main_num1]
	PUSH ax
	MOV ax, [main_num2]
	PUSH ax
	CALL proc_add
	MOV bx, ax
	MOV [main_result], bx
	LEA ax, [_constant17]
	CALL _proc_print_string
	MOV ax, [main_result]
	CALL _proc_print_number
	CALL _proc_print_new_line
	JMP _statement_label_2_jump2
_statement_label_2_jump1:
	MOV ax, [main_choice]
	PUSH ax
	MOV ax, [_constant21]
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
	MOV ax, [main_num1]
	PUSH ax
	MOV ax, [main_num2]
	PUSH ax
	CALL proc_subtract
	MOV bx, ax
	MOV [main_result], bx
	LEA ax, [_constant17]
	CALL _proc_print_string
	MOV ax, [main_result]
	CALL _proc_print_number
	CALL _proc_print_new_line
	JMP _statement_label_3_jump2
_statement_label_3_jump1:
	MOV ax, [main_choice]
	PUSH ax
	MOV ax, [_constant20]
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
	JNE _statement_label_4_jump1
	MOV ax, [main_num1]
	PUSH ax
	MOV ax, [main_num2]
	PUSH ax
	CALL proc_multiply
	MOV bx, ax
	MOV [main_result], bx
	LEA ax, [_constant17]
	CALL _proc_print_string
	MOV ax, [main_result]
	CALL _proc_print_number
	CALL _proc_print_new_line
	JMP _statement_label_4_jump2
_statement_label_4_jump1:
	MOV ax, [main_choice]
	PUSH ax
	MOV ax, [_constant19]
	MOV bx, ax
	POP ax
	CMP ax, bx
	JE _expre5_jump
	MOV ax, 0
	JMP _expre5_end
_expre5_jump:
	MOV ax, 1
_expre5_end:
	CMP ax, 1
	JNE _statement_label_5_jump1
	MOV ax, [main_num2]
	PUSH ax
	MOV ax, [_constant18]
	MOV bx, ax
	POP ax
	CMP ax, bx
	JNE _expre6_jump
	MOV ax, 0
	JMP _expre6_end
_expre6_jump:
	MOV ax, 1
_expre6_end:
	CMP ax, 1
	JNE _statement_label_6_jump1
	MOV ax, [main_num1]
	PUSH ax
	MOV ax, [main_num2]
	PUSH ax
	CALL proc_divide
	MOV bx, ax
	MOV [main_result], bx
	LEA ax, [_constant17]
	CALL _proc_print_string
	MOV ax, [main_result]
	CALL _proc_print_number
	CALL _proc_print_new_line
	JMP _statement_label_6_jump2
_statement_label_6_jump1:
	LEA ax, [_constant16]
	CALL _proc_print_string
	CALL _proc_print_new_line
_statement_label_6_jump2:
	JMP _statement_label_5_jump2
_statement_label_5_jump1:
	MOV ax, [main_choice]
	PUSH ax
	MOV ax, [_constant15]
	MOV bx, ax
	POP ax
	CMP ax, bx
	JE _expre7_jump
	MOV ax, 0
	JMP _expre7_end
_expre7_jump:
	MOV ax, 1
_expre7_end:
	CMP ax, 1
	JNE _statement_label_7_jump1
	MOV ax, [main_num1]
	PUSH ax
	CALL proc_factorial
	MOV bx, ax
	MOV [main_result], bx
	LEA ax, [_constant13]
	CALL _proc_print_string
	MOV ax, [main_num1]
	CALL _proc_print_number
	LEA ax, [_constant14]
	CALL _proc_print_string
	MOV ax, [main_result]
	CALL _proc_print_number
	CALL _proc_print_new_line
	JMP _statement_label_7_jump2
_statement_label_7_jump1:
	LEA ax, [_constant12]
	CALL _proc_print_string
	CALL _proc_print_new_line
_statement_label_7_jump2:
_statement_label_5_jump2:
_statement_label_4_jump2:
_statement_label_3_jump2:
_statement_label_2_jump2:
	CALL _proc_scan_number
	MOV [main_choice], ax
	CALL _proc_print_new_line
	JMP _statement_label_1
_statement_label_1_exit:
	MOV ah, 4ch
	INT 21h
	; ^^The program will terminate here.
