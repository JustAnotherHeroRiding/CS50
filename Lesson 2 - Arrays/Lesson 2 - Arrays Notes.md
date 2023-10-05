[Week 2 Link](https://cs50.harvard.edu/x/2023/weeks/2/)
[Video timestamp](https://youtu.be/ODTROxjb8Tw?t=8456)
## 20 minutes left then we solve the exercises

## Key Points
- A string is not a built in type in C but comes from the cs50 Library
- A string is an array of characters which take just one byte
- A string take up as many bytes as there are characters, and a sentinel byte at the end which is "\0"
- This sentinel byte marks the end of the array
- An array of strings is an array full of char arrays
- strlen(string) from the string.h library returns the string length
- Similarly there is a function to turn a word into uppercase, returning the letter if it is already uppercase or turning it into uppercase
- This can also be done by subtracting 32 from a char to get the ascii value of its uppercase counterpart
- Each string is assigned a block in memory, which is why the sentinel bytes are important to mark the end of a string
- Strings(and arrays in general) can be indexed with array[n] just like in python JS
- C programs always return a status code
- If it is 0, then everything worked as expected and all the code was executed
- If something went wrong or the input was not correctly provided, then a code of anything but 0 will stop the program from executing further
- The main function can also accept command line arguments
- If we put `int main(int argc, string argv[])` , argc is the number of arguments, argv is an array of arguments
- argv[0] will always be ./{programName} , with each following parameter being stored in the array from argv[1] and forward
- We can check that the correct number of arguments were provided by checking the argc count

# Exercises

- [Practice Problems](https://cs50.harvard.edu/x/2023/problems/2/) #DONE 
- [Lab 2](https://cs50.harvard.edu/x/2023/labs/2/) #DONE 
- [Problem Set 2](https://cs50.harvard.edu/x/2023/psets/2/)``


### Hours.c
- Depending on whether T(total) or A(average) is passed when asking for a char, we need to calculate the total or average hours
- First we ask for the number of weeks
- Then we create an array with as many slots as there are weeks
- With the for loop we populate each element in the array with the number of hours spent on doing the homework
- We ask for the character that will decide the output
- This character must be T or A, type does not matter as it will be uppercased
- Then we print the returned value of the function
- The function initializes a new variable called total, where if we want to see the total we simply add all the hours in the array
- If we want to see the average then we will divide the total by the number of weeks and return the result as a float
- Since we already have a do while loop, there is no scenario where a character other than A or T is passed
### N0 V0w3ls

- Create a program that will replace all vowels with a letter that looks similar to the word
- We just loop over the word and check if each char is one of the vowels and the replace them with the number

### Password
- We need to check that a password contains all 4 required character types
- We need a lowercase and uppercase letter, a number and a symbol
- Using the ctype.h library, we can check if a char is uppercase, lowercase or a digit, and if not then it is a symbol

### Scrabble
- Using the array provided, score each word depending on the letters used in the word
- Afterwards print the word



### Readability
- The instructions for this exercise are very explanatory
