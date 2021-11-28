class OrderedList:

  def __init__(self, lst=[]):
    
    self.lst = lst

  def add(self, nodes):
    for node in nodes:
      #if node == None: continue
      #for lnode in self.lst:
      #  
      #  if node == lnode:
      #    break
      if node != None:
        if node in self.lst: 
          continue
        self.lst.append(node)
        self.lst.sort()


  def getFirst(self):
    print([x.total for x in self.lst if x!=None])
    #print(self.lst[-1].total, "::", self.lst[-1].value)
    #print(self.lst[-1].value)
    return self.lst.pop()
  #def add(self, nodes):
  #  _lst = self.lst[::]
  #  print("1: ", _lst)

  #  for node in nodes:
  #    if node == None: return
  #    if node in _lst: continue
  #    if not _lst: _lst.append(node)
  #    else:
  #      i = 0
  #      for x in _lst:
  #        if (node != x and node.total >= x.total):
  #          _lst.insert(i, node)
  #          break
  #        i += 1
  #    self.lst = _lst[::]

  #def getFirst(self):
  #  print([x.total for x in self.lst if x != None])
  #  return self.lst.pop()

  def isEmpty(self):
    return not self.lst
