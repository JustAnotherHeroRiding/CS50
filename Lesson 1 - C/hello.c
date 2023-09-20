#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

/* int main(void)
{
    char answer[100]; // Assuming the name won't exceed 100 characters

    printf("What is your name? ");
    fgets(answer, sizeof(answer), stdin);

    // Remove the newline character added by fgets
    size_t len = strlen(answer);
    if (len > 0 && answer[len-1] == '\n') {
        answer[len-1] = '\0';
    }

    printf("hello, %s\n", answer);
    return 0;
}
 */


int main(void)
{
    string answer = get_string("What is your name? ");
    printf("hello, %s\n", answer);
    //printf("Hello World\n");
}