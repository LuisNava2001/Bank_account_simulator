#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

#define MAX_TRANSACTIONS 100

typedef struct {
    char description[50];
    double amount;
    char date[30];
} Transaction;

int main(){
    int election = 0;
    int count = 0;
    double current_money = 100.00;
    double deposit = 0;
    double withdraw = 0;
    double history_money = 0;
    Transaction history[MAX_TRANSACTIONS];

    time_t t;
    struct tm *timeinfo;

    printf("\n#########################################################################\n\nDear Colaborator! I'm glad to see you again...\n");
    printf("Welcome to Apizaco Bank, Your Best Election!\n\n");
    
    while(1){
        time(&t);
        timeinfo = localtime(&t);
        printf("%s",asctime(timeinfo));
        printf("\n\nPlease, select an option you want to do...\n\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Balance Check\n");
        printf("4. Transaction history\n");
        printf("5. Exit the program\n\n");
        printf("=======>:   ");
        if(scanf("%d", &election) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }
        printf("\n\n#########################################################################\n\n");

        switch (election)
        {
        case 1:
            printf("###         DEPOSIT         ###\n\n");
            printf("%s\n\n",asctime(timeinfo));
            printf("Wallet: $ %f\n\n", current_money);
            printf("Enter your deposit: $ ");
            scanf("%lf", &deposit);
            if(deposit > 0){
                time_t t = time(NULL);
                struct tm*timeinfo = localtime(&t);
                current_money = current_money + deposit;
                printf("\nWallet: $ %lf\n", current_money);
                strcpy(history[count].description, "Deposit:");
                history[count].amount = deposit;
                strftime(history[count].date, sizeof(history[count].date), "%Y-%m-%d %H:%M:%S", timeinfo);
                count++;
            }else{
                if(deposit == 0) {
                    printf("\n\nYou did not deposit anything... Please, try again.");
                } else {
                    printf("\n\nYou can not deposit negative numbers... Please, try again.");
                }
            }
            printf("\n\n#########################################################################\n\n");
            printf("Press any key to continue...\n\n");
            getch();
            break;
        
        case 2:
            printf("###         WITHDRAW         ###\n\n");
            printf("%s\n\n",asctime(timeinfo));
            printf("Wallet: $ %f\n\n", current_money);
            printf("Enter your withdrawal: $ ");
            scanf("%lf", &withdraw);
            if(withdraw >= 0 & current_money >= withdraw){
                time_t t = time(NULL);
                struct tm*timeinfo = localtime(&t);
                current_money = current_money - withdraw;
                printf("\nWallet: $ %lf\n", current_money);
                strcpy(history[count].description, "Withdrawal:");
                history[count].amount = -withdraw;
                strftime(history[count].date, sizeof(history[count].date), "%Y-%m-%d %H:%M:%S", timeinfo);
                count++;
            } else {
                printf("\n\nYou do not have enough money to withdraw that quantity... Please, try again.");
            }
            printf("\n\n#########################################################################\n\n");
            printf("Press any key to continue...\n\n");
            getch();
            break;

        case 3:
            printf("###         BALANCE CHECK         ###\n\n");
            printf("%s\n\n",asctime(timeinfo));
            printf("Wallet: $ %f\n\n", current_money);

            printf("Press any key to continue...\n\n");
            getch();
            break;

        case 4:
            printf("###         TRANSACTION HISTORY         ###\n\n");
            printf("%s\n",asctime(timeinfo));
            for (int i = 0; i < count; i++) {
                if (i == 0){
                    printf("============================================================\n");
                }
                printf("%d. %s $ %.2f   ---   %s\n============================================================\n", i + 1, history[i].description, history[i].amount, history[i].date);
            }
            printf("\n\nPress any key to continue...\n\n");
            getch();
            break;
        
        case 5:
            printf("%s\n\n",asctime(timeinfo));
            printf("Good bye!!\nBy LuisNava2001.\n");
            return 0;
        
        default:
            printf("\n\nError!! Invalid Option. Try again.\n\n");
        }
    }
    return 0;
}