#include <stdio.h>
void confirmation(int menu_number);
void welcome();
int menu();

int main()
{
    int menu_number;
welcome();
getchar();
menu();
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
float coins_total,coins_E=3.5,coins_C=4.5,coins_M=5.5;
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