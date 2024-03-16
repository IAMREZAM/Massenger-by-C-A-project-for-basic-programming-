#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>        
#include <string.h>
#include <conio.h>
#include <stdlib.h> 
#define PHONE_SIZE 5     //number of users
#define NUM_SIZE 12      //number of phone number digits + 1
#define pass_size 20     //number of password digits and username size
#define MAIL_NUMBER 10   //number of messages
#define MAIL_SIZE 30     //size of message
int signup(char number[PHONE_SIZE][NUM_SIZE], char password[PHONE_SIZE][pass_size], char repass[PHONE_SIZE][pass_size], char user[PHONE_SIZE][pass_size], char mail[PHONE_SIZE][PHONE_SIZE][MAIL_NUMBER][MAIL_SIZE], int* i);
int loginlist(char mail[PHONE_SIZE][PHONE_SIZE][MAIL_NUMBER][MAIL_SIZE], char user[PHONE_SIZE][pass_size], int* i);
int checkphoneformat(char* number);
int login(char user[PHONE_SIZE][pass_size], char password[PHONE_SIZE][pass_size], char mail[PHONE_SIZE][PHONE_SIZE][MAIL_NUMBER][MAIL_SIZE], int* i);
int logout();
int signup(char number[PHONE_SIZE][NUM_SIZE], char password[PHONE_SIZE][pass_size], char repass[PHONE_SIZE][pass_size], char user[PHONE_SIZE][pass_size], char mail[PHONE_SIZE][PHONE_SIZE][MAIL_NUMBER][MAIL_SIZE], int* i) {
	int flag = 0, point = 0;    //both of them has flag responsibility
	for (*i = 1; *i < 5; (*i)++) {
		if (number[*i][0] == '1') {     //check that how many users have signed up
			printf("Enter your phone number\n");
			scanf("%s", number[*i]);
			for (int j = 1; j < *i; j++) {
				if (strcmp(number[j], number[*i]) == 0) {    //check that if its not Repetitious
					printf("its already signed up\n");
					number[*i][0] = '1';
					return 0;
				}
			}
			if (checkphoneformat(number[*i])) { //entering the checkphoneformat function
				printf("wrong format ");
				(*i) = (*i) - 1;
				continue;
			}
			else if (strlen(number[*i]) != 11) {    //check that if the number has acceptable number of digits
				printf("wrong number of digits");
				number[*i][0] = '1';
				(*i) = (*i) - 1;
				continue;
			}
			else {
				system("cls");
				while (1) {
					printf("Enter your username\n""WARNING: use underline(_) as space( )\n");        //username part
					scanf("%s", user[*i]);
					if (strlen(user[*i]) > 20) {   //checking the username number of charachters
						printf("less than 21 charachters\n");
						continue;
					}
					for (int j = 0; j < *i; j++) {
						if (strcmp(user[j], user[*i]) == 0) {
							printf("its already taken\n");               //checking the username if its not taken
							flag = 1;
							break;
						}
						else
							flag = 0;
					}
					if (flag == 1)
						continue;
					else {
						system("cls");
						break;
					}
				}
				while (1) {  //it gets password and check it
					printf("please Enter your password\n");
					scanf("%s", password[*i]);
					if (5 < strlen(password[*i]) && strlen(password[*i]) < 21) {  //check password length
						printf("type again\n");
						scanf("%s", repass[*i]);
						if (strcmp(password[*i], repass[*i]) != 0) {
							printf("password doesnt match\n");
							continue;
						}
						else {
							loginlist(mail, user, i);   //if the information were enterd correctley you will login here
							return 1;
						}
					}
					else {
						printf("wrong number of digits    ");
						continue;
					}

				}
			}
		}
	}
	if (number[4][0] != 0) {       //if four accounts sign up this will work
		printf("sorry, there is no empty room /:\n");
		return 0;
	}
	return 0;
}
int loginlist(char mail[PHONE_SIZE][PHONE_SIZE][MAIL_NUMBER][MAIL_SIZE], char user[PHONE_SIZE][pass_size], int* i) {  //login function
	int loggoption, reciever, flag, mailnumber, point;  //some variables that is used just in this function
	printf("youre logged in\n");
	while (1) {
		printf("choose one of the following options:    ""1 to send message    ""2 to see messages\n""3 to create group    ""4 to create channel    ""0 to logout\n");
		scanf("%d", &loggoption);
		if (loggoption == 1) {
			system("cls");
			while (1) {
				printf("who is the reciever? ;)\n");
				char userecieve[pass_size];
				scanf("%s", userecieve);       //getting the name of reciever
				for (int p = 1; p < 5; p++) {   //checking the username if it exists
					if (p == *i)
						continue;
					if (strcmp(userecieve, user[p]) == 0) {
						reciever = p;
						flag = 0;
						break;
					}
					else {
						flag = 1;
					}
				}
				if (flag == 1) {
					printf("there is no username such that\n");
					continue;
				}
				for (mailnumber = 0; mailnumber < 10; mailnumber++) {  //checking if there are free room for  message
					if (mail[*i][reciever][mailnumber][1] == '0') {
						flag = 0;
						break;
					}
					else
						flag = 1;
				}
				if (flag == 1) {
					printf("there is no room for message\n");
					break;
				}
				printf("type your message\n""WARNING: use underline(_) as space( )\n");
				scanf("%s", mail[*i][reciever][mailnumber]);                //getting the message text
				printf("message has been delivered\n");
				break;
			}
		}
		else if (loggoption == 2) {      //user chose seeing messages
			system("cls");
			while (1) {
				printf("1 for inbox    and     2 for sent box\n");
				int box;
				scanf("%d", &box);
				if (box == 1) {       //inbox part
					system("cls");
					int sender;
					printf("who is the sender\n");
					char usersend[pass_size];
					scanf("%s", usersend);   //getting sender username
					for (int p = 1; p < 5; p++) {
						if (strcmp(usersend, user[p]) == 0) {       //checking if it exists 
							sender = p;
							flag = 0;
							break;
						}
						else
							flag = 1;
					}
					if (flag == 1) {
						printf("there is no username such that\n");
						continue;
					}
					printf("this is your inbox\n");
					for (int p = 0; p < 10; p++) {
						if (mail[sender][*i][p][0] != '0') {           //searching for messages
							printf("%s\n", mail[sender][*i][p]);
							point = 0;
						}
						else
							point = 1;
					}
					if (point == 1)
						printf("there is no message to show\n");   //when there is no message to show
					point = 0;
					break;
				}
				else if (box == 2) {     //sent messages part
					printf("who is the reciever\n");
					char userecieve[pass_size];
					scanf("%s", userecieve);         //getting reciever username
					for (int p = 1; p < 5; p++) {
						if (strcmp(userecieve, user[p]) == 0) {          //finding username
							reciever = p;
							flag = 0;
							break;
						}
						else
							flag = 1;
					}
					if (flag == 1) {
						printf("there is no username such that\n");
						continue;
					}
					printf("this is your inbox\n");
					for (int j = 0; j < 5; j++) {
						if (mail[*i][reciever][j][0] != '0') {         //checking if there is a message
							printf("%s\n", mail[*i][reciever][j]);
							point = 0;
						}
						else
							point = 1;
					}
					if (point == 1)
						printf("there is no message to show\n");   //when there is no message to show
					point = 0;
					break;
				}
				else     //if user enter a unacceptable input
					continue;
			}
		}
		else if (loggoption == 3) {
			continue;
		}
		else if (loggoption == 4) {
			continue;
		}
		else if (loggoption == 0) {  //logout
			logout();
			return 0;
		}
		else {
			printf("unacceptable, try again\n");
			continue;
		}
	}
}
int checkphoneformat(char* number) {   //checking input format function
	if (number[0] != '0')  //checking if the first charachter is '0'
		return 1;
	else {
		for (int i = 1; i < 11; i++) {    //checking if all chrachters all natural numbers
			if (number[i] == '0' || number[i] == '1' || number[i] == '2' || number[i] == '3' || number[i] == '4' || number[i] == '5' || number[i] == '6' || number[i] == '7' || number[i] == '8' || number[i] == '9')
				printf("_");
			else
				return 1;
		}
	}
	return 0;
}
int login(char user[PHONE_SIZE][pass_size], char password[PHONE_SIZE][pass_size], char mail[PHONE_SIZE][PHONE_SIZE][MAIL_NUMBER][MAIL_SIZE], int* i) {   //login function
	system("cls");
	while (1) {
		printf("login with your username and password\n");
		printf("enter your username\n");
		scanf("%s", user[0]);     //getting the username
		if (strlen(user[0]) > 20) {    //check number of digits  
			printf("wrong format");
			continue;
		}
		else
			for (int j = 1; j < 5; j++)
				if (strcmp(user[0], user[j]) == 0) {
					system("cls");
					printf("enter the password\n");
					scanf("%s", password[0]);      //getting password
					if (strcmp(password[0], password[j]) == 0) {
						loginlist(mail, user, &j);       //now user is loged in
						return 1;
					}
					else {
						printf("password does not match with number");
						continue;
					}
				}
		printf("user doesnt exist, try again with another one\n");    //if there isnt username such that
		continue;
	}
}
int logout() {      //logout function
	printf("youre logged out\n");
	return 0;
}
void main() {      //main function
	int  o, w;     //o refers to option 
	int* i;         //a pointers for using in functions and arrays argumants 
	i = &w;
	char number[PHONE_SIZE][NUM_SIZE], password[PHONE_SIZE][pass_size], repass[PHONE_SIZE][pass_size], user[PHONE_SIZE][pass_size], mail[PHONE_SIZE][PHONE_SIZE][MAIL_NUMBER][MAIL_SIZE];
	FILE *inmessage = fopen("input.text", "r");
	if (inmessage != NULL) {
		for (int m = 0; m < 5; m++)
			for (int n = 0; n < 5; n++)
				for (int k = 0; k < 10; k++)
					fscanf(inmessage, "%s", mail[m][n][k]);
		fclose(inmessage);
	}
	else
		for (int m = 0; m < 5; m++)
			for (int n = 0; n < 5; n++)
				for (int k = 0; k < 10; k++)
					mail[m][n][k][1] = '0';
	FILE *inphone = fopen("phone.text", "r");
	if (inphone != NULL) {
		for (int d = 1; d < 5; d++) {
			printf("*");
			fscanf(inphone, "%s", number[d]);
		}
		fclose(inphone);
	}
		else
			number[1][0] = '1', number[2][0] = '1', number[3][0] = '1', number[4][0] = '1';
	FILE *passID = fopen("passID.text", "r");
	if (passID != NULL) {
		for (int e = 1; e < 5; e++)
			fscanf(passID, "%s", password[e]);
		for (int e = 1; e < 5; e++)
			fscanf(passID, "%s", user[e]);
		fclose(passID);
	}
	else
		printf("*");
	printf("welcome to RM messenger\n");  //first this will be showed
	while (1) {
		int flag = 0;
		printf("please choose one of the following options\n""1 to sign up , 2 to login & 3 to quit\n");
		scanf("%d", &o);		//getting one option
		if (o == 1) { //sign up
			system("cls");
			signup(number, password, repass, user, mail, i);
		}
		else if (o == 2) {   //login part
			system("cls");
			login(user, password, mail, i);   //entering login function
		}
		else if (o == 3) {
			system("cls");
			printf("thanks for choosing our messenger\n");  //quit program
			FILE *outphone = fopen("phone.text", "w");
			for (int r = 1; r < 5; r++) {
				fprintf(outphone, "%s\n", number[r]);
			}
			fclose(outphone);
			FILE *outmessage = fopen("input.text", "w");
			for (int m = 0; m < 5; m++)
				for (int n = 0; n < 5; n++)
					for (int k = 0; k < 10; k++)
						fprintf(outmessage, "%s\n", mail[m][n][k]);
			fclose(outmessage);
			FILE *passIDO = fopen("passID.text", "w");
				for (int e = 1; e < 5; e++)
					fprintf(passIDO, "%s\n", password[e]);
				for (int y = 0; y < 5; y++)
					printf(passIDO, "%s\n", user[y]);
			fclose(passIDO);
			break;
		}
		else {    //if user enter a unacceptable input
			system("cls");
			printf("unacceptable, try again\n");
			continue;
		}
	}
}