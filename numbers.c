#include <stdio.h>
void before(char num1, char num2);
void after(char c, int n);
char romanval[1000];
int i = 0;
int main()
{
    int j;
    int number;
    printf("Enter number: ");
    scanf("%d", &number);
    if (number <= 0)
    {
        printf("Invalid number");
        return 0;
    }
    while (number != 0)
    {
        if (number >= 1000)
        {
            after('M', number / 1000);
            number = number - (number / 1000) * 1000;
        }
        else if (number >= 500)
        {
            if (number < (500 + 4 * 100))
            {
                after('D', number / 500);
                number = number - (number / 500) * 500;
            }
            else
            {
                before('C','M');
                number = number - (1000-100);
            }
        }
        else if (number >= 100)
        {
            if (number < (100 + 3 * 100))
            {
                after('C', number / 100);
                number = number - (number / 100) * 100;
            }
            else
            {
                before('L', 'D');

                number = number - (500 - 100);
            }
        }
        else if (number >= 50 )
        {
            if (number < (50 + 4 * 10))
            {
                after('L', number / 50);
                number = number - (number / 50) * 50;
            }
            else
            {
                before('X','C');
                number = number - (100-10);
            }
        }
        else if (number >= 10)
        {
            if (number < (10 + 3 * 10))
            {
                after('X', number / 10);
                number = number - (number / 10) * 10;
            }
            else
            {
                before('X','L');
                number = number - (50 - 10);
            }
        }
        else if (number >= 5)
        {
            if (number < (5 + 4 * 1))
            {
                after('V', number / 5);
                number = number - (number / 5) * 5;
            }
            else
            {
                before('I', 'X');
                number = number - (10 - 1);
            }
        }
        else if (number >= 1)
        {
            if (number < 4)
            {
                after('I', number / 1);
                number = number - (number / 1) * 1;
            }
            else
            {
                before('I', 'V');
                number = number - (5 - 1);
            }
        }
    }
    printf("Roman number is: ");
    for(j = 0; j < i; j++)
        printf("%c", romanval[j]);
    return 0;
}
void before(char num1, char num2)
{
    romanval[i++] = num1;
    romanval[i++] = num2;
}
void after(char c, int n)
{
    int j;
    for (j = 0; j < n; j++)
        romanval[i++] = c;
}
