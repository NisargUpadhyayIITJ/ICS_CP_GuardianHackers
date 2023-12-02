/*Create a tool in C that crafts a password, the complexity of which is determined by user-defined
criteria. The produced password should be 10 characters in length, and its strength is gauged based
on specific guidelines. Should the generated password fail to meet the maximum robustness
standard, the program will refine and represent a password that embodies a full strength score.

50% strength: The password comprises only numbers.

65% strength: The password consists of numbers and lowercase alphabets.

75% strength: The password seamlessly blends numbers, lowercase, and uppercase alphabets.

85% strength: Introducing special characters into the mix, the password now has numbers, both
lowercase and uppercase alphabets, and select special characters (?,+,=,-).

100% strength: Achieving pinnacle strength, the password incorporates numbers, both cases of
alphabets, and an expansive range of special characters (?,+,=,-,!,@,#,$). Furthermore, each
character type should be represented at least twice.*/


#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


// This function checks if the generated strong password has not been generated previously by
// checkin all the previously generated passwords from a file.
int prev_check(char a[]);

// A function to check the strength of the password using a specific criteria
int checking_strength(char a[], int size);

// This function generates a random password that meets the criteria for 100% strength
void randomf(char a[],int n);



int checking_strength(char a[],int size)
{
    int digit = 0, small_alphabet = 0, big_alphabet = 0, special = 0;
    // Criteria for different strength levels
    // The function returns a strength level and prints a corresponding message

    // Check for 50% strength
    for (int i = 0; i < size; i++)
    {
        if (isdigit(a[i]))
        {
            digit++;
        }
        if(islower(a[i]) || isupper(a[i])|| a[i] == '?' || a[i] == '-' || a[i] == '+' || a[i] == '=' || a[i] == '@' || a[i] == '!' || a[i] == '#' || a[i] == '$' || a[i] == '^' || a[i] == '&' || a[i] == '*')
        {
            special++;
        }
    }
    if (digit >= 10 && special ==0)
    {
        printf("50%% strength\n");
        return 0;
    }
    digit = 0;
    special = 0;
    // Check for 65% strength
    int b = 0;
    for (int i = 0; i < size; i++)
    {
        if (isdigit(a[i]) || islower(a[i]) || isupper(a[i]) || a[i] == '?' || a[i] == '-' || a[i] == '+' || a[i] == '=' || a[i] == '@' || a[i] == '!' || a[i] == '#' || a[i] == '$' || a[i] == '^' || a[i] == '&' || a[i] == '*')
        {
            if (islower(a[i]))
            {
                small_alphabet++;
            }
            if (isdigit(a[i]))
            {
                digit++;
            }
            if(isupper(a[i]) || a[i] == '?' || a[i] == '-' || a[i] == '+' || a[i] == '=' || a[i] == '@' || a[i] == '!' || a[i] == '#' || a[i] == '$' || a[i] == '^' || a[i] == '&' || a[i] == '*')
            {
                special++; 
            }
            b++;
        }
    }
    if (b >= 10 && small_alphabet >= 1 && digit >=1 && special == 0)
    {
        printf("65%% strength\n");
        return 0;
    }
    small_alphabet = 0;
    digit = 0;
    special = 0;
    // Check for 75% strength
    int c = 0;
    for (int i = 0; i < size; i++)
    {
        if (isdigit(a[i]) || islower(a[i]) || isupper(a[i]) || a[i] == '?' || a[i] == '-' || a[i] == '+' || a[i] == '=' || a[i] == '@' || a[i] == '!' || a[i] == '#' || a[i] == '$' || a[i] == '^' || a[i] == '&' || a[i] == '*')
        {
            c++;
            if (islower(a[i]))
            {
                small_alphabet++;
            }
            if (isupper(a[i]))
            {
                big_alphabet++;
            }
            if (isdigit(a[i]))
            {
                digit++;
            }
            if(a[i] == '?' || a[i] == '-' || a[i] == '+' || a[i] == '=' || a[i] == '@' || a[i] == '!' || a[i] == '#' || a[i] == '$' || a[i] == '^' || a[i] == '&' || a[i] == '*')
            {
                special++;
            }
        }
    }

    if (c >= 10 && small_alphabet >= 1 && big_alphabet >= 1 && digit >=1 && special == 0)
    {
        printf("75%% strength\n");
        return 0;
    }
    small_alphabet = 0;
    digit = 0;
    special = 0;
    big_alphabet = 0;
    // Check for 85% strength
    int f = 0;
    for (int i = 0; i < size; i++)
    {
        if (isdigit(a[i]) || islower(a[i]) || isupper(a[i]) || a[i] == '?' || a[i] == '-' || a[i] == '+' || a[i] == '=' || a[i] == '@' || a[i] == '!' || a[i] == '#' || a[i] == '$' || a[i] == '^' || a[i] == '&' || a[i] == '*')
        {
            f++;
            if (islower(a[i]))
            {
                small_alphabet++;
            }
            if (isupper(a[i]))
            {
                big_alphabet++;
            }
            if (a[i] == '?' || a[i] == '-' || a[i] == '+' || a[i] == '=' || a[i] == '@' || a[i] == '!' || a[i] == '#' || a[i] == '$' || a[i] == '^' || a[i] == '&' || a[i] == '*')
            {
                special++;
            }
            if (isdigit(a[i]))
            {
                digit++;
            }
        }
    }

    if (f >= 10 && (small_alphabet < 2 || big_alphabet < 2 || digit < 2 ||special < 2) && (big_alphabet > 0 && small_alphabet > 0 && special > 0 && digit > 0))
    {
        printf("85%% strength\n");
        return 0;
    }
    small_alphabet = 0;
    digit = 0;
    special = 0;
    big_alphabet = 0;

    // Check for 100% strength
    int l = 0;
    for (int i = 0; i < size; i++)
    {
        if (isdigit(a[i]) || islower(a[i]) || isupper(a[i]) || a[i] == '?' || a[i] == '-' || a[i] == '+' || a[i] == '=' || a[i] == '!' || a[i] == '@' || a[i] == '#' || a[i] == '$' || a[i] == '^' || a[i] == '&' || a[i] == '*')
        {
            l++;
            if (islower(a[i]))
            {
                small_alphabet++;
            }
            if (isupper(a[i]))
            {
                big_alphabet++;
            }
            if (a[i] == '?' || a[i] == '-' || a[i] == '+' || a[i] == '=' || a[i] == '!' || a[i] == '@' || a[i] == '#' || a[i] == '$' || a[i] == '^' || a[i] == '&' || a[i] == '*')
            {
                special++;
            }
            if (isdigit(a[i]))
            {
                digit++;
            }
        }
    }

    if (l >= 10 && small_alphabet >= 2 && big_alphabet >= 2 && special >= 2 && digit >= 2)
    {
        int q = prev_check(a);
        if (q != 3)
        {
            printf("100%% strength\n");
            return 1;
        }
        else
        {
            return 0;
        }
    }

    // Check for less than 50% strength
    else
    {
        printf("<50%% strength\n");
        return 2;
    }
}


