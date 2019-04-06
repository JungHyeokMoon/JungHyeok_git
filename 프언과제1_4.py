class binaryNode:
    def __init__(self, value):
        self.value = value
        self.right = None
        self.left = None


class binaryTree:
    def __init__(self):
        self.root = None

    def set_root(self, r):
        self.root = r

    def make_left_sub_tree(self, cur, left):
        cur.left = left

    def make_right_sub_tree(self, cur, right):
        cur.right = right

    def preorder_traverse(self, cur):
        if not cur:
            return
        print(cur.value, end="\n")
        self.preorder_traverse(cur.left)
        self.preorder_traverse(cur.right)

    def inorder_traverse(self, cur):
        if not cur:
            return
        self.inorder_traverse(cur.left)
        print(cur.value, end="\n")
        self.inorder_traverse(cur.right)

    def postorder_traverse(self, cur):
        if not cur:
            return
        self.postorder_traverse(cur.left)
        self.postorder_traverse(cur.right)
        print(cur.value, end="\n")


if __name__ == '__main__':
    node1 = binaryNode(15)
    node2 = binaryNode(1)
    node3 = binaryNode(37)
    node4 = binaryNode(61)
    node5 = binaryNode(26)
    node6 = binaryNode(59)
    node7 = binaryNode(48)

    tree = binaryTree()
    tree.set_root(node1)

    tree.make_left_sub_tree(node1, node2)
    tree.make_right_sub_tree(node1, node3)
    tree.make_left_sub_tree(node2, node4)
    tree.make_right_sub_tree(node2, node5)
    tree.make_left_sub_tree(node3, node6)
    tree.make_right_sub_tree(node3, node7)

    print("Preorder Traverse")
    tree.preorder_traverse(node1)
    print("Inorder Traverse")
    tree.inorder_traverse(node1)
    print("Postorder Traverse")
    tree.postorder_traverse(node1)
