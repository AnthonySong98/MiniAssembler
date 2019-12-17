.DATA 0x100000 # 数据段定义开始
 BUF: .WORD 0X000000FF, 0X55005500 # 定义数据

 .TEXT # 代码段定义开始
 start:

 addi $t0, $Zero, 0 # 程序的第一条指令必须有一个标号， $t0=0
 lw $v0, buf ($t0) # $v0=000000FF (buf[0])
 addi $t0, $t0, 4 # $t0=$t0+4
 lw $v1, buf($t0) # $v1=55005500 (buf[4])
  add $v0, $v0, $v1 # $v0=$v0+$v1=550055FF
addi $t0, $t0, 4 # $t0=$t0+1
  sw $v0, buf($t0) # buf[8]=550055FF
  j start