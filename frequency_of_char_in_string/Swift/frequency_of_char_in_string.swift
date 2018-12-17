import Foundation

// declare a class in Swift
class StringManipulate
{
	// define a method
	// label: the_str
	// parameter: my_str, type: String
	// return type: String
	func stringFormat(the_str my_str:String) -> String
	{
		// replace all the space in string with nothing
		let rmSpaceStr = my_str.replacingOccurrences(of:" ", with: "")

		// convert the string into lowercase
		let lwrStr = rmSpaceStr.lowercased()

		// convert the string into array
		var arr = Array(lwrStr)
		// sort the array in ascend order
		arr.sort()
		// conver the array back to the string, make the string be sorted
		let sortedStr = String(arr)

		// give it back to the main flow
		return sortedStr
	}
}

// class for implement the method to calculate the frequency of char and print it with format
class FreqOfChar
{
	// return type: A `Dictionary` with `Character` as Key-Type, `Int` as Value-Type 
	func freqOfCharInStr(the_str my_str:String) -> Dictionary<Character,Int>
	{
		// convert the given string into array
		var arr = Array(my_str)

		// make an empty dictionary with Character(key) and Int(value)
		var my_dict = [Character:Int]()

		// run variable
		var i = 0
		var j = 0
		// frequency of char
		var count = 0

		// get the number of elements in array
		var len = arr.count

		// loop through the array
		while(i < len)
		{
			// every char appears at least once
			count = 1

			// if we hit the last char, obviously, this char just appears once, so put it into the dictionary with default freq
			if(i == len - 1) {
				my_dict[arr[i]] = count
				// exit the loop since we reach the last char
				break
			}else{
				// if not, get the next index
				j = i + 1
			}

			/* `while` 2 consecutive char in array is the same
			* increase the freq(count += 1)
			* decrease the len
			* remove the second char from the array(`arr.remove(at: removed_index)`)
			*/
			while(arr[i] == arr[j])
			{
				count += 1
				arr.remove(at: j)
				len -= 1
				// if we hit the last char(while decrease the len), exit the loop
				if(i == len - 1)
				{
					break
				}
			}

			// put the current char and its freq into dictionary
			my_dict[arr[i]] = count
			// increase run the variable for fear that it will cause us infinite loop
			i += 1
		}

		// give back the dictionary
		return my_dict
	}

	// print the char and its freq with format
	func printDict(the_dict my_dict:Dictionary<Character,Int>)
	{
		// get all the keys(`my_dict.keys`) and convert it to array of keys(`Array()`)
		var my_keys = Array(my_dict.keys)
		// sort the array of keys, which is actually sort the char alphabetically
		my_keys.sort()

		// for-loop through the array of key, print out the char(`key`) and its freq(`my_dict[key]`)
		for key in my_keys
		{
			/* Swift is good at handling `nil`, so that when we access the dictionary element, we receive this
			* my_dict = ["a": 1, "v":2]
			* my_dict["a"] -> Optional(1)
			* Therefore, I have to use this format(my_dict[key] ?? 0)
			* Means that if there is value -> print value. If not, print 0
			* So, we got the result: (my_dict["a"] ?? 0) -> 1
			*/
			print("\'\(key)\' : \(my_dict[key] ?? 0)")
		}
	}
}

// make a string
let str: String = "Hello Swift World"

/* <heading> Format the string </heading> */
// make an instance of StringManipulate
let handle_str = StringManipulate()
// call the method, with label
var new_str = handle_str.stringFormat(the_str: str)

/* <heading> Calculate the frequency of char in string </heading> */
let freq_of_char = FreqOfChar()
var dictionary = freq_of_char.freqOfCharInStr(the_str: new_str)
freq_of_char.printDict(the_dict: dictionary)
