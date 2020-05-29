  hex             unsigned      two's complement
src truncated   src truncated   src truncated
1   1  0001     1   1  001      1   1   001
3   3  0011     3   3  011      3   3   011
5   5  0101     5   5  101      5   -3  101
C   4  1100     12  4  100      -4      100
E   6  1110     14  6  110      -2      110

solution
                    1               1
                    3               3
                    5               5
                    4               4
                    6               6

int 4   bytes 5319 00000000 00000000 0001 0100 1100 0111
short 2 bytes      0001 0100 1100 0111
                   1100 1111 1100 0111
                   1100 1111 1100 0111