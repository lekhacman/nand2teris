// keyboard = RAM[24576] screen = RAM[16384] - RAM[]
  @i
  M=0
  @16384
  D=A
  @scr
  M=D
  @8191
  D=A
  @limit
  M=D
(REFRESH)
  @KBD
  D=M
  @HIDE
  D;JEQ

  @SHOW
  0;JMP

(SHOW)
  @i
  D=M
  @scr
  A=D+M
  M=-1

  @limit
  D=D-M
  @REFRESH
  D;JEQ

  @i
  M=M+1
  @REFRESH
  0;JMP
(HIDE)
  @i
  D=M

  @scr
  A=M+D
  M=0

  @REFRESH
  D;JEQ

  @i
  M=M-1

  @REFRESH
  0;JMP
