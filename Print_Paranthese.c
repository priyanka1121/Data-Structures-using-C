// C program to Print all combinations
// of balanced parentheses
#include <stdio.h>
#define MAX_SIZE 100

void _print(int pos, int n, int open, int close);


void print(int n)
{
    if (n > 0)
        _print(0, n, 0, 0);
    return;
}

void _print(int pos, int n, int open, int close)
{
    static char str[MAX_SIZE];

    if (close == n)
    {
        printf("%s \n", str);
        return;
    }
    else
    {
        if (open > close)
        {
            str[pos] = '}';
            _print(pos + 1, n, open, close + 1);
        }

        if (open < n)
        {
            str[pos] = '{';
            _print(pos + 1, n, open + 1, close);
        }
    }
}

// Driver program to test above functions
int main()
{
    int n = 3;
    print(n);
    getchar();
    return 0;
}
