#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define ENTER 13
#define TAB 9
#define BACKSPACE 8
struct user
{
    char fullName[50];
    char email[50];
    char password[50];
    char username[50];
    char phone[50];
};

void takeinput(char ch[50])
{
    fgets(ch, 50, stdin);
    ch[strlen(ch)-1] = '\0';
    printf("%s\n", ch);
    
}

void generate_username(char email[50], char username[50])
{
    int i;
    
    for ( i = 0; i < strlen(email); i++)
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
    printf("Your username is %s",username);
    

}

void takepassword(char pwd[50])
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
    char username[50], pword[50];
    char password2[50];
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
            printf("\nYour username is %s",User.username);
            printf("\nYour fullname is %s",User.fullName);
            fp = fopen("Users2.txt", "a+");
            fwrite(&User, sizeof(struct user), 1, fp);
            if (fwrite != 0)
                printf("\n\nUser registration successful, Your username is %s", User.username);
            else
                printf("\n\nSorry! something went wrong : ");
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
        fp = fopen("Users.dat", "r");
        while (fread(&usr, sizeof(struct user), 1, fp))
        {
            if (!strcmp(usr.username, username))
            {
                system("cls");
                if (!strcmp(usr.password, pword))
                {
                    printf("\n\t\t\t\t\t\t\t\t\tWelcome %s", usr.fullName);
                    printf("\n\n|Full Name:\t%s", usr.fullName);
                    printf("\n|Emain:\t\t%s", usr.email);
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
    case 3:
        printf("\t\t\t Bye Bye :)");
        break;
    }
    return 0;
}
