/* this is my first assembly source */


#	 this is a comment 
	
.global main 			#  has .global directive to be seen by all other source modules (source code files)   

main:	 			# this is the main label (i.e. the istruction loaded into pc when main is executed)
	
/* NB
the GNU linker specifically requires a _start symbol to specify the first instruction to be executed in a program
*/

	mov r0, #2 		# put 2 inside r0
	bx lr			# return from main
	
