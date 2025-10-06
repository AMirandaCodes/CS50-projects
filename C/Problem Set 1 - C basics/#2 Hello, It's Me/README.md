# Problem 2: Hello, It's Me

## Brief
In this problem, the program should prompt the user for their name and then greet them personally. For example, if the user enters `Adele`, the program outputs: hello Adele.

## Approach
This exercise is about:
- Using the CS50 library to prompt for and capture a user’s input string with get_string.
- Printing dynamic text using printf with the *%s* format specifier.
- Combining input and output to make the program more interactive than a simple print statement.

## My solution

### Description
The program asks the user to enter their name and then responds with a personalized greeting in the format: hello, [name]. 

### How to Use It
1. Ensure you have the CS50 library installed and configured.
2. Navigate to the corresponding folder.
3. Compile the code with: *make hello*
4. Run the program with: *./hello*
5. When prompted, enter your name, and the program will greet you.

#### Code Snippet
```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("What is your name?\n");
    printf("Hello, %s\n", name);
}

