Address Value   Register Value
0x100 0xFF      %rax     0x100
0x108 0xAB      %rcx       0x1
0x110 0x13      %rdx       0x3
0x118 0x11




instruction             destination value
addq %rcx,(%rax)        (%rax)      0x100
subq %rdx,8(%rax)       0x108       0xA8
imulq $16,(%rax,%rdx,8) 0x118       0x110
incq 16(%rax)           0x110       0x14
decq %rcx               %rcx        0x0
subq %rdx,%rax          %rax        0xFD

solution
0x100  0x100
0x108  0xA8
0x118  0x110
0x110  0x14
%rcx   0x0
%rax   0xFD