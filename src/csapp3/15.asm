je 4003fd       // a + 1 = b + 2 = d
callq *%rax

je 400425       // 0x31 = 49. 49 -12 = 37 = 0x25

400544: 77 02   ja 400547
400545: 5d      pop %rbp

jmpq 4005e8