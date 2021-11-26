for i in range(int(input())):
    no = input()
    l = ['0','2','4','6','8']
    if(no[-1] in l):
        print(0)
    else:
        s = 0
        for i in l:
            if i in no:
                s += 1
        if s == 0:
            print(-1)
            continue
        if no[0] in l:
            print(1)
        else:
            print(2)