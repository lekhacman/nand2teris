%rdi x
%rsi n

long shift(long x, long n) {
    x <<= 4;
    x >>= n;
    return x;
}

left shift: sal / shl
right shift: sar (arithmetic) / shr (logical)

shift:
    movq %rdi, %rax
    salq $4, %rax
    movl %esi, %ecx
    sarq %ecx, %rax
    ret
