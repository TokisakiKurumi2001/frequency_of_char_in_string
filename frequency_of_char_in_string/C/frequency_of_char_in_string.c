#include <stdio.h>
#include "sort.h"
#include "stringarr.h"
#include "dictionary.h"
#include "frequency.h"

int main(int argc, char * argv[])
{
	// make a string
	char str[] = "Hello C World";
	// pointing to the string
	char * ptr_str = str;
	// get the size of the original string so that we can use to make a copied string
	int size = sizeof(str) / sizeof(char);


	// make another string then copy this string to it
	char * my_str = malloc(size * sizeof(char));
	// copy string
	int copy_string = safecopy(size, my_str, size, ptr_str);
	// if there is a problem with copying string
	if(copy_string == -1)
	{
		free(my_str);
		die("Couldn\'t copy the string");
	}
	// From now on, we will work on the copy string only, no touching the original string


	/* First remove the space character from the string */
	// declare a char to remove from the string
	char space = ' ';
	// remover all the spaces
	// size_after_rmSpace with be the new size of the string because when we remove the space, the length of the string has changed
	int size_after_rmSpace = rmCharInStr(my_str, size, space);


	/* Lowercase the string */
	char * lwr_str = strUpr2Lwr(my_str, size_after_rmSpace);
	// if we cannot convert to the lowercase character, there must be an error
	if(!lwr_str)
	{
		free(lwr_str);
		die("Couldn\'t convert the string into all lowercase string");
	}

	/* Sort the string to make the similar character stand next to each other */
	char * final_str = bubble_sort(lwr_str, size_after_rmSpace, ascend);
	// if we cannot sort the array, log out error message and exit the code
	if(!final_str)
	{
		free(final_str);
		die("Couldn\'t sort the string");
	}

	/* Count the frequency of the character inside the string */
	// First make an array of struct that hold enough the character in the string
	struct Dictionary dict[size_after_rmSpace];
	// create a pointer to point to the array of struct
	struct Dictionary * my_dict = NULL;
	// point the begining of the array of struct
	my_dict = dict;
	// start countning frequency, the `final_size` will be the size of the string that contains only different character
	int final_size = frequency_of_char_dict(final_str, size_after_rmSpace, my_dict);
	// print out the result
	// move the pointer to the beginning of the array
	my_dict = dict;
	// loop through the array of struct and print out the letter and its frequency
	int i = 0;
	for(i = 0; i < final_size; i++)
	{
		printDict(my_dict);
		// move the pointer to the next element in the array
		my_dict++;
	}


	/* Free the memory in case this program crash, no information will be leaked out */
	// free the copy string
	free(my_str);
	// free the lowercase string
	free(lwr_str);
	// free the sorted string
	free(final_str);
	return 0;
}
