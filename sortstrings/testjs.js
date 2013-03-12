var strlist = require('./stringlist').stringlist

var start = 0;
var end = 0;

start = Date.now();
strlist.sort()
end = Date.now();

console.log("Over "
	    + strlist.length
	    + " elements : "
	    + (end - start)
	    + " milliseconds");