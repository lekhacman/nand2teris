1 movl $0x4050,%eax     Immediate--Register, 4 bytes
2 movw %bp,%sp          Register--Register,  2 bytes
3 movb (%rdi,%rcx),%al  Memory--Register,    1 byte
4 movb $-17,(%esp)      Immediate--Memory,   1 byte
5 movq %rax,-12(%rbp)   Register--Memory,    8 bytes


movb $0xF, (%ebx)    => bytes has 8 bits but the first argument has only 4 bits
movl %rax, (%rsp)    => data lost cuz %rax is 8 bytes
movw (%rax),4(%rsp)  => unknown operation
movb %al,%sl         => unknown register %sl (correct)
movq %rax,$0x123     => invalid operation (correct)
movl %eax,%rdx       => valid
movb %si, 8(%rbp)    => data lost

Solution
movb $0xF, (%ebx)    => Cannot use %ebx as address register
movl %rax, (%rsp)    => Mismatch between instruction suffix and register ID
movw (%rax),4(%rsp)  => Cannot have both source and destination be memory references
movb %al,%sl         => No register named %sl
movl %eax,$0x123     => Cannot have immediate as destination
movl %eax,%dx        => Destination operand incorrect size
movb %si, 8(%rbp)    => Mismatch between instruction suffix and register ID
