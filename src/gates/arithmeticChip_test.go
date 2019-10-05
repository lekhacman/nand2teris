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

type aluOutput struct {
	out [16]bool
	zr  bool
	ng  bool
}

func TestALU(t *testing.T) {
	path, _ := filepath.Abs("./chips/02/ALU.cmp.json")
	testPlanPath, _ := ioutil.ReadFile(path)
	var cases []struct {
		X   [16]bool
		Y   [16]bool
		ZX  bool
		NX  bool
		ZY  bool
		NY  bool
		F   bool
		NO  bool
		Out [16]bool
		ZR  bool
		NG  bool
	}
	if err := json.Unmarshal(testPlanPath, &cases); err != nil {
		log.Fatal(err)
	}

	for id, c := range cases {
		out, zr, ng := ALU(c.X, c.Y, c.ZX, c.NX, c.ZY, c.NY, c.F, c.NO)
		got := aluOutput{
			out, zr, ng,
		}
		want := aluOutput{
			c.Out, c.ZR, c.NG,
		}
		if got != want {
			t.Errorf("#%d ALU\ngot:%v\nwan:%v\n", id+1, got, want)
		}
	}
}

func TestALUnostat(t *testing.T) {
	path, _ := filepath.Abs("./chips/02/ALU-nostat.cmp.json")
	testPlanPath, _ := ioutil.ReadFile(path)
	var cases []struct {
		X   [16]bool
		Y   [16]bool
		ZX  bool
		NX  bool
		ZY  bool
		NY  bool
		F   bool
		NO  bool
		Out [16]bool
	}
	if err := json.Unmarshal(testPlanPath, &cases); err != nil {
		log.Fatal(err)
	}

	for id, c := range cases {
		got := ALUnostat(c.X, c.Y, c.ZX, c.NX, c.ZY, c.NY, c.F, c.NO)
		if got != c.Out {
			t.Errorf("#%d ALU-nostat\ngot:%v\nwan:%v\n", id+1, got, c.Out)
		}
	}
}
