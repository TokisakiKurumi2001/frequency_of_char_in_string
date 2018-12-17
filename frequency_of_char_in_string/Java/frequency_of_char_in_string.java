// HashMap is like Dictionary in C#, Java has Dictionary, but lots of people use HashMap, and its feature is like Dictionary
import java.util.HashMap;
// library for calling some array methods
import java.util.Arrays;

class FreqCharStr
{
	public static void main(String[] args)
	{
		// make a string for the program to calculate the frequency of character in that string
		String str = "Hello Java World";
		// an empty string to hold some changes of the original string
		String string = "";

		/// <heading> Remove all the space character in the string </heading>
		// make an instance, in case you forget how to make an instance in Java, like C#, different from Objective-C
		RmSpaceChar rmChar = new RmSpaceChar();
		// call the function
		string = rmChar.rmSpaceChar(str);

		// All the function(method) of the class in Java must start with an lowercase character, while in C#, the opposite thing happen

		/// <heading> Convert all the string to the lowercase </heading>
		string = string.toLowerCase();

		/// <heading> Sort the string in the alphabeltical order </heading>
		StringSorting strSort = new StringSorting();
		string = strSort.sortString(string);

		/// <heading> Calculate the frequency of character in the string </heading>
		FreqOfCharInStr freq = new FreqOfCharInStr();

		// make a HashMap(like Dictionary in C#) to store the character and its frequency
		// Note: `Character` is a class, `char` is a type, `Integer` is a class, `int` is a type
		// Declaration in Java is much different from C#, especially in HashMap and Dictionary
		HashMap<Character,Integer> my_dict = new HashMap<Character,Integer>();

		// convert the string into a array of char, so that we can access each char in the string
		char character[] = string.toCharArray();

		// calculate the frequency
		my_dict = freq.frequency_of_char(character);
		// and then print out the result to the console
		freq.print_dictionary(my_dict);
	}
}
