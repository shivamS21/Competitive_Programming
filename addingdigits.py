a,b,n = map(int,input().split())
p =b - (a*10) % b
if 10 > p > 0:
    a = a * 10 + p
    print(str(a)+'0'*(n-1))
elif p==b:
    print(str(a)+'0'*n)
else:
    print(-1)