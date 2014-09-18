#include <stdio.h>
#include <math.h>

int
main(int argc, char *argv[])
{
    int sum = 0;

    for (int number = 1; number < 1000; number++)
    {
        if ((number % 3 == 0) || (number % 5 == 0) && !(number % 15 == 0))
        {
            sum += number;
        }
    }
    printf("%i\n", sum);

}
