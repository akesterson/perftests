var stringlist = require('./stringlist').stringlist

var stringcounts = {};
var start = 0;
var end = 0;
var item = "";

start = Date.now();
for ( item in stringlist ) {
    if ( item in stringcounts ) {
	stringcounts[item] = stringcounts[item] + 1;
    } else {
	stringcounts[item] = 1;
    }
}
end = Date.now();

console.log("Over "
	    + stringlist.length
	    + " elements : "
	    + (end - start)
	    + " milliseconds");