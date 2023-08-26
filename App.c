/*
 * App.c
 *
 * Created: 11/8/2023 3 PM
 *  Author: Azza Saeed
 */

#include "App.h"

extern num_seats;
extern Bus_num;
extern ID[SIZE];

extern Bus1_seats;
extern Bus2_seats;
extern Bus3_seats;

int Login(void)
{
    char Save_username[SIZE]="azza";
    int Save_password=1234;
    char New_username[SIZE];
    int  New_password;
    int res=0;
    printf("Enter User name:\n");
    scanf("%s",New_username);
    printf("Please enter the Password:\n");
    scanf("%d",&New_password);

    if( (Compar(Save_username,New_username)==1) && (Save_password==New_password)  )
    {
        printf("Login passed...!\n");
        res=1;
    }
    else if(  (Compar(Save_username,New_username)==0) && (Save_password==New_password) )
    {
        printf("Invalid Username...!\n");
        res=0;
    }
    else if( (Compar(Save_username,New_username)==0) && !(Save_password==New_password) )
    {
        printf("Invalid Username and invalid password...!\n");
        res=0;
    }
    else if(  (Compar(Save_username,New_username)==1) && ((Save_password==New_password)==0) )
    {
        printf("Invalid password...!\n");
        res=0;
    }
    else
    {
        // Do Nothing
    }

    return res;
}

int Compar(char* Save, char* Enterd)
{
    int comper  ;
    int flag=1;
    for(comper = FIRST ; Save[comper] || Enterd[comper] ;comper++)
    {
        if(Save[comper] !=Enterd[comper] )
        {
            flag=0;
        }
        else
        {
            // Do Nothing
        }
    }
    return flag;
}

int Display_Selected_Bus(void)
{
    printf("Select Bus from the next bus's....\n");
    printf("                 ********************             \n");
    printf("Press 1 to select Bus1 to Giza        Press 2 to select Bus2 to Ramsis\n");
    printf("Press 3 to select Bus3 to Elwasta\n");

    printf("Please enter Bus's number:\n");
    scanf("%d",&Bus_num);
    if( Bus_num==BUS1 || Bus_num==BUS2 || Bus_num==BUS3 )
    {
        switch(Bus_num)
    {
        case 1:
            printf("Number of available seats= %d\n",Bus1_seats);
            return 1;
        break;
        case 2:
            printf("Number of available seats= %d\n",Bus2_seats);
            return 2;
        break;
        case 3:
            printf("Number of available seats= %d\n",Bus3_seats);
            return 3;
        break;
        default:
        break;
    }

    }
    else{

     printf("Please enter valid bus number from the list above...!!!\n");
        return 0;
    }


}

int * Reserve_Seats(int busnum)
{
    int number_Bus=busnum;
    printf("Welcome in reservation phase...!!!\n");
    printf("                 ********************             \n");
    printf("\n");
    if(number_Bus==BUS1)
    {
        printf("Please enter number of seat's you need:\n");
            scanf("%d",&num_seats);
            if(num_seats<0)
            {
                printf("Please enter valid number from 0 to 20\n");
            }
            else
            {
                ID[0]=1;
                ID[NUM_ID_Didits-1]=num_seats;

                if( ID[1] >= Bus1_seats)
                {
                   printf("No seat available ,try another time...\n");
                   return 0;
                }
                  Bus1_seats=Bus1_seats-ID[1];
                printf("number of new seats available=%d\n",Bus1_seats);

            }
    }
    else if(number_Bus==BUS2)
    {
            printf("Please enter number of seat's you need:\n");
            scanf("%d",&num_seats);
            if(num_seats<0 )
            {
                printf("Please enter valid number from 0 to 20\n");
            }
            else
            {
                ID[0]=2;
                ID[NUM_ID_Didits-1]=num_seats;

                if( ID[1] >= Bus2_seats)
                {
                   printf("No seat available ,try another time...\n");
                   return 0;
                }
                    Bus2_seats=Bus2_seats-ID[1];
                printf("number of new seats available=%d\n",Bus2_seats);

            }

    }
    else if(number_Bus==BUS3)
    {
            printf("Please enter number of seat's you need:\n");
            scanf("%d",&num_seats);
            if(num_seats<=0)
            {
                printf("Please enter valid number from 0 to 20\n");
            }
            else
            {
                ID[0]=3;
                ID[NUM_ID_Didits-1]=num_seats;

                if( ID[1] >= Bus3_seats)
                {
                   printf("No seat available ,try another time...\n");
                   return 0;

                }
                Bus3_seats=Bus3_seats-ID[1];
                printf("number of new seats available=%d\n",Bus3_seats);
            }
    }
    else{
        printf("Invalid Bus number...!!\n");
        return 0;
    }

    return ID;
}


