pant:	CLR 	P3.0
	CLR	P3.1
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
inicio:	mov	R0,#2FH
	mov	R1,#3FH
	lcall	readc
	lcall	readc
	lcall	readc
	lcall	readc
	lcall	readc
	lcall	readc
	lcall	readc
	lcall	readc
	lcall	readc
	lcall	readc
	lcall	readc
	lcall	readc
	lcall	readc
	lcall	readc
	lcall	readc
	lcall	readc
	ljmp	ord

readc:	lcall 	time
	mov	A,P3
	anl	A,#0F0H
	mov	70H,A
	lcall	time
	mov	A,P3
	anl	A,#0F0H
	swap	A
	orl	A,70H
	INC	R0
	INC	R1
	mov	@R1,A
	mov	@R0,A
	setb	P3.0
	mov	P1,A
	lcall 	de5ms
	clr	P3.0
	ret
ord:	lcall	bubble
	lcall	bubble
	lcall	bubble
	lcall	bubble
	lcall	bubble
	lcall	bubble
	lcall	bubble
	lcall	bubble
	lcall	bubble
	lcall	bubble
	lcall	bubble
	lcall	bubble
	lcall	bubble
	lcall	bubble
	lcall	bubble
	lcall	bubble

imp:	mov	P1,#0C0H
	lcall	de5ms
	setb	P3.0
	mov	P1,40H
	lcall	de5ms
	mov	P1,41H
	lcall	de5ms
	mov	P1,42H
	lcall	de5ms
	mov	P1,43H
	lcall	de5ms
	mov	P1,44H
	lcall	de5ms
	mov	P1,45H
	lcall	de5ms
	mov	P1,46H
	lcall	de5ms
	mov	P1,47H
	lcall	de5ms
	mov	P1,48H
	lcall	de5ms
	mov	P1,49H
	lcall	de5ms
	mov	P1,4AH
	lcall	de5ms
	mov	P1,4BH
	lcall	de5ms
	mov	P1,4CH
	lcall	de5ms
	mov	P1,4DH
	lcall	de5ms
	mov	P1,4EH
	lcall	de5ms
	mov	P1,4FH
	lcall	de5ms
	clr	P3.0
	ljmp    time
comp:	mov	A, 70H
	mov	B, 71H
	CLR	C
	ClR	AC
	subb 	A,B
	JNC	ncarry	 
	ret
ncarry: mov	A,71H
	xch	A,70H
	xch	A,71H
	ret


bubble:	mov	70H, 40H
	mov	71H, 41H
	lcall	comp
	mov	40H,70H
	mov	41H,71H
	mov	70H, 41H
	mov	71H, 42H
	lcall	comp
	mov	41H,70H
	mov	42H,71H
	mov	70H, 42H
	mov	71H, 43H
	lcall	comp
	mov	42H,70H
	mov	43H,71H
	mov	70H, 43H
	mov	71H, 44H
	lcall	comp
	mov	43H,70H
	mov	44H,71H
	mov	70H, 44H
	mov	71H, 45H
	lcall	comp
	mov	44H,70H
	mov	45H,71H
	mov	70H, 45H
	mov	71H, 46H
	lcall	comp
	mov	45H,70H
	mov	46H,71H
	mov	70H, 46H
	mov	71H, 47H
	lcall	comp
	mov	46H,70H
	mov	47H,71H
	mov	70H, 47H
	mov	71H, 48H
	lcall	comp
	mov	47H,70H
	mov	48H,71H
	mov	70H, 48H
	mov	71H, 49H
	lcall	comp
	mov	48H,70H
	mov	49H,71H
	mov	70H, 49H
	mov	71H, 4AH
	lcall	comp
	mov	49H,70H
	mov	4AH,71H
	mov	70H, 4AH
	mov	71H, 4BH
	lcall	comp
	mov	4AH,70H
	mov	4BH,71H
	mov	70H, 4BH
	mov	71H, 4CH
	lcall	comp
	mov	4BH,70H
	mov	4CH,71H
	mov	70H, 4CH
	mov	71H, 4DH
	lcall	comp
	mov	4CH,70H
	mov	4DH,71H
	mov	70H, 4DH
	mov	71H, 4EH
	lcall	comp
	mov	4DH,70H
	mov	4EH,71H
	mov	70H, 4EH
	mov	71H, 4FH
	lcall	comp
	mov	4EH,70H
	mov	4FH,71H
	ret



de5ms:	SETB	P3.1
	mov	R7, #0AH
aca:	mov	R6,#0FAH
aqui2:	DJNZ	R6, aqui2
	DJNZ	R7, aca
	CLR P3.1
	RET


time2:	ljmp 	time2
time:	mov	R7,#40H
paca:	mov	R6,#0FAH
aca2:	MOV 	R5,#0FAH
aqui3:	DJNZ 	R5,aqui3
	djnz	R6,aca2
	djnz	R7,paca
	ret