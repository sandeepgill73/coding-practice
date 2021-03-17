#(1) Store the first 10 cube roots, their cubes, and the last digit in the number.
#(2) Ignore the last 3 digits of the input number, and for the remaining numbers,
#    find the cube in the table that is less than or equal to the remaining number, and
#    take the corresponding cube root to be the first number in your answer. 
#(3) For the last 3 digits that you previously ignored, loop through the table and when
#    you get to the ith index, where i equals the last digit of the remaining 3 numbers,
#    take the corresponding number in the right column as your answer.
#(4) These numbers combined are the cube root answer.

def fastCubeRoot(num):
  
  # python dicts are unordered so we store the
  # elements in dicts within an array
  cubes_10 = [
     {'0': 0},
     {'1': 1},
     {'8': 8},
    {'27': 7},
    {'64': 4},
   {'125': 5},
   {'216': 6},
   {'343': 3},
   {'512': 2},
   {'729': 9}
  ]
  
  # get last 3 numbers and the remaining numbers
  arr = list(str(num))
  last = arr[-3:]
  first = int(''.join(arr[0:-3]))
  
  # answer will be stored here
  lastDigit = 0
  firstDigit = 0
  index = 0

  # get last digit of cube root
  for i in range(0, len(cubes_10)):
    if index == int(last[len(last)-1]):
      lastDigit = cubes_10[i].get(cubes_10[i].keys()[0])
    index += 1
    
  # get first digit of cube root
  index = 0
  for i in range(0, len(cubes_10)):
    if int(cubes_10[i].keys()[0]) <= first:
      firstDigit = index;
    index += 1
    
  # return cube root answer
  return str(firstDigit) + '' + str(lastDigit)
  
print(fastCubeRoot(830584))
print(fastCubeRoot(148877))
