#include <stdio.h>
#include <math.h>

// Define a struct to represent a complex number
struct Complex {
    float real;
    float imaginary;
};

// Function to add two complex numbers
struct Complex add(struct Complex c1, struct Complex c2) {
    struct Complex result;
    result.real = c1.real + c2.real;
    result.imaginary = c1.imaginary + c2.imaginary;
    return result;
}

// Function to subtract two complex numbers
struct Complex subtract(struct Complex c1, struct Complex c2) {
    struct Complex result;
    result.real = c1.real - c2.real;
    result.imaginary = c1.imaginary - c2.imaginary;
    return result;
}

// Function to calculate the dot product of two complex numbers
float dot(struct Complex c1, struct Complex c2) {
    return c1.real * c2.real + c1.imaginary * c2.imaginary;
}

// Function to calculate the magnitude of a complex number
float magnitude(struct Complex c) {
    return sqrt(c.real * c.real + c.imaginary * c.imaginary);
}

// Function to calculate the cosine similarity between two complex numbers
float cosineSimilarity(struct Complex c1, struct Complex c2) {
    float dotProduct = dot(c1, c2);
    float magC1 = magnitude(c1);
    float magC2 = magnitude(c2);
    
    return dotProduct / (magC1 * magC2);
}

int main() {
    int n;
    printf("Enter the number of dimensions (n): ");
    scanf("%d", &n);

    struct Complex c1, c2, result;
    printf("Enter the values of the first complex number (C1): ");
    scanf("%f %f", &c1.real, &c1.imaginary);
    printf("Enter the values of the second complex number (C2): ");
    scanf("%f %f", &c2.real, &c2.imaginary);

    char operation[10];
    while (1) {
        printf("Enter the operation (ADD, SUB, DOT, COSINE, or -1 to exit): ");
        scanf("%s", operation);

        if (strcmp(operation, "-1") == 0) {
            break;
        } else if (strcmp(operation, "ADD") == 0) {
            result = add(c1, c2);
            printf("Result: %.2f %.2f\n", result.real, result.imaginary);
        } else if (strcmp(operation, "SUB") == 0) {
            result = subtract(c1, c2);
            printf("Result: %.2f %.2f\n", result.real, result.imaginary);
        } else if (strcmp(operation, "DOT") == 0) {
            float dotResult = dot(c1, c2);
            printf("Result: %.2f\n", dotResult);
        } else if (strcmp(operation, "COSINE") == 0) {
            float cosineResult = cosineSimilarity(c1, c2);
            printf("Result: %.2f\n", cosineResult);
        } else {
            printf("Invalid operation. Please enter ADD, SUB, DOT, COSINE, or -1 to exit.\n");
        }
    }

    return 0;
}
