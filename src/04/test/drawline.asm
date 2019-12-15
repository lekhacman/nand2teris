  @SCREEN
  D=A
  @first
  M=D

  @31
  D=A
  @n
  M=D

  @i
  M=0

(LOOP)
  @i
  D=M
  @n
  D=D-M
  @END
  D;JGT

  @i
  D=M
  @first
  A=D+M
  M=-1

  @i
  M=M+1
  @LOOP
  0;JMP

(END)
  @END
  0;JMP
