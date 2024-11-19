class MyStack(object):
    def __init__(self):
        self.queue1 = []
        self.queue2 = []

    def push(self, x):
        if self.queue1:
            self.queue1.append(x)
        else:
            self.queue2.append(x)

    def pop(self):
        if self.queue1:
            while self.queue1:
                x = self.queue1.pop(0)
                if len(self.queue1) == 0:
                    break
                self.queue2.append(x)
        else:
            while self.queue2:
                x = self.queue2.pop(0)
                if len(self.queue2) == 0:
                    break
                self.queue1.append(x)
        return x

    def top(self):
        if self.queue1:
            while self.queue1:
                x = self.queue1.pop(0)
                self.queue2.append(x)
        else:
            while self.queue2:
                x = self.queue2.pop(0)
                self.queue1.append(x)
        return x

    def empty(self):
        return not self.queue1 and not self.queue2


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()