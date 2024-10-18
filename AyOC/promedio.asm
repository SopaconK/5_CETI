inicio:	mov	R0,#00H
	mov	R1,#00H
	mov	R2,#01H
leer:	mov	P1,R2
	lcall 	time
	mov	A, R0
	add	A, P3
	mov 	R0, A
	mov 	A,R1
	addc	A,#00H
	mov	R1,A
	mov	A,R2
	add	A,#01H
	mov	R2,A
	mov 	A,#00H
	cjne	R2, #09H, leer
prom: 	mov	A, R1
	rrc 	A
	mov	R1,A
	mov	A,R0
	rrc	A
	mov 	R0,A
	mov	A, R1
	rrc 	A
	mov	R1,A
	mov	A,R0
	rrc	A
	mov 	R0,A
	mov	A, R1
	rrc 	A
	mov	R1,A
	mov	A,R0
	rrc	A
	mov 	R0,A
	mov	P1,R0
	lcall time
	ljmp	inicio
time:	mov	R7,#40H
paca:	mov	R6,#0FAH
aca:	MOV 	R5,#0FAH
aqui:	DJNZ 	R5,aqui
	djnz	R6,aca
	djnz	R7,paca
	ret