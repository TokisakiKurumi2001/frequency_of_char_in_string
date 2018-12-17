<?php
	// PHP defined module to format string and calculate the frequency
	require "string_format.php";
	require "freq_of_char_in_str.php";

	// declare a string
	$str = "Hello PHP world";

	// call the function
	$my_str = stringFormat($str);

	// calculate the frequency of char in string
	$my_dict = FreqOfChar($my_str);
	
	// print out the string
	echo "<h3>".$str."</h3>";
	// and result of the function
	printDict($my_dict);
?>
