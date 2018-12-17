public class RmSpaceChar
{
	public String rmSpaceChar(String str)
	{
		// make a new string, which is copied from the input string, because I don't want to change the input string if not nnecessary
		String my_str = str;
		// replace the space(" ") with nothing("")
		my_str = my_str.replace(" ","");
		// give it back to the main function
		return my_str;
	}
}