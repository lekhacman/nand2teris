package gates

import (
	"encoding/json"
	"io/ioutil"
	"log"
	"path/filepath"
	"testing"
)

func TestHalfAdder(t *testing.T) {
	path, _ := filepath.Abs("./chips/02/HalfAdder.cmp.json")
	testPlanPath, _ := ioutil.ReadFile(path)
	var cases []struct {
		A     bool
		B     bool
		Sum   bool
		Carry bool
	}
	if err := json.Unmarshal(testPlanPath, &cases); err != nil {
		log.Fatal(err)
	}

	for id, c := range cases {
		sum, carry := HalfAdder(c.A, c.B)
		got := [2]bool{sum, carry}
		want := [2]bool{c.Sum, c.Carry}
		if got != want {
			t.Errorf("#%d HalfAdder\ngot:%v\nwan:%v\n", id+1, got, want)
		}
	}
}

func TestFullAdder(t *testing.T) {
	path, _ := filepath.Abs("./chips/02/FullAdder.cmp.json")
	testPlanPath, _ := ioutil.ReadFile(path)
	var cases []struct {
		A     bool
		B     bool
		C     bool
		Sum   bool
		Carry bool
	}
	if err := json.Unmarshal(testPlanPath, &cases); err != nil {
		log.Fatal(err)
	}

	for id, c := range cases {
		sum, carry := FullAdder(c.A, c.B, c.C)
		//if sum != c.Sum {
		//	t.Errorf("#%d Sum got:%v wan:%v\n", id+1, sum, c.Sum)
		//}
		//if carry != c.Carry {
		//	t.Errorf("#%d Carry got:%v wan:%v\n", id+1, carry, c.Carry)
		//}
		got := [2]bool{sum, carry}
		want := [2]bool{c.Sum, c.Carry}
		if got != want {
			t.Errorf("#%d FullAdder\ngot:%v\nwan:%v\n", id+1, got, want)
		}
	}
}
