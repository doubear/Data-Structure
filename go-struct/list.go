package list

type Node struct {
	Value interface{}

	next *Node
}

func (n *Node) Next() *Node {
	return n.next
}

type SinglyLinkedList struct {
	front  *Node
	length int
}

//init list
func (s *SinglyLinkedList) Init() *SinglyLinkedList {
	s.length = 0
	return s
}

func New() *SinglyLinkedList {
	return new(SinglyLinkedList).Init()
}

func (s *SinglyLinkedList) Front() *Node {
	return s.front
}

func (s *SinglyLinkedList) Back() *Node {
	currentNode := s.front
	for currentNode != nil && currentNode.next != nil {
		currentNode = currentNode.next
	}
	return currentNode
}

func (s *SinglyLinkedList) Append(n *Node) {
	if s.front == nil {
		s.front = n
	} else {
		currentNode := s.front

		for currentNode.next != nil {
			currentNode = currentNode.next
		}

		currentNode.next = n
	}

	s.length++
}

func (s *SinglyLinkedList) Prepend(n *Node) {
	if s.front == nil {
		s.front = n
	} else {
		n.next = s.front
		s.front = n
	}

	s.length++
}

func (s *SinglyLinkedList) InsertBefore(insert *Node, before *Node) {
	if s.front == before {
		insert.next = before
		s.front = insert
		s.length++
	} else {
		currentNode := s.front
		for currentNode != nil && currentNode.next != nil && currentNode.next != before {
			currentNode = currentNode.next
		}

		if currentNode.next == before {
			insert.next = before
			currentNode.next = insert
			s.length++
		}
	}
}

func (s *SinglyLinkedList) InsertAfter(insert *Node, after *Node) {
	currentNode := s.front
	for currentNode != nil && currentNode != after && currentNode.next != nil {
		currentNode = currentNode.next
	}

	if currentNode == after {
		insert.next = after.next
		after.next = insert
		s.length++
	}
}

func (s *SinglyLinkedList) Remove(n *Node) {
	if s.front == n {
		s.front = n.next
		s.length--
	} else {
		currentNode := s.front

		// search for node n
		for currentNode != nil && currentNode.next != nil && currentNode.next != n {
			currentNode = currentNode.next
		}

		// see if current's next node is n
		// if it's not n, then node n wasn't found in list s
		if currentNode.next == n {
			currentNode.next = currentNode.next.next
			s.length--
		}
	}
}
