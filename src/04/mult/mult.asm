// Put your code here.
  @i
  M=1
  @2
  M=0

(LOOP)
  @i
  D=M
  @1
  D=D-M
  @END
  D;JGT

  @0
  D=M
  @2
  M=D+M

  @i
  M=M+1
  @LOOP
  0;JMP

(END)
  @END
  0;JMP
