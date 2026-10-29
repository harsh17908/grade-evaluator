/*
 * Grade Evaluator — console program in C
 * Author: Harsh Verma (github.com/harsh17908)
 * Reads marks (0-100), validates range, maps to grade.
 * Build: gcc grade.c -o grade
 * Run: ./grade  (Windows: grade.exe)
 */
#include <stdio.h>

static void clear_stdin(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

static const char *grade_for(double marks) {
    if (marks >= 90.0) return "A+";
    if (marks >= 80.0) return "A";
    if (marks >= 70.0) return "B";
    if (marks >= 60.0) return "C";
    if (marks >= 50.0) return "D";
    if (marks >= 33.0) return "E (Pass)";
    return "F (Fail)";
}

int main(void) {
    double marks;

    printf("==== Grade Evaluator ====\n");
    printf("Enter marks (0-100): ");

    if (scanf("%lf", &marks) != 1) {
        printf("Invalid input. Please enter a number.\n");
        return 1;
    }
    clear_stdin();

    if (marks < 0.0 || marks > 100.0) {
        printf("Error: marks must be between 0 and 100.\n");
        return 1;
    }

    printf("Marks: %.2f\n", marks);
    printf("Grade: %s\n", grade_for(marks));

    if (marks < 33.0)
        printf("Result: Fail — keep practicing, you will improve.\n");
    else
        printf("Result: Pass — well done.\n");

    return 0;
}
