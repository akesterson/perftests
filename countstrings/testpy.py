import stringlist
import time
stringcounts = {}
start = time.time()
for item in stringlist.stringlist:
    if item in stringcounts:
        stringcounts[item] = stringcounts[item] + 1
    else:
        stringcounts[item] = 1
end = time.time()
print("Over {} elements : {} milliseconds"
      "".format(len(stringlist.stringlist),
                str((end - start)/1000).split('.')[0]
                )
      )
