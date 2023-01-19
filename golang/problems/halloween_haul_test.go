package problems

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

var (
	treeA = &Node{
		left:  &Node{candy: 72},
		right: &Node{candy: 3},
	}
	treeB = &Node{
		left:  &Node{candy: 4},
		right: &Node{candy: 9},
	}
	treeC = &Node{
		left:  treeB,
		right: &Node{candy: 15},
	}
	treeD = &Node{
		left:  treeC,
		right: &Node{candy: 2},
	}
	treeE = &Node{
		left:  &Node{candy: 6},
		right: treeD,
	}
	treeF = &Node{
		left:  treeA,
		right: treeE,
	}
	treeG = &Node{
		left:  &Node{candy: 7},
		right: &Node{candy: 41},
	}
	treeH = &Node{
		left:  treeF,
		right: treeG,
	}
)

func TestCountTotalCandy(t *testing.T) {
	assert.Equal(t, 4+9, treeB.countCandy())
	assert.Equal(t, 4+9+15, treeC.countCandy())
}

func TestMinimumStreets(t *testing.T) {
	assert.Equal(t, 32, treeH.calculateEdgeCount())
}

func TestCalculateHeight(t *testing.T) {
	assert.Equal(t, 6, treeH.calculateHeight())
}

func TestReadTree(t *testing.T) {
	var (
		testA = "(72 3)"
		testB = "(4 9)"
		testC = "((4 9) 15)"
	)

	assert.Equal(t, treeA, readTree(testA))
	assert.Equal(t, treeB, readTree(testB))
	assert.Equal(t, treeC, readTree(testC))
}
