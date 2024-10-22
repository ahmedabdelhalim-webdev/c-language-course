#include <stdio.h>
#include <stdlib.h>

// Function to get an integer from the user
int get_int(const char *prompt) {
    int value;
    printf("%s: ", prompt);
    while (scanf("%d", &value) != 1) {
        // Clear invalid input
        while (getchar() != '\n');
        printf("Invalid input. Please enter an integer: ");
    }
    // Clear the newline character left in the input buffer
    while (getchar() != '\n');
    return value;
}

// Function to print a column of height
void print_column(int height) {
    for (int i = 0; i < height; i++) {
        printf("#\n");
    }
}

int main(void) {
    int h = get_int("Enter height");
    print_column(h);
    return 0;
}
/*
Explanation of the Code
Getting User Input:

The get_int function prompts the user for an integer input and uses scanf to read it. If the input is invalid (not an integer), it clears the input buffer and prompts the user again.
Printing the Column:

The print_column function takes an integer height and prints a # character on a new line for each value from 0 to height - 1.
Main Function:

In main, the user is prompted to enter a height, which is then passed to the print_column function to print the column of # characters.
How to Compile and Run
To compile and run this code, you can use the following commands in a terminal:
*/