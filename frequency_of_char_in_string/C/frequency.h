#ifndef __frequency_h__
#define __frequency_h__

#include <stdio.h>
#include "sort.h"
#include "stringarr.h"
#include "dictionary.h"

// count the appearance of the char inside the string, receive a string pointer(arr) and its size
int frequency_of_char(char * arr, int size)
{
	// make a new size, which is the same like the parameter size, but later it will decrease and be returned back from the function
	int the_size = size;

	/* make a copied of the input string */

	// get the memory for sharing a size for a copy string
	char * cpy_str = malloc(size * sizeof(char));
	// if we cannot get the address for this copied string, delete it and announce error
	if(!cpy_str)
	{
		free(cpy_str);
		die("Couldn\'t make a copy string");
	}
	// if no error fall through, copy the string
	int rc = safecopy(size, cpy_str, size, arr);
	// if something is wrong with the copy string, delete it and log out the error
	if(rc == -1)
	{
		free(cpy_str);
		die("Couldn\'t copy the string");
	}

	// count the appearance frequency of the character
	// some tracking variable
	int i = 0;
	int j = 0;
	// the repetition of the char
	int count = 0;
	// loop through the string from the first char to the near last char(the_size - 1)
	// However in C, the last character is '\0', which mean that the length of the string is always greater than the alphabet letter in it 1 unit
	// Ex: "Hello" -> "Hello\0" in C
	//  Len : 5			Len : 6
	// Therefore, when I reach index (len - 2), which is actually the last character of the string, this is why C doesn't leave any letters not count
	
	/*
	* The reason why I choose to use while loop is that the repetition of the loop is not predictable.
	* It depends upon the the size of the string
	*/

	/*
	* In case I forget the logic behind this function when I read it later. Here is the logic behind the function:
	* If I found two next-to characters is the same, I delete the second character, repeat it over and over again until I got the different character
	* Because the string is sorted, the same character(if exists) will stand next-to each other, by this mean, every time I find the same character, `count` increase by 1
	* Until I got the different character, the recent value of `count` is the frequency of the character
	*/

	/*
	* Advantage: by sorting, I don't have to loop through all the array every time I need to compare one char, the same char will be deleted, so it leave the different characters only
	* Disadvantage: using too many function will cause this program to run slowly
	*/
	
	// loop the array
	while(i < the_size - 1)
	{
		// default count must be 1, since every character in the string appears at least one time
		count = 1;
		// get the index of the next character we are pointing to
		j = i + 1;
		// if the next-to char is equal to the pointed char
		while(cpy_str[i] == cpy_str[j])
		{
			// increase `count`
			count++;
			// remove the character at the next-to char
			int r = rmElAtIndex(cpy_str,the_size,j);
			// if we can remove successfully, no errors will pops up
			if(r != 0)
			{
				die("Cannot remove this element at this index");
			}
			// decrease the size, since we just delete 1 char from the string
			the_size--;

			// After this, the `while` loop will check if the next-to char is equal to the examed char or not
			// if it still equal, continue doing this procedure again
			// if not, exit this loop and keep the current frequency(`count`)
		}

		// print out to the console the char and its frequency
		printf("%c:%d\n",cpy_str[i],count);

		// increase the index we are pointing to, to prevent infinite-loop
		i++;
	}

	// if everything runs smoothly, return 0 as a sign of success
	return 0;
}

// just like the function above, the only difference is that instead of printing to the console, we assign the char and its freq to the struct
// this function receive a string, its size and a pointer to the struct
int frequency_of_char_dict(char * arr, int size, struct Dictionary * my_dict)
{
	int the_size = size;
	char * cpy_str = malloc(size * sizeof(char));
	if(!cpy_str)
	{
		free(cpy_str);
		die("Couldn\'t make a copy string");
	}
	int rc = safecopy(size, cpy_str, size, arr);
	if(rc == -1)
	{
		free(cpy_str);
		die("Couldn\'t copy the string");
	}

	int i = 0;
	int j = 0;
	int count = 0;
	while(i < the_size - 1)
	{
		count = 1;
		j = i + 1;
		while(cpy_str[i] == cpy_str[j])
		{
			count++;
			int r = rmElAtIndex(cpy_str,the_size,j);
			if(r != 0)
			{
				die("Cannot remove this element at this index");
			}
			the_size--;
		}

		// we create a struct contains character in the string and its frequency and the input pointer
		createDict(my_dict,cpy_str[i],count);

		// increase the index for continuing this loop to the nearly end of the string
		i++;
		// move the pointer to the next struct inside the array of struct
		my_dict++;
	}

	// return the i, as `i` has reach the end of the new string, since we remove some similar characters inside the string
	// the size of the string probably has changed
	return i;
}

#endif