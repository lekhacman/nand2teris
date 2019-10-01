package gates

func HalfAdder(a, b bool) (sum, carry bool) {
	carry = And(a, b)
	sum = Xor(a, b)
	return
}

func FullAdder(a, b, c bool) (sum, carry bool) {
	//xorBC := Xor(b, c)
	//sum = Mux(xorBC, Not(xorBC), a)
	//carry = Mux(And(b, c), Or(b, c), a)
	s1, c1 := HalfAdder(a, b)
	sum, c2 := HalfAdder(s1, c)
	carry = Or(c1, c2)
	return
}
