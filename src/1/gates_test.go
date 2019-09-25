package gates

import (
	"testing"
)

func TestNot(t *testing.T) {
	cases := []struct {
		input bool
		want  bool
	}{
		{
			input: true,
			want:  false,
		},
		{
			input: false,
			want:  true,
		},
	}
	for _, c := range cases {
		got := Not(c.input)
		if got != c.want {
			t.Errorf("Not(%t) = %t, want %t", c.input, got, c.want)
		}
	}
}

func TestAnd(t *testing.T) {
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
			want:  false,
		},
		{
			input: [2]bool{true, false},
			want:  false,
		},
		{
			input: [2]bool{true, true},
			want:  true,
		},
	}

	for _, c := range cases {
		got := And(c.input[0], c.input[1])
		if got != c.want {
			t.Errorf("And(%t, %t) = %t, want %t", c.input[0], c.input[1], got, c.want)
		}
	}
}

func TestOr(t *testing.T) {
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
			want:  true,
		},
	}

	for _, c := range cases {
		got := Or(c.input[0], c.input[1])
		if got != c.want {
			t.Errorf("Or(%t, %t) = %t, want %t", c.input[0], c.input[1], got, c.want)
		}
	}
}

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
			t.Errorf("Xor(%t, %t) = %t, want %t", c.input[0], c.input[1], got, c.want)
		}
	}
}

func TestMux(t *testing.T) {
	cases := []struct {
		input [3]bool
		want  bool
	}{
		{
			input: [3]bool{false, false, false},
			want:  false,
		},
		{
			input: [3]bool{false, true, false},
			want:  false,
		},
		{
			input: [3]bool{true, false, false},
			want:  true,
		},
		{
			input: [3]bool{true, true, false},
			want:  true,
		},
		{
			input: [3]bool{false, false, true},
			want:  false,
		},
		{
			input: [3]bool{false, true, true},
			want:  true,
		},
		{
			input: [3]bool{true, false, true},
			want:  false,
		},
		{
			input: [3]bool{true, true, true},
			want:  true,
		},
	}

	//toBinary := func(x bool) byte {
	//	if x {
	//		return 1
	//	}
	//	return 0
	//}

	//fmt.Println("| a | b |sel|got|wan|err|")
	for _, c := range cases {
		got := Mux(c.input[0], c.input[1], c.input[2])
		//err := " "
		if got != c.want {
			t.Errorf(
				"Mux(%t, %t, %t) = %t, want %t",
				c.input[0],
				c.input[1],
				c.input[2],
				got,
				c.want,
			)
			//err = "x"
		}
		//fmt.Printf(
		//	"| %b | %b | %b | %b | %b | %v |\n",
		//	toBinary(c.input[0]),
		//	toBinary(c.input[1]),
		//	toBinary(c.input[2]),
		//	toBinary(got),
		//	toBinary(c.want),
		//	err,
		//)
	}
}

func TestDMux(t *testing.T) {
	cases := []struct {
		input [2]bool
		want  [2]bool
	}{
		{
			input: [2]bool{false, false},
			want:  [2]bool{false, false},
		},
		{
			input: [2]bool{false, true},
			want:  [2]bool{false, false},
		},
		{
			input: [2]bool{true, false},
			want:  [2]bool{true, false},
		},
		{
			input: [2]bool{true, true},
			want:  [2]bool{false, true},
		},
	}

	for _, c := range cases {
		got := DMux(c.input[0], c.input[1])
		if got != c.want {
			t.Errorf("DMux(%t, %t) = %v, want %v", c.input[0], c.input[1], got, c.want)
		}
	}
}

func TestNot16(t *testing.T) {
	cases := []struct {
		input [16]bool
		want  [16]bool
	}{
		{
			input: [16]bool{false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
			want:  [16]bool{true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true},
		},
		{
			input: [16]bool{true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true},
			want:  [16]bool{false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
		},
		{
			input: [16]bool{true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false},
			want:  [16]bool{false, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true},
		},
		{
			input: [16]bool{false, false, true, true, true, true, false, false, true, true, false, false, false, false, true, true},
			want:  [16]bool{true, true, false, false, false, false, true, true, false, false, true, true, true, true, false, false},
		},
		{
			input: [16]bool{false, false, false, true, false, false, true, false, false, false, true, true, false, true, false, false},
			want:  [16]bool{true, true, true, false, true, true, false, true, true, true, false, false, true, false, true, true},
		},
	}
	for _, c := range cases {
		got := Not16(c.input)
		if got != c.want {
			t.Errorf("Not16(%v)\n = %v, \nwant %v", c.input, got, c.want)
		}
	}
}

func TestAnd16(t *testing.T) {
	cases := []struct {
		input [2][16]bool
		want  [16]bool
	}{
		{
			input: [2][16]bool{
				{false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
				{false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
			},
			want: [16]bool{false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
		},
		{
			input: [2][16]bool{
				{false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
				{true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true},
			},
			want: [16]bool{false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
		},
		{
			input: [2][16]bool{
				{true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true},
				{true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true},
			},
			want: [16]bool{true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true},
		},
		{
			input: [2][16]bool{
				{true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false},
				{false, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true},
			},
			want: [16]bool{false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
		},
		{
			input: [2][16]bool{
				{false, false, true, true, true, true, false, false, true, true, false, false, false, false, true, true},
				{false, false, false, false, true, true, true, true, true, true, true, true, false, false, false, false},
			},
			want: [16]bool{false, false, false, false, true, true, false, false, true, true, false, false, false, false, false, false},
		},
		{
			input: [2][16]bool{
				{false, false, false, true, false, false, true, false, false, false, true, true, false, true, false, false},
				{true, false, false, true, true, false, false, false, false, true, true, true, false, true, true, false},
			},
			want: [16]bool{false, false, false, true, false, false, false, false, false, false, true, true, false, true, false, false},
		},
	}
	for _, c := range cases {
		got := And16(c.input[0], c.input[1])
		if got != c.want {
			t.Errorf("And16(%v)\n = %v, \nwant %v", c.input, got, c.want)
		}
	}
}

func TestOr8Way(t *testing.T) {
	cases := []struct {
		in  [8]bool
		out bool
	}{
		{
			in:  [8]bool{},
			out: false,
		},
		{
			in:  [8]bool{true, true, true, true, true, true, true, true},
			out: true,
		},
		{
			in:  [8]bool{false, false, false, true, false, false, false, false},
			out: true,
		},
		{
			in:  [8]bool{false, false, false, false, false, false, false, true},
			out: true,
		},
		{
			in:  [8]bool{false, false, true, false, false, true, true, false},
			out: true,
		},
	}

	for _, c := range cases {
		got := Or8Way(c.in)
		if got != c.out {
			t.Errorf("Or8Way(%v)\n = %t, want %t", c.in, got, c.out)
		}
	}
}
