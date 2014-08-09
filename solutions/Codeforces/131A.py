#Problem Name : 131A - cAPS lOCK
#Execution Time : 92 ms
#Memory : 0 KB
a = raw_input()
if a[1:].upper() == a[1:]:
    print a.swapcase()
else:
    print a