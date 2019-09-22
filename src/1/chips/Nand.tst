load Nand.hdl,
output-file Nand.out,
output-list a b out,
compare-to Nand.cmp;
set a 0, set b 0, eval, output;
set a 0, set b 1, eval, output;
set a 1, set b 0, eval, output;
set a 1, set b 1, eval, output;
