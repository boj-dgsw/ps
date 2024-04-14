s=io.read()a=0 for i=1,#s-3 do
a=a+(string.sub(s,i,i+3)=="DKSH"and 1 or 0)end
print(a)
