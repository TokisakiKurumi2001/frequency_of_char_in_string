<?php
	function freqOfChar($string)
	{
		// make an empty associative array, which is like a Dictionary in C#
		$dictionary = array();
		
		// convert the input string into array
		$array = str_split($string);

		// some run variable
		$i = 0;
		$j = 0;
		// the frequency of char `count` variable
		$count = 0;
		// the number of elements in array
		$len = count($array);

		// loop through the array
		while($i < $len)
		{
			// every character appears at least once
			$count = 1;

			// if we reach the last character
			if($i == $len - 1) {
				// add the char and its freq(automatically will be 1) to the `$dictionary`
				$dictionary[$array[$i]] = $count;
				// exit the loop
				break;
			}else{
				// if we haven't reached the last char yet, get the next character
				$j = $i + 1;
			}

			/* if two consecutive character is the same
			* increase the frequency by 1
			* decrease the length by 1
			* remove the second character(`array_splice`) -> j:index_to_delete, 1->number_of_elements_to_delete
			*/
			while($array[$i] == $array[$j])
			{
				$count++;
				array_splice($array,$j,1);
				$len--;
				// if we reach the last char, exit the loop
				if($i == $len - 1)
				{
					break;
				}
			}

			// add the current char and its freq to `$dictionary`
			$dictionary[$array[$i]] = $count;
			// increase run variable lest we should reach the infinite loop
			$i++;
		}
		return $dictionary;
	}

	// print the char and its freq
	function printDict($the_dict)
	{
		// get all the keys in associative array `$the_dict`
		$keys = array_keys($the_dict);
		// loop through each key
		foreach($keys as $key)
		{
			// print out the char($key) and its freq($the_dict[$key])
			echo "<p>'".$key."' : ".$the_dict[$key]."</p>";
		}
	}
?>