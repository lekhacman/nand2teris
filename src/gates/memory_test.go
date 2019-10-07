package gates

import "testing"

func TestDFF(t *testing.T) {
	cases := []bool{
		true,
		false,
	}

	for id, in := range cases {
		memory := DFF(in)
		got := memory()
		if in != got {
			t.Errorf("#%d DFF(%t)() = %t", id, in, got)
		}
	}
}
