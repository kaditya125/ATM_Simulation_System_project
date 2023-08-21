#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <string.h>

struct Customer
{
    char name[10];
    long int bank_ac;
    long int ATM_card;
    long mob_num;
    int pin;
    double debit;
    double credit;
    double balance;
}cust[10];
//Functions
void login();
void checkBalance(struct Customer cust);
float moneyDeposit(struct Customer cust);
float moneyWithdraw(struct Customer cust);
void menuExit(struct Customer cust);
int changepin(struct Customer cust);
void errorMessage();

    int option;
    int n, i,choose;
    bool again = true;
    long int ATM_CARD,ATM_PIN;

int main() 
{
    
    
   time_t tm;
   time(&tm);

    printf("enter the number of customer:- ");
    scanf("%d",&n);
    printf("Seed the customer's details:\n");
    for(i=1;i<=n;i++)
    {
        printf("customer %d detail's:-\n",i);
        printf("Name:- ");
        scanf("%s",&cust[i].name);
        printf("\nBank_account:- ");
        scanf("%ld",&cust[i].bank_ac);
        printf("\nATM CARD NO:- ");
        scanf("%ld",&cust[i].ATM_card);
        printf("\nMobile.Num:- ");
        scanf("%ld",&cust[i].mob_num);
        printf("\n Deposit Balance:- ");
        scanf("%lf",&cust[i].balance);
        printf("\n Set four digit Pin:- ");
        scanf("%d",&cust[i].pin);
    }
    
    printf("Customer details:-\n");
    printf("________________________________________________________\n");
    printf("\nS.No\tName\tBank Account\tATM_CARD\tMobile Num\tBalance\tPin\n");
    printf("________________________________________________________\n");
    for(i=1;i<=n;i++)
    {
        printf("\n%d).\t%s\t%ld\t%ld\t%ld\t%lf\t%d\n",i,cust[i].name,cust[i].bank_ac,cust[i].ATM_card,cust[i].mob_num,cust[i].balance,cust[i].pin);
    }
    printf("______________________________________________________\n");
    
    printf("______________________Hello Dear!_____________________________\n");
    printf("________________Welcome to ATM Banking_____________________\n\n");
       printf("________________insert your ATM CARD______________________\n");
       scanf("%ld",&ATM_CARD);
       printf("___________________card Detected_______________________\n");
       printf("\nplease Enter your 4 digit pin:\n");
      while(1)
      {
       scanf("%ld",&ATM_PIN);
       for(i=1;i<=n;i++)
       { 
          if(ATM_CARD==cust[i].ATM_card)
              if(ATM_PIN==cust[i].pin)
    
          {
            while (again)
            {
             printf("welcome %s!!!!\n",cust[i].name);
             printf("****Please choose one of the options below****\n\n");
             printf("< 1 >  Check Balance\n");
             printf("< 2 >  Deposit\n");
             printf("< 3 >  Withdraw\n");
             printf("< 4 >  Change Pin\n");
             printf("< 5 >  Exit\n\n");
         
             printf("________________________________________________\n");
             printf("Your Selection:\t");
             scanf("%d", &option);
            switch (option)
            {
                case 1:
                   checkBalance(cust[i]);
                   break;
                case 2:
                 cust[i].balance = moneyDeposit(cust[i]);
                   break;
                case 3:
                 cust[i].balance = moneyWithdraw(cust[i]);
                   break;
                case 4:
                 cust[i].pin = changepin(cust[i]);
                   break;

                case 5:
                   menuExit(cust[i]);
                   return 0;

                default:
                    errorMessage();
                    break;
            }

            printf("____________________________________________\n");
            printf("Would you like to do another transaction:\n");
            printf("< 1 > Yes\n");
            printf("< 2 > No\n");
            scanf("%d", &choose);
            
             if (choose == 2) 
             {
               again = false;
               menuExit(cust[i]);
             }
            }
          }
          else
             printf("oops!! pin invalid.please enter correct pin\n");
        }
        
        }
    
    return 0;
}

//Functions

//Main Menu

void checkBalance(struct Customer cust) {
    printf("You Choose to See your Balance\n");
    printf("\n\n****Your Available Balance is:   ₹%.2f\n\n",cust.balance);

}//Check Balance

float moneyDeposit(struct Customer cust) {
    float deposit;
    printf("You choose to Deposit a money\n");
    printf("Your Balance is: ₹%.2f\n\n",cust.balance);
    printf("****Enter your amount to Deposit\n");
    scanf("%f", &deposit);


   cust.balance += deposit;
   cust.credit+=deposit;
    

    printf("\nYour New Balance is:   ₹%.2f\n\n", cust.balance);
    return cust.balance;

}//money deposit

 float moneyWithdraw(struct Customer cust) {
    float withdraw;
    bool back = true;

    printf("You choose to Withdraw a money\n");
    printf("Your Balance is: ₹%.2f\n\n",cust.balance);
    printf("please enter the amount greater than 500 ");
    while (back) {
    
    printf("Enter your amount to withdraw:\n");
    scanf("%f", &withdraw);
    if(withdraw>500)

   {
   
    if (withdraw < cust.balance) {
        back = false;
       cust.balance -= withdraw;
        cust.debit+=withdraw;
        printf("\nYour withdrawing money is:  ₹%.2f\n", withdraw);
        printf("Your New Balance is:   ₹%.2f\n\n",cust.balance);

    }

        else  {

        printf("oops!!!You don't have enough money\n");
        printf("Please contact to your Bank Customer Services\n");
        printf("Your Balance is:   ₹%.2f\n\n",cust.balance);

    }
}
else 
{
	printf("please enter greater than 500");
}
    }
    return cust.balance;


}//money withdraw

int changepin(struct Customer cust){
	int oldpin,newpin;
	printf("please enter your old pin:-");
	while(1)
	{
	scanf("%d",&oldpin);
	if(cust.pin==oldpin)
	{
		printf("\nEnter your new four digit pin:-");
		scanf("%d",&newpin);
		cust.pin=newpin;
		printf("\ncongo!! your pin has been change succesfully!");
		break;
	}else
	{
		printf("\nsorry! its invalid pin. Try with another pin!");
	}
}
return cust.pin;

}

void menuExit(struct Customer cust) {
    time_t tm;
    time(&tm);
    printf("--------------Take your receipt!!!------------------\n");
    printf("---------------------Receipt-------------------------\n");
    printf("%s",ctime(&tm));
    printf("_____________________________________________________\n");
    printf("Transaction details:-\n");
    printf("Dear %s!!!!\n",cust.name);
    printf("BANK ACCOUNT:-%ld\n",cust.bank_ac);
    printf("MOBILE NUMBER:-%ld\n",cust.mob_num);
    printf("AMOUNT CREDITTED:-%.2f\n",cust.credit);
    printf("AMOUNT DEBITTED:- %.2f\n",cust.debit);
    printf("CURRENT BALANCE:-₹%.2f\n",cust.balance);
    printf("Thank you for using ATM Banking Machine!!!-----\n");
    printf("_____________________________________________________\n");


}

void errorMessage() {;
    printf("!!!You selected invalid number!!!\n");
}