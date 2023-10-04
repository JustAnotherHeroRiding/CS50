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

- [Practice Problems](https://cs50.harvard.edu/x/2023/problems/2/)
- [Lab 2](https://cs50.harvard.edu/x/2023/labs/2/)
- [Problem Set 2](https://cs50.harvard.edu/x/2023/psets/2/)
