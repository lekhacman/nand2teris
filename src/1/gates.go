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
