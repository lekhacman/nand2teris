package gates

// --- Primitive Gates ---
func Not(x bool) bool {
	return !x
}

func And(x, y bool) bool {
	return x && y
}

func Or(x, y bool) bool {
	return x || y
}

// --- End of Primitive Gates ---

func Nand(x, y bool) bool {
	return Not(And(x, y))
}

func Xor(x, y bool) bool {
	return Or(And(x, Not(y)), And(Not(x), y))
}

// If sel = true, return y, else return x
func Mux(x, y, sel bool) bool {
	return (x && !y && !sel) || (x && y && !sel) || (!x && y && sel) || (x && y && sel)
	//return Or(
	//  Or(
	//
	//  ),
	//  Or(
	//
	//  ),
	//)
}
