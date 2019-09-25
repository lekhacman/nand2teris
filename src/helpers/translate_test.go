package helpers

import "testing"

func TestToBoolean(t *testing.T) {
	input := "0011110011000011"
	want := "{false, false, true, true, true, true, false, false, true, true, false, false, false, false, true, true}"

	got := ToBoolean(input)

	if got != want {
		t.Errorf("ToBoolean(%v) = %v\n want %v", input, got, want)
	}
}
