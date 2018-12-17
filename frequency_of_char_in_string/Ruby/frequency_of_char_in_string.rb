# a method that works this
# "Hello" -> "ehllo"
def stringFormat(my_str)
	# remove all the space characters with regular expression
	# \s -> white space => \s+ -> white spaces
	# gsub, (I think) it is replacing string according to rules of regular expression
	rmSpaceStr = my_str.gsub(/\s+/,"")

	# convert all characters in the string to lowercase with `downcase`
	lwrStr = rmSpaceStr.downcase

	# convert the string into array with `chars`
	arr = lwrStr.chars
	# sort the array in ascending order with `sort`
	sortedArr = arr.sort
	# convert the array back to the string with `join`
	sortedStr = sortedArr.join

	# give back to the main flow
	return sortedStr
end

# a method that calculate the frequency of char in string
def freqOfChar(my_str)
	# convert the string into array
	arr = my_str.chars
	# get the number of elements in the array
	len = arr.size

	# an empty hash object, which store the key-value object, like dictionary
	my_dict = {}

	# some run vairables
	i = 0
	j = 0
	# the frequency of char
	count = 0

	# loop through the array
	while(i < len)
		# every char appears at least once
		count = 1
		
		# if we hit the last element of the array, put the char(`arr[i]`) and its freq(which is 1) into the `dictionary` and exit the loop
		if(i == len - 1)
			my_dict[arr[i]] = count
			break
		else
			# if not, get the next index
			j = i + 1
		end

		# `while` 2 consecutive chars are the same
		# increase the count by 1 -> freq increase
		# remove the second char(`delete_at(index_want_to_remove)`)
		# decrease the `len`
		while(arr[i] == arr[j])
			count += 1
			arr.delete_at(j)
			len -= 1
			# if we hit the last element when removing element, exit the loop
			if(i == len - 1)
				break
			end
		end

		# put the current char and its freq into hash `my_dict`
		my_dict[arr[i]] = count
		# increase the run variable so that we won't create an infinite loop
		i += 1
	end

	# give the hash object `my_dict` back to the main flow
	return my_dict
end

# print the hash, which has char-freq as key-value to the console with format
def printDict(dictionary)
	# get all the keys(all chars) of the hash and put it into the array
	my_keys = dictionary.keys
	# get the number of chars (in string)
	len = my_keys.size

	# loop through the array of chars
	# `0...len` : from 0 to less than len because the size = max_index + 1
	for i in (0...len)
		# get the char (from the array)
		key = my_keys[i]
		# get the freq of char from the hash
		value = dictionary[key]
		# print to the console
		puts "\'#{key}\' : #{value}"
	end
end

# make a string
string = "Hello Ruby World"
# format the string
the_str = stringFormat(string)
# calculate the frequency of char in string, and print it out
the_dict = freqOfChar(the_str)
printDict(the_dict)
