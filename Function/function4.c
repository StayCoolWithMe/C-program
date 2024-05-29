#include<stdio.h>

char name[100][100];
float math[100];
float physic[100];
float chemistry[100];
float result[100];
int total = 0;

float average1(float math, float physic, float chemistry);
void info();
float calculate();
void output();

int main() {
    info();
    output();
    return 0;
}

void info() {
    printf("Enter the total number of students: ");
    scanf("%d", &total);

    while (total < 1) {
        printf("Invalid total, please enter another one: ");
        scanf("%d", &total);
    }

    for(int i = 0; i < total; i++) {
        printf("Enter your name: ");
        scanf("%s", name[i]);
        printf("Enter your math score: ");
        scanf("%f", &math[i]);
        printf("Enter your physics score: ");
        scanf("%f", &physic[i]);
        printf("Enter your chemistry score: ");
        scanf("%f", &chemistry[i]);
        result[i] = average1(math[i], physic[i], chemistry[i]);
    }
}

float average1(float math, float physic, float chemistry) {
    return (math + physic + chemistry) / 3;
}

float calculate() {
    float averageclass = 0;
    for(int i = 0; i < total; i++) {
        averageclass += result[i];
    }   
    return averageclass / total; 
}
void output() {
    printf("Name\tMath Score\tPhysics Score\tChemistry Score\tAverage\n");
    for(int i = 0; i < total; i++) {
        printf("%s\t%.0f\t\t%.0f\t\t%.0f\t\t%.2f\n", name[i], math[i], physic[i], chemistry[i], result[i]);
    }
    printf("Average Class Score: %.2f\n", calculate());
}
