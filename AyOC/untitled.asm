inicio: mov 	P1, #01H
	lcall 	time
	mov 	P1,#00H
	lcall 	time
	ljmp 	inicio
time:	mov	R2,#30H
paca:	mov	R1,#0FAH
aca:	MOV 	R0,#0FAH
aqui:	DJNZ 	R0,aqui
	djnz	R1,aca
	djnz	R2,paca
	ret