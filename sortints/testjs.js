var intlist = require('./intlist').intlist

var intcounts = {};
var start = 0;
var end = 0;
var item = "";

start = Date.now();
intlist.sort(function(a,b){return a-b})
end = Date.now();

console.log("Over "
	    + intlist.length
	    + " elements : "
	    + (end - start)
	    + " milliseconds");