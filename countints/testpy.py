import intlist
import time
intcounts = {}
start = time.time()
for item in intlist.intlist:
    if item in intcounts:
        intcounts[item] = intcounts[item] + 1
    else:
        intcounts[item] = 1
end = time.time()
print("Over {} elements : {} milliseconds"
      "".format(len(intlist.intlist),
                str((end - start)/1000).split('.')[0]
                )
      )
