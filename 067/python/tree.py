class Node:

  def __init__(self, value, row = 0):
    self.left = None
    self.right = None

    self.value = value
    self.total = value

  def __gt__(self, node):
    if node != None:
      return self.total > node.total
  def __lt__(self, node):
    if node != None:
      return self.total < node.total
  def __ge__(self, node):
    if node != None:
      return self.total >= node.total
  def __le__(self, node):
    if node != None:
      return self.total <= node.total

  def getChildren(self):
    return self.left, self.right

  def update(self):
    if (self.left != None and self.left.total < self.left.value + self.total): 
      self.left.total = self.total + self.left.value
    else: self.left = None
    if (self.right != None and self.right.total < self.right.value + self.total): 
      self.right.total = self.total + self.right.value
    else: self.right = None


    ## The node has already been visited and has a better found path
    #if (self.stotal < parent.stotal + self.svalue): pass
    #else:
    #  self.total = parent.total + self.value
    #  self.stotal = parent.stotal + self.svalue
    #print(self.stotal)

class Tree:

  def __init__(self):
    self.nodes = []
    self.currentRow = None

  def getRoot(self):
    return self.nodes[0][0]

  def addNode(self, row, value):
    if (self.currentRow != row): 
      self.currentRow = row
      self.nodes.append([])
    
    node = Node(value, row) 
    self.nodes[self.currentRow].append(node)
    if self.currentRow > 0:
      self.setParents(node)


  def setParents(self, node):
      try: self.nodes[self.currentRow-1][len(self.nodes[self.currentRow])-1].left = node
      except IndexError: pass
      try: self.nodes[self.currentRow-1][len(self.nodes[self.currentRow])-2].right = node
      except IndexError: pass

