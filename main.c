
/* Ryan Reddoch
   CS-1714-B1
   Exercise 6 */
   // test

// HEADERS //
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// CONSTANTS //
#define ERROR_TRAP_BUFFER 1024
#define MAX_YEAR 2022
#define MIN_YEAR 1475
#define AUTHOR_CHAR_LIMIT 32
#define CITY_CHAR_LIMIT 64
#define MAX_COUNTER 1



// String Check Function
int stringCheck (char str[ERROR_TRAP_BUFFER], size_t maxSize);
// Author Name Function
void getName (char str[ERROR_TRAP_BUFFER], int MAX_SIZE);
// Pub Year Function
void getYear (unsigned int *val);

// Pub city Function
void getCity (char str[ERROR_TRAP_BUFFER], int MAX_SIZE);

int
main ()
{
  char buffer[ERROR_TRAP_BUFFER];
  
  char pubCity[MAX_COUNTER][CITY_CHAR_LIMIT];
 
  char authorLname[MAX_COUNTER][AUTHOR_CHAR_LIMIT];
  
  unsigned int pubYear[MAX_COUNTER];

  // main boolean variable for do while loop //

  int idx = 0;
  int counter = 0;

  for (; idx <= MAX_COUNTER; idx++)
    {

      //////////////// AURHOR LAST NAME ////////////
      getName (buffer, AUTHOR_CHAR_LIMIT);
      strcpy (authorLname[idx], buffer);
      memset (buffer, '\0', ERROR_TRAP_BUFFER);

      ///////////// PUBLICATION YEAR  //////////////////////

      getYear (&pubYear[idx]);

      /////////// PUBLICATION CITY //////////////////////
      getCity (buffer, CITY_CHAR_LIMIT);
      strcpy (pubCity[idx], buffer);
      memset (buffer, '\0', ERROR_TRAP_BUFFER);

      counter++;
      if (idx == MAX_COUNTER)
	{

	  break;
	}
      printf ("Would you like to continue?\n Y/N\n");
      scanf ("%s", buffer);
      getchar ();
      char ans = toupper (buffer[0]);
      if (ans != 'Y')
	{
	  break;
	}
    }

  for (int idx = 0; idx < counter; idx++)
    {
    

      printf ("\nAuthor's Last Name: %s \nPublication Year: %u \nPublication City: %s\n", authorLname[idx], pubYear[idx], pubCity[idx]);
    }
  return 0;
}

// String Check
int stringCheck (char str[ERROR_TRAP_BUFFER], size_t maxSize)
{
  int strReturnSize = (int)(strlen (str) - maxSize);

  (strReturnSize <= 0) ? strReturnSize = 0
    : printf ("Input size is too big, you are %d over, please try again \n",
	      strReturnSize);

  return strReturnSize;
}

// Author Last Name
void getName (char str[ERROR_TRAP_BUFFER], int MAX_SIZE)
{
  do
    {

      printf ("What is the author's last name? \n");
      scanf (" %[^\n]s", str);

    }while (stringCheck (str, MAX_SIZE) > 0);

}

// Publication Year
void
getYear (unsigned int *val)
{
  bool isGood;
  do
    {
      isGood = false;
      printf ("What is the publication year?\n");
      scanf ("%u", val);
      getchar ();
      if ((*val < MIN_YEAR) || (*val > MAX_YEAR))
	{
	  printf ("Publication year must be between 1475 and 2022\n");
	  isGood = true;
	}

    }while (isGood);
}

// Pub City
void
getCity (char str[ERROR_TRAP_BUFFER], int MAX_SIZE)
{

  do
    {

      printf ("What is the publication city?\n");
      scanf ("%[^\n]s", str);

    }while (stringCheck (str, MAX_SIZE) > 0);

}