void randomf(char a[],int n)
{
    char lower[] = "abcdefghijklmnopqrstuvwxyz";
    char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char special[] = "?+-!@#$^&*";
    char number[] = "0123456789";

    srand(time(NULL));

    a[0] = lower[rand() % 26];
    a[1] = special[rand() % 10];
    a[2] = upper[rand() % 26];
    a[3] = number[rand() % 10];
    a[4] = lower[rand() % 26];
    a[5] = special[rand() % 10];
    a[6] = upper[rand() % 26];
    a[7] = number[rand() % 10];
    a[8] = lower[rand() % 26];
    a[9] = special[rand() % 10];
    for(int k=10;k<n;k++)
    {
        a[k]='\0';
    }

    // this swaps any two characters randomly in the string so that the password is completely random
    for(int k=0;k<4;k++)
    {
        int i = rand() % 10;
        int j = rand() % 10;
        char temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    
}


int prev_check(char a[])
{
    FILE *fp;
    fp = fopen("prev_pass.txt", "a+");
    if (fp == NULL)
    {
        printf("Unable to open the file\n");
        return 4;
    }
    else
    {
        int found = 0;
        char temp_str[100];
        while (!feof(fp))
        {
            // Check f the generated password has been generated previously
            fscanf(fp, "%s", temp_str);
            if (strcmp(a, temp_str) == 0)
            {
                printf("The password entered/generated has been already generated previously\n");
                found = 1;
                return 3;
            }
        }

        // If the password is unique, append it to the file
        if (!found)
        {
            fprintf(fp, "%s\n", a);
            return 15;
        }
  
        // Close the file
        fclose(fp);
    }
    return 34;
}

int main()
{
    char a[100];
    int play = 1;
    int b;
    while (play == 1)
    {
        printf("Enter Password: ");
        scanf("%s", a);
        int size = strlen(a);
        while(size < 10)
        {
            printf("Password should contains atleast 10 characters\n");
            printf("Re-enter password: ");
            scanf("%s",a);
            size = strlen(a);
        }
        b = checking_strength(a,size);
        if (b == 0 || b == 2)
        {
            randomf(a,size);
            int y = prev_check(a);
            if (y == 15)
            {
                printf("New suggested password: ");
                printf("%s\n", a);
            }
            else
            {
                randomf(a,size);
                printf("New suggested password: ");
                printf("%s\n", a);
            }
        }
        else
        {
            printf("Your password is strong.\n");
        }

        // Loop to generate more than one password

        printf("Enter 1 if you want to re-enter password\nEnter 2 if you want to re-generate the password\nElse any other number to exit: ");

        scanf("%d", &play);

        while (play == 2)
        {
            randomf(a,size);
            int u = prev_check(a);
            if (u == 15)
            {
                printf("New suggested password: ");
                printf("%s\n", a);
            }
            else
            {
                randomf(a,size);

                printf("New suggested password: ");

                printf("%s\n", a);
            }
            printf("Enter 1 if you want to re-enter password\n");
            printf("Enter 2 if you want to re-generate the password\n");
            printf("Else any other number to exit: ");
            scanf("%d", &play);
        }
    }
    printf("New password saved successfully and stored.");

    return 0;
}