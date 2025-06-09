;Hello World Program based on leason 1 and 2 on asmtutor.com
;Written by daniel Dreyer for CMSC 313 8:30AM class
;compile with: nasm -f elf32 -g -F dwarf -o myProgram.o myProgram.asm
;link and load with:  ld -m elf_i386 -o myProgram myProgram.o
;run: ./myProgram 

SECTION .data
msg     db      'Hello World!', 0Ah ;assigns message variable with message string
 
SECTION .text
global  _start
 
_start:
 
    mov     edx, 13	;number of bytes to write- one for each letter and the line feed character
    mov     ecx, msg	;moves the address of the string to ecx
    mov     ebx, 1	;write the STDOUT file
    mov     eax, 4	;invokes kernel opcode 4 of SYS_WRITE
    int     80h
 
    mov     ebx, 0      ;returns 0 on exit 
    mov     eax, 1      ;invokes kernel opcode 1 of SYS_EXIT 
    int     80h