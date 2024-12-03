pant:	CLR 	P3.0
	CLR	P3.1
	CLR	P3.2
	mov	P1,#38H
	lcall 	de5ms
	mov	P1,#38H
	lcall 	de5ms
	mov	P1,#38H
	lcall 	de5ms
	mov	P1,#38H
	lcall 	de5ms
	mov	P1,#0CH
	lcall	de5ms
	mov	P1,#01H
	lcall 	de5ms
	mov	P1,#06H
	lcall	de5ms
	mov	P1,#80H
	mov 	3EH, #00H
	mov	3FH, #00H
inicio: mov	R0,#3EH

	lcall	leer
	mov	R2,3FH
	mov	B,#0EH
	mov	50h,#00H
	MOV	51H,#00H
	
auxi:	lcall	leer
	mov	A,B
	SUBB	A,#04H
	JNC	ncarry3
	mov	P1,#0C0H
	lcall	de5ms
	mov	B,#0FFH
ncarry3:	DJNZ	R2,auxi
	
prom:	
ayuda1:	mov	A,51H
	CLR	C
	CLR	AC
	subb	A,3FH
	JNC	ncarry4
	mov	B,A
	mov	A,50H
	JZ	fin
	DEC	A
	mov	50H,A
	mov	A,B
ncarry4: mov 	51H,A
	mov	A,3EH
	INC	A
	mov	3EH,A
	ljmp	ayuda1

fin:	mov	60H,3EH
	lcall	bitabcd
	setb	P3.0
	lcall	coso1

ciclo:	ljmp ciclo
leer:	lcall 	time
	mov	A,P3
	anl	A,#0F0H
	mov	70H,A
	setB     P3.2
	lcall	time
	CLR	P3.2
	mov	A,P3
	anl	A,#0F0H
	swap	A
	orl	A,70H
	INC	R0
	mov	@R0,A
	mov	60H,A
	mov	A,51H
	CLR	C
	CLR 	AC
	ADD	A,60H
	MOV	51H,A
	MOV	A,50H
	ADDC	A,#00H
	MOV	50H,A
	lcall	bitabcd
	setb	P3.0
coso1:	mov	A,52H
	JZ	coso2
	DEC	B
	orl	A,#30H
	mov	P1,A
	lcall 	de5ms
	mov	A,53H
	DEC	B
	orl	A,#30H
	mov	P1,A
	lcall 	de5ms
	mov	A,54H
	DEC	B
	orl	A,#30H
	mov	P1,A
	lcall 	de5ms
	mov	P1,#20H
	DEC 	B
	lcall	de5ms
	clr	P3.0
	ret

coso2: mov	A,53H
	JZ	coso3
	DEC	B
	orl	A,#30H
	mov	P1,A
	lcall 	de5ms
	mov	A,54H
	DEC	B
	orl	A,#30H
	mov	P1,A
	lcall 	de5ms
	mov	P1,#20H
	DEC 	B
	lcall	de5ms
	clr	P3.0
	ret

coso3: mov	A,54H
	JZ	coso4
	DEC	B
	orl	A,#30H
	mov	P1,A
	lcall 	de5ms
	mov	P1,#20H
	DEC 	B
	lcall	de5ms
	clr	P3.0
	ret

coso4: mov	P1,#20H
	DEC 	B
	lcall	de5ms
	clr	P3.0
	ret

bitabcd:mov	52H,#00H
	mov	53H,#00H
	mov	54H,#00H
cien:	mov	A,60H
	CLR	C
	CLR	AC
	subb	A,#64H
	JNC	ncarry1
	ADD	A,#64H
	LJMP	diez
ncarry1:	MOV	60H,A
	MOV	A,52H
	ADD	A,#01H
	MOV	52H,A
	LJMP	cien

diez:	mov	A,60H
	CLR	C
	CLR	AC
	subb	A,#0AH
	JNC	ncarry2
	ADD	A,#0AH
	LJMP	uno
ncarry2:	MOV	60H,A
	MOV	A,53H
	ADD	A,#01H
	MOV	53H,A
	LJMP	diez
uno:	MOV 	54H,60H
	ret

de5ms:	
	SETB	P3.1
	mov	R7, #0AH
aca:	mov	R6,#0FAH
aqui2:	DJNZ	R6, aqui2
	DJNZ	R7, aca
	CLR P3.1
	RET


time2:	ljmp 	time2
time:	
	mov	R7,#40H
paca:	mov	R6,#0FAH
aca2:	MOV 	R5,#0FAH
aqui3:	DJNZ 	R5,aqui3
	djnz	R6,aca2
	djnz	R7,paca
	ret