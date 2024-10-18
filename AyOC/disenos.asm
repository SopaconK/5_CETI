inicio: mov 	A,P3
escal:	cjne 	A,#01H, stair
	mov	P1,#01H
	lcall 	time
	mov 	P1,#02H
	lcall 	time
	mov	P1,#04H
	lcall 	time
	mov 	P1,#08H
	lcall	time
	mov	P1,#10H
	lcall	time
	mov	P1,#20H
	lcall 	time
	mov	P1,#40H
	lcall 	time
	mov	P1,#80H
	lcall	time
	
stair:	cjne 	A,#02H, half
	mov 	P1,#18H
	lcall	time
	mov 	P1,#24H
	lcall	time
	mov	P1,#42H
	lcall	time
	mov	P1,#81H
	lcall	time	
half:	cjne	A,#04H, impar
	mov	P1,#0F0H
	lcall 	time
	mov	P1,#0FH
	lcall	time
impar:	cjne 	A,#08H, inicio
	mov	P1,#01H
	lcall 	time
	mov	P1,#04H
	lcall 	time
	mov	P1,#10H
	lcall	time
	mov	P1,#40H
	lcall 	time
	ljmp inicio
time:	mov	R2,#04H
paca:	mov	R1,#0FAH
aca:	MOV 	R0,#0FAH
aqui:	DJNZ 	R0,aqui
	djnz	R1,aca
	djnz	R2,paca
	ret