class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def dfs(node):
    if not node:
        return []

    result = []
    result.append(node.value)

    if node.left:
        result += dfs(node.left)

    if node.right:
        result += dfs(node.right)

    return result



# Example usage
# Create a tree
#        1
#      /   \
#     2     3
#    / \   / \
#   4   5 6   7
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
root.right.left = Node(6)
root.right.right = Node(7)

# Perform DFS on the tree
print(dfs(root)) # Output: [1, 2, 4, 5, 3, 6, 7]
