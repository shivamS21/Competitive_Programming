#include <stdio.h>
#include <stdlib.h>

int randomGenerator(int no)
{
    no ^= no << 13;
    no ^= no >> 17;
    no ^= no << 5;
    return no;
}

int main()
{
    int N;
    scanf("%d",&N);
    int temp = 341;
    for(int i=0; i<N;i++)
    {
        int a=temp+i;
        printf("%zu\n",randomGenerator(a));
    }
    return 0;
}