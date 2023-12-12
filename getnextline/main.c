#include <string.h>
#include <stdio.h>
 
// Function
int fun()
{
    static int count = 0;
    count++;
    return count;
}
 
// Driver Code
int main()
{
    printf("%d ", fun());
    printf("%d ", fun());
    printf("%d ", fun());
    printf("%d ", fun());
    printf("%d ", fun());
    printf("%d ", fun());
    printf("%d ", fun());
    printf("%d ", fun());

    return 0;
}