# this is the function that will take a string, and return a array of character(in lowercase) in the string, and but them in alphabetic order
# 'Hello World' --> ('d','e','h','l','l','l','o','o','r','w')
sub ConvertStringToCharArray
{
	# get the string first
	# since perl always get the inputs and treats them like array
	# we must first get the array of characters
	my @the_char = @_;

	# then join them again to make a string
	$string = join('',@the_char);

	# delete the space character
	# 'Hello World' --> ('Hello','World')
	@raw_string = split(' ', $string);

	# make a empty array to merge, later will store the characters of the string
	@raw_array = ();

	# loop through each string the the raw_string, convert the string into array
	foreach $str (@raw_string)
	{
		# split each char into element of the string
		@str_arr = split('',$str);
		# merge the arrays
		@raw_array = (@raw_array,@str_arr);
	}

	# sort the result array to get the uppercase letter to the top
	@raw_array = sort(@raw_array);
	# change all the uppercases to lowercases
	@format_array = UppercaseToLowerCase(@raw_array);
	# return the array
	return @format_array;
}

# this function is self-explanatory, but this function doesn't sort the array, so that it no longer the origin string
sub UppercaseToLowerCase
{
	# take the array
	my @list = @_;
	# sort the array with ASCII order, therefore, the capital letter will be in the first place
	# replace the capital letter, until we reach the lowercase number, then break out of the loop
	# this mean that the loop can be run shorter
	
	# sort the array
	@ascii_order = sort(@list);
	
	# count variable to track the index of the element in the array
	$i = 0;
	# loop through the array
	foreach $char (@ascii_order)
	{
		# get the ascii order of the character
		$order = ord($char);
		# A -> 65, Z -> 90 ==> $order >= 65 && $order <= 90
		if($order >= 65 && $order <= 90) {
			# replace that uppercase character with a lowercase one
			# reference of the `splice` function is in array.pl from 131 to 141
			# add 32 to the order result into the lowercase number
			splice(@list,$i,1,chr($order+32));
		}else{
			# since we had made all the lowercase character goes the top, if we reach a lowercase character
			# it's meant to `break` this loop, in order not to use too many resources
			last;
		}

		# increase the count variable to track the index of the element in the array
		$i++;
	}

	# sort the array once again
	@good_list = sort(@list);
	return @good_list;
}

# calculate the frequency of a character in a string
sub FrequencyCharacter
{
	# let first get the array
	my @array = @_;

	# get the size of the array
	$size = scalar(@array);

	# empty the hash before using it to store keys/values
	%data = ();

	# a variable to track the index of the character
	$i = 0;

	# loop through the array, we choose `while` loop in this case because we don't want the loop goes to some
	# where that is out of bound(index > array_max_index), because in the `while` body, we have to delete some character
	# which makes a massive effect to the loop

	# $size -> get to the maximum index of the array
	while($i < $size)
	{
		# all character must appear at least once in the string, so that the $count(default) must be 1
		$count = 1;
		# reach the next character
		# if i get to the last character of string, $array[$j] will be nothing instead of IndexOutOfBoundException
		$j = $i + 1;
		# if the next character is the same with the character we are working on, that character appears more than 1 times
		# since I have sort the array in the alphabetic order, same character will be placed next to each other
		while($array[$i] eq $array[$j])
		{
			$count = $count + 1;
			# delete the same character
			splice(@array,$j,1);
			# we have delete 1 character of the origin array, we should decrease the size of the array too
			$size = $size - 1;
		}

		# pass the character and its repetition into an hash
		$data{$array[$i]} = $count;

		# increase the index, so that not to getting into infinite-loop
		$i = $i + 1;
	}

	# pass the hash out as the result
	return %data;
}

# string example
print "String operation\n";
# give an example string
$strings = "Hello Perl World";
# convert this string into an array
@a = ConvertStringToCharArray($strings);
# a check to see if the string is null or not(I mean I shouldn't perform a function on this str = '')
$the_size = scalar(@a);
# if the string is null, size would less than 0
if($the_size <= 0)
{
	# point out the error, and exit the code, so that I don't have to care about those lines of code following this
	die("String cannot be null, please put in a string on line 128");
}
# see the repetition of the character in the string, store its in a hash variable, with keys and values
%big_data = FrequencyCharacter(@a);

# get all the keys of the hash
@names = keys %big_data;
# sort this keys so that it won't be in a random order
@names = sort(@names);
# log out the repetition and the character
foreach $name (@names)
{
	print "$name : $big_data{$name}\n";
}

print "\nInteger operation\n";
# make an array
@integers = (1,2,3,4,5,1,5,2,4);
# sort it in ASCII order
@integers = sort(@integers);
# use the function to check the amount of appearance of the character
%enormous_data = FrequencyCharacter(@integers);
# operate on the hash so that we know our result
@key_chain = keys %enormous_data;

@key_chain = sort(@key_chain);

foreach $single_key (@key_chain)
{
	print "$single_key : $enormous_data{$single_key}\n";
}
