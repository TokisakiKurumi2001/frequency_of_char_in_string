#import <Foundation/Foundation.h>
#import <stdio.h>
// import the `StringManipulate.h` to use the method `NSString2NSArray`
#import "StringManipulate.h"

// declare a class
@interface FreqOfCharInStr : NSObject
-(NSDictionary *)freqOfChar: (NSString *)my_str;
-(void)printDict: (NSDictionary *)the_dict;
@end

// implement the method
@implementation FreqOfCharInStr
/* <heading> Receive the NSString, return the NSDictionary(hold the char and its freq) </heading> */
-(NSDictionary *)freqOfChar: (NSString *)my_str;
{
	// make a StringManipulate object in order to use the method
	StringManipulate * stringFormat = [[StringManipulate alloc] init];
	
	// convert the input NSString to NSArray, then change it to the type of NSMutableArray to remove some duplicate character
	NSArray * arr = [stringFormat NSString2NSArray:my_str];
	// `mutableCopy` make a copy of immutable type to mutable one
	NSMutableArray * cpyArr = [arr mutableCopy];

	// get the number of charactes in NSString through the `length` method(applied on NSString)
	int len = [my_str length];

	// run variable and `count` indicates for the frequency of the character
	int i = 0;
	int j = 0;
	int count = 0;

	// make a NSMutableDictionary, so that we can add Object into it, with the capacity to hold all characters
	// in case the whole NSString contains all different characters
	NSMutableDictionary * dictionary = [NSMutableDictionary dictionaryWithCapacity:len];

	// loop through the array
	while(i < len)
	{
		// initialize the `count` with 1, since every char appears at least once
		count = 1;
		// get the character(from the NSString) through the NSMutableArray(with method `objectAtIndex`), which has the type of NSString
		NSString * current_char = [cpyArr objectAtIndex:i];

		// if we reach the last character of the string
		if(i == len - 1) {
			// convert the count(type of int) -> NSString `freq` using method to make NSString with from object(`stringWithFormat`)
			NSString * freq = [NSString stringWithFormat:@"%d",count];
			// pass the freq and its char into the NSMutableDictionary `dictionary`
			[dictionary setObject:freq forKey:current_char];
			// exit the loop since we have reached the last element
			break;
		}else{
			// if we haven't reached the last element yet, get the index of the next character
			j = i + 1;
		}

		/* if two consecutive character is the same, remove the second char until it's not
		* get the character with from `cpyArr`(which is the NSMutableArray) with `objectAtIndex`
		* compare two NSString by method `isEqualToString`
		*/
		while([[cpyArr objectAtIndex:i] isEqualToString:[cpyArr objectAtIndex:j]])
		{
			/* while the above condition is still right, increase the frequency by 1
			* remove the second character from the `cpyArr` by `removeObjectAtIndex`
			* decrease the len by 1
			* if by decreasing the `len`, we reached the last character, exit the loop
			*/
			count++;
			[cpyArr removeObjectAtIndex:j];
			len--;
			if(i == len - 1)
			{
				break;
			}
		}

		// convert the frequency from type `int` into type `NSString`
		NSString * freq = [NSString stringWithFormat:@"%d",count];
		// add the record into the `dictionary`
		[dictionary setObject:freq forKey:current_char];
		// increase the run variable lest the code should enter the infinite loop
		i++;
	}

	// give back the dictionary
	return dictionary;
}

/* <heading> Print each char and its freq to the console </heading> */
-(void)printDict: (NSDictionary *)the_dict;
{
	// get the all characters from the dictionary `the_dict` (char is the key)
	NSArray * keys = [the_dict allKeys];
	// sort the array of keys(array of characters) using descriptor, since `allKeys` return all keys without any order
	NSSortDescriptor * sortOrder = [[NSSortDescriptor alloc] initWithKey:@"self" ascending:YES];
	NSArray * sortDescriptors = [NSArray arrayWithObject:sortOrder];
	NSArray * sortedKeys = [keys sortedArrayUsingDescriptors:sortDescriptors];

	// loop through the sorted array of keys, print the char and its freq(`objectForKey`), freq is value, char is key
	for(NSString * key in sortedKeys)
	{
		NSLog(@"\'%@\' : %@",key,[the_dict objectForKey:key]);
	}
}
@end