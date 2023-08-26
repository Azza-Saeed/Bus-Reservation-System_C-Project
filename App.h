/*
 * App.h
 *
 * Created: 11/8/2023 3 PM
 *  Author: Azza Saeed
 */
#ifndef APP_H_
#define APP_H_

#define FIRST 0
#define SIZE 10
#define BUS1 1
#define BUS2 2
#define BUS3 3
#define NUM 20
#define NUM_ID_Didits 2   // id digits limitation must be two digits
 /*
 * Description: function to login the system
 * input: void
 * return: int (state of login)
 */
int Login(void);
 /*
 * Description: function to compare two strings
 * input: first string
 * return: second string
 */
int Compar(char* Save, char* Enterd);
 /*
 * Description: function to display the bis
 * input: void
 * return: void
 */
int Display_Selected_Bus(void);
 /*
 * Description: function to reserve seats
 * input: int
 * return: pointer to int
 */
int * Reserve_Seats(int);
 /*
 * Description: function to cancel the reservation of seats
 * input: void
 * return: void
 */
void Cancel_Seats(void);
 /*
 * Description: function to test the login phase
 * input: void
 * return: void
 */
void login_test(void);
 /*
 * Description: function to test the display phase
 * input: void
 * return: void
 */
void Display_Test(void);
 /*
 * Description: function to test the reservation phase
 * input: int
 * return: void
 */
void Reservation_Test(int busnum);

#endif
