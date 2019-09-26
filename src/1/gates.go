package gates

// --- Given Primitive Gates ---
func Nand(x, y bool) bool {
	return !(x && y)
}

// --- End of Given Primitive Gates ---

func Not(x bool) bool {
	return Nand(x, x)
}

func And(x, y bool) bool {
	return Not(Nand(x, y))
}

func Or(x, y bool) bool {
	return Nand(Not(x), Not(y))
}

func Xor(x, y bool) bool {
	return Or(And(x, Not(y)), And(Not(x), y))
}

// If sel = true, return y, else return x
func Mux(x, y, sel bool) bool {
	//return (x && !y && !sel) || (x && y && !sel) || (!x && y && sel) || (x && y && sel)
	notX := Not(x)
	notY := Not(y)
	notSel := Not(sel)
	xy := And(x, y)
	notYnotSel := And(notY, notSel)
	ySel := And(y, sel)
	xnotYnotSel := And(x, notYnotSel)
	xyNotSel := And(xy, notSel)
	or1 := Or(
		xnotYnotSel,
		xyNotSel,
	)
	andNotXySel := And(notX, ySel)
	xysel := And(xy, sel)
	or2 := Or(
		andNotXySel,
		xysel,
	)
	return Or(
		or1,
		or2,
	)
}

// If sel=0 then {a=in, b=0} else {a=0, b=in}.
// [Go] If sel=false then {a=in, b=false} else {a=false, b=in}.
func DMux(in, sel bool) [2]bool {

	return [2]bool{
		Mux(in, false, sel),
		Mux(false, in, sel),
	}
}

func Not16(in [16]bool) [16]bool {
	var out [16]bool
	for i := 0; i < len(out); i++ {
		out[i] = Not(in[i])
	}
	return out
}

func And16(a, b [16]bool) [16]bool {
	var out [16]bool
	for i := 0; i < len(out); i++ {
		out[i] = And(a[i], b[i])
		//fmt.Printf("And(a=a[%d], b=b[%d], out=out[%d]);\n", i, i, i)
	}
	return out
}

func Mux16(a, b [16]bool, sel bool) [16]bool {
	var out [16]bool
	for i := 0; i < 16; i++ {
		out[i] = Mux(a[i], b[i], sel)
	}
	return out
}

func reduce(
	fn func(acc bool, cur bool) bool,
	init bool,
	f [8]bool,
) bool {
	out := init
	for _, item := range f {
		out = fn(out, item)
		//fmt.Printf("Or(a=in[%d], b=in[%d], out=temp);\n", id, id + 1)
	}
	return out
}

func Or8Way(in [8]bool) bool {
	return reduce(Or, false, in)
}

func Mux4Way16(a, b, c, d [16]bool, sel [2]bool) [16]bool {
	return Mux16(
		Mux16(a, b, sel[1]),
		Mux16(c, d, sel[1]),
		sel[0],
	)
}

func Mux8Way16(a, b, c, d, e, f, g, h [16]bool, sel [3]bool) [16]bool {

	return Mux16(
		Mux4Way16(a, b, c, d, [2]bool{sel[1], sel[2]}),
		Mux4Way16(e, f, g, h, [2]bool{sel[1], sel[2]}),
		sel[0],
	)
}
