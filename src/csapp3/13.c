int comp (data_t a, data_t b) {
    return a COMP b;
}
a       b      tada
rdx    rsi     rdi
edx    esi     edi
dx     si      di
dl     sil     dil

cmpl %esi, %edi     a - b
setl %al            SF ^ OF
t = a - b