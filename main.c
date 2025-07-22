#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

void account(void);
void accountCreated(void);
void login(void);
void loginsu(void);
void display(char[]);
void logout(void);
void transferMoney(void);
void checkBalance(char[]);

void gotoxy(int x, int y){
    COORD c;
    c.X = x;
    c.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

struct data{
    char username[50];
    int date,month,year;
    char phone[15];
    char adhaar[20];
    char first_name[20];
    char last_name[20];
    char father_name[20];
    char mother_name[20];
    char address[100];
    char account_type[50];
};

struct transaction{
    char to_person_username[50];
    char from_person_username[50];
    long int amount;
};

struct user_password{
    char pass[50];
};

int main(){
    int choice;

    gotoxy(20,3);
    printf("WELCOME TO BANK ACCOUNT SYSTEM \n\n");
    gotoxy(18,5);

    printf("******************************");
    gotoxy(20,10);
    printf("CREATE A BANK ACCOUNT ('1')  ");
    gotoxy(20,12);
    printf("ALREADY A USER? SIGN IN ('2') ");
    gotoxy(20,14);
    printf("EXIT ('3') \n\n");

    printf("/n/n Enter your choice : ");
    scanf("%d" ,&choice);

    switch(choice){
        case 1: 
                system("cls");
                printf("\n\n USERNAME (50 characters limit)! ");
                printf("\n\n PASSWORD (50 characters limit)! ");
                account();
                break;

        case 2: 
               login();
               break;
            
        case 3: 
                exit(0);
                break;

                getch();
               
    }
    return 0;
}

void account(){
    char password[20];
    int passwordlen, i, seek=0;
    char ch;
    FILE *fp, *fu;
    struct data u1;
    struct user_password u2;

    fp = fopen("username.text","ab");

    system("cls");
    printf("\n\n -------CREATE ACCOUNT-------");

    printf("\n\nFIRST NAME : ");
    scanf("%s" ,&u1.first_name);
    printf("\n\nLAST NAME : ");
    scanf("%s" ,&u1.last_name);

    printf("\n\nFATHER's NAME..");
	scanf("%s", &u1.father_name);

	printf("\n\nMOTHER's NAME..");
	scanf("%s", &u1.mother_name);

	printf("\n\nADDRESS..");
	scanf("%s", &u1.address);

	printf("\n\nACCOUNT TYPE");
	scanf("%s", &u1.account_type);

    printf("\n\nDATE OF BIRTH : ");
    printf("\nDATE : ");
    scanf("%d" ,u1.date);
    printf("\nMONTH : ");
    scanf("%d" ,u1.month);
    printf("\nYEAR : ");
    scanf("%d" ,u1.year);

    printf("\n\nADHAR NUMBER");
	scanf("%s", &u1.adhaar);

	printf("\n\nPHONE NUMBER");
	scanf("%s", &u1.phone);

	printf("\n\nUSERNAME.. ");
	scanf("%s", &u1.username);

    printf("\n\nPASSWORD : ");

    for(int i=0; i<50; i++){
        ch = getch();
        if(ch!=13){
            password[i] = ch;
            ch = '*';
            printf("%c" ,ch);
        }
        else{
            break;
        }
    }
    password[i] = '\0';
    strcpy(u2.pass, password); 

    fwrite(&u1,sizeof(u1),1,fp);
    fclose(fp);


    accountCreated();
}

void accountCreated(){
    int i;
    char ch;
    system("cls");
    printf("PLEASE WAIT.....\n\n YOUR DATA IS PROCESSING.....\n\n");
    for(int i=0; i<200000000; i++){
        i++;
        i--;
    }

    gotoxy(30,10);
    printf("ACCOUNT CREATED SUCCESFULLY...");
    gotoxy(0,20);

    printf("Press enter to login.");

    getch();
    login();

}

void login(){
    system("cls");

    char username[50];
    char password[50];

    int i,j,k;
    char ch;
    FILE *fp, *fu;
    struct data u1;
    struct user_password u2;

    fp = fopen("username.txt","rb");
    if(fp==NULL){
        printf("ERROR IN OPENING FILE...");
    }

    gotoxy(32,2);
    printf(" ACCOUNT LOGIN ");
    gotoxy(7,5);
    printf("****************************************************");

    gotoxy(35,10);
    printf("=== LOGIN ===");

    gotoxy(35,12);
    printf("USERNAME : ");
    scanf("%s",&username);

    gotoxy(35,14);
    printf("PASSWORD : ");

    for(int i=0; i<50; i++){
        ch = getch();
        if(ch!=13){
            password[i] = ch;
            ch = '*';
            printf("%c" ,ch);
        }
        else{
            break;
        }
    }

    while( fread(&u1,sizeof(u1),1,fp)){
        if(strcmp(u1.username,username)==0){
                loginsu();
                display(username);
        }
    }

    fclose(fp);
}

void loginsu()
{
	int i;
	system("cls");
	printf("Fetching account details.....\n");
	for (i = 0; i < 20000; i++) {
		i++;
		i--;
	}

	gotoxy(30, 10);
	printf("LOGIN SUCCESSFUL....");
	gotoxy(0, 20);
	printf("Press enter to continue");

	getch();
}

void display(char username[]){
    system("cls");
    FILE* fp;
    int i, choice;

    fp = fopen("username.txt","rb");
    struct data u1;

    if(fp==NULL){
        printf("ERROR IN FILE OPENING...");
    }

    while(fread(&u1,sizeof(u1),1,fp)){
        if(strcmp(u1.username,username)==0){
            gotoxy(30,1);
            printf("WELCOME, %s %s" ,u1.first_name,u1.last_name);
            gotoxy(28, 2);
			printf("..........................");
			gotoxy(55, 6);
			printf("==== YOUR ACCOUNT INFO ====");
			gotoxy(55, 8);
			printf("***************************");
			gotoxy(55, 10);
			printf("NAME..%s %s", u1.first_name,
				u1.last_name);

			gotoxy(55, 12);
			printf("FATHER's NAME..%s %s",
				u1.father_name,
				u1.last_name);

			gotoxy(55, 14);
			printf("MOTHER's NAME..%s",
				u1.mother_name);

			gotoxy(55, 16);
			printf("ADHAR CARD NUMBER..%s",
				u1.adhaar);

			gotoxy(55, 18);
			printf("MOBILE NUMBER..%s",
				u1.phone);

			gotoxy(55, 20);
			printf("DATE OF BIRTH.. %d-%d-%d",
				u1.date, u1.month, u1.year);

			gotoxy(55, 22);
			printf("ADDRESS..%s", u1.address);

			gotoxy(55, 24);
			printf("ACCOUNT TYPE..%s",
				u1.account_type);
        }
    }

    fclose(fp);

    gotoxy(0,6);
    printf(" HOME ");
	gotoxy(0, 7);
	printf("******");
	gotoxy(0, 9);
	printf(" 1....CHECK BALANCE");
	gotoxy(0, 11);
	printf(" 2....TRANSFER MONEY");
	gotoxy(0, 13);
	printf(" 3....LOG OUT\n\n");
	gotoxy(0, 15);
	printf(" 4....EXIT\n\n");

	printf(" ENTER YOUR CHOICES..");
	scanf("%d", &choice);

	switch (choice) {
	case 1:
		checkbalance(username);
		break;

	case 2:
		transfermoney();
		break;

	case 3:
		logout();
		login();
		break;

	case 4:
		exit(0);
		break;
	}
}

void logout(){
    int i,j;
    system("cls");
    printf("PLEASE WAIT, loggin out");
    for(int i=0; i<10; i++){
        for(int j=0; j<25000000; j++){
            j++;
            j--;
        }
        printf(".");
    }

    gotoxy(30,10);
    printf("Sign out successfully..\n");

    gotoxy(0,20);
    printf("Press any key to continue..\n");
    getch();
}

void transferMoney(){
    FILE *fm,*fp;
    struct data u1;
    struct transaction t1;

    char username_from[50];
    char username_to[50];
    int senderfound=0;
    int receiverfound=0;

    system("cls");

    gotoxy(33,4);
    printf("----Transfer Money----");
    gotoxy(33,5);
    printf("======================");

    gotoxy(33,11);
    printf("FROM (your username) : ");
    scanf("%s" ,username_from);

    gotoxy(33,13);
    printf("TO (username of person) : ");
    scanf("%s" ,username_to);

    fp = fopen("username.txt","rb");
    if(fp==NULL){
        printf("ERROR IN FILE OPENING...");
        getch();
        return;
    }

    while(fread(&u1,sizeof(u1),1,fp)){
        if(strcmp(username_from,u1.username)==0){
            senderfound=1;
        }
        if(strcmp(username_to,u1.username)==0){
            receiverfound=1;
            strcpy(t1.to_person_username,u1.username);
        }
    }

    fclose(fp);

    if(!senderfound){
        printf("Sender not found.");
        getch();
        return;
    }
    if(!receiverfound){
        printf("Receiver not found.");
        getch();
        return;
    }

    strcpy(t1.from_person_username,username_from);

    gotoxy(33,16);
    printf("Enter amount to be transferred: ");
    scanf("%ld" ,&t1.amount);

    fm = fopen("mon.txt","ab");
    if (fm == NULL) {
        printf("Error opening transaction file!\n");
        getch();
        return;
    }

    fwrite(&t1,sizeof(t1),1,fm);
    fclose(fm);

    gotoxy(0,26);
    printf("----------------------------------------------");
    gotoxy(0,27);
    printf("Transferring Amount, PLEASE WAIT...");

    gotoxy(10,29);
    for(int i=0; i<50; i++){
        ptinf("*");
        sleep(30);
    }

    gotoxy(33,33);
    printf("AMOUNT TRANSFERRED SUCCESSFULLY.");
    gotoxy(33,35);
    printf("Press any key to menu.");
    getch();

    display(username_from);
}

void checkBalance(char username[]){
    system("cls");
    FILE *fm;
    struct transaction t1;
    char ch;
    int i=1, sumamount=0;

    fm = fopen("mon.txt","rb");

    int k = 5, l = 10;
	int m = 30, n = 10;
	int u = 60, v = 10;

    gotoxy(30,2);
    printf("==== BALANCE DASHBOARD ====");
    gotoxy(30,3);
    printf("***************************");

    gotoxy(k,l);
    printf("S. No.");
    gotoxy(m,n);
    printf("TRANSACTION ID");
    gotoxy(u,v);
    printf("AMOUNT");

    while(fread(&t1,sizeof(t1),1,fm)){
        if(strcmp(username,t1.to_person_username)==0){
            gotoxy(k,++l);
            printf("%d" ,i);
            i++;
            gotoxy(m,++n);
            printf("%d" ,t1.from_person_username);
            gotoxy(u,++v);
            printf("%d" ,t1.amount);

            sumamount += t1.amount;

        }
    }

    gotoxy(80,10);
    printf("TOTAL AMOUNT");
    gotoxy(80,12);
    printf("%d" ,sumamount);

    getch();
    fclose(fm);
    diaplay(username);
}