#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int usage();
int fib(int n, long long a[], int *i);

int
main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Too few arguments...\n");
        usage();
        return -1;
    }

    // We use a cache to keep track of values already calculated.
    // On start the cache is loaded from disc and read to memory.
    FILE * cache;
    char value[128];

    long long cache_array[64];
    int i = 0;
    

    if ((cache = fopen(argv[1], "r")) == NULL)
    {
        printf("Cache not opened, exiting.\n");
        fclose(cache);
        exit(1);
    }

    while (fgets(value, 128, cache))
    {
        cache_array[i] = atoi(value);
        //printf("Element %i of Cache Array is: %i\n", i, cache_array[i]);
        i++;            
    }
    i--;
    fclose(cache);
    
    //printf("%i\n", i);
    printf("%i\n", fib(46, cache_array, &i));
    //printf("%i\n", i);
    long long sum = 0;
    for (int j = 0; j <= 50; j++)
    {
        int val = cache_array[j]; 
        if (val % 2 == 0 && val <= 4000000000)
        {
            sum += val;
            //printf("val=%i\n", val);
            printf("cache_array[%i]=%i\n", j, cache_array[j]);
        }
    }
    printf("The result is obviously: %i\n", sum);



}


int
fib(int n, long long a[], int *i)
/* n - the number to be computed
 * a - the array containing previous computations
 * i - the highest number previously computed */
{
//    printf("A and i is %i\n", *i);
    if (n == 0 || n == 1)
    {
        return 1;
    }
//    printf("B\n");
    if (n > *i) // n is not cached
    {
//        printf("C\n");
        long long fib_1 = 0;
        long long fib_2 = 1;
        long long fib_n;

        // Calculate n
        for ( int idx = 0; idx <= n; idx++ )
        {
            if (idx < *i) // No calculation needed
            {
//                printf("C:%i: idx<i, i=%i\n", idx, *i);
                continue;
            }    
            else if (idx == *i) // End of the line
            {
//                printf("C:%i:End, i=%i\n", idx, *i);
                fib_n = a[idx];
                fib_1 = a[idx-2];
                fib_2 = a[idx-1];
//               printf("fib = (%i;%i;%i)\n", fib_n, fib_2, fib_1);
            }
            else
            {
                fib_n = fib_1+fib_2;
                fib_1 = fib_2;
                fib_2 = fib_n;
                a[idx] = fib_n;
//                printf("fib = (%i;%i;%i)\n", fib_n, fib_2, fib_1);
//                printf("C:Else and i is %i\n", *i);
//                printf("CC:%i\n", *i);
            }
        }
        *i = n;
//        printf("i is %i\n", *i);
        return fib_n;
    }
    else // n is in cache so we can return it directly
    {
        printf("D\n");
        return a[n];
    }
}

int
usage()
{
    printf("\nUsage:\n");
}

