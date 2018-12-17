#ifndef __sort_h__
#define __sort_h__

// include necessary libraries for the program
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>

// create a new type, actually the pointer to the function in order to pass the function(actually pass the pointer of it) into
// other functions
typedef int (* compare) (char a, char b);

// if there is an error, use this function to log out for debugging purpose and exit the code
void die(const char * message)
{
	// error has been found
	if(errno) {
		perror(message);
	}else{
		// no built-in errors found
		printf("ERROR:%s",message);
	}
	// exit the code right away
	exit(1);
}

// copy the string from `from` to `to`
// safely add the size of two string as the parameter to make sure reduce errors of eof
int safecopy(int to_len, char * to, int from_len, char * from)
{
	// if the string(pointer to string) is null, which we cannot implement the entire code on copying null thing
	// raise the exception(like Python) and exit the code
	assert(to != NULL && from != NULL && "from and to cannot be NULL");

	// `-1` for the last character '\0'(end of string escape character)
	// if from_len >= to_len, we cannot copy all the character from `from` to `to`, therefore, we just loop to the to_len-1 then stop
	// if from_len == to_len -> from_len > to_len -1 -> we can copy all, assign to_len-1 for looping, nothing wrong will happen and '\0' can be add
	// if from_len < to_len -> loop through the `from` string, and copy all the characters
	int max = from_len > to_len - 1 ? to_len - 1 : from_len;

	// if from_len or to_len < 0, we can copy, because there is nothing to copy
	if(from_len < 0 || to_len <= 0)
	{
		// return -1 as an error flag
		return -1;
	}

	// count variable `i` for looping
	int i = 0;
	// loop though the minimum size(max) to make sure we don't operate on 'nothing'
	for(i = 0; i < max; i++)
	{
		// assign each element of `to` with `from`
		to[i] = from[i];
	}

	// add to the end of the string an end escape character
	to[to_len - 1] = '\0';
	// return 0 -> nothing wrong happens
	return 0;
}

// receive an array, a sorting order(compare), and size of the array then return sorted array
// we don't want to touch the original array, so that if we reuse the original array, nothing wrong will happen
char * bubble_sort(char * arr, int size, compare cmp)
{
	// `temp` for holding variable when swapping element
	int temp = 0;
	// count variable for two loops
	int i = 0;
	int j = 0;

	// call the compiler to give target a space equal to the space of the origin array(`arr`)
	// so that I can perform a fully copy
	char * target = malloc(size * sizeof(char));
	// if I cannot get the target, maybe the compiler cannot set the space for it
	if(!target)
	{
		// wrong thing happens, log out the message then exit the code(which is in `die` function)
		die("Cannot make the copy array");
	}

	// safely copy from array to target
	int rc = safecopy(size, target, size, arr);
	// if the error happens
	if(rc == -1)
	{
		// log out the message for debugging
		die("Copy between array has an big error, the size must be greater than 0");
		// release the target so that we can save the program from leaking information when something out of control happens
		free(target);
	}

	// loop through the array(target) 2 times to perform a bubble sort
	// loop through the array from index 0 to the near end index, because the last character is the string ending char '\0'
	// It would cause a big error because this thing will be at the beginning of the sorted string
	// the original function for sorting array is ... i < size .... j < size - 1
	for(i = 0; i < size - 1; i++)
	{
		for(j = 0; j < size - 2; j++)
		{
			// call the pointer to the function `cmp`
			if(cmp(target[j],target[j+1]) > 0)
			{
				// swap the 2 elements if they are in wrong position of the expected array(array that has been sorted)
				temp = target[j];
				target[j] = target[j+1];
				target[j+1] = temp;
			}
		}
	}

	return target;
}

// sorting order
int ascend(char a, char b)
{
	// if first char is greater than second char, we should swap
	return a - b;
}

int descend(char a, char b)
{
	return b - a;
}

#endif