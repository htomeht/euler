#You are given the following information, but you may prefer to do some research for yourself.
#
#    1 Jan 1900 was a Monday.
#    Thirty days has September,
#    April, June and November.
#    All the rest have thirty-one,
#    Saving February alone,
#    Which has twenty-eight, rain or shine.
#    And on leap years, twenty-nine.
#    A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
#
#How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

class Calender:

  def __init__(self):
    self.months = {1:31, 2:28, 3:31, 4:30, 5:31, 6:30, 7:31, 8:31, 9:30, 10:31, 11:30, 12:31}
  
  def getRangeYears(self, start, end):
    r = []
    for year in range(start, end+1):
      r.append(self.getYear(year))
    return r

  def getYear(self, year):
    y = [] 
    for month in range(1,13):
      y.append(self.getMonth(year, month))
    return y
  
  def getMonth(self, year, month):
    m = []
    for day in range(1, self.countDays(year, month)+1):
      m.append(day)
    return m

  #def getDay(self, year, month, day):

  def countDays(self, year, month):
    if (month == 2 and (year % 4 == 0 and (year % 100 != 0 or year % 400 == 0))): 
      return self.months[month] + 1
    return self.months[month]

class Day:
  
  def __init__(self, day):
    self.day = day

  def get(self):
    return self.day
