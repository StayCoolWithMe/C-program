#include <stdio.h>

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    while (numStudents <= 0) {
        printf("Invalid number of students. Please enter a positive integer: ");
        scanf("%d", &numStudents);
    }

    float classTotal = 0.0;

        char name[50];
        int mathGrade, englishGrade, scienceGrade;
    for ( int i = 1; i <= numStudents; i++) {

        printf("\n--- Student %d ---\n", i);
        printf("Enter student name: ");
        scanf(" %s", name);
        printf("Enter Math grade (out of 100): ");
        scanf("%d", &mathGrade);
        printf("Enter English grade (out of 100): ");
        scanf("%d", &englishGrade);
        printf("Enter Science grade (out of 100): ");
        scanf("%d", &scienceGrade);

        float averageGrade = (mathGrade + englishGrade + scienceGrade) / 3.0;
        classTotal += averageGrade;

        printf("\nStudent Name: %s\n", name);
        printf("Math Grade: %d\n", mathGrade);
        printf("English Grade: %d\n", englishGrade);
        printf("Science Grade: %d\n", scienceGrade);
        printf("Average Grade: %.2f\n", averageGrade);

        if (averageGrade >= 60) {
            printf("Analysis: Pass\n");
        } else {
            printf("Analysis: Fail\n");
        }
    }

    float classAverage = classTotal / numStudents;
    printf("\nClass Average Grade: %.2f\n", classAverage);

    return 0;
}