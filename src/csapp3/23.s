dw_loop:
    movq    %rdi, %rbx
    movq    %rdi, %rcx
    idivq   $9, %rcx
    leaq    (,%rdi,4), %rdx
.L2:
    leaq    5(%rbx, %rcx), %rcx
    subq    $2, %rdx
    testq   %rdx, %rdx
    jg      .L2
    rep; ret

x %rdi
y %rcx
n %rdx
