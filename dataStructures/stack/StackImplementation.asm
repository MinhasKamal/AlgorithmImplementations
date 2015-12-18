##Writer: Minhas Kamal
##Date: 02-MAY-2014
##Function:	This program is a simple demonstration of stack.

#####**data**#####
.data

prompt: 	.asciiz "\n# What operation do you want to perform?\nPress-\t1.for push \n\t2.for pop \n\t3.for print all \n\t4.for exit \nSelection: "
prompt2: 	.asciiz "Enter the value: "
conf_pop:	.asciiz "\nOperation pop is successful.\n"
conf_push:	.asciiz "Operation push is successful.\n"
exit_msg: 	.asciiz "\n\n\nProgram exits...."
comma_space: .asciiz ", "

num: 		.double 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
			.double 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
capacity: 	.word 40
init:		.double 0.0

#####**text**#####
.text

main:
	lw $t1, capacity		#load capacity
	l.d $f4, init			#load the initial value
	li $t2, 0				#initial index is 0
	
loop:
	la $a0, prompt			#prompt
	li $v0, 4
	syscall
	
	li $v0, 5				#take choice from user
	syscall
	
	la $t0, num				#load array
	
	beq $v0, 1, push
	beq $v0, 2, pop
	beq $v0, 3, print_all
	j exit
	
	
#-------------------------------------------------------------------------------------------------------------------
#pushes one number on top
push: 
	li $t3, 0
	
	beq $t2, $t1, loop		#return when capacity is full
	
push_loop:					#find the address
	add $t0, $t0, 8
	add $t3, $t3, 1
	ble $t3, $t2, push_loop
	sub $t0, $t0, 8			#subtract once
	
	la $a0, prompt2			#prompt for input
	li $v0, 4
	syscall
	
	li $v0, 7				#take input
	syscall
	
	s.d $f0, ($t0)			#store the value
	
	add $t2, $t2, 1			#increase index
	
	la $a0, conf_push		#confirmation
	li $v0, 4
	syscall
	
	j loop					#return

	
#-------------------------------------------------------------------------------------------------------------------
#pops up top number	
pop:
	li $t3, 0
	
	beq $t2, $t3, loop		#return when nothing to pop
	
pop_loop:					#find the number
	add $t0, $t0, 8
	add $t3, $t3, 1
	blt $t3, $t2, pop_loop
	sub $t0, $t0, 8		#subtract once
	
	
	l.d $f12, ($t0)			#print the number
	li $v0, 3
	syscall
	
	s.d $f4, ($t0)			#initialize
	sub $t2, $t2, 1			#reduce index
	
	la $a0, conf_pop		#confirmation
	li $v0, 4
	syscall
	
	j loop					#return

#-------------------------------------------------------------------------------------------------------------------
#prints all the values	
print_all:
	li $t3, 0
print_loop:
	l.d $f12, ($t0)			#print the number
	li $v0, 3
	syscall
	
	la $a0, comma_space		#seperate ", "
	li $v0, 4
	syscall
	
	add $t0, $t0, 8
	add $t3, $t3, 1			#increase the loop counter
	blt $t3, $t1, print_loop
	j loop
	
	
#-------------------------------------------------------------------------------------------------------------------
#exit from the program
exit:
	la $a0, exit_msg	#exit message
	li $v0, 4
	syscall
	
	li $v0, 10
	syscall
