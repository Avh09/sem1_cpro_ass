#include <stdio.h>

int main() {
    FILE *file;
    char inputString[100];

    // Open the file in write mode
    file = fopen("output.txt", "a+");

    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1; // Exit with an error code
    }

    // Get a string input from the user
    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);

    // Write the string to the file
    fprintf(file, "%s", inputString);

    // Close the file
    fclose(file);

    printf("String has been written to the file successfully.\n");

    return 0;
}
