from tree import Node, Tree
from ordlist import OrderedList

file = open("input")

nodes = []
root = None
tree = Tree()

r = 0
for row in file:
  for element in row.split(" "):
    tree.addNode(r, int(element))
  r += 1

root = tree.getRoot()

def traverse(root):
  ordList = OrderedList()
  ordList.add([root])
  node = None
  total = 0 

  while not ordList.isEmpty():
    node = ordList.getFirst()
    if (node != None):
      #print("Node: ", node.value)
      if node.total > total: 
        total = node.total
      node.update()
      left, right = node.getChildren()

      ordList.add([left,right])
    else: break

  print("Total: " + str(total))

traverse(root)
