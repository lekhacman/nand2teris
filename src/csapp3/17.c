//long absdiff_se(long x, long y) {
//    long result;
//    if (x>= y)
//        goto x_ge_y;
//    lt_cnt++;
//    result = y - x;
//    return result;
//
//    x_ge_y:
//    ge_cnt++;
//    result = x - y;
//    return result;
//}
long absdiff_se(long x, long y) {
    long result;
    if (x < y)
        goto x_lt_y;
    ge_cnt++;
    result = x - y;
    return result;

    x_lt_y:
        lt_cnt++;
        result = y - x;
        return result;
}
