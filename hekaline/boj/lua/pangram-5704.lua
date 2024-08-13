function isPangram(s)
    arr={}
  
    for i=1,#s do
        local c=s:sub(i,i)
        if c:match("%a")then
            arr[c]=true
        end
    end
  
    for i=string.byte('a'),string.byte('z')do
        if not arr[string.char(i)] then
            return false
        end
    end
  
    return true
end

while 1 do
    s=io.read'l'
    if s=='*' then break end
    print(isPangram(s) and "Y" or "N")
end
