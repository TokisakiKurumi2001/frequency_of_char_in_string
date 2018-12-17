// import Arrays because we gonna use some feature of Arrays to implement the idea more easily
import java.util.Arrays;
public class StringSorting
{
	public String sortString(String str)
	{
		// convert the input string into an array
		char my_str[] = str.toCharArray();

		// using sort, built-in function that only apply on Array to put the array of char into ascending order
		Arrays.sort(my_str);

		// make a new string from the sorted array
		String the_str = new String(my_str);

		// put the string back, it's just like you realy sort the string
		return the_str;
	}
}