class MinStack(object):
    def __init__(self):
        self.stack = []
        self.minv = []

    def push(self, val):
        self.stack.append(val)
        if not self.minv:
            self.minv.append(val)
        if val < self.minv[0]:
            self.minv[0] = val

    def pop(self):
        self.stack.pop(-1)
        # del 함수의 time complexity: O(n)

    def top(self):
        return self.stack[-1]

    def getMin(self):
        # return min(self.stack)
        # min 메서드의 time complexity: O(n)
        return self.minv[0]



# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()