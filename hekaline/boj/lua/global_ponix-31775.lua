a={}for i=1,3 do
a[io.read():sub(1,1)]=true
end
print(a['l']and a['k']and a['p']and"GLOBAL"or"PONIX")
