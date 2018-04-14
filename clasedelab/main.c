#include <stdio.h>
#include <stdlib.h>


void mostrarNombre(char[] [20], int);
int main()
{

   char nombres[5][20];
   int i;

   for(i=0;i<5;i++)
   {
       printf("ingrese nombre:");
       gets(nombres[i]);
   }

   mostrarNombre(nombres, 5);







    return 0;
}
void mostrarNombre(char x[] [20], int cantidad)
{
    int i;
   for(i=0; i<cantidad; i++)
      {
       printf("%s", x[i]);
      }
}
