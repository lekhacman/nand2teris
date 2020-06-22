//x in %rdi, y in %rsi, z in %rdx
//orq     %rsi, %rdx
//sarq    $9, %rdx
//notq    %rdx
//movq    %rdx, %bax
//subq    %rsi, %rbx
//ret

short arith3(short x, short y, short z) {
    short p1 = z | y;
    short p2 = p1 >> 9;
    short p3 = !p2;
    short p4 = p3 - x;
    return p4;
}

//solution but i think the last line is incorrect
//short p1 = y | z;
// short p2 = p1 >> 9;
// short p3 = ~p2;
// short p4 = y - p3;

