class MyStack(object):
    def __init__(self):
        self.queue1 = []
        self.queue2 = []

    def push(self, x):
        self.queue2.append(x)
        for i in range(len(self.queue1)-1):
            self.queue2.append(self.queue1.pop(0))
        self.queue1 = self.queue2
       
    def pop(self):
        return self.queue1.pop(0)

    def top(self):
        return self.queue1[0]

    def empty(self):
        return len(self.queue1)==0


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()