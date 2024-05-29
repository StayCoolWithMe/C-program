#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_slot 20
#define Hour_to_minute 30

//This is variable 
int choice;
int num=0;
int Car_plate[20];
char car_type[max_slot][20]={"1.Moto-cycle","2.Car","3.Truck"};
float price[]={2,4,6};
float total[max_slot];
int  type[20];
float duration[20];

// Function prototypes
void error();
void exit_program();
void park_car();
void remove_car();
void display();
float calculator(float price,float duration);

// Main function
int main(){
    error();
    do
    {
        printf("1.Park car\n");
        printf("2.Remove car\n");
        printf("3.Display Parking\n");
        printf("4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            {
                park_car();
                break;
            }
            case 2:
            {
                remove_car();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                exit_program();
            }
            default:
            {
                printf("INVALID CHOICE\n");
            }
        }
    } while(choice!=4);
}

// Function definitions
void error(){
    printf("Enter the number of cars");
    scanf("%d",&num);
    while(num<1 ||num >max_slot)
    {
        printf("Invalid number, please enter another one");
        scanf("%d",&num);
    }
}

void park_car()
{
    for(int i=0; i<num; i++)
    {
        if(i < max_slot)
        {
            printf("Enter your vehicle plate for vehicle %d:", i + 1);
            scanf("%d", &Car_plate[i]);
            printf("What's your vehicle type(1.Motocycle/2.Car/3.Truck)");
            scanf("%d", &type[i]);
            printf("What's your parking duration(h)");
            scanf("%f", &duration[i]);
            int index = -1;
            for(int j=0; j<3; j++)
            {
                if(strcmp(car_type[type[i]-1], car_type[j]) == 0)
                {
                    index = j;
                    break;
                }   
            }
            if(index != -1)
            {
                printf("%s will be available at %.2f per hour", car_type[index], price[index]);
                total[i] = calculator(price[i], duration[i]);
                printf("Your total will be %.2f\n", total[i]);
            }
        }
        else
        {
            printf("The car parking lot is unavailable\n");
        }
    }
}

void remove_car()
{
    if(num == 0)
    {
        printf("No cars to remove\n");
    }
    int delete;
    printf("Enter car No(1-%d) to remove", num);
    scanf("%d", &delete);
    delete--;
    if(delete < 0 || delete >= max_slot)
    {
        printf("Invalid number\n");
    }
    for(int i=delete; i<num-1; i++)
    {
        Car_plate[i] = Car_plate[i+1];
        strcpy(car_type[i], car_type[i+1]);
        duration[i] = duration[i+1];
        total[i] = total[i+1];
    }
    num--;
}

void display(){
    printf("NO\t\tCar plate\t\tCar type\t\tDuration\t\tTotal\n");
    for(int i=0; i<num; i++)
    {
        printf("%d\t\t%d\t\t\t%s\t\t\t%.2f\t\t\t%.2f\n", i+1, Car_plate[i], car_type[type[i]-1], duration[i], total[i]);
    }
}

void exit_program(){
    exit(0);
}

float calculator(float price, float duration)
{
    int minute = duration * Hour_to_minute;
    if(minute<60)
    {
        return (minute*price)/60;
    }
    else
    {
        return price*duration;
    }
}




