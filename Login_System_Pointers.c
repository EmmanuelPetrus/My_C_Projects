#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "login_functions.c"

int main(void)
{
    details person;
    int length = 0;
    details *person_store = &person;
    int *len_store = &length;
    FILE *fp;
    char *password2;
    int opt, usrFound;
    char a = 'n', b = 'm', c = '2';
    system("cls");
    system("color 0b");
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
        char *name = take_input(person_store, a, len_store);
        char *phone_no = take_input(person_store, c, len_store);
        char *email = take_input(person_store, b, len_store);
        char *password = takepassword(person_store, len_store);
        char *user_name = generate_username(person_store, len_store);
        free_memory(name, email, user_name,phone_no,password);
        break;
        // printf("Enter your password:\t");
        // User.password = space_allocator();
        // takepassword(User.password);
        // printf("\n Confirm your password:\t");
        // takepassword(password2);

        // if (!strcmp(User.password, password2))
        // {
        //     generate_username(User.email, User.username);
        //     printf("\nYour username is %s", User.username);
        //     printf("\nYour fullname is %s", User.fullName);
        //     fp = fopen("Users2.txt", "a+");
        //     fwrite(&User, sizeof(struct user), 1, fp);
        //     if (fp == NULL)
        //     {
        //         fprintf(stderr, "Error opening file for writing");
        //         exit(1);
        //     }
        //     else
        //         printf("\n\nUser registration successful, Your username is %s", User.username);
        //     fclose(fp);
        // }
        // else
        // {
        //     printf("\nPassword do not match");
        // }
        // case 2:

        //     printf("\nEnter your username:\t");
        //     takeinput(username);
        //     printf("Enter your password:\t");
        //     takepassword(pword);
        //     fp = fopen("Users2.txt", "r");
        //     if (fp == NULL)
        //     {
        //         fprintf(stderr, "Error opening file for reading");
        //         exit(1);
        //     }

        //     while (fread(&usr, sizeof(struct user), 1, fp))
        //     {
        //         if (!strcmp(usr.username, username))
        // {
        //     system("cls");
        //     if (!strcmp(usr.password, pword))
        //     {
        //         system("cls");
        //         printf("\n\t\t\t\t\t\t\t\t\tWelcome %s", usr.fullName);
        //         printf("\n\n|Full Name:\t%s", usr.fullName);
        //         printf("\n|Email:\t\t%s", usr.email);
        //         printf("\n|Username:\t%s", usr.username);
        //         printf("\n|Contact no.:\t%s", usr.phone);
        //     }
        //     else
        //     {
        //         printf("\n\nInvalid Password!");
        //         Beep(800, 300);
        //     }
        //     usrFound = 1;
        // }
        //     }
        //     if (!usrFound)
        //     {
        //         printf("\n\nUser is not registered!");
        //         Beep(800, 300);
        //     }
        //     fclose(fp);
        //     break;
        // case 3:
        //     printf("\t\t\t Bye Bye :)");
        //     break;
    }
    // free_memory(name, email, user_name,password);
    return 0;
}
