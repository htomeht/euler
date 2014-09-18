class Fibonacci:

  def __init__(self):
    self._term = 0
    self._current = 0
    self._next = 1

  def __iter__(self):
    return self

  def next(self):
    self._current, self._next = self._next, self._current + self._next
    self._term += 1
    return self._current

  def getTerm(self):
    return self._term
