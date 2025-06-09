SECTION .data			;.data section of program
inputBuf:	db	0x83, 0x6A, 0x88, 0xDE, 0x9A, 0xC3, 0x54, 0x9A ;defines the input values from given data
inputLen:	equ	$ - inputBuf ;calculates length of inputBuf
newline:	db 	10	     ;defines new line 

SECTION .bss			;.bss section of program
outputBuf:	resb 	80	;resurves 80 bytes for out put (included based on peramitors given)

	
SECTION .text			;.text section of program
global  _start			;declares the start for the program

_start:				;starts program

	mov	esi, inputBuf	;loads the address of inputBuf into esi
	mov	edi, outputBuf	;loads address of outputBuf into edi
	mov	ecx, inputLen	;loads inputLen to ecx regestry
	

nextchar: 			;goes through inputBuf of ach character and changes it to ascii hex
	lodsb			;loads byte from address in esi into al and increments esi by 1
	

	mov	ah, al		;copies al to ah
	shr	al, 4		;shifts al by 4 bits so we are left with only upper 4 bits

	jz	finished	;if al is 0 jump to finished section
	call	convert_to_ascii ;calls and sends al to convert_to_ascii section
	stosb			 ;stores result to outputBuf and incroments edi

	
	mov	al, ah		;copies ah to al
	and	al, 0x0F	;masks the upper 4 bits leaving only the lower 4 
	
	call	convert_to_ascii ;calls and sends al to convert_to_ascii section
	stosb			 ;stores result to outputBuf and incroments edi

	mov	al, ' '		;adds a space to the end of each section in al
	stosb			;stores result to outputBuf and incroments edi

	jmp	nextchar	;jumps to the top of nextchar to prossess next byte
	

finished:			;creates the final prossess of the program

	mov	al, 10		;loads newline into al 
	stosb			;stores result to outputbuf and incroments edi
	mov	eax, 4		;ststem call for sys_write
	mov	ebx, 1		;file descriptor 1
	mov	ecx, outputBuf 	;sends ecx the adress of outputBuf
	mov	edx, edi	;length of the outputBuf
	sub	edx, outputBuf 	;calculates length by subtracting the adress of outputBuf from edi
	int	0x80		;system call to write descriptor 1


	mov	eax, 1		;system call for sys_exit
	xor	ebx, ebx	;exit with code 0
	int	0x80		;makes system call to exit program

	
convert_to_ascii:		;convers to ascii value
	cmp	al, 9		;compare value in al with 9
	jbe	convert_decimal	;if al is less then or equal to 9, jump to convert_decimal
	add	al, 0x37	;add 0x37 to convert to hex value of ascii
	ret			;return to calling function

convert_decimal:		;convert to decimal diget
	add	al, 0x30	;add 0x30 to convert al to corisponding ascii digit
	ret			;return to calling function
