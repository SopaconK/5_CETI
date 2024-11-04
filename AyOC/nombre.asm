inicio:	CLR 	P3.0
	CLR 	P3.1
	mov	P1,#38h
	lcall	de120us
	mov	P1,#38h
	lcall	de120us
	mov	P1,#38h
	lcall	de120us
	mov	P1,#38h
	lcall	de120us
	mov	P1,#0CH
	lcall	de120us
	mov	P1,#01H
	lcall	de5ms
	mov	P1,#06H
	lcall	de120us
	mov	P1,#0C0H
	lcall	de120us
	setb	P3.0
	mov	P1,#42H
	lcall	de120us	
	lcall	time
	mov	P1,#55H
	lcall	de120us	
	lcall	time
	mov	P1,#45H
	lcall	de120us	
	lcall	time
	mov	P1,#4EH
	lcall	de120us	
	lcall	time
	mov	P1,#52H
	lcall	de120us	
	lcall	time
	mov	P1,#4FH
	lcall	de120us	
	lcall	time
	mov	P1,#53H
	lcall	de120us	
	lcall	time
	mov	P1,#54H
	lcall	de120us	
	lcall	time
	mov	P1,#52H
	lcall	de120us	
	lcall	time
	mov	P1,#4FH
	lcall	de120us	
	lcall	time
	CLR	p3.0
	mov	P1,#04H
	lcall	de120us
	mov	P1,#8FH
	lcall	de120us
	setb	P3.0
	mov	P1,#4FH
	lcall	de120us
	lcall	time
	mov	P1,#52H
	LCALL	de120us
	lcall	time
	mov	P1,#54H
	lcall	de120us
	lcall	time
	mov	P1,#53H
	lcall	de120us
	lcall	time
	mov	P1,#4FH
	lcall	de120us
	lcall	time
	mov	P1,#52H
	lcall	de120us
	lcall	time
	mov	P1,#4EH
	lcall	de120us
	lcall	time
	mov	P1,#45H
	lcall	de120us
	lcall	time
	mov	P1,#55H
	lcall	de120us
	lcall	time
	mov	P1,#42H
	lcall	de120us
	lcall	time
	ljmp	inicio
de120us:
de5ms:	SETB	P3.1
	mov	R1, #0AH
aca:	mov	R0,#0FAH
aqui2:	DJNZ	R0, aqui2
	DJNZ	R1, aca
	CLR P3.1
	RET


time:	mov	R7,#04H
paca:	mov	R6,#0FAH
aca2:	MOV 	R5,#0FAH
aqui3:	DJNZ 	R5,aqui3
	djnz	R6,aca2
	djnz	R7,paca
	ret
