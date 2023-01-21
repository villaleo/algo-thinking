package halloween_haul

/// Problem source: https://dmoj.ca/problem/dwite12c1p4

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

type NeighborhoodNode struct {
	candy int
	left  *NeighborhoodNode
	right *NeighborhoodNode
}

const TestCases = 5

func Solution() {
	reader := bufio.NewReader(os.Stdin)
	var tree *NeighborhoodNode
	for i := 0; i < TestCases; i++ {
		line, err := reader.ReadString('\n')
		if err != nil {
			fmt.Println(err.Error())
			os.Exit(1)
		}
		tree = readTree(line)

		totalCandy := tree.countCandy()
		height := tree.calculateHeight()
		amountOfStreets := tree.calculateEdgeCount() - height
		fmt.Printf("%d %d\n", amountOfStreets, totalCandy)
	}
}

func readTreeHelper(line string, pos *int) *NeighborhoodNode {
	tree := &NeighborhoodNode{}
	if line[*pos] == '(' {
		*pos++
		tree.left = readTreeHelper(line, pos)
		*pos++
		tree.right = readTreeHelper(line, pos)
		*pos++
		return tree
	} else {
		tree.candy = int(line[*pos] - '0')
		*pos++
		if line[*pos] != ')' && line[*pos] != ' ' {
			tree.candy = tree.candy*10 + int(line[*pos]-'0')
			*pos++
		}
		return tree
	}
}

func readTree(line string) *NeighborhoodNode {
	var position int
	return readTreeHelper(line, &position)
}

func (root *NeighborhoodNode) isHouse() bool {
	return root.left == nil && root.right == nil
}

func (root *NeighborhoodNode) countCandy() int {
	if root.isHouse() {
		return root.candy
	}
	return root.left.countCandy() + root.right.countCandy()
}

func (root *NeighborhoodNode) calculateEdgeCount() int {
	if root.isHouse() {
		return 0
	}
	return root.left.calculateEdgeCount() + root.right.calculateEdgeCount() + 4
}

func (root *NeighborhoodNode) calculateHeight() int {
	if root.isHouse() {
		return 0
	}
	leftHeight, rightHeight := root.left.calculateHeight(), root.right.calculateHeight()
	return 1 + int(math.Max(float64(leftHeight), float64(rightHeight)))
}
