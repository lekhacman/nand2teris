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
