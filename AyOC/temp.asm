		ORG	0000h
		ljmp	inicio
		
		ORG	000Bh
		lcall 	temp
		reti
		
temp:		mov	A,R0
		DEC	A
		JZ	cero
		ret
		
cero:		mov	A,R1
		inc	A
		mov	R1,A
		subb	A,#3EH
		JNC	nocarry
		lcall	imprimir
		ret
		
nocarry:	mov	A,R2
		inc	A
		mov	R2,A
		mov	R1,#00H
		lcall	imprimir
		ret


imprimir:	mov	P1,#80H
		lcall	de5ms
		mov	60H,R2
		lcall	bitabcd
		MOV	A,53H
		ORL	A,#30H
		setb	P3.0
		MOV	P1,A
		lcall	de5ms
		MOV	A,54H
		ORL	A,#30H
		mov	P1,A
		lcall	de5ms
		mov	P1,#3AH
		lcall	de5ms
		clr	P3.0
		MOV 	60H,R1
		lcall	bitabcd
		MOV	A,53H
		ORL	A,#30H
		setb	P3.0
		MOV	P1,A
		lcall	de5ms
		MOV	A,54H
		ORL	A,#30H
		mov	P1,A
		lcall	de5ms
		clr	P3.0
		ret
		
inicio:		mov	TMOD, #08H
		setb	TCON.4
		setb	ET0
		
pant:		mov	R0,#7AH
		CLR 	P3.0
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
		lcall	de5ms
		SETB	P3.0
		mov	P1,#30H
		lcall	de5ms
		mov	P1,#30H
		lcall	de5ms
		mov	P1,#3AH
		lcall	de5ms
		mov	P1,#30H
		lcall	de5ms
		mov	P1,#30H
		lcall	de5ms
		clr	p3.0
		clr 	C
		
ciclo:		ljmp 	ciclo


bitabcd:	mov	52H,#00H
		mov	53H,#00H
		mov	54H,#00H
cien:		mov	A,60H
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

diez:		mov	A,60H
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
uno:		MOV 	54H,60H
		ret
			

de5ms:		;ret
		SETB	P3.1
		mov	R7, #0AH
aca:		mov	R6,#0FAH
aqui2:		DJNZ	R6, aqui2
		DJNZ	R7, aca
		CLR P3.1
		RET

