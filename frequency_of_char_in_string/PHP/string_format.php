<?php
	// format string : "Hello" -> "ehllo"
	function stringFormat($string)
	{
		/* <heading> Remove all spaces </heading> */
		// replace all space(' ') with nothing('') with str_replace
		$noSpaceStr = str_replace(' ','',$string);

		/* <heading> Convert uppercase to lowercase </heading> */
		// strtolower -> convert to lowercase
		$lowerStr = strtolower($noSpaceStr);

		/* <heading> Sort the character in string </heading> */
		// convert string to array, `split` each element in string
		$arr_str = str_split($lowerStr);
		// `sort` the array in ascend order using `asort`
		asort($arr_str);
		// convert array to string, each element is a character using `implode`
		$sortStr = implode($arr_str);

		// give it back to the main flow
		return $sortStr;
	}
?>