using System;
// use this thing to make dictionary
using System.Collections.Generic;

namespace FreqCharInStr
{
	class Program
	{
		// make a class for implementating the function to remove the space character
		class StringManipulate
		{
			/// <summary>Receive a string then return a new string with no space in it</summary>
			/// <parameter>String str</paramter>
			/// <return>A string</return>
			public string rmSpaceChar(string str)
			{
				// make a new string so that it won't affect on the input string
				string new_str = str;
				// replace space characters in the string, eg: "Hello World" -> "HelloWorld"
				new_str = new_str.Replace(" ","");
				return new_str;
			}
		}

		// class for sorting the array in ascend order
		class ArraySorting
		{
			/// <summary>Receive a string, then put the letter in the alphabeltic order in the return string</summary>
			public string SortArray(string str)
			{
				// convert the string into array of char
				char[] my_str = str.ToCharArray();
				// sort the array ascendingly, according to the ASCII table
				Array.Sort(my_str);
				// make a string from the array of string
				string new_str = new string(my_str);
				return new_str;
			}
		}

		// get the frequency of character in string
		class Frequency
		{
			/// <summary>a method to get the freq of char in str</summary>
			/// <return>A dictionary holding the char and its freq</return>

			public Dictionary<char,int> Frequency_of_char(string str)
			{
				// make a dictionay to hold the char and its freq
				Dictionary<char,int> dict = new Dictionary<char,int>();
				// get the length of the string
				int len = str.Length;
				// count variable to travel through the array to get the char
				int i = 0;
				int j = 0;
				// the frequency of char, first initialize it with `0`, because everything in the first place should be started with `0`
				int count = 0;
				
				// loop through the array with `while` loop because the iteriatation of this loop is unpredictable
				while(i < len)
				{
					// every character should appear at least once in the array
					count = 1;
					// if `i` reach the last index, print out that this is the last character, it should appear once only in the string
					if(i == len - 1) {
						// add to the Dictionary a new pair of value
						dict.Add(str[i],count);
						// break the loop because it already got to the last index
						break;
					}else{
						// if `i` doesn't get to the last index, `j` will be the next index
						j = i + 1;
					}

					// compare two consecutive char, if they are the same, remove the second char, decrease the len of the array by 1
					// the same character means that the character `str[i]` has to appear more than 1, increase count by 1
					while(str[i] == str[j])
					{
						count++;
						str = str.Remove(j,1);
						len--;
						// if `i` got to the last character while we remove character at index `j`, exit the loop
						// for example, some last character of the loop is the same
						/*
						*	'www' -> i = 0, j = 1, len = 3
						*	'ww'  -> i = 0, j = 1, len = 2
						* 	'w'   -> i = 0, j = 1, len = 1 -> i == len - 1, this is the end of the loop, break
						* If not, `j` will be j = 1, index out of bound exception
						*/
						if(i == len - 1)
						{
							break;
						}
					}

					// add to the Dictionary a new pair of char and its frequency
					dict.Add(str[i],count);
					// increase `i`(index) so that we won't be arrange in infinite loop
					i++;
				}

				// bring all the dictionary back to the main function
				return dict;
			}
		}

		static void Main(string[] args)
		{
			// make a string
			string input = "Hello C sharp world";
			
			/// <heading>Remove space character</heading>
			// make an object to implement the function
			StringManipulate rmSpaceChar = new StringManipulate();
			// make an empty string to receive a string without spaces
			string my_str = "";
			// remove the space then assign it
			my_str = rmSpaceChar.rmSpaceChar(input);

			/// <heading>Convert the all uppercase letter in the string into lowercase</heading>
			my_str = my_str.ToLower();
			
			/// <heading>Sort the string</heading>
			ArraySorting arrSort = new ArraySorting();
			// sort the array
			my_str = arrSort.SortArray(my_str);

			/// <heading>Calculate the frequency of character in the string</heading>
			// create an instance to implement the method to count the frequency
			Frequency freq = new Frequency();
			// make a dictionary
			Dictionary<char,int> my_dict = new Dictionary<char,int>();
			// initialize to the dictionary
			my_dict = freq.Frequency_of_char(my_str);

			// print out the dictionary, each key-value
			// make a KeyValuePair instance to access to the pair of values in Dictionary
			foreach(KeyValuePair<char,int> word in my_dict)
			{
				// Access the `Key` and `Value` field of the `word` instance
				Console.WriteLine("\'{0}\' : {1}",word.Key,word.Value);
			}
		}
	}
}
