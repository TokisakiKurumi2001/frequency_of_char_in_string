#ifndef __dictionary_h__
#define __dictionary_h__

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

// make a new type, `Dictionary`, which contains a char(letter) and its frequency in the string(freq)
struct Dictionary
{
	char letter;
	int freq;
}; // don't forget the semicolon after declare a struct

// receive a pointer to the struct, a letter and its frequency, pass in the letter and frequency into the struct we are pointing to
int createDict(struct Dictionary * dict,char my_letter, char my_freq)
{
	// if the pointer to the struct has some problems, log out the error message and exit the code
	if(!dict)
	{
		// delete the pointer, so that when this program crashes, nobody can steal any data
		free(dict);
		// message for log out
		die("Structure pointer encounters problems. Please pass in the real pointer");
	}

	// initialize data into the struct through its pointer
	dict->letter = my_letter;
	dict->freq = my_freq;

	// if there is something wrong this function, for examle, wrong pointer address, `die` would handle
	// therefore, I make this function `void` so that it don't need to return anything

	// However, for further development, I again make this function return some int
	return 0;
}

// print out the Dictionary
void printDict(struct Dictionary * dict)
{
	// access the field inside struct through pointer, we have to use arrow sign(`->`)
	printf("\'%c\': %d\n", dict->letter, dict->freq);
}

#endif