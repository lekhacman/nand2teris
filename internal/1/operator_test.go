package operator

import "testing"

func TestNand(t *testing.T) {
	cases := []struct {
		input [2]int
		want  int
	}{
		{
			input: [2]int{0, 0},
			want:  1,
		},
		{
			input: [2]int{0, 1},
			want:  1,
		},
		{
			input: [2]int{1, 0},
			want:  1,
		},
		{
			input: [2]int{1, 1},
			want:  0,
		},
	}

	for _, c := range cases {
		got := Nand(c.input[0], c.input[1])
		if got != c.want {
			t.Errorf("Nand(%b, %b) = %b, want %b", c.input[0], c.input[1], got, c.want)
		}
	}
}
