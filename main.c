#include <stdio.h>
//#include "main.h"
#define FILENAME "checking.log"
#pragma warning(disable : 4996) // To supress errors
#define SENT 4

void display_title(void)
{
    puts("Banking\n");
    puts("Code by Jason Ventura!\n");
}

void say_goodbye(void)
{
    puts("All done\n");
}
typedef struct
{
    int id;
    double I; // Initial account balance
    double D; // Deposit
    double W; // Withdraw
    double C; // Check 
    double NB; // New balance
    char name[100];
} bankmember_t;

bankmember_t person = {.I = 1200.20 };


double withdraw(bankmember_t person)
{
    double withdrawal = 0;
    printf("Enter an amount to withdraw: ");
    scanf("%lfdeposit\n", &withdrawal);
    if (withdrawal > person.I) return withdraw(person); // Recursion to prevent handle incorrect withdrawals 
    person.W = withdrawal;
    // printf("You deposited: %.2f\n", person.D);
    return person.W;
}

double deposit(bankmember_t person)
{
    double deposited = 0;
    printf("Enter an amount to deposit: ");
    scanf("%lfdeposit\n", &deposited);
    person.D = deposited;
   // printf("You deposited: %.2f\n", person.D);
    return person.D;
}



void create_checking_account_file()
{
    FILE* fp = fopen(FILENAME, "w"); // Write to the file
    if (fp == NULL) { perror("fopen"); }
    fprintf(fp, "%lf %lf %lf", person.I, withdraw(person) , 619.84);
    fclose(fp);

    fp = fopen(FILENAME, "r"); // Read the file
    if (fp == NULL) { perror("fopen"); }
    //double  I, D, C, NB;

    // puts("File must start with i\n");
     //char IsI = getchar();
     //printf("The file starts with %d", IsI);

    fscanf(fp, "%lf", &person.I);
    printf("Initial Account balance: %.2f\n", person.I); // Read initial account balance

    fscanf(fp, "%lf", &person.W);
    printf("You withdrawed: %.2f\n", person.W);// Read withdrawal
    person.NB = person.I - person.W;
    printf("New Balance: %.2f\n", person.NB); // Read new balance

    fscanf(fp, "%lf", &person.D);
    printf("Deposit: %.2f\n", person.D);
    person.NB += person.D;
    printf("New Balance: %.2f\n", person.NB); // Read new balance again

    fclose(fp);
}

int main(void)
{
    display_title();
    create_checking_account_file();
    say_goodbye();

    return 0;
}