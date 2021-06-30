#...START BY DOING WHAT IS NECESSARY, THEN WHAT IS POSSIBLE AND SUDDENLY YOU ARE DOING THE IMPOSSIBLE... 
import math
   
t = 1
t = int(input())
for _ in range(t):
    n = int(input())
    a = [n]
    while a[-1] > 1:
            rem = a[-1] % 3
            if rem == 2:
                a[-1] += 1
                for i in range(len(a)-2,-1,-1):
                    a[i] = a[i+1] * 3
            else:
                a.append(a[-1]//3)
    print(a[0])

   
   
   
   
# Author : shivamSha_123
 