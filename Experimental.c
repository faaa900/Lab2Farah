#include <stdio.h>

/*The quantity requirement of each ingredient to make a cup of coffee.*/
# define coffee_beans 8
# define Esp_Cap_water 30
# define mocha_water 39
# define Esp_Cap_choco 0
# define mocha_choco 30
#define esp_milk 0
#define Cap_milk 70
#define Mocha_milk 160

/*Cost*/
#define coins_E 3.5
#define coins_C 4.5
#define coins_M 5.5
#define total_amount

/*The admin password*/
#define password 1234

/*The low threshold quantity for each ingredient in the machine*/
#define Thresh_beans 10
#define Thresh_water 50
#define Thresh_choco 50
#define Thresh_milk 200

void confirmation(int menu_number);
void welcome();
int menu();

int main()
{
    int menu_number;
welcome();
getchar();
/*menu();*/
menu_number=menu();
confirmation(menu_number);
return 0;
}

void welcome()
{
    printf("\t\t Hello there! \n");
    printf("\t\t Press any key to continue \n");
}

int menu()
{
 int menu_number;
printf("Main menu \n Enter a number from the list: \n 1.Espresso (%f) \n 2.Cappuccino (%f) \n 3.Mocha (%f) \n 4.Exit \n",coins_E,coins_C,coins_M);
scanf("%i",&menu_number); 
return menu_number;  
}

void confirmation(int menu_number)
{
    switch(menu_number)
    {
        case 1:printf("You have selected espresso\n");break;
        case 2:printf("You have selected cappuccino\n");break;
        case 3:printf("You have selected Mocha\n");break;
        case 4:break;
        default:printf("Invalid input\n");break;

    }
}