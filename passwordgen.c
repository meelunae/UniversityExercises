/* C language pseudo-random password generator (the randomness is not cryptographically secure enough to make it worth using).
Project created first class to get used to the language */

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
char chars [] = { 'a', 'b', 'c', 'd','e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O','P', 'Q','R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '^', '@', '_', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '^', '@', '_', '^', '@', '_', '^', '@', '_'}; // array that contains all the characters
int i;
FILE * fp;
int charnum;
char name [32];
printf("Where are you gonna use the password? \n");
scanf("%s", name);
printf("Insert number of chars.	 \n");
scanf("%d", &charnum);
printf("Password: ");
char password[charnum+1];
srand(time(NULL)); 
for(i = 0; i < charnum; i++)
{
int randomindex = rand() % 85;
char randomvalue;
randomvalue = chars[randomindex];
password[i] = randomvalue;
}
fp = fopen ("passwords.txt", "a");
printf ("%s - %s \n", password, name);
fprintf(fp, "%s - %s \n", password, name);
return 0;
}
