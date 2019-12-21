.DATA 0x010000 # 数据段定义开始
 BUF:
 .WORD 0X000000FF, 0X55005500 # 定义数据
buf2:
.byte 3,8,87, 21 #定义了4个字节数，3,8,87, 21
.half 0x34a,15 #定义了2个半字（16位）数，十六进制的34a
    # 和十进制数15
.word 6:3, 2 #定义了4个字（32位）数，6，6，6，2
str:
.ascii "hel lo  A","a"
str2:
.asciiz "h"

 .TEXT 2020# 代码段定义开始
 start:
 add $v0, $v1, $t3
 addu $a1, $a0, $t2
sub $t7,$s2, $s6
subu $s1, $v0, $t4
and $t8, $s0, $a2

mult $a0, $t5
multu $a5, $t0
div $s3, $v1
divu $v1, $s3

mfc0 $t7,$s2,0
mtc0 $s2,$t7,0

or $a2, $s0, $t1
xor $t2, $v0, $s1
nor $a1, $s5, $t3
slt $v1, $s7, $t2
sltu $a0, $t1, $v0

sll $s0, $t2, 2
srl $t7, $v1, 3
sra $t4, $s5, 4

sllv $t8, $s0, $a2
srlv $t8, $s0, $a2
srav $t8, $s0, $a2




