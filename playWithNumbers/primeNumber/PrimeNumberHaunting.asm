##Writer: Minhas Kamal
##Date: 01-MAY-2014
##Function:	Finds prime numbers in a certain range.

#####**data**#####
.data

prompt: 	.asciiz "Enter your range: "
new_line: 	.asciiz "\n"

#####**text**#####
.text

main:
	la $a0, prompt			#prompt for user input
	li $v0, 4
	syscall
	
	li $v0, 5				#take start integer
	syscall
	add $t1, $v0, $zero	
	
	li $t0, 2				#see if divisible by 2 or not (even or odd)
	div $t4, $t1, $t0		
	mul $t4, $t4, $t0
	bne $t4, $t1, odd
	addi $t1, $t1, 1		#if even make odd
odd:
	
	li $v0, 5				#take stop integer
	syscall
	add $t2, $v0, $zero	
	
	
	addi $t3, $t1, -2		#loop controller
loop_1:
	addi $t3, $t3, 2

	ble $t3, 1, loop_1		#loopback when <=1 is inputted 
	beq $t3, 3, isPrime		#when 3 is inputted 
	bgt $t3, $t2, exit		#when >$t2 exit
	
	li $t0, 3				#loop controller #starts from 3 to last
	div $t4, $t3, $t0 
loop_2:
	div $t4, $t3, $t0		#see if divisible or not
	mul $t4, $t4, $t0
	beq $t4, $t3, isNotPrime
	
	addi $t0, $t0, 2		#continue the loop
	blt $t0, $t4, loop_2
	
isPrime:
	add $a0, $t3, $zero
	li $v0, 1
	syscall
	la $a0, new_line
	li $v0, 4
	syscall
	j loop_1
	
isNotPrime:
	j loop_1
	

exit:
	li $v0, 10
	syscall
