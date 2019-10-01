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

func TestAdd16(t *testing.T) {
	path, _ := filepath.Abs("./chips/02/Add16.cmp.json")
	testPlanPath, _ := ioutil.ReadFile(path)
	var cases []struct {
		A   [16]bool
		B   [16]bool
		Out [16]bool
	}
	if err := json.Unmarshal(testPlanPath, &cases); err != nil {
		log.Fatal(err)
	}

	for id, c := range cases {
		got := Add16(c.A, c.B)
		if got != c.Out {
			t.Errorf("#%d Add16\ngot:%v\nwan:%v\n", id+1, got, c.Out)
		}
	}
}

func TestInc16(t *testing.T) {
	path, _ := filepath.Abs("./chips/02/Inc16.cmp.json")
	testPlanPath, _ := ioutil.ReadFile(path)
	var cases []struct {
		In  [16]bool
		Out [16]bool
	}
	if err := json.Unmarshal(testPlanPath, &cases); err != nil {
		log.Fatal(err)
	}

	for id, c := range cases {
		got := Inc16(c.In)
		if got != c.Out {
			t.Errorf("#%d Inc16\ngot:%v\nwan:%v\n", id+1, got, c.Out)
		}
	}
}
