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

// print the dict to the console, push it into the array `dictionary` in the `app`(VueJS instance)
// so that VueJS can log it out the web page
function printDict(dict)
{
	// get the char and freq of the Dictionary, then assign to local variable
	var char = dict.char;
	var freq = dict.freq;
	// pass the data to the console, which is actually, push new record into the dictionary array
	// `char` and `freq` will automatically be replaced with actual value
	// This is one of the most fantastic thing in VueJS, the console pipe
	console.log(app.dictionary.push({character:char,frequency:freq}));
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

// the ultimate function, receive the string, and print each character and its frequency to the console
// so that VueJS can take that and present to the web page
function calcFreqOfChar(the_str)
{
	// formate the given string(remove spaces, uppercase to lowercase, sort)
	var new_str = stringFormat(the_str);
	// `split` each character in the string into individual element of the array
	var arr = new_str.split("");
	// get the number of elements in the array
	var len = arr.length;
	// make a empty array that will hold the array of Dictionary(instance to store character and its frequency)
	var new_dict = new Array(len);
	// assign to it
	new_dict = freqOfChar(new_str);
	// `forEach` element inside the Dictionary array, print out the element to the console, with some formats to push into the `app.dictionary` array
	new_dict.forEach(printDict);
}

// make a new HTML Component, for looping through the array(app.dictionary) and print out the char and freq with format : 'char':freq
Vue.component('paragraph', {
	// v-bind:record -> receive a record instance
	props:['record'],
	// access the record instance in the field of `character` and `frequency`
	template: '<p>\'{{ record.character }}\' : {{ record.frequency }}'
})

// declare a Vue instance, applied of element whose id = app
var app = new Vue({
	el: "#app",
	// the data, infomation in the `app`, replace the value in `{{value}}`
	data: {
		// reflect will be in the input field and the `p{{reflect}}`
		reflect: "Hello World",
		// an empty array, waiting for being push data
		dictionary: [
		]
	},
	// an method that is in the `app`
	methods: {
		// a function called when the user type anything in the input
		freqOfCharStr: function() {
			// remove all the element in the `dictionary` array
			this.dictionary.splice(0,this.dictionary.length);
			// get the text of the input
			var text = this.reflect;
			// calculate the frequency of the given string, then log out to the web page
			calcFreqOfChar(text);
		}
	}
})
