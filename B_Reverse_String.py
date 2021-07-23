for _ in range(int(input())):
    s = input()
    t = input()

    flag=0
    if s==t:
        flag=1
    
    for i in range(len(t)):
        cur_str = t[:i+1]

        for j in range(len(s)):
           
            if j+len(cur_str)<=len(s) and cur_str == s[j:j+len(cur_str)]:
                #print(j+len(cur_str))
                rem = t[i+1:]
                l = len(rem)
                if l <= j + len(cur_str) -1:
                    tt = s[j+len(cur_str)-l-1:j+len(cur_str)-1]
                    tt = tt[::-1]
                    if t[i+1:] == tt:
                        flag=1
    
    if flag==1:
        print("YES")
    else:
        print("NO")

        


