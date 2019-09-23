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
	return Or(
		Or(
			And(x, And(Not(y), Not(sel))),
			And(And(x, y), Not(sel)),
		),
		Or(
			And(Not(x), And(y, sel)),
			And(And(x, y), sel),
		),
	)
}
