/* make the chart has 2 different color, I make this function
* The 2 color is interleaved(color1-color2-color1-color2-...)
* Therefore, if the number of bars in chart is even, divide by 2 then add to the array
* If the number is odd, take 1 from it, divide by 2, at last put color1 to the array
*/
function chooseBgColor(len)
{
	var color1 = "rgba(255, 99, 132, 0.2)";
	var color2 = "rgba(54, 162, 235, 0.2)";
	// make an empty array to push data
	var my_bgColor = new Array();
	var i = 0;
	if(len % 2 == 0) {
		for(i = 0; i < (len/2); i++)
		{
			my_bgColor.push(color1);
			my_bgColor.push(color2);
		}
	}else{
		for(i = 0; i < ((len - 1)/2); i++)
		{
			my_bgColor.push(color1);
			my_bgColor.push(color2);
		}
		my_bgColor.push(color1);
	}
	return my_bgColor;
}

// Works the same like chooseBgColor, the difference is that this one set the border-color of the bar
function chooseBdColor(len)
{
	var color1 = "rgba(255,99,132,1)";
	var color2 = "rgba(54, 162, 235, 1)";
	var my_bdColor = new Array();
	var i = 0;
	if(len % 2 == 0) {
		for(i = 0; i < (len/2); i++)
		{
			my_bdColor.push(color1);
			my_bdColor.push(color2);
		}
	}else{
		for(i = 0; i < ((len - 1)/2); i++)
		{
			my_bdColor.push(color1);
			my_bdColor.push(color2);
		}
		my_bdColor.push(color1);
	}
	return my_bdColor;
}

/* draw the bar
* chars -> the label of the bar(type:Array)
* freqs -> the quantity of the bar(type:Array)
* bgColor -> Background-color of the bar(type:Array)
* bdColor -> Border-color of the bar(type:Array)
*/
function drawBarChart(chars,freqs,bgColor,bdColor)
{
	// get the canvas
	var ctx = document.getElementById("bar_char").getContext("2d");
	// draw the bar with some option
	var myChar = new Chart(ctx, {
		type: 'bar',
		data: {
			labels: chars,
			datasets: [{
				label: 'Frequency of char',
				data: freqs,
				backgroundColor: bgColor,
				borderColor: bdColor,
				borderWidth: 1
			}]
		},
		options: {
			scales: {
				yAxes: [{
					ticks: {
						beginAtZero: true
					}
				}]
			}
		}
	});
}

// make Vue instance to listen to `click` event then draw bar chart
var app = new Vue({
	el: "#my_app",
	data: {
		// make empty arrays waiting for pushing data from jQuery
		character : [],
		frequency : []
	},
	methods: {
		// click function
		drawChart: function() {
			// get the number of characters in the `character` array -> number of bars in chart
			var the_len = this.character.length
			// make the empty `the_bgColor` and `the_bdColor` array to store the background and border color
			var the_bgColor = new Array(the_len);
			// initilize to the array from the array return from an function
			the_bgColor = chooseBgColor(the_len);
			var the_bdColor = new Array(the_len);
			the_bdColor = chooseBdColor(the_len);
			// apply the ultimate function
			drawBarChart(this.character,this.frequency,the_bgColor,the_bdColor);
		}
	}
})
