#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define Esp_beans 8
#define Esp_water 30

#define Cap_beans 8
#define Cap_water 30
#define Cap_milk 70

#define Mocha_beans 8
#define Mocha_water 39
#define Mocha_milk 160
#define Mocha_choco 30

#define Threshold 10
#define Password 1234
#define total_amount 0

// Global variables
double total = total_amount;
int coffee_beans = 100, water = 500, milk = 200, chocolate = 100;
double Esp_price = 3.5;
double Cap_price = 4.5;
double Mocha_price = 5.5;

// Function declarations
void main_menu();
void order();
void admin();
void refill();
void change_prices();
void display_ingredients_and_total();
void reset_total();  

// Main function
int main() {
    int choice;

    while (1) {
        main_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                order();
                break;
            case 2:
                admin();
                break;
            case 3:
                printf("Resetting the program\n");
                return 0;
            default:
                printf("Invalid option.Try again.\n");
        }
    }
    return 0;
}

// Defining a function to display the main menu
void main_menu() {
    printf("\n\t\t Coffee Maker Simulator\n1. Order a coffee\n2. Admin mode\n3. Exit\nEnter a number:");
}

// Defining a function to allow user to order coffee
void order() {
    int choice;
    double price = 0.0;

    while (1) {
        printf("\n\t\t Coffee Menu\n");

        if (coffee_beans >= Esp_beans && water >= Esp_water) {
            printf("1. Espresso (%.2f AED)\n", Esp_price);
        } else {
            printf("1.Unavailable due to temporarily insufficient ingredients \n");
        }

        if (coffee_beans >= Cap_beans && water >= Cap_water && milk >= Cap_milk) {
            printf("2. Cappuccino (%.2f AED)\n", Cap_price);
        } else {
            printf("2. Unavailable due to temporarily insufficient ingredients \n");
        }

        if (coffee_beans >= Mocha_beans && water >= Mocha_water && milk >= Mocha_milk && chocolate >= Mocha_choco) {
            printf("3. Mocha (%.2f AED)\n", Mocha_price);
        } else {
            printf("3.Unavailable due to temporarily insufficient ingredients \n");
        }

        printf("0. Go back\n");
        printf("Select your coffee: ");
        scanf("%d", &choice);

        if (choice == 0) return;
         
         // Prompt user to confirm selection
        char confirm;
        printf(" Do you want to confirm your selection? (y/n): ");
        scanf(" %c", &confirm);

        if (confirm != 'y') {
            printf("Returning to the coffee menu.\n");
            continue;
        }

        switch (choice) {
            case 1:
                if (coffee_beans >= Esp_beans && water >= Esp_water) {
                    price = Esp_price;
                    coffee_beans -= Esp_beans;
                    water -= Esp_water;
                } else {
                    printf("Cannot make Espresso. Please refill ingredients.\n");
                    continue;
                }
                break;
            case 2:
                if (coffee_beans >= Cap_beans && water >= Cap_water && milk >= Cap_milk) {
                    price = Cap_price;
                    coffee_beans -= Cap_beans;
                    water -= Cap_water;
                    milk -= Cap_milk;
                } else {
                    printf("Cannot make cappuccino. Please refill ingredients.\n");
                    continue;
                }
                break;
            case 3:
                if (coffee_beans >= Mocha_beans && water >= Mocha_water && milk >= Mocha_milk && chocolate >= Mocha_choco) {
                    price = Mocha_price;
                    coffee_beans -= Mocha_beans;
                    water -= Mocha_water;
                    milk -= Mocha_milk;
                    chocolate -= Mocha_choco;
                } else {
                    printf("Cannot make Mocha. Please refill ingredients.\n");
                    continue;
                }
                break;
            default:
                printf("Invalid selection. Try again.\n");
                continue;
        }

        printf("Your choice costs %.2f AED. Please pay.\n", price);

        // Payment logic
        double paid_money = 0.0;
        double coin;

        while (paid_money < price) {
            printf("Insert coin (1 or 0.5 AED): ");
            scanf("%lf", &coin);

            if (coin == 1.0 || coin == 0.5) {
                paid_money += coin;
            } else {
                printf("Invalid coin. Please try again.\n");
            }
        }
         double change = paid_money - price;

        printf("Your coffee is ready! %.2f AED paid. Enjoy!\n", paid_money);
        printf("Your change is %.2f AED \n",change);

        // Update total sales
        total += price;

        // Check for low ingredients and print alerts
        if (coffee_beans <= Threshold) {
            printf("Attention! coffee beans must be refilled.\n");
        }
        if (water <= Threshold) {
            printf("Attention! water must be refilled.\n");
        }
        if (milk <= Threshold) {
            printf("Attention! milk must be refilled.\n");
        }
        if (chocolate <= Threshold) {
            printf("Attention! chocolate syrup must be refilled.\n");
        }

        return;
    }
}

// Defining function to allow access to admin interface
void admin() {
    int password, choice;

    printf("Enter admin password: ");
    scanf("%d", &password);

    if (password != Password) {
        printf("Incorrect password.\n");
        return;
    }

    while (1) {
        printf("\n\t\tAdmin space\n1. Display ingredients and total sales\n2. Refill ingredients\n3. adjust coffee prices\n4. Reset sales\n0. Exit admin space\nSelect a number:");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_ingredients_and_total();
                break;
            case 2:
                refill();
                break;
            case 3:
                change_prices();
                break;
            case 4:
                reset_total();
            case 0:
                return;
            default:
                printf("Invalid option. Try again.\n");
        }
    }
}

// Defining function to refill ingredients
/*void refill() {

}*/

// Defining function to adjust coffee prices
void change_prices() {
    printf("Current prices:\n");
    printf("Espresso: %.2f AED\n", Esp_price);
    printf("Cappuccino: %.2f AED\n", Cap_price);
    printf("Mocha: %.2f AED\n", Mocha_price);

    printf("\nEnter new price for Espresso: ");
    scanf("%lf", &Esp_price);
    printf("Enter new price for Cappuccino: ");
    scanf("%lf", &Cap_price);
    printf("Enter new price for Mocha: ");
    scanf("%lf", &Mocha_price);

    printf("Coffee prices have been updated\n");
}

// Defining function to display ingredients and total amount
void display_ingredients_and_total() {
    printf("Current ingredients:\n");
    printf("Coffee Beans: %d g\n", coffee_beans);
    printf("Water: %d ml\n", water);
    printf("Milk: %d ml\n", milk);
    printf("Chocolate Syrup: %d ml\n", chocolate);
    printf("Total sales: %.2f AED\n", total);
}

// Function to reset total sales
void reset_total() {
    char confirm;
    printf("Are you sure you want to reset total sales to zero? (y/n): ");
    scanf(" %c", &confirm);

    if (confirm == 'y') {
        total = 0; // Reset the total sales
        printf("Total sales reset.Collect the money from the machine\n");
    } else {
        printf("Total sales reset canceled.\n");
    }
}