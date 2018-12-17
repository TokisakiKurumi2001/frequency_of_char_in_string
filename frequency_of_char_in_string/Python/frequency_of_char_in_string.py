# import defined module to use function
from stringformat import *
from freqofchar import *

# declare a string
my_str = "Hello Python World"

# format the string => "Hello" -> "ehllo"
sortedStr = stringFormat(my_str)

# calculate the frequency of char in string
dictionary = freqOfCharInStr(sortedStr)

# print out the dictionary with format
printDict(dictionary)
