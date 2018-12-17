function stringFormat(the_string)
{
	var no_space_str = the_string.replace(/ /g,"");
	var lwr_str = no_space_str.toLowerCase();

	var arr = lwr_str.split("");
	var sort_arr = arr.sort();
	var sort_str = sort_arr.join("");

	return sort_str;
}

function Dictionary(char,freq)
{
	this.char = char;
	this.freq = freq;
}

function printDict(dict)
{
	// pass the char and the frequency to the empty array make in VueJS
	console.log(app.character.push(dict.char));
	console.log(app.frequency.push(dict.freq));
}

function freqOfChar(my_str)
{
	var arr = my_str.split("");
	var len = arr.length;
	var dict = new Array(len);

	var i = 0;
	var j = 0;
	var count = 0;

	while(i < len)
	{
		count = 1;

		if(i == len - 1) {
			dict[i] = new Dictionary(arr[i],count);
			break;
		}else{
			j = i + 1;
		}

		while(arr[i] == arr[j])
		{
			count++;
			arr.splice(j,1);
			len--;
			if(i == len - 1)
			{
				break;
			}
		}

		dict[i] = new Dictionary(arr[i],count);
		
		i++;
	}

	return dict;
}

// jQuery run
$(function(){
	// when the input is being typed, calculate the frequency then log out
	$("#string").keydown(function(){
		var the_str = $("#string").val();

		// delete all the existing element in the `character` and `frequency` array
		// to pass new data
		console.log(app.character.splice(0,app.character.length));
		console.log(app.frequency.splice(0,app.frequency.length));

		var new_str = stringFormat(the_str);

		var new_arr = new_str.split("");
		var len = new_arr.length;
		var my_dict = new Array(len);

		my_dict = freqOfChar(new_str);
		my_dict.forEach(printDict);
	});
});
