#include <stdio.h>



struct Date
{

    int day;
    int month;
    int year;

    
};
void initdate(struct Date *ptrdate)
    {
    printf("IN INITIAL DATE FUNCTION \n");
    ptrdate->day=0;
    ptrdate->month=0;
    ptrdate->year=0;
    
    }

    void printDateOnConsole(struct Date *ptrDate)
    {
         printf("IN PRINT DATE ON CONSOLE FUNCTION \n");

        printf("Date is %d-%d-%d \n",ptrDate->day,ptrDate->month,ptrDate->year);
    }

    void acceptDateFromConsole(struct Date *ptrDate)
    { printf("IN ACCEPT DATE FROM CONSOLE FUNCTION \n");

printf("Enter day month year \n ");
scanf("%d%d%d",&ptrDate->day,&ptrDate->month,&ptrDate->year);

    }



int main()
{

    
    int ch;
    struct Date dt;
    do
    {
          printf("************DATE**************\n");
          printf("0.EXIT\n");
          printf("1.Initial Date\n");
           printf("2.Print Date On Console\n");
            printf("3.Accept Date On console\n");
             printf("Enter your choice\n");
        
        scanf("%d",&ch);

        switch (ch)
        {
        case 0:
            printf("************EXIT**************\n");
                break;
        case 1:
            initdate(&dt);
            break;

        case 2:
            printDateOnConsole(&dt);
            break;

        case 3:
            acceptDateFromConsole(&dt);
            break;

        default:
           printf("ENTER VALID CHOICE\n");

            break;
        }
        

    } while (ch);

    return 0;
}