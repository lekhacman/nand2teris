package operator

import "testing"

func TestNand(t *testing.T) {
	cases := []struct {
		input [2]bool
		want  bool
	}{
		{
			input: [2]bool{false, false},
			want:  true,
		},
		{
			input: [2]bool{false, true},
			want:  true,
		},
		{
			input: [2]bool{true, false},
			want:  true,
		},
		{
			input: [2]bool{true, true},
			want:  false,
		},
	}

	for _, c := range cases {
		got := Nand(c.input[0], c.input[1])
		if got != c.want {
			t.Errorf("Nand(%t, %t) = %t, want %t", c.input[0], c.input[1], got, c.want)
		}
	}
}

func TestXor(t *testing.T) {
	cases := []struct {
		input [2]bool
		want  bool
	}{
		{
			input: [2]bool{false, false},
			want:  false,
		},
		{
			input: [2]bool{false, true},
			want:  true,
		},
		{
			input: [2]bool{true, false},
			want:  true,
		},
		{
			input: [2]bool{true, true},
			want:  false,
		},
	}

	for _, c := range cases {
		got := Xor(c.input[0], c.input[1])
		if got != c.want {
			t.Errorf("Nand(%t, %t) = %t, want %t", c.input[0], c.input[1], got, c.want)
		}
	}
}
