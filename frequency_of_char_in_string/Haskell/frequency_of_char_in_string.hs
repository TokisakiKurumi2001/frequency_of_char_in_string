-- import necessary library to use some built-in function
import Data.Char
import Data.List

-- declare a string
the_str = "Hello Haskell World"

-- <heading> Remove all the non-alphabetic character from the string </heading>
-- receives an array of Char([Char]) then returns back an array of Char ([Char])
rmSpaceChar :: [Char] -> [Char]
-- iterates through each element in the list(array of Char) (arr <- str)
-- adds it to the returned list([arr | ...])
-- if the char is in the list of lowercase alphabetic list(arr `elem` ['a'..'z']) or in the list of Uppercase one (['A'..'Z'])
rmSpaceChar str = [arr | arr <- str, arr `elem` ['a'..'z'] || arr `elem` ['A'..'Z']]

-- <heading> Convert all the character in the string to the lowercase character </heading>
upr2Lwr :: [Char] -> [Char]
--iterate through each element of the list, convert uppercase to lowercase by using `toLower` function
upr2Lwr str = [toLower string | string <- str]
-- `toLower` function
-- receives a `Char` return a `Char`
-- if that character is Uppercase, convert to lowercase then return, if not, return that character

-- <heading> Sort the list in the ascending order </heading>
sortString :: [Char] -> [Char]
-- use the `sort` method
-- `sort` receives a list, then return a list of ascended ordered list
sortString str = sort str

-- <heading> Put all the functions(remove space character, convert uppercase to lowercase, sort the string) into one function </heading>
stringFormat :: [Char] -> [Char]
-- I see on the web people use this `.` to chaining many function together
-- However, I have no idea what the right syntax is
-- I use the normal way to chain many functions(with parentheses `()`)
-- The order of the function, rmSpaceChar str -> first_str -> upr2Lwr first_str -> second_str
-- -> sortString second_str -> final_str
stringFormat str = sortString (upr2Lwr (rmSpaceChar str))

-- <heading> Remove all the repeated character in the list, leave the list contains different chars only </heading>
uniqueString :: [Char] -> [Char]
-- `nub` is the function that remove all the repeated element in the list
-- format the string before give it to `nub` so that the result will be in the ascend order
uniqueString str = nub (stringFormat str)

-- <heading> Count how many a character repeated in the given string then return the character and its frequency </heading>
-- Receives a character(Char), a array of Char(given string) and returns a character and its frequency((Char,Int))
freqEachChar :: Char -> [Char] -> (Char,Int)
-- get the array of element([char | ..])
-- in which is the `char` is from the given string(char <- string)
-- and the `char` has to be the same like the given character(char == character)

-- count the repetition of the given char is the array is just like count the number of element from the above list
-- (length repeatChar)
-- return back the character and its frequency in the format (character,repetition)
freqEachChar character string = 
	let repeatChar = [char | char <- string, char == character]
	    repetition = length repeatChar
	in (character,repetition)

-- <heading> Count the frequency of each character of the unique string(string pass through `uniqueString`) in full string(str) </heading>
-- Receives two string([Char]) and returns a list of turple of char and its freq([(Char,Int)])
freqOfChar :: [Char] -> [Char]-> [(Char,Int)]
-- for each distinct element(`char`) in the uniq_str(char <- uniq_str), apply the function `countEach` on the `char` and the original string(`str`)
-- `where` `countEach` function applied on the char(the_char) and original string(the_str) and actually (`=`) a function `freqEachChar`
-- applied on that char(the_char) and that string(the_str), `freqEachChar` is above
freqOfChar uniq_str str = [countEach char str| char <- uniq_str]
	where countEach the_char the_str = freqEachChar the_char the_str

-- <heading> Count the repetition of each character in the given string </heading>
-- Receives a string([Char]) and return the list of char and its freq([(Char,Int)])
calcFreqOfChar :: [Char] -> [(Char,Int)]
-- get all the distinct character in the string with `uniqueString` function applied on the input string(`str`)
-- format the given string with `stringFormat`, this function remove all spaces, convert uppercase to lowercase
-- then applied the `freqOfChar` on the unique_string and the formatted_string
calcFreqOfChar str =
	let unique_str = uniqueString str
	    my_str = stringFormat str
	in freqOfChar unique_str my_str

-- <heading> Receive a list of turples contains a char and its freq, format them then put into a list of String </heading>
formatFreq :: [(Char,Int)] -> [String]
-- convert the char to string(`show(char)`) and the frequency, then concat those string(`++`) with some format(":")
-- where the `char` and `freq` is initialized from the given list of turples(`(char,freq) <- frequency`)
formatFreq frequency = [show(char) ++ " : " ++ show(freq) | (char,freq) <- frequency]

-- <heading> Print out the char(in the original string) and its frequency according with some format to the console </heading>
-- Receives a list of String, return back to the console(`IO()`)
printFreq :: [String] -> IO()
-- break the list of String into individual string with `unlines`, then print out each string in the list with `putStrLn`
printFreq arr_str = putStrLn (unlines arr_str)

-- main function to perform all the tasks
main = do
	-- calculate the frequency of each char in the string(`calcFreqOfChar`), format the result(which is [(Char,Int)])
	-- into [String] with `formatFreq`, then print out to the console(`printFreq`)
	printFreq (formatFreq (calcFreqOfChar the_str))
