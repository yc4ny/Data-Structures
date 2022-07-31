	;; the first parameter(rdi) is the number to evaluate
	
	global 	_threexplusone

	section	.text

_threexplusone:
	mov	rax, rdi
	xor	rcx, rcx
	xor 	r8, r8
	xor 	r9, r9
loop:	
	cmp	rax, 1		;if rdi is one, we're done
	je 	donezo
	inc	rcx
	mov	r9, rax
	and	r9, 1
	cmp	r9, 1
	je 	odd		;if its odd, jump to odd
even:
	shr 	rax, 1
	jmp	loop
odd:
	imul	rax, 3
	inc 	rax
	jmp	loop
donezo:
	mov	rax, rcx
	ret