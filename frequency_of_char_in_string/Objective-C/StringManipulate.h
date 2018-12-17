/*
*  The @interface and @implementation can be put into 1 file, name it with extension of .h
*  Then import it into another .m or .h will work fine!
*/

#import <Foundation/Foundation.h>
#import <stdio.h>

// make a class for implement some methods
@interface StringManipulate : NSObject
// declare a bunch of methods
// the syntax of defining a method in Objective-C(in case you forget)
// (return-type)function-name: (first-parameter-type)name-of-first-parameter [label-for-second-parameter(second-parameter-type)name-of-second-parameter, ... ]
-(NSString *)rmSpaceStr: (NSString *)my_str;
-(NSString *)upr2Lwr: (NSString *)my_str;
-(NSArray *)NSString2NSArray:(NSString *)my_str;
-(NSString *)NSArray2NSString:(NSArray *)my_arr withLen:(NSUInteger)len;
-(NSString *)sortString: (NSString *)my_str;
-(NSString *)formatString: (NSString *)my_str;
@end

// tell the compiler what methods should do
@implementation StringManipulate
/* <heading> Remove all the spaces character in the input NSString, return a new NSString without spaces </heading> */
-(NSString *)rmSpaceStr: (NSString *)my_str;
{
	// using the `stringReplacingOccurencesOfString` method to replace each space with(`withString`) nothing @""
	NSString * new_str = [my_str stringByReplacingOccurrencesOfString:@" " withString:@""];
	return new_str;
}

/* <heading> Convert all the uppercase letter in the string into lowercase letter </heading> */
-(NSString *)upr2Lwr: (NSString *)my_str;
{
	// using the `lowercaseString` method, which convert the uppercase to lowercase
	NSString * lwrStr = [my_str lowercaseString];
	return lwrStr;
}

/* <heading> Convert each character in the NSString into an element in NSArray </heading> */
-(NSArray *)NSString2NSArray: (NSString *)my_str;
{
	// get the number of character in the NSString
	NSUInteger len = [my_str length];
	// make an empty NSMutableArray `characters` that can hold all the characters of NSString(`initWithCapacity:len`)
	NSMutableArray * characters = [[NSMutableArray alloc] initWithCapacity:len];
	/* for-loop through the NSString
	* get each character of the string(`[my_str characterAtIndex:i]`)
	* convert that character into NSString `my_char` (`[NSString stringWithFormat:@"%c",the_char]`, we know that this is a char so that we use %c)
	*    @"" is a declaration of NSString
	* add the NSString into the NSMutableArray(`[characters addObject:my_char]`)
	*/
	int i = 0;
	for(i = 0; i < len; i++)
	{
		unichar the_char = [my_str characterAtIndex:i];
		NSString * my_char = [NSString stringWithFormat:@"%c",the_char];
		[characters addObject:my_char];
	}

	// make the NSArray `the_arr` from the NSMutableArray `characters` with `copy`
	NSArray * the_arr = [characters copy];
	return the_arr;
}

/* <heading> Join each element in the NSArray to make a NSString </heading> */
-(NSString *)NSArray2NSString: (NSArray *)my_arr withLen:(NSUInteger)len;
{
	/* In case you forget, NSMutableString or NSMutableArray, ... is a String or Array, ... that can add, remove element
	* NSString, NSArray is a strict one, when initializing, it can not be changed(can not delete or add element)
	* make an NSMutableString to concat string together(since element in NSArray has the type of NSString) with the maximum length equal to the number of elements in NSArray
	* get the number of element of the NSArray as the parameter, since, I'm kind of lazy apply the length method on NSArray
	*/
	NSMutableString * the_str = [NSMutableString stringWithCapacity:len];
	
	/* loop through the NSArray
	* get each element in the NSArray(`[my_arr objectAtIndex:i]`)
	* append that NSString(element in NSArray) to the NSMutableString `the_str`
	*/
	int i = 0;
	for(i =  0; i < len; i++)
	{
		NSString * my_char = [my_arr objectAtIndex:i];
		[the_str appendString:my_char];
	}

	// make a NSString from NSMutableString with `copy`
	NSString * my_str = [the_str copy];
	return my_str;
}

/* <heading> Sort the NSString in ascending order </heading> */
-(NSString *)sortString: (NSString *)my_str;
{
	// get the length of the NSString
	NSUInteger len = [my_str length];
	// convert NSString to NSArray(each char is an element)
	// The reason why I convert NSString to NSArray to use the sort method on the NSArray, which is unusual to apply NSString
	NSArray * arr = [self NSString2NSArray:my_str];
	
	// this is the syntax of `sorting` the NSArray in Objective-C
	/* first make `sortOrder` which sort the element in the NSArray
	* `initWithKey:@"self"` -> the element is NSArray is the thing to sort
	* `ascending:YES` -> order is ascending
	*/
	NSSortDescriptor * sortOrder = [[NSSortDescriptor alloc] initWithKey:@"self" ascending:YES];
	// make a NSArray from the NSSortDescriptor object `sortOrder`
	NSArray * descriptors = [NSArray arrayWithObject:sortOrder];
	// sort the NSArray using descriptors
	NSArray * sortedArr = [arr sortedArrayUsingDescriptors:descriptors];

	// convert the NSArray back to the NSString -> NSString sorted
	NSString * the_str = [self NSArray2NSString:sortedArr withLen:len];
	return the_str;
}

/* <heading> Put all the method together, receive a NSString -> return NSString(without spaces, no uppercase letter and sorted) </heading> */
-(NSString *)formatString: (NSString *)my_str;
{
	NSString * strSpace = [self rmSpaceStr:my_str];
	NSString * strLwr = [self upr2Lwr:strSpace];
	NSString * sortedStr = [self sortString:strLwr];
	return sortedStr;
}
@end