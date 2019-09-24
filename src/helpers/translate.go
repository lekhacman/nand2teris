package helpers

import "strings"

func ToBoolean(str string) [16]bool {
	mapper := func(fn func(d string) bool, functor []string) [16]bool {
		var result [16]bool
		for i := 0; i < len(functor); i++ {
			result[i] = fn(functor[i])
		}
		return result
	}
	isOne := func(d string) bool { return "1" == d }
	digit := strings.Split(str, "")

	return mapper(isOne, digit)
}
