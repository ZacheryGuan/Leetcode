# 递归。
# 每次返回两个值：dp[0]=抢当前节点 dp[1]=不抢当前节点
# 若抢当前节点，子节点的不能抢，用dp[1]
# 若不抢当前节点，子节点可以选个大的(并非一定用dp[0]!!!)
# 定义和使用类方法记得加self
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
    
    def is_leaf(self):
        if self.left is None and self.right is None:
            return True
        return False

class Solution:    
    def dp(self, node: TreeNode) -> (int, int):
        
        # rob this node, not rob
        if node is None:
            return 0, 0
        # if is_leaf(node):
        #     return node.x, 0
        
        left_money = self.dp(node.left)
        right_money = self.dp(node.right)

        rob_this_node = node.val + left_money[1] + right_money[1]
        # not_rob = left_money[0] + right_money[0]  # wrong
        not_rob = max(left_money) + max(right_money)  # 应该可以选
        print("r, nr", rob_this_node, not_rob)
        return rob_this_node, not_rob

    def rob(self, root: TreeNode) -> int:      
        return max(self.dp(root))
