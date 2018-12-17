import java.util.HashMap;
import java.util.Arrays;
// ArrayList for receive individual keys of the HashMap
import java.util.ArrayList;
// Collections is used for sorting the ArrayList
import java.util.Collections;

public class FreqOfCharInStr
{
	// remove a char from string at specific index
	// receive an array of char and index to delete as parameters
	/* to remove a char at specific index, we override the rest of the array from that index and keep the front element
	*  (element whose index less than the remove_index) the same
	*/ 
	public String rmCharAt(char arr_char[], int index)
	{
		// get the number of element in the array
		int len = arr_char.length;

		// a run variable for for-loop
		int i = 0;
		// make a new array of char which is less than the input array 1 element
		char new_arr[] = new char[len-1];

		// copy the original array to the new array, from the beginning to next-to char with remove_index
		for(i = 0; i < index; i++)
		{
			new_arr[i] = arr_char[i];
		}
		// override the char from the remove_index with the one next to it and continue to the end of the array
		for(i = index; i < len - 1; i++)
		{
			new_arr[i] = arr_char[i+1];
		}

		// make a new string from the removed array
		String s = new String(new_arr);
		// return the string
		// because it's hard to return a array of character in Java, I choose to return a String, which is then can be converted back to the array
		return s;
	}

	// calculate the frequency of char in the string, return a HashMap which contains the char(Character) and its freq(Integer)
	// receive a array of char, which is transformed from a string
	public HashMap<Character,Integer> frequency_of_char(char arr_char[])
	{
		// make an empty HashMap
		HashMap<Character,Integer> dictionary = new HashMap<Character,Integer>();

		// run variable
		int i = 0;
		int j = 0;

		// ancestor of the frequency, always hold the value `0` at first
		int count = 0;

		// get the number of elements in the array
		int len = arr_char.length;

		// empty string, which will hold the return string when we remove element from the array then will be converted back to the array
		String str = "";

		// loop through element in the array
		while(i < len)
		{
			// each character appears at least one the string, right?
			count = 1;
			// if we reach the last element of the array, obviously, this character appear only 1, since we already sort the array
			if(i == len - 1){
				// push the char and its freq to the HashMap `dictionary`
				dictionary.put(arr_char[i],count);
				// break this loop because we have reached the last element
				break;
			}else{
				// if we haven't reached the last char, get the index of the next-to char
				j = i + 1;
			}

			// compare two next-to char, while it is the same, remove the char next-to it, decrease the len of the array, and increase the frequency
			while(arr_char[i] == arr_char[j])
			{
				count++;
				str = rmCharAt(arr_char,j);
				// convert the string back to the array
				arr_char = str.toCharArray();
				len--;
				// if `i` got to the last character while we remove character at index `j`, exit the loop
				// for example, some last character of the loop is the same
				/*
				*	'www' -> i = 0, j = 1, len = 3
				*	'ww'  -> i = 0, j = 1, len = 2
				* 	'w'   -> i = 0, j = 1, len = 1 -> i == len - 1, this is the end of the loop, break
				* If not, `j` will be j = 1, index out of bound
				*/
				if(i == len - 1)
				{
					break;
				}
			}

			// push the HashMap a new pair of char and freq
			dictionary.put(arr_char[i],count);
			// increase `i` so that we won't get to the infinite loop
			i++;
		}

		// give back the dictionary
		return dictionary;
	}

	// print the HashMap in ascending order
	// receive a HashMap
	public void print_dictionary(HashMap<Character,Integer> hashmap)
	{
		// get the keys of the HashMap, and put them into the ArrayList
		// in this case, keys are instance of Character so that ArrayList<Character> must be used
		// keySet() -> get all the keys
		ArrayList<Character> my_keys = new ArrayList<Character>(hashmap.keySet());
		// sort the keys, which is an ArrayList with Collections method
		Collections.sort(my_keys);
		// two string to hold value of `keys` and `values` of HashMap
		String value = "";
		String key = "";
		// for-loop through the ArrayList
		for(Character my_key : my_keys)
		{
			// convert keys from Character to String
			key = my_key.toString();
			// convert value from Integer to String, get the value by method `get(key)` with corresponding key
			value = hashmap.get(my_key).toString();
			// print to the console
			System.out.println("\'" + key + "\' : " + value);
		}
	}
}