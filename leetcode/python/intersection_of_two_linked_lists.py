class Solution:
    # @param two ListNodes
    # @return the intersected ListNode
    def getIntersectionNode(self, head_a, head_b):
        a, b = head_a, head_b
        while a and b and a is not b:
            a, b = a.next, b.next
            if not a:
                a, head_b = head_b, None
            if not b:
                b, head_a = head_a, None
        return b if a else None
