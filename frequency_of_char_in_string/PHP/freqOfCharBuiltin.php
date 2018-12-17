<?php
	function calcFreqOfChar($string)
	{
		// convert the input string into array
		$array = str_split($string);

		// calculate the freq of char by function
		$dictionary = array_count_values($array);

		return $dictionary;
	}
?>