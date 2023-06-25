//
//  main.c
//  kopirka_cisel
//
//Načtěte na standardním vstupu předem neznámý počet celých čísel (longint resp. long), každé číslo je na jiném řádku. Celý vstup vypište na standardní výstup dvakrát po sobě.

//  Created by Natálie Smolíková on 04.11.2021.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct spojovy{
    long int hod;
    struct spojovy* next;
} spojak;

spojak* init()
{
    return NULL;
}

spojak* insert_end(long int co, spojak* hlava)
{
    spojak* pom;
    if (hlava == NULL)
    {   hlava = malloc(sizeof(spojak));
        hlava -> hod = co;
        hlava -> next = NULL;
            return hlava;
    }
    
    pom = malloc(sizeof(spojak));
    hlava -> next = pom;
    pom -> hod = co;
    pom -> next = NULL;
    return pom;
    
}

int main() {
    spojak *posl = init(), *start = init(), *posl2 = init();
    long int cislo =0, num;
    int x = 1,vstup, znamenko = 1;
    int a =0;
    
  while(x)
  {
      while (((((vstup =getchar()) >= 48) && (vstup <=57) )|| vstup == 45 )&& vstup != EOF)
      {
         
          if (vstup == 45) znamenko = -1;
          if (vstup >=48 && vstup <=57)
             cislo = 10 * cislo + vstup - 48;
      }
      
      if (vstup == EOF) x = 0;
      if (x != 0)
      {
          if (a ==0)
              
          { num = cislo*znamenko;
          posl = insert_end(num, posl);
          start = posl;
          posl2 =posl;
          cislo = 0, num=0, znamenko =1;
              
          }
          else {
              num = cislo*znamenko;
              posl = insert_end(num, posl);
              cislo = 0, num=0, znamenko =1;
          }
          a++;
      }
      
      
  }
       
   
   
   // spojak *posl2 = posl;
    
       while(start != NULL)
        {    printf("%ld\n", start -> hod);
            start = start -> next;
        }
    while(posl2 != NULL)
     {    printf("%ld\n", posl2 -> hod);
         posl2 = posl2 -> next;
     }
    
    return 0;
}
