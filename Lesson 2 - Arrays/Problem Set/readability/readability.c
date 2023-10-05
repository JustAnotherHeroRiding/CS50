#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    // printf("%s\n", text);
    printf("%i letters\n", letters);
    printf("%i words\n", words);
    printf("%i sentences\n", sentences);
    // where L is the average number of letters per 100 words in the text, 
    //and S is the average number of sentences per 100 words in the text.

    float L;
    float S;
    int index = 0.0588 * L - 0.296 * S - 15.8;
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    int total = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            total += 1;
        }
    }
    return total;
}

int count_words(string text)
{
    int total = 0;
    int textLength = strlen(text);

    if (textLength == 0)
    {
        return 0;
    }
    else
    {
        total += 1;
    }
    for (int i = 1; i < textLength; i++)
    {
        if (isspace(text[i]) && !isspace(text[i - 1]))
        {
            total += 1;
        }
    }

    return total;
}

int count_sentences(string text)
{
    // if there is a '.', '!' or '?' then we add one point
    int total = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            total += 1;
        }
    }

    return total;
}