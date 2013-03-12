import intlist
import time
start = time.time()
intlist.intlist.sort()
end = time.time()
print("Over {} elements : {} milliseconds"
      "".format(len(intlist.intlist),
                str((end - start)/1000).split('.')[0]
                )
      )
