package main

import (
	"fmt"
	"github.com/lekhacman/nand2teris/src/helpers"
)

func main() {
	toTranslate := [][6]string{
		{
			"0000000000000000",
			"0000000000000000",
			"0000000000000000",
			"0000000000000000",
			"00",
			"0000000000000000",
		},
		{
			"0000000000000000",
			"0000000000000000",
			"0000000000000000",
			"0000000000000000",
			"01",
			"0000000000000000",
		},
	}

	for _, c := range toTranslate {
		data := helpers.Mapp(helpers.ToBoolean, c[:])
		fmt.Printf("a=%s\nb=%s\nc=%s\nd=%s\nc=%s\nd=%s\n-------\n", data[0], data[1], data[2], data[3], data[4], data[5])
	}
}
