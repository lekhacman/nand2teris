package gates

import "fmt"

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

func Add16(a, b [16]bool) (out [16]bool) {
	carry := false
	id := len(out) - 1
	for id >= 0 {
		out[id], carry = FullAdder(a[id], b[id], carry)
		id--
	}
	if carry {
		fmt.Println("Overflow!")
	}
	return
}

func Inc16(in [16]bool) [16]bool {
	var one = [16]bool{}
	one[15] = true
	return Add16(in, one)
}

func ALU(x, y [16]bool, zx, nx, zy, ny, f, no bool) (out [16]bool, zr, ng bool) {
	return
}
