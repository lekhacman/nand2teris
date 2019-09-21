package operator

func Nand(_x, _y int) int {
	var isOne = func(i int) bool { return i == 1 }
	x := isOne(_x)
	y := isOne(_y)

	result := !(x && y)

	if result {
		return 1
	}

	return 0
}
