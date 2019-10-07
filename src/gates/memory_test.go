package gates

import (
	"encoding/json"
	"io/ioutil"
	"log"
	"path/filepath"
	"testing"
)

func TestDFF(t *testing.T) {
	cases := []bool{
		true,
		false,
	}

	for id, in := range cases {
		memory := DFF(in)
		got := memory()
		if in != got {
			t.Errorf("#%d DFF(%t)() = %t", id, in, got)
		}
	}
}

func TestBit(t *testing.T) {
	path, _ := filepath.Abs("./chips/03/a/Bit.cmp.json")
	testPlanPath, _ := ioutil.ReadFile(path)
	var series []struct {
		In   bool
		Load bool
		Out  bool
	}
	if err := json.Unmarshal(testPlanPath, &series); err != nil {
		log.Fatal(err)
	}

	bitChip := NewBit()
	bit := bitChip(series[0].In, series[0].Load)

	for i := 1; i < len(series); i++ {
		got := bit()

		if got != series[i].Out {
			t.Errorf("#%d Bit", i)
		}
		bit = bitChip(series[i].In, series[i].Load)
	}
}
