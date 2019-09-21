package operator

func Nand(x, y bool) bool {
	return !(x && y)
}

func Xor(x, y bool) bool {
	return x && !y || y && !x
}
