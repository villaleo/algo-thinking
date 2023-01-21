package descendant_distance

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

var (
	treeA = &Person{
		name:        "Ruben",
		numChildren: 2,
		children:    []*Person{{name: "Santiago"}, {name: "Nancy"}},
	}
	treeB = &Person{
		name:        "Leo",
		numChildren: 3,
		children: []*Person{
			{name: "Jose"},
			{name: "Violeta"},
			{
				name:        "Andrea",
				numChildren: 2,
				children:    []*Person{{name: "Trista"}, {name: "Brandon"}},
			},
		},
	}
)

func TestDescendentsAtDistance(t *testing.T) {
	assert.Equal(t, 2, descendentsAtDistance(treeA, 1))
	assert.Equal(t, 0, descendentsAtDistance(treeA, 5))
	assert.Equal(t, 2, descendentsAtDistance(treeB, 2))
}
