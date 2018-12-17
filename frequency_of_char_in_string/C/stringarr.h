#ifndef __stringarr_h__
#define __stringarr_h__

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int rmElAtIndex(char * arr, int size, int index)
{
	// run variable
	int i = 0;
	// if the input array is passing wrongly in, alert the errors
	if(!arr)
	{
		die("Array you give doesn\'t exit");
	}
	
	// if the index we want to delete greater than size, this mean error too
	if(index > size)
	{
		die("Index out of bound");
	}

	// loop from the index(we want to delete) to the end of array, overwrite the element at the index with the next element and continue to do so
	for(i = index; i < size - 1; i++)
	{
		arr[i] = arr[i+1];
	}

	// add to the end of the new string, last character of the original string
	arr[size-1] = '\0';
	return 0;
}

// convert uppercase string into lowercase string
char * strUpr2Lwr(char * arr, int size)
{
	// make a copy string, make a memory for it
	char * target = malloc(size * sizeof(char));
	// if we cannot make memory for it, declare an error and exit the code
	if(!target)
	{
		die("Make memory for copy string and doesn\'t succeed");
	}

	// copy the string into the test string so that we can perform any code on it without touching the original string
	int rc = safecopy(size, target, size, arr);
	// if the copy occur problems, it's time to get out
	if(rc == -1)
	{
		die("Cannot copy the string");
	}

	// run variable and its loop
	int i = 0;
	for(i = 0; i < size; i++)
	{
		/* if the element we point to(target[i]) is uppercase letter, ord('A') < ord(target[i]) < ord('Z')
		*							   									    /\
		*																  	 |
		* perl syntax comes to explanation ----------------------------------|
		*/
		if(target[i] >= 'A' && target[i] <= 'Z')
		{
			// change it to lowercase by adding 32, into it, 'a' - 'A' = 32 in ASCII table
			target[i] = target[i] + 32;
		}
	}

	// after finishing converting the whole string into lowercase letter, return for futher use
	return target;
}

// self-explanatory, all the function and workflow is like strUpr2Lwr
// however, instead of ord('A'), ord('z'), we use ord('a'),ord('z')
// and subtract the target element by 32
char * strLwr2Upr(char * arr, int size)
{
	char * target = malloc(size * sizeof(char));
	if(!target)
	{
		die("Make memory for copy string and doesn\'t succeed");
	}
	int rc = safecopy(size, target, size, arr);
	if(rc == -1)
	{
		die("Cannot copy the string");
	}

	int i = 0;
	for(i = 0; i < size; i++)
	{
		if(target[i] >= 'a' && target[i] <= 'z')
		{
			target[i] = target[i] - 32;
		}
	}

	return target;
}

// remove a character in the string
int rmCharInStr(char * arr, int size, char rmChar)
{
	// run variable
	int i = 0;
	// make a copy of the size because we will change it afterall
	int the_size = size;
	// using while, because the size can change
	while(i < the_size)
	{
		// if the target element is like the character we want to remove from the string, remove character that index
		// with function rmElAtIndex(), and decrease the size since we just remove 1 character from the string
		if(arr[i] == rmChar)
		{
			rmElAtIndex(arr, the_size, i);
			the_size--;
		}
		// never forget to increase run variable `i`, otherwise, we will cause an infinite loop
		i++;
	}

	// return the new size
	return the_size;
}

#endif