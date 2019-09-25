package helpers

import (
	"fmt"
	"strings"
)

func reduce(
	fn func(acc string, cur string) string,
	init string,
	f []string,
) string {
	out := init
	for _, item := range f {
		out = fn(out, item)
	}
	return out
}

func mapp(fn func(string) string, f []string) []string {
	out := make([]string, len(f))
	for id, item := range f {
		out[id] = fn(item)
	}
	return out
}

func ToBoolean(str string) string {
	binaryToBool := func(b string) string {
		if b == "0" {
			return "false"
		}
		return "true"
	}
	connect := func(acc, item string) string {
		return fmt.Sprintf("%s, %s", acc, item)
	}
	bools := mapp(
		binaryToBool,
		strings.Split(str, ""),
	)
	var out = reduce(
		connect,
		bools[0],
		bools[1:],
	)

	return fmt.Sprintf("{%s}", out)
}
