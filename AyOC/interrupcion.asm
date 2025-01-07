		ORG 0000H
		LJMP PANT
		ORG 0003H
		LJMP	caso1		
		ORG 0013H
		LJMP	caso2

pant:		CLR 	P3.0  ; inicializar la pantalla
		CLR	P3.1
	
		mov	60H, #00H
		mov	R1,#00H
		MOV	R2,#00H		
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

		;Habilitar interrupciones
		mov	IE,#85H
		mov	IP,#04H
	
inicio:		; Todo lo de sin interrupciones 
		;E
		mov	P1,#01H  
		lcall 	de5ms
		mov	P1,#04H
		lcall	de5ms
		mov	P1,#8FH
		lcall	de5ms
		SETB	P3.0
		mov	P1,#45H
		lcall	de5ms
		CLR P3.0
		lcall	de1s
		
		; ME

		mov	P1,#01H  
		lcall 	de5ms
		mov	P1,#04H
		lcall	de5ms
		mov	P1,#8FH
		lcall	de5ms
		SETB	P3.0
		mov	P1,#4DH 
		lcall 	de5ms
		mov	P1,#45H
		lcall	de5ms
		CLR P3.0
		lcall	de1s
		;MME

		mov	P1,#01H  
		lcall 	de5ms
		mov	P1,#04H
		lcall	de5ms
		mov	P1,#8FH
		lcall	de5ms
		SETB	P3.0
		mov	P1,#4DH
		lcall 	de5ms
		mov	P1,#4DH 
		lcall 	de5ms
		mov	P1,#45H
		lcall	de5ms
		CLR P3.0
		lcall	de1s
		
		;AMME

		mov	P1,#01H  
		lcall 	de5ms
		mov	P1,#04H
		lcall	de5ms
		mov	P1,#8FH
		lcall	de5ms
		SETB	P3.0
		mov	P1,#41H
		lcall	de5ms
		mov	P1,#4DH
		lcall 	de5ms
		mov	P1,#4DH 
		lcall 	de5ms
		mov	P1,#45H
		lcall	de5ms
		CLR P3.0
		lcall	de1s
		
		;NAMME

		mov	P1,#01H  
		lcall 	de5ms
		mov	P1,#04H
		lcall	de5ms
		mov	P1,#8FH
		lcall	de5ms
		SETB	P3.0
		mov	p1,#4EH
		lcall	de5ms
		mov	P1,#41H
		lcall	de5ms
		mov	P1,#4DH
		lcall 	de5ms
		mov	P1,#4DH 
		lcall 	de5ms
		mov	P1,#45H
		lcall	de5ms
		CLR P3.0
		lcall	de1s

		;UNAMME

		mov	P1,#01H  
		lcall 	de5ms
		mov	P1,#04H
		lcall	de5ms
		mov	P1,#8FH
		lcall	de5ms
		SETB	P3.0
		mov	P1,#55H
		lcall	de5ms
		mov	p1,#4EH
		lcall	de5ms
		mov	P1,#41H
		lcall	de5ms
		mov	P1,#4DH
		lcall 	de5ms
		mov	P1,#4DH 
		lcall 	de5ms
		mov	P1,#45H
		lcall	de5ms
		CLR P3.0
		lcall	de1s

		;EUNAMME

		mov	P1,#01H  
		lcall 	de5ms
		mov	P1,#04H
		lcall	de5ms
		mov	P1,#8FH
		lcall	de5ms
		SETB	P3.0
		mov	P1,#45H
		lcall	de5ms
		mov	P1,#55H
		lcall	de5ms
		mov	p1,#4EH
		lcall	de5ms
		mov	P1,#41H
		lcall	de5ms
		mov	P1,#4DH
		lcall 	de5ms
		mov	P1,#4DH 
		lcall 	de5ms
		mov	P1,#45H
		lcall	de5ms
		CLR P3.0
		lcall	de1s

		;LEUNAMME
		mov	P1,#01H  
		lcall 	de5ms
		mov	P1,#04H
		lcall	de5ms
		mov	P1,#8FH
		lcall	de5ms
		SETB	P3.0
		mov	P1,#4CH
		lcall	de5ms
		mov	P1,#45H
		lcall	de5ms
		mov	P1,#55H
		lcall	de5ms
		mov	p1,#4EH
		lcall	de5ms
		mov	P1,#41H
		lcall	de5ms
		mov	P1,#4DH
		lcall 	de5ms
		mov	P1,#4DH 
		lcall 	de5ms
		mov	P1,#45H
		lcall	de5ms
		CLR P3.0
		lcall	de1s

		; reiniciar 
		
		LJMP 	inicio
	


app:		; Imprime el apellido paterno (BUENROSTRO)
		mov	P1,#01H  
		lcall 	de5ms
		mov	P1,#04H
		lcall	de5ms
		mov	P1,#8FH
		lcall	de5ms
		SETB	P3.0
		
		mov	P1,#4FH
		lcall	de5ms
		mov	P1,#52H
		lcall	de5ms
		mov	P1,#54H
		lcall	de5ms
		mov	P1,#53H
		lcall	de5ms
		mov	P1,#4FH
		lcall	de5ms
		mov	P1,#52H
		lcall	de5ms
		mov	P1,#4EH
		lcall	de5ms
		mov	P1,#45H
		lcall	de5ms
		mov	P1,#55H
		lcall	de5ms
		mov	P1,#42H
		lcall	de5ms
		CLR	P3.0
		ret


caso1:		;Aqui hacemos el tiempo de 1s de la interrupcion 0
		mov	66h, #07H
paca3:		DJNZ	66h, aqui3
		reti
aqui3:		lcall	app
		lcall	de100ms2
		ljmp 	paca3


apm:		; Imprime el apellido materno (BRISENO)
		mov	P1,#01H  
		lcall 	de5ms
		mov	P1,#04H
		lcall	de5ms
		mov	P1,#8FH
		lcall	de5ms
		SETB	P3.0
		mov	P1, #4FH
		lcall	de5ms
		mov	P1, #4EH
		lcall	de5ms
		mov	P1, #45H
		lcall	de5ms
		mov	P1, #53H
		lcall	de5ms
		mov	P1, #49H
		lcall	de5ms
		mov	P1, #52H
		lcall	de5ms
		mov	P1, #42H
		lcall	de5ms
		CLR	P3.0
		ret
		
caso2:		;Aqui hacemos el tiempo de 1s de la interrupcion 1
		mov	65h, #07H
paca4:		DJNZ	65h, aqui4
		reti
aqui4:		lcall	apm
		lcall	de100ms
		ljmp 	paca4


de1s:		
		mov	42h,#08H
paca1:		mov	41h,#0FAH
aca1:		MOV 	40h,#0FAH
aqui1:		DJNZ 	40h,aqui1
		djnz	41h,aca1
		djnz	42h,paca1
		ret

de100ms:	
		mov	62h,#01H
paca5:		mov	61h,#0FAH
aca5:		MOV 	60h,#0FAH
aqui5:		DJNZ 	60h,aqui5
		djnz	61h,aca5
		djnz	62h,paca5
		ret

de100ms2:	
		mov	72h,#01H
paca6:		mov	71h,#0FAH
aca6:		MOV 	70h,#0FAH
aqui6:		DJNZ 	70h,aqui6
		djnz	71h,aca6
		djnz	72h,paca6
		ret


de5ms:		
		SETB	P3.1
		mov	R7, #0AH
aca2:		mov	R6,#0FAH
aqui2:		DJNZ	R6, aqui2
		DJNZ	R7, aca2
		CLR P3.1
		RET