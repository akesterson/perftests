import stringlist
import time
start = time.time()
stringlist.stringlist.sort()
end = time.time()
print("Over {} elements : {} milliseconds"
      "".format(len(stringlist.stringlist),
                str((end - start)/1000).split('.')[0]
                )
      )
