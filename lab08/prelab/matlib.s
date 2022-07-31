	;; parameter 1(in rdi) is the first number
	;; parameter 2(in rsi) is the number to mult by
	;; return value is a long that is a product of first and second param
	global _product
	global _power
	
	section .text

_product:
	xor 	rax, rax
	xor 	r10, r10	; count integer
start:
	cmp 	r10, rsi 	; if count = number to mult by,
	je	done		; exit
	add	rax, rdi
	inc	r10		; increment count
	jmp	start
done:
	ret

	;; parameter 1(in rdi) is the base
	;; parameter 2(in rsi) is the power
	;; return value is long that is power product of first and second param
_power:
	
recurse:
	cmp	rsi, 0 		; if rsi = 0
	mov	rax, 1
	je	epilogue 	; return one
	dec	rsi
	call 	_power
	push	rdi
	push 	rsi
	mov 	rsi, rdi
	mov	rdi, rax
	call 	_product
	pop 	rsi
	pop 	rdi
epilogue:
	ret