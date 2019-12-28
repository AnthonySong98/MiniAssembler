.data

.text
BIOS:
	lui $1, 0xffff
	ori $28,$1,0xf000
	addi $29,$0,0xfff #初始化 $sp
	addi $8,$0,4
	addi $9,$0,8
	addi $10,$0,0x55aa
	addi $11,$0,0xaa55
	addi $16,$0,0xe1 #ram错误码
CHKRAM:
	lw $24,0($8)
	sw $9,0($8)
	lw $12,0($8)
	bne $12,$9,ERR
	sw $11,0($8)
	lw $12,0($8)
	bne $12,$11,ERR
	sw $24,0($8) #恢复原来的值
	beq $8,$9,CHKKEY #全部检查完
	sw $25,0xc50($28) # 复位看门狗
	addi $8,$8,4 #到下一个双字
	j CHKRAM
CHKKEY:
	addi $16,$0,0xe2 #KEY 错误码
	lw $8,0xc12($28) #读键盘状 态
	andi $8,$8,1
	bne $8,$0,ERR #没按键的时候有按键信息，出错
	j 0x2020 #启动用户程序 的地址
ERR:
	ori $4,$16,0
	jal DISP # 在数码管上输出错误码
LP:
	sw $25,0xc50($28) # 复位看门狗
	j LP
DISP:
	sw $1,0($29)
	ori $8, $0, 4
	sub $29,$29,$8
	sw $28,0($29)
	sub $29,$29,$8 #入栈
	lui $1,0xffff
	ori $28,$1,0xf000
	ori $1,$0,0xff00
	sw $1,0xc04($28)
	ori $8,$4,0
	sw $8,0xc00($28)
	srl $8,$8,16
	sw $8,0xc02($28) #显示
	addi $29,$29,4
	lw $28,0($29)
	addi $29,$29,4
	lw $1,0($29) #出栈
	jr $31 #返回
KEY:
	sw $16,0($29)
	ori $8, $0, 4
	sub $29,$29,$8
	sw $17,0($29)
	sub $29,$29,$8
	sw $1,0($29)
	sub $29,$29,$8
	sw $28,0($29)
	sub $29,$29,$8 #入栈
	lui $1,0xffff
	ori $28,$1,0xf000
	addi $16,$0,1
	beq $4,$16,KFUN1
KLOP:
	lw $17,0xc12($28)
	andi $17,$17,1
	sw $25,0xc50($28) # 复位看门狗
	beq $17,$0,KLOP
	lw $17,0xc10($28)
	j CODED
KFUN1:
	lw $17,0xc12($28)
	andi $17,$17,1
	beq $17,$0,NOKEY
	j READKEY
NOKEY:
	addi $2,$0,0xff
	j KEYEXIT
READKEY:
	lw $17,0xc10($28)
CODED:
	addi $16,$0,0xee
	bne $17,$16,KEY1
	addi $2,$0,0xd
	j KEYEXIT
KEY1:
	addi $16,$0,0xed
	bne $17,$16,KEY2
	addi $2,$0,0xe
	j KEYEXIT
KEY2:
	addi $16,$0,0xeb
	bne $17,$16,KEY3
	addi $2,$0,0
	j KEYEXIT
KEY3:
	addi $16,$0,0xe7
	bne $17,$16,KEY4
	addi $2,$0,0xf
	j KEYEXIT
KEY4:
	addi $16,$0,0xde
	bne $17,$16,KEY5
	addi $2,$0,0xc
	j KEYEXIT
KEY5:
	addi $16,$0,0xdd
	bne $17,$16,KEY6
	addi $2,$0,9
	j KEYEXIT
KEY6:
	addi $16,$0,0xdb
	bne $17,$16,KEY7
	addi $2,$0,8
	j KEYEXIT
KEY7:
	addi $16,$0,0xd7
	bne $17,$16,KEY8
	addi $2,$0,7
	j KEYEXIT
KEY8:
	addi $16 ,$0,0xbe
	bne $17,$16,KEY9
	addi $2,$0,0xb
	j KEYEXIT
KEY9:
	addi $16,$0,0xbd
	bne $17,$16,KEY10
	addi $2,$0,6
	j KEYEXIT
KEY10:
	addi $16,$0,0xbb
	bne $17,$16,KEY11
	addi $2,$0,5
	j KEYEXIT
KEY11:
	addi $16,$0,0xb7
	bne $17,$16,KEY12
	addi $2,$0,4
	j KEYEXIT
KEY12:
	addi $16,$0,0x7e
	bne $17,$16,KEY13
	addi $2,$0,0xa
	j KEYEXIT
KEY13:
	addi $16,$0,0x7d
	bne $17,$16,KEY14
	addi $2,$0,3
	j KEYEXIT
KEY14:
	addi $16,$0,0x7b
	bne $17,$16,KEY15
	addi $2,$0,2
	j KEYEXIT
KEY15:
	addi $16,$0,0x77
	bne $17,$16,KEY16
	addi $2,$0,1
	j KEYEXIT
KEY16:
	addi $16,$0,0xff
KEYEXIT:
	ADDI $29,$29,4
	lw $17,0($29)
	addi $29,$29,4
	lw $16,0($29)
	addi $29,$29,4
	lw $28,0($29)
	addi $29,$29,4
	lw $1,0($29) #出栈
	jr $31