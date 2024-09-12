n,m=map(int,input().split());
n=max(n,4)
if m<=3:
    print(0)
    exit(0)

if n%2==1:
    n+=1
if m%2==1:
    m-=1
    
cnt=(m-n)//2+1
ans=(n+m)*(cnt//2)
if cnt%2==1:
    ans+=(n+m)//2
    
print(ans)
