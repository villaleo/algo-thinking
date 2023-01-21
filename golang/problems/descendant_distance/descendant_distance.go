package descendant_distance

/// Problem source: https://dmoj.ca/problem/ecna05b

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

type Person struct {
	name        string
	numChildren int
	children    []*Person
	score       int
}

var familyTree map[string]*Person
var descendantDistance int

func Solution() {
	var numTestCases int
	_, err := fmt.Scanln(&numTestCases)
	panicIfErr(err)

	var outputBuffers []*strings.Builder
	for testCase := 1; testCase <= numTestCases; testCase++ {
		familyTree = map[string]*Person{}
		readFamilyTree()

		var people []*Person
		for _, person := range familyTree {
			person.score = descendentsAtDistance(person, descendantDistance)
			people = append(people, person)
		}
		sort.SliceStable(people, func(i, j int) bool {
			if people[i].score == people[j].score {
				return people[i].name == people[j].name
			}
			return people[i].score > people[j].score
		})

		numPeople := len(familyTree)
		outputBuffers = append(outputBuffers, getResultsFromResultsSlice(people, numPeople))
	}
	for testCase, buffer := range outputBuffers {
		fmt.Printf("Tree %d:\n", testCase+1)
		fmt.Println(buffer.String())
	}
}

func readFamilyTree() {
	var numLinesForTestCase int
	_, err := fmt.Scanln(&numLinesForTestCase, &descendantDistance)
	panicIfErr(err)

	reader := bufio.NewReader(os.Stdin)
	for i := 0; i < numLinesForTestCase; i++ {
		line, err := reader.ReadString('\n')
		panicIfErr(err)
		line = strings.ReplaceAll(line, "\n", "")
		tokens := strings.Split(line, " ")
		rootName := tokens[0]
		numChildren, err := strconv.ParseInt(tokens[1], 10, 32)
		panicIfErr(err)

		if person, ok := familyTree[rootName]; !ok {
			familyTree[rootName] = &Person{
				name:        rootName,
				numChildren: int(numChildren),
				children:    []*Person{},
			}
		} else {
			person.numChildren += int(numChildren)
		}
		for _, name := range tokens[2:] {
			children := &familyTree[rootName].children
			if person, ok := familyTree[name]; ok {
				*children = append(*children, person)
			} else {
				newPerson := &Person{name: name}
				familyTree[name] = newPerson
				*children = append(*children, newPerson)
			}
		}
	}
}

func descendentsAtDistance(node *Person, distance int) int {
	if distance == 1 {
		return node.numChildren
	}
	var sum int
	for _, child := range node.children {
		sum += descendentsAtDistance(child, distance-1)
	}
	return sum
}

func panicIfErr(err error) {
	if err != nil {
		fmt.Println(err.Error())
		os.Exit(1)
	}
}

func getResultsFromResultsSlice(people []*Person, numPeople int) *strings.Builder {
	result := &strings.Builder{}
	for i := 0; i < 3 && i < numPeople && people[i].score > 0; {
		result.WriteString(fmt.Sprintf("%s %d\n", people[i].name, people[i].score))
		i++
		for i < numPeople && people[i].score == people[i-1].score {
			result.WriteString(fmt.Sprintf("%s %d\n", people[i].name, people[i].score))
			i++
		}
	}
	return result
}
