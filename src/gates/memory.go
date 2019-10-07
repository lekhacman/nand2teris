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
