#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>


float average(int values, ...)
{
    va_list var_arg;
    int count;
    float sum=0;

    va_start(var_arg, values);

    for(count = 0; count < values; count++){
        sum += va_arg(var_arg, int);
    }

    va_end(var_arg);

    return sum/values;
}

int isLetter(char values, ...)
{
    va_list list;
    int isLetter = 1;
    va_start(list, values);

    /*
     how to determine if va_list have no more valid 
     values in other (better?) way??? 
    */
    while(values != 0)
    {
        printf("%c ", values);
        isLetter &= (isalpha(values))? 1 : 0;
        values = va_arg(list, int);
    }

    va_end(list);    

    return isLetter;
}


int main(void)
{
    // printf("%f \n", average(2, 3, '!'));
    isLetter('c','f','f','f','a', 'X', 'Z', 0)?printf("Is a letter"):printf("Isn't a letter");
    isLetter('Z', 0)?printf("Is a letter"):printf("Isn't a letter");
    isLetter('Z', '-', 'p' , 0)?printf("Is a letter"):printf("Isn't a letter");
    printf("\n");
}
