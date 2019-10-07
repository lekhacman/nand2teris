package gates

// Primitive chip

/**
Data-flip-flop chip
Chip name: DFF
Inputs: in
Outputs: out
Function: out(t) = in(t - 1)

the Go-DFF chip implemented here is a partial application
*/
func DFF(in bool) func() bool {
	return func() bool { return in }
}

// End of primitive chip

/**
Chip name: Bit
Inputs: in, load
Outputs: out
Function:
If load(t - 1)
  then out(t) = in(t - 1)
  else out(t) = out(t - 1)
*/
func NewBit() func(in, load bool) func() bool {
	memory := DFF(false)

	return func(in, load bool) func() bool {
		memory = DFF(Mux(memory(), in, load))
		return memory
	}
}
