f=io.read
s=0
for i=1,f'n'do
s=s+(f'n'%2==0 and 1 or -1)end
print(s>0 and"Happy"or"Sad")
