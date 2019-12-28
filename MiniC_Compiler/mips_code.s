.data
	key: .word 0
.text

keyread:
	addi $t0, $zero, 10
	sw $t0, key($zero)
	nop
	jr $ra
	nop

print:
	add $t0, $a0, $zero
	sw $t0, 0xff00($zero)
	nop
	jr $ra
	nop

delay:
	addi $sp, $sp, -4
	sw $s0, 0($sp)
	addi $t0, $zero, 3000000
	add $s0, $t0, $zero
L1:
	addi $t0, $zero, 0
	add $t1, $t0, $zero
	add $t0, $s0, $zero
	slt $t0, $t1, $t0
	beq $t0, $zero, L2
	nop
	addi $t0, $zero, 1
	add $t1, $t0, $zero
	add $t0, $s0, $zero
	sub $t0, $t0, $t1
	add $s0, $t0, $zero
	nop
	j L1
	nop
L2:
	lw $s0, 0($sp)
	addi $sp, $sp, 4
	nop
	jr $ra
	nop

fib:
	addi $sp, $sp, -16
	sw $s3, 12($sp)
	sw $s2, 8($sp)
	sw $s1, 4($sp)
	sw $s0, 0($sp)
	addi $t0, $zero, 2
	add $t1, $t0, $zero
	add $t0, $a0, $zero
	slt $t0, $t0, $t1
	beq $t0, $zero, L3
	nop
	add $t0, $a0, $zero
	add $v0, $t0, $zero
	lw $s0, 0($sp)
	lw $s1, 4($sp)
	lw $s2, 8($sp)
	lw $s3, 12($sp)
	addi $sp, $sp, 16
	nop
	jr $ra
	nop
L3:
	addi $t0, $zero, 0
	add $s0, $t0, $zero
	addi $t0, $zero, 1
	add $s1, $t0, $zero
	addi $t0, $zero, 0
	add $s2, $t0, $zero
	addi $t0, $zero, 2
	add $s3, $t0, $zero
L4:
	add $t0, $a0, $zero
	add $t2, $t0, $zero
	add $t0, $s3, $zero
	add $t1, $t0, $zero
	addi $t0, $zero, 1
	beq $t1, $t2, L6
	nop
	slt $t0, $t1, $t2
L6:
	beq $t0, $zero, L5
	nop
	add $t0, $s1, $zero
	add $t1, $t0, $zero
	add $t0, $s0, $zero
	add $t0, $t0, $t1
	add $s2, $t0, $zero
	add $t0, $s1, $zero
	add $s0, $t0, $zero
	add $t0, $s2, $zero
	add $s1, $t0, $zero
	addi $t0, $zero, 1
	add $t1, $t0, $zero
	add $t0, $s3, $zero
	add $t0, $t0, $t1
	add $s3, $t0, $zero
	nop
	j L4
	nop
L5:
	add $t0, $s2, $zero
	add $v0, $t0, $zero
	lw $s0, 0($sp)
	lw $s1, 4($sp)
	lw $s2, 8($sp)
	lw $s3, 12($sp)
	addi $sp, $sp, 16
	nop
	jr $ra
	nop

main:
	addi $t0, $zero, 5
	add $s0, $t0, $zero
L7:
	addi $t0, $zero, 1
	beq $t0, $zero, L8
	nop
	addi $sp, $sp, -8
	sw $ra, 4($sp)
	sw $t9, 0($sp)
	add $t0, $s1, $zero
	add $a0, $t0, $zero
	nop
	jal print
	nop
	lw $t9, 0($sp)
	lw $ra, 4($sp)
	addi $sp, $sp, 8
	addi $sp, $sp, -8
	sw $ra, 4($sp)
	sw $t9, 0($sp)
	nop
	jal delay
	nop
	lw $t9, 0($sp)
	lw $ra, 4($sp)
	addi $sp, $sp, 8
	nop
	j L7
	nop
L8:
	nop
	jr $ra
	nop
