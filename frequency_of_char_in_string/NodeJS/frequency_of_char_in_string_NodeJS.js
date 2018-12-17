function stringFormat(the_string)
{
	// <heading> Remove all the space character with nothing</heading>
	// to remove all character, we have to use regular expression
	// For example, / /g -> all spaces, /blue/g -> all the string "blue"
	var no_space_str = the_string.replace(/ /g,"");

	// <heading> Convert the string to the lowercase string with `toLowerCase` </heading>
	var lwr_str = no_space_str.toLowerCase();

	// <heading> Convert the string into array with `split`, distinguish different element with nothing("") </heading>
	// This is just like Perl
	var arr = lwr_str.split("");

	// <heading> Sort the array </heading>
	// this is why we have to convert it to the array, we cannot sort the string
	var sort_arr = arr.sort();

	// // <heading> Convert the array of char back to the string </heading>
	var sort_str = sort_arr.join("");

	return sort_str;
}

// make an Object, receive two parameter, a character(`char`) and its frequency(`freq`)
function Dictionary(char,freq)
{
	// assign the `char` and `freq` from the paramter to them of the Object (this.char = char)
	this.char = char;
	this.freq = freq;
}

// print out the result, which is the char and its freq to the console
function printDict(dict)
{
	// string with this format 'char':freq
	var string = "\'" + dict.char + "\' : " + dict.freq;
	// log out to the console
	console.log(string);
}

// calculate the frequency of character in the string
function freqOfChar(my_str)
{
	// convert the array to the string, with `split`, every char of string will an element(`split("")`)
	var arr = my_str.split("");
	// get the number of element in the array with `length`
	var len = arr.length;
	// make an empty array, with the size is like array `arr`
	var dict = new Array(len);

	// some run variable for the while-loop
	var i = 0;
	var j = 0;
	// the original frequency of the char
	var count = 0;

	// loop through each element of the `arr`
	while(i < len)
	{
		// each character appears at least one in the string, so that the default value must be 1
		count = 1;
		// if we reach the last character of the string, this char will appear only once in the string
		// so that make a record of character (`arr[i]`) and default freq(count = 1)
		if(i == len - 1) {
			dict[i] = new Dictionary(arr[i],count);
			// exit the loop, prevent the below code(which is only applied when we haven't reached the last element) from happening
			break;
		}else{
			// if we haven't reached the last element, get the next-to character
			j = i + 1;
		}

		// while two next-to characters are the same
		// increase the freq(`count++`), remove the second element(which is at index `j`) (`arr.splice(j,1)`)
		// decrease the len(`len--`) and if while the `len` is reduced, it make `i` reach the last element, exit the current while, print out the freq
		while(arr[i] == arr[j])
		{
			count++;
			arr.splice(j,1);
			len--;
			if(i == len - 1)
			{
				break;
			}
		}

		// assign to the array of Dictionary, a new record of the current char and its frequency
		dict[i] = new Dictionary(arr[i],count);
		// increase the run variable `i` so that we won't catch the infinite loop
		i++;
	}

	// give all the array of Dictionary back to the caller(main function)
	return dict;
}

// ultimate function, receive a string, print out to the console the character and its frequency in the string
function calcFreqOfChar(string)
{
	// format the input string(remove spaces, uppercase to lowercase then sort)
	var new_str = stringFormat(string);
	// convert the string into array, each character is an element in the array
	var new_arr = new_str.split("");
	// get the number of elements in the array
	var len = new_arr.length;
	// make an empty array to store list of Dictionaries(hold the character and its frequency)
	var dict = new Array(len);
	// assign to it
	dict = freqOfChar(new_str);
	// `forEach` element inside the `dict` array, print out to the console
	dict.forEach(printDict);
}

// make a string
var the_str = "Hello NodeJS World";
// call the ultimate function and pass the string into it
calcFreqOfChar(the_str);
