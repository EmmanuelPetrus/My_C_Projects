#include <stdio.h>

#include <conio.h>
#include <windows.h>

typedef struct Details details;
struct Details
{
    char *fname;
    char *email;
    char *username;
    char *phone_num;
};

char *take_input(details *user, char n, int *length)
{
    char *info = (n != 'n') ? "email" : "name";
    printf("\nWhat is the length of your %s ? ", info);
    scanf("%d", length);
    fgetc(stdin);
    (*length) += 3;
    if (!strcmp(info, "name"))
    {
        user->fname = (char *)calloc(*length, sizeof(char));
        printf("\nWhat is your fullname: ");
        fgets(user->fname, *length, stdin);
        *length = 0;
        return user->fname;
    }
    else
    {
        user->email = (char *)calloc(*length, sizeof(char));
        printf("\nWhat is your gmail ? ");
        fgets(user->email, *length, stdin);
        // *length = 0;
        return user->email;
    }
}

char *generate_username(details *user, int *len)
{
    int i;
    char *email_pointer = user->email;
    user->username = (char *)calloc(*len, sizeof(char));
    for (i = 0; i < strlen(user->email); i++)
    {
        if (*(email_pointer + i) == '@')
        {
            break;
        }
        else
        {
            *(user->username + i) = *(email_pointer + i);
        }
    }
    user->username[i] = '\0';
    *len = 0;
    printf("Your username is %s\n", user->username);
    return user->username;
}
int main(void)
{
    details person;
    int length = 0;
    details *person_store = &person;
    int *len_store = &length;
    char a = 'n', b = 'm';
    char *name = take_input(person_store, a, len_store);
    char *email = take_input(person_store, b, len_store);
    char *user_name = generate_username(person_store, len_store);
    printf("%d", length);
    // printf("%s", person.email);
    free(name);
    free(email);

    return 0;
}
