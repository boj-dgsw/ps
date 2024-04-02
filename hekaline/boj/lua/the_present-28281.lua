f=io.read
n=f'n'x=f'n'm=5e9
a={}for i=1,n do a[i]=f'n'end
for i=1,n-1 do
m=math.min(m,a[i]*x+a[i+1]*x)end
print(m)
