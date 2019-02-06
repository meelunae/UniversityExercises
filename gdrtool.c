
/* Basic GDR characters inserting/viewing tool with low-effort binary file manipulation. Personal exercise made with friends before exams */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct personaggio {
    char name[100];
    int gender;
    int CHAR_RACE;
    int CHAR_CLASS;
} character;

int print();
int insert();
void clean();

int main()
{
    char code;
    /*if((fp = fopen("characters.dat", "a+b")) == NULL)
    {
        fprintf(stderr, "Errore nell'apertura del file!");
        exit (EXIT_FAILURE);
    }  apro il file per controllare*/
    for(;;)
    {
        printf("Welcome to the management software of our little roleplaying game! \n \
        \t \t p. Print characters\n \t \t i. Insert characters\n \t \t c. Clean characters file (completely erase!)\n \t \t q. Quit \n \
        Insert the char equivalent of what you want to do:  \n");
        code = getchar();
        switch(code)
        {
            case 'q': return 0; break;
            case 'p': print(); printf("Found %d characters!", print()); break;
            case 'i': insert(); break;
            case 'c': clean(); break;
        }
    }
    return 0;  
}
int insert()
{
    FILE * fp;
    fp = fopen("characters.dat", "a");
    character **characterslist;
    int n, i;
    printf("How many characters are we gonna insert today? ");
    scanf("%d", &n);
    characterslist = malloc(n * sizeof(character));
    for(i=0; i<n; i++)
    {
        getchar();
        characterslist[i] = malloc(sizeof(character));
        printf("Insert the character's name: ");
        fgets(characterslist[i]->name, 100, stdin);
        printf("Insert the character's gender: \n 1. Male \n 2. Female \n 3. Undefined \n");
        scanf("%d", &characterslist[i]->gender);
        printf("Insert the character's race: \n 1. Orc \n 2. Halfling \n 3. Fairy \n 4. Elf \n");
        scanf("%d", &characterslist[i]->CHAR_RACE);
        printf("Insert the character's class: \n 1. Swordsman \n 2. Bard \n 3. Thief \n 4. Killer \n 5. Mage \n");
        scanf("%d", &characterslist[i]->CHAR_CLASS);
        printf("Name:\t%s\nSex:\t%d\nRace:\t%d\nClass:\t%d\n", characterslist[i]->name, characterslist[i]->gender, characterslist[i]->CHAR_RACE, characterslist[i]->CHAR_CLASS);
        fwrite(characterslist[i], sizeof(character), 1, fp);
    	getchar();
        }
    fclose(fp);
    return n;
}
void clean()
{
    FILE * fp;
    fp = fopen("characters.dat", "w");
    fputs("", fp);
    printf("File has been successfully cleaned and all characters are gone forever. :(\n");
    getchar();
    fclose(fp);
}
int print()
{
        FILE * fp;
	fp = fopen("characters.dat", "r");
	int i;
	int n=0;
        character Appoggio[100];
        for(i=0; i<100;i++)	
	{
		fread(&Appoggio[i], sizeof(character), 1, fp);
		if(feof(fp))
		{
			break;
		}
		else
		{
			printf("Name:\t%s\n", Appoggio[i].name);
        		printf("Gender:\t%d\n", Appoggio[i].gender);
        		printf("Race:\t%d\n", Appoggio[i].CHAR_RACE);
       		        printf("Class:\t%d\n", Appoggio[i].CHAR_CLASS);
		n++;
		}
	}
		fclose(fp);
		return n;
}
