#import <Foundation/Foundation.h>
#import <stdio.h>
// import some defined library to use some external method
#import "StringManipulate.h"
#import "FreqOfCharInStr.h"

int main(int argc, const char * argv[])
{
	// define this one to run the code
	NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];

	// define a NSString to count the frequency of char in the string
	NSString * s = @"Hello Objective C World";
	
	// make a StringManipulate object to format the string
	StringManipulate * formatStr = [[StringManipulate alloc] init];
	// formatString method => "Hello" -> "ehllo"
	NSString * the_str = [formatStr formatString:s];

	// make a FreqOfCharInStr object to calculate the frequency of char, and print it out to the console
	FreqOfCharInStr * freqOfCharStr = [[FreqOfCharInStr alloc] init];
	// calculate frequency
	NSDictionary * my_dict = [freqOfCharStr freqOfChar:the_str];
	// print the result to the console
	[freqOfCharStr printDict:my_dict];

	// this one is to run the code, too
	[pool drain];
	return 0;
}
