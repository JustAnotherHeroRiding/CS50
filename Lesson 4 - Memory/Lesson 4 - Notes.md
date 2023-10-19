

#### Important Links

- [Lesson 4 Timestamp](https://youtu.be/kY7wcPMqKtA?t=7546) #DONE 
- [Section](https://cs50.harvard.edu/x/2023/sections/4/) 
- [Practice Problems](https://cs50.harvard.edu/x/2023/problems/4/) 
- [Lab 4](https://cs50.harvard.edu/x/2023/labs/4/) 
- [Problem Set 4](https://cs50.harvard.edu/x/2023/psets/4/)




## Image
### A bit map is an image represents an image

# Go through the notes and write my own notes with an explanation of the concepts covered
- RGB are just values of red green and blue, ranging from 0 to 255
- 255 is represented as FF in hexadecimal
- The decimal system has 10 digits, the hexadecimal system has 16 digits
````
  0 1 2 3 4 5 6 7 8 9 a b c d e f
````
- Hexadecimal is also known as _base-16_.
- When counting in hexadecimal, each column is a power of 16.
- The number `0` is represented as `00`.
- The number `1` is represented as `01`.
- The number `9` is represented by `09`.
- The number `10` is represented as `0A`.
- The number `15` is represented as `0F`.
- The number `16` is represented as `10`.
- The number `255` is represented as `FF`, because 16 x 15 (or `F`) is 240. Add 15 more to make 255. This is the highest number you can count using a two-digit hexadecimal system.
- Hexadecimal is useful because it can be represented using fewer digits. Hexadecimal allows us to represent information more succinctly.

## Memory

<img src="https://cs50.harvard.edu/x/2023/notes/4/cs50Week4Slide066.png">
- Each location in memory has its own address 
- The `C` language has two powerful operators that relate to memory:  
    ```
      & Provides the address of something stored in memory.
      * Instructs the compiler to go to a location in memory.
    ```
## Pointers
- A _pointer_ is a variable that contains the address of some value. Most succinctly, a pointer is an address in your computer’s memory.
- Consider the following code:
    
    ```
    int n = 50;
    
    int *p = &n;
    ```
    
Notice that `p` is a pointer that contains a number that is the address of an integer `n`.

- Modify your code as follows:
    ```
    #include <stdio.h>
    
    int main(void)
    {
        int n = 50;
        int *p = &n;
        printf("%p\n", p);
    }
    ```    
Notice that this code has the same effect as our previous code. We have simply leveraged our new knowledge of the `&` and `*` operators.

- To illustrate the use of the `*` operator, consider the following:
    
    ```
    #include <stdio.h>
    
    int main(void)
    {
        int n = 50;
        int *p = &n;
        printf("%i\n", *p);
    }
    ```
    
    Notice that the `printf` line prints the integer at the location of `p`.


## Strings
- The string type that we used so far in CS50 is just `char *s`
<img src="https://cs50.harvard.edu/x/2023/notes/4/cs50Week4Slide085.png">
<img src="https://cs50.harvard.edu/x/2023/notes/4/cs50Week4Slide086.png">
- Notice how a pointer called `s` tells the compiler where the first byte of the string exists in memory.
    
- Modify your code as follows:
    
    ```
    #include <cs50.h>
    #include <stdio.h>
    
    int main(void)
    {
        string s = "HI!";
        printf("%p\n", s);
        printf("%p\n", &s[0]);
        printf("%p\n", &s[1]);
        printf("%p\n", &s[2]);
        printf("%p\n", &s[3]);
    }
    ```
    
    Notice the above prints the memory locations of each character in the string `s`.
    
- Likewise, you can modify your code as follows:
    
    ```
    #include <stdio.h>
    
    int main(void)
    {
        char *s = "HI!";
        printf("%s\n", s);
    }
    ```
    
    Notice that this code will present the string that starts at the location of `s`.

## Pointer arithmetic
Further, you can modify your code as follows:

```
#include <stdio.h>

int main(void)
{
    char *s = "HI!";
    printf("%c\n", *s);
    printf("%c\n", *(s + 1));
    printf("%c\n", *(s + 2));
}
```
- This will work in a similar way to just printing the entire string with `%s`, stopping when it hits the null terminator `/0`

## Comparing strings
- A string of characters is simply an array of characters identified by its first byte.
- Recall that last week we proposed that we could not compare two strings using the `==` operator.
- Utilizing the `==` operator in an attempt to compare strings will attempt to compare the memory locations of the strings instead of the characters therein. Accordingly, we recommended the use of `strcmp`.
- To illustrate this, type `code compare.c` and write code as follows:
```
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get two strings
    char *s = get_string("s: ");
    char *t = get_string("t: ");

    // Compare strings' addresses
    if (s == t)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}
```

<img src="https://cs50.harvard.edu/x/2023/notes/4/cs50Week4Slide115.png">
<img src="https://cs50.harvard.edu/x/2023/notes/4/cs50Week4Slide116.png">
  
Modify your code as follows:

```
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get two strings
    char *s = get_string("s: ");
    char *t = get_string("t: ");

    // Print strings
    printf("%s\n", s);
    printf("%s\n", t);
}
```

## Copying strings

- Before we address this challenge, it’s important to ensure that we don’t experience a _segmentation fault_ through our code, where we attempt to copy `string s` to `string t`, where `string t` does not exist. We can employ the `strlen` function as follows to assist with that:
    
    ```
    #include <cs50.h>
    #include <ctype.h>
    #include <stdio.h>
    #include <string.h>
    
    int main(void)
    {
        // Get a string
        string s = get_string("s: ");
    
        // Copy string's address
        string t = s;
    
        // Capitalize first letter in string
        if (strlen(t) > 0)
        {
            t[0] = toupper(t[0]);
        }
    
        // Print string twice
        printf("s: %s\n", s);
        printf("t: %s\n", t);
    }
    ```
    
    Notice that `strlen` is used to make sure `string t` exists. If it does not, nothing will be copied.


- Notice that `s` and `t` are still pointing at the same blocks of memory. This is not an authentic copy of a string. Instead, these are two pointers pointing at the same string.
    
- To be able to make an authentic copy of the string, we will need to introduce two new building blocks. First, `malloc` allows you, the programmer, to allocate a block of a specific size of memory. Second, `free` allows you to tell the compiler to _free up_ that block of memory you previously allocated.
    
- We can modify our code to create an authentic copy of our string as follows:
    
    ```
    #include <cs50.h>
    #include <ctype.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    int main(void)
    {
        // Get a string
        char *s = get_string("s: ");
    
        // Allocate memory for another string
        char *t = malloc(strlen(s) + 1);
    
        // Copy string into memory, including '\0'
        for (int i = 0; i <= strlen(s); i++)
        {
            t[i] = s[i];
        }
    
        // Capitalize copy
        t[0] = toupper(t[0]);
    
        // Print strings
        printf("s: %s\n", s);
        printf("t: %s\n", t);
    }
    ```
    
    Notice that `malloc(strlen(s) + 1)` creates a block of memory that is the length of the string `s` plus one. This allows for the inclusion of the _null_ `\0` character in our final, copied string. Then, the `for` loop walks through the string `s` and assigns each value to that same location on the string `t`.
    
- It turns out that there is an inefficiency in our code. Modify your code as follows:
    
    ```
    #include <cs50.h>
    #include <ctype.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    int main(void)
    {
        // Get a string
        char *s = get_string("s: ");
    
        // Allocate memory for another string
        char *t = malloc(strlen(s) + 1);
    
        // Copy string into memory, including '\0'
        for (int i = 0, n = strlen(s); i <= n; i++)
        {
            t[i] = s[i];
        }
    
        // Capitalize copy
        t[0] = toupper(t[0]);
    
        // Print strings
        printf("s: %s\n", s);
        printf("t: %s\n", t);
    }
    ```

## Valgrind

- Valgrind_ is a tool that can check to see if there are memory-related issues with your programs wherein you utilized `malloc`. Specifically, it checks to see if you `free` all the memory you allocated.
- Consider the following code:
    
    ```
    #include <stdio.h>
    #include <stdlib.h>
    
    int main(void)
    {
        int *x = malloc(3 * sizeof(int));
        x[0] = 72;
        x[1] = 73;
        x[2] = 33;
    }
    ```
    
    Notice that running this program does not cause any errors. While `malloc` is used to allocate enough memory for an array, the code fails to `free` that allocated memory.
    
- If you type `make memory` followed by `valgrind ./memory`, you will get a report from valgrind that will report where memory has been lost as a result of your program.
- You can modify your code as follows:
    
    ```
    #include <stdio.h>
    #include <stdlib.h>
    
    int main(void)
    {
        int *x = malloc(3 * sizeof(int));
        x[0] = 72;
        x[1] = 73;
        x[2] = 33;
        free(x);
    }
    ```
    
    Notice that running valgrind again now results in no memory leaks.

## Garbage Values

- When you ask the compiler for a block of memory, there is no guarantee that this memory will be empty.
- It’s very possible that this memory that you allocated was previously utilized by the computer. Accordingly, you may see _junk_ or _garbage values_. This is a result of you getting a block of memory but not initializing it. For example, consider the following code:
    
    ```
    #include <stdio.h>
    #include <stdlib.h>
    
    int main(void)
    {
        int scores[1024];
        for (int i = 0; i < 1024; i++)
        {
            printf("%i\n", scores[i]);
        }
    }
    ```
    
    Notice that running this code will allocate `1024` locations in memory for your array, but the `for` loop will likely show that not all values therein are `0`. It’s always best practice to be aware of the potential for garbage values when you do not initialize blocks of memory to some other value like zero or otherwise.

## Swap 
  
- In the real world, a common need in programming is to swap two values. Naturally, it’s hard to swap two variables without a temporary holding space. In practice, you can type `code swap.c` and write code as follows to see this in action:

```
#include <stdio.h>
#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(&x, &y);
    printf("x is %i, y is %i\n", x, y);
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
```

Notice that variables are not passed by _value_ but by _reference_. That is, the addresses of `a` and `b` are provided to the function. Therefore, the `swap` function can know where to make changes to the actual `a` and `b` from the main function.



### Stack and heap memory
<img src="https://cs50.harvard.edu/x/2023/notes/4/cs50Week4Slide163.png">
- The stack and the heap grow in opposite directions
- If the stack touches the heap it will lead to a stack overflow, and a heap overflow if the opossite happens
- The swap and the main function live in two different buffers of memory
- That is why we need to pass the pointers so that the original location in memory gets changed and not just the local copy in the second buffer


## `scanf`

- In CS50, we have created functions like `get_int` to simplify the act of getting input from the user.
- `scanf` is a built-in function that can get user input.
- We can reimplement `get_int` rather easily using `scanf` as follows:
    
    ```
    #include <stdio.h>
    
    int main(void)
    {
        int x;
        printf("x: ");
        scanf("%i", &x);
        printf("x: %i\n", x);
    }
    ```
    
    Notice that the value of `x` is stored at the location of `x` in the line `scanf("%i", &x)`.
    
- However, attempting to reimplement `get_string` is not easy. Consider the following:
    
    ```
    #include <stdio.h>
    
    int main(void)
    {
        char *s;
        printf("s: ");
        scanf("%s", s);
        printf("s: %s\n", s);
    }
    ```
    
    Notice that no `&` is required because strings are special. Still, this program will not function. Nowhere in this program do we allocate the amount of memory required for our string.
    
- We can modify our code as follows:
    
    ```
    #include <stdio.h>
    
    int main(void)
    {
        char s[4];
        printf("s: ");
        scanf("%s", s);
        printf("s: %s\n", s);
    }
    ```
    
    Notice that if we pre-allocate an array of size `4`, we can type `cat` and the program functions. However, a string larger than this would create an error.


## Files

- You can read from and manipulate files. While this topic will be discussed further in a future week, consider the following code for `phonebook.c`:
    
    ```
    #include <cs50.h>
    #include <stdio.h>
    #include <string.h>
    
    int main(void)
    {
        // Open CSV file
        FILE *file = fopen("phonebook.csv", "a");
    
        // Get name and number
        char *name = get_string("Name: ");
        char *number = get_string("Number: ");
    
        // Print to file
        fprintf(file, "%s,%s\n", name, number);
    
        // Close file
        fclose(file);
    }
    ```
    
    Notice that this code uses pointers to access the file.
    
- You can create a file called `phonebook.csv` in advance of running the above code. After running the above program and inputting a name and phone number, you will notice that this data persists in your CSV file.