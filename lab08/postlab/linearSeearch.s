	;; the first parameter(rdi) is a pointer to an array
	;; the second parameter(rsi) is the size of the array
	;; the third parameter(rdx) is a target element to find in the array

	global	_linearSearch

	section	.text

_linearSearch:
	xor	rax, rax  	;empty rax
	mov	r8, 0		;put 0 in r8, which will be our counting int
	mov	r9, rdi		;another pointer to the array(iterator)
loop:  
	push	rsi		;save value of rsi
	cmp	rsi, r8		;compare rsi to count
	je	donezobad	;if size-(count) = 0, we have iterated through
	pop	rsi		;original value of rsi
	cmp	edx, [r9]	;compare target value(rdx) to r9(arr ptr)
	je	donezo		;if equal, exit
	add	r9, 4		;increment r9(arr ptr) by 4(size of int)
	add 	r8, 1		;increment r8(counter) by 1
	jmp	loop		;return to start of loop
donezobad:
	mov	rax, -1		;return -1 if we dont find the value
	ret
donezo:
	mov	rax, r8		;if we find the value, return the index it is at
	ret