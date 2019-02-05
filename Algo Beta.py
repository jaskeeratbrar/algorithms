class Solution:

    def __init__(self, ip):
        self.inputList = ip

    def outputSortedList(self, A, B, n):

    // n - size of the list

        var = self.inputList
        counta = var.count(A)
        var.clear()
        var = [A] * counta
        blist = [B] * (n - counta)
        var.extend(blist)
        return var
