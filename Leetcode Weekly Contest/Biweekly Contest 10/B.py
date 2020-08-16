from typing import *


class Solution:
    def t2s_(self, root: TreeNode, s: Set) -> None:
        if root:
            self.t2s_(root.left, s)
            s.add(root.val)
            self.t2s_(root.right, s)
    
    def t2s(self, root: TreeNode) -> Set:
        s = set()
        self.t2s_(root, s)
        return s

    def twoSumBSTs(self, root1: TreeNode, root2: TreeNode, target: int) -> bool:
        tree1 = self.t2s(root1)
        tree2 = self.t2s(root2)
        for i in tree1:
            if target - i in tree2:
                return True
        return False
