package gates

func HalfAdder(a, b bool) (sum, carry bool) {
	carry = And(a, b)
	sum = Xor(a, b)
	return
}
