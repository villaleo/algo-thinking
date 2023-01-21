package halloween_haul

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

var (
	treeA = &NeighborhoodNode{
		left:  &NeighborhoodNode{candy: 72},
		right: &NeighborhoodNode{candy: 3},
	}
	treeB = &NeighborhoodNode{
		left:  &NeighborhoodNode{candy: 4},
		right: &NeighborhoodNode{candy: 9},
	}
	treeC = &NeighborhoodNode{
		left:  treeB,
		right: &NeighborhoodNode{candy: 15},
	}
	treeD = &NeighborhoodNode{
		left:  treeC,
		right: &NeighborhoodNode{candy: 2},
	}
	treeE = &NeighborhoodNode{
		left:  &NeighborhoodNode{candy: 6},
		right: treeD,
	}
	treeF = &NeighborhoodNode{
		left:  treeA,
		right: treeE,
	}
	treeG = &NeighborhoodNode{
		left:  &NeighborhoodNode{candy: 7},
		right: &NeighborhoodNode{candy: 41},
	}
	treeH = &NeighborhoodNode{
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
