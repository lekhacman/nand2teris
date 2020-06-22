void cond(short a, short *p) {
    if(a == 0)
        goto else;
    if(*p >= a)
        goto else;
    *p = a;

    else:
        return;
}

// assembly can handle only 2 operands
