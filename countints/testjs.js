var intlist = require('./intlist').intlist

var intcounts = {};
var start = 0;
var end = 0;
var item = "";

start = Date.now();
for ( item in intlist ) {
    if ( item in intcounts ) {
	intcounts[item] = intcounts[item] + 1;
    } else {
	intcounts[item] = 1;
    }
}
end = Date.now();

console.log("Over "
	    + intlist.length
	    + " elements : "
	    + (end - start)
	    + " milliseconds");