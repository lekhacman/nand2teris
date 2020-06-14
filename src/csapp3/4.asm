src_t *sp;
dest_t *dp;

*dp = (dest_t) *sp;

sp is stored in %rdi
dp is stored in %rsi

src_t   dest_t      instruction
long    long        movq (%rdi), %rax
                    movq %rax, (%rsi)

char    int         movb    (%rdi), %al
                    movsbl  %al,    (%rsi)
char    unsigned    movzbl (%rdi), %eax
                    movl   %eax, (%rsi)
uChar   long        movzbq (%rdi), %rax
                    movq   %rax, (%rsi)
int     char        movb (%rdi), %al
                    movb %al, (%rsi)
u       uChar       movl (%rdi), %eax
                    movb %al, (%rsi)
char    short       movsbw (%rdi), %ax
                    movw %ax, (%rsi)

Solutions
long long           movq (%rdi), %rax       Read 8 bytes
                    movq %rax, (%rsi)       Store 8 bytes
char int            movsbl (%rdi), %eax     Convert char to int
                    movl %eax, (%rsi)       Store 4 bytes
char unsigned       movsbl (%rdi), %eax     Convert char to int
                    movl %eax, (%rsi)       Store 4 bytes
unsigned char long  movzbl (%rdi), %eax     Read byte and zero-extend
                    movq %rax, (%rsi)       Store 8 bytes
int char            movl (%rdi), %eax       Read 4 bytes
                    movb %al, (%rsi)        Store low-order byte
unsigned uchar      movl (%rdi), %eax       Read 4 bytes
                    movb %al, (%rsi)        Store low-order byte
char short          movsbw (%rdi), %ax      Read byte and sign-extend
                    movw %ax, (%rsi)        Store 2 bytes
