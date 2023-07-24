#include <stdio.h>
#include <time.h>
// so sanh toc do co và kh co register
int main()
{
    clock_t start, end;

    double test;

    int i;                       // register int i;

    start = clock();

    for (i = 0; i < 0xFFFFFFFF; i++);

    end = clock();

    test = ((double)(end - start))/CLOCKS_PER_SEC;

    printf("time: %f\n", test);
    
    return 0;
}
