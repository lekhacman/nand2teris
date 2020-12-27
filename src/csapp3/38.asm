sum_element:
   leaq 0(,%rdi,8), %rdx     // 8i -> rdx
   subq %rdi, %rdx           // rdx = 8i - i = 7i
   addq %rsi, %rdx           // rdx = 7i + j
   leaq (%rsi,%rsi,4), %rax  // rax = 4j + j = 5j
   addq %rax, %rdi           // rdi = rax + rdi = 5j + i
   movq Q(,%rdi,8), %rax     // rax = [Q + 8rdi] = [Q + 8i + 40j]
   addq P(,%rdx,8), %rax     // rax = rax + [P + 8rdx] = rax + [P + 56i + 8j]
   ret                       // = [P + 56i + 8j] + [Q + 8i + 40j]