void Cancel_Seats(void)
{
    int idd[SIZE];
    int i;
    int new_id[SIZE];
    printf("Welcome to cancel phase...!!!\n");
    printf("please enter id of seats:\n");
    for(i=0;i<NUM_ID_Didits;i++)
    {
        scanf("%d",&idd[i]);
    }
    new_id[1]=idd[0];
    switch(new_id[1])
    {
        case 1:
            if(Bus1_seats == NUM)
            {
                printf("All Bus seats is not reserved...\n");
            }
            else{
                Bus1_seats=Bus1_seats+idd[1];
                printf("num_seats after cancellation=%d\n",Bus1_seats);
            }
        break;
        case 2:
            if( Bus2_seats == NUM )
            {
                printf("All Bus seats is not reserved...\n");
            }
            else{
                Bus2_seats=Bus2_seats+idd[1];
                printf("num_seats after cancellation=%d\n",Bus2_seats);
            }

        break;
        case 3:
            if( Bus3_seats == NUM )
            {
                printf("All Bus seats is not reserved...\n");
            }
            else{
                Bus3_seats=Bus3_seats+idd[1];
                printf("num_seats after cancellation=%d\n",Bus3_seats);
            }

        break;

    }


}

void login_test(void)
{
    if(Login())
    {
        printf("Test case passed\n");
    }
    else{
        printf("program failled\n");
    }
}

void Display_Test(void)
{
    if(Display_Selected_Bus())
    {
        printf("Test case passed\n");
    }
    else
    {
        printf("program failled\n");
    }
}

void Reservation_Test(int busnum)
{
    if(Reserve_Seats(busnum))
    {
        printf("Test case passed\n");
    }
    else{
        printf("Program failled\n");
    }
}

void Runable_Fun(void)
{
    int *arr;
    int selected_Phase;
    int press;
    int pressed_bus;
    int login_pressed;

    printf("Hello for our system, please login us....\n");
    printf("                 ********************             \n");
    printf("Press 1 to login\n");
    scanf("%d",&login_pressed);
    if( login_pressed==1 )
    {
        int Is_Pass=Login();


        if(Is_Pass)
        {
            int busnumber;
            busnumber=Display_Selected_Bus();
            int i,j;
            if(busnumber==BUS1 || busnumber==BUS2 || busnumber==BUS3)
            {
                top:  printf("Press 1 to reserve phase   Press 2 to cancel phase \n");
                scanf("%d",&press);
                if(press==1)
                {
                    arr=Reserve_Seats(busnumber);
                    printf("id=");
                    for(i=0;i<2;i++)
                    {
                    printf("%d",arr[i]);
                    }
                    printf("\n");
                    goto top;
            }
            else if(press==2)
            {
                    Cancel_Seats();
                    goto top;
            }
        }
        else{
            // Do Nothing
        }


    }
    else
    {
        printf("Please check login phase...!!!\n");
    }

    }
    else{
        printf("Please enter valid number..\n");
    }

    return 0;
}
