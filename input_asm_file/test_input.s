.DATA 0x100000 # 数据段定义开始
 BUF:
 .WORD 0X000000FF, 0X55005500 # 定义数据
buf2:
.byte 3,8,87, 21 #定义了4个字节数，3,8,87, 21
.half 0x34a,15 #定义了2个半字（16位）数，十六进制的34a
    # 和十进制数15
.word "5":3, 6:3 #定义了4个字（32位）数，6，6，6，2
str:
.ascii "hel lo\0","a"
str2:
.asciiz "hello"
 .float     12.678

.double 12.678, 7.6137e-1

 .TEXT # 代码段定义开始
 start:
 addi $t0, $Zero, 0 # 程序的第一条指令必须有一个标号， $t0=0
 l1: lw $v0, buf ($t0) # $v0=000000FF (buf[0])
 l2: addi $t0, $t0, 4 # $t0=$t0+4
 l3:

 lw $v1, buf($t0) # $v1=55005500 (buf[4])
  add $v0, $v0, $v1 # $v0=$v0+$v1=550055FF
addi $t0, $t0, 4 # $t0=$t0+1
  sw $v0, buf($t0) # buf[8]=550055FF
  j start