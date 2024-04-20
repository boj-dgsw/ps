s=io.read()u=string.sub
print((#s>2 and u(s,1,1)=='\"'and u(s,#s,#s)=='\"')and u(s,2,#s-1)or"CE")
