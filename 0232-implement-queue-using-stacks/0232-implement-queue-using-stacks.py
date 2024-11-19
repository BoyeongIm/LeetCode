class MyQueue(object):
    # stack: LIFO
    # queue: FIFO
    def __init__(self):
        self.instack = []
        self.outstack = []

    def push(self, x):
        self.instack.append(x)

    def pop(self):
        return self.peek()

    def peek(self):
        if not self.outstack:
            while self.instack:
                self.outstack.append(self.instack.pop())
        return self.outstack[-1]

    def empty(self):
        if not self.instack and not self.outstack:
            return True
        else:
            return False
        


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()