#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define ENTER 13         //ASCII value for enter key
#define TAB 9              //ASCII value for tab key
#define BACKSPACE 8         //ASCII value for tab key
#define BUFFER 50           //Upper bound for characters

// function prototypes 

void takeinput(char []);
void generate_username(char [],char []);
void take_password(char []);

//A struct to store the information of every user
struct user
{
    char fullName[BUFFER];
    char email[BUFFER];
    char password[BUFFER];
    char username[BUFFER];
    char phone[BUFFER];
};

//A function to store inputs from the user 
void takeinput(char ch[BUFFER])
{
    fgets(ch, BUFFER, stdin);
    ch[strlen(ch) - 1] = '\0';
    printf("%s\n", ch);
}

//A function to generate username from the email
void generate_username(char email[BUFFER], char username[BUFFER])
{
    int i;

    for (i = 0; i < strlen(email); i++)
    {
        if (email[i] == '@')
        {
            break;
        }
        else
        {
            username[i] = email[i];
        }
    }
    username[i] = '\0';
    printf("Your username is %s", username);
}

//A function to take in password of the user and store it appropriately
void takepassword(char pwd[BUFFER])
{
    int i = 0;
    char ch;
    while (1)
    {
        ch = getch();
        if (ch == ENTER || ch == TAB)
        {
            pwd[i] = '\0';
            break;
        }

        else if (ch == BACKSPACE)
        {
            if (i > 0)
            {
                i--;
                printf("\b \b");
            }
        }
        else
        {
            pwd[i++] = ch;
            printf("*");
        }
    }
}
int main(void)
{
    system("cls");
    system("color 0b");
    struct user User;
    struct user usr;
    FILE *fp;
    char username[BUFFER], pword[BUFFER];
    char password2[BUFFER];
    int opt, usrFound;
    printf("\n\t\t\t------------Welcome to authentication system----------------");
    printf("\nPlease choose your operation");
    printf("\n1.Signup");
    printf("\n2.Login");
    printf("\n3.Exit");

    printf("\nYour choice:\t");
    scanf("%d", &opt);
    fgetc(stdin);

    switch (opt)
    {
    case 1:
        system("cls");
        printf("\nEnter your full name:\t");
        takeinput(User.fullName);
        printf("Enter your email:\t");
        takeinput(User.email);
        printf("Enter your contact no:\t");
        takeinput(User.phone);
        printf("Enter your password:\t");
        takepassword(User.password);
        printf("\n Confirm your password:\t");
        takepassword(password2);

        if (!strcmp(User.password, password2))
        {
            generate_username(User.email, User.username);
            printf("\nYour username is %s", User.username);
            printf("\nYour fullname is %s", User.fullName);
            fp = fopen("Users2.txt", "a+");
            fwrite(&User, sizeof(struct user), 1, fp);
            if (fp == NULL)
            {
                fprintf(stderr, "Error opening file for writing");
                exit(1);
            }
            else
                printf("\n\nUser registration successful, Your username is %s", User.username);
            fclose(fp);
        }
        else
        {
            printf("\nPassword do not match");
        }
        break;
    case 2:

        printf("\nEnter your username:\t");
        takeinput(username);
        printf("Enter your password:\t");
        takepassword(pword);
        fp = fopen("Users2.txt", "r");
        if (fp == NULL)
        {
            fprintf(stderr, "Error opening file for reading");
            exit(1);
        }

        while (fread(&usr, sizeof(struct user), 1, fp))
        {
            if (!strcmp(usr.username, username))
            {
                system("cls");
                if (!strcmp(usr.password, pword))
                {
                    system("cls");
                    printf("\n\t\t\t\t\t\t\t\t\tWelcome %s", usr.fullName);
                    printf("\n\n|Full Name:\t%s", usr.fullName);
                    printf("\n|Email:\t\t%s", usr.email);
                    printf("\n|Username:\t%s", usr.username);
                    printf("\n|Contact no.:\t%s", usr.phone);
                }
                else
                {
                    printf("\n\nInvalid Password!");
                    Beep(800, 300);
                }
                usrFound = 1;
            }
        }
        if (!usrFound)
        {
            printf("\n\nUser is not registered!");
            Beep(800, 300);
        }
        fclose(fp);
        break;
    case 3:
        printf("\t\t\t Bye Bye :)");
        break;
    }
    return 0;
}
