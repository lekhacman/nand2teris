//             %rdi     %rsi    %rdx    %rcx
void switcher(long a, long b, long c, long *dest) {
    long val;


    switch (a) {
        case 5:      // case A L7
            c = b ^ 15;
        case 0:      // case B L3
            val =  c + 112;
            break;
        case 2:      // case C
        case 7:      // case D L5
            val = (b + c) << 2;
            break;
        case 4:      // case E L6
            val = a;
            break;
        default:
            val = b;
    }

    *dest = val;
}
