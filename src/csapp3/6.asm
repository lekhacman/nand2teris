%rbx = p
%rdx = q

leaq 9(%rdx), %rax          q + 9
leaq (%rdx,%rbx), %rax      q + p
leaq (%rdx,%rbx,3), %rax    q + 3p
leaq 2(%rbx,%rbx,7), %rax   8p + 2
leaq 0xE(,%rdx,3), %rax     3q + 14
leaq 6(%rbx,%rdx,7), %rax   7q + p + 6