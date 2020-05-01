class MinStack:

    def __init__(self):
        self.stack = None
        

    def push(self, x: int) -> None:
        if(self.stack == None):
            node = Node(x,x)
            self.stack=node
        else:
            node = Node(x,self.stack.min)
            node.next = self.stack
            self.stack = node

    def pop(self) -> None:
        val = self.stack.value
        self.stack = self.stack.next
        

    def top(self) -> int:
        return self.stack.value
        

    def getMin(self) -> int:
        return self.stack.min

class Node:
    def __init__(self, value, prev_min):
        self.min = min(value, prev_min)
        self.value = value
        self.next = None
