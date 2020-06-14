// x in %rdi, y in %rsi, z in %rdx
//scale3:
//  leaq (%rsi,%rsi,9), %rbx      rbx=10y
//  leaq (%rbx,%rdx), %rbx        rbx = rbx + z    rbx = 10y + z
//  leaq (%rbx,%rdi,%rsi), %rbx   rbx = rbx + xy   rbx = 10y + z + xy
//  ret

short scale3(short x, short y, short z) {
    short t = 10*y + z + x*y;
    return t;
}
