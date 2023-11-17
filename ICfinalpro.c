#include<stdio.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int checking_strength(char a[])
{
    int count =0,star= 0;
    for(int i=0;i<10;i++)
    {
        if(isdigit(a[i]))
        {
            count ++;
        }
    }
    if (count ==10)
    {
        printf("50%% strength\n");
        return 0;
    }
    int b =0;
    for (int i =0;i<10;i++)
    {
        if (isdigit(a[i]) || islower(a[i]))
        {
            if(islower(a[i]))
            {
                star++;
            }
            b++;
        }
    }
    if(b ==10 && star>=1)
    {
        printf("65%% strength\n");
        return 0;
    }
    int c=0,d=0,e=0;
    for(int i=0;i<10;i++)
    {
        if(isdigit(a[i]) ||islower(a[i])||isalpha(a[i]))
        {
            c ++;
            if(islower(a[i]))
            {
                d++;
            }
            if(isalpha(a[i]))
            {
                e++;
            }
        }
    }
    if(c ==10&& d>=1&& e>=1)
    {
        printf("75%% strength\n");
        return 0;
    }
    int f=0,g=0,h=0,k=0;
    for (int i=0;i<10;i++)
    {
        if(isdigit(a[i]) ||islower(a[i])||isalpha(a[i])||a[i]=='?'||a[i]=='-'||a[i]=='+'||a[i]=='=')
        {
            f ++;
            if(islower(a[i]))
            {
                g++;
            }
            if(isalpha(a[i]))
            {
                h++;
            }
            if(a[i]=='?'||a[i]=='-'||a[i]=='+'||a[i]=='=')
            {
                k++;
            }
        }
    }
    if(f ==10 && g>=1&&h>=1&&k>=1)
    {
        printf("85%% strength\n");
        return 0;
    }
    int l=0,m=0,n=0,o=0,p=0;
    for(int i=0;i<10;i++)
    {
        if(isdigit(a[i]) ||islower(a[i])||isalpha(a[i])||a[i]=='?'||a[i]=='-'||a[i]=='+'||a[i]=='='||a[i]=='!'||a[i]=='@'||a[i]=='#'||a[i]=='$')
        {
            l ++;
            if(islower(a[i]))
            {
                m++;
            }
            if(isalpha(a[i]))
            {
                n++;
            }
            if(a[i]=='?'||a[i]=='-'||a[i]=='+'||a[i]=='='||a[i]=='!'||a[i]=='@'||a[i]=='#'||a[i]=='$')
            {
                o++;
            }
        }
    }
    if(l ==10 && m>=2&&n>=2&&o>=2)
    {
        printf("100%% strength\n");
        return 1;
    }
    else
    {
        printf("<50%% strength\n");
        return 2;
    }
    return 0;
}

void randomf(char a[])
{
    char lower[]="abcdefghijklmnopqrstuvwxyz";
    char upper[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char special[]="?+-!@#$";
    char number[]="0123456789";

    srand(time(NULL));

    
        a[0]=lower[rand()%26];
        a[1]=special[rand()%7];
        a[2]=upper[rand()%26];
        a[3]=number[rand()%10];
        a[4]=lower[rand()%26];
        a[5]=special[rand()%7];
        a[6]=upper[rand()%26];
        a[7]=number[rand()%10];
        a[8]=lower[rand()%26];
        a[9]=special[rand()%7];

    
    int i = rand()%10;
    int j=rand()%10;
    char temp = a[i] ;
    a[i]=a[j];
    a[j]=temp;


    printf("%s\n",a);
    
}


int main ()
{
    char a[10];
    scanf("%s",a);
    int b;
    b = checking_strength(a);
    if(b==0||b==2)
    {
        printf("New suggested password: ");
        randomf(a);
    }
    
    else
    {
        printf("Your password is strong.");
    }
    


    return 0;
}