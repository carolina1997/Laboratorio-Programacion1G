#include <stdio.h>
#include <stdlib.h>


#define TAM 5


typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct
{
    int legajo;
    char nombre[50];
    char sexo;
    float sueldo;
    eFecha fechaIngreso;
    int isEmty;

}eEmpleado;

int buscarLibre(eEmpleado[], int tam);
void inicializarEmpleado(eEmpleado[], int tam);
int buscarEmpleado (eEmpleado[], int tam, int legajo);
void cargarEmpleado(eEmpleado[], int tam);
void mostrarEmpleado(eEmpleado[], int tam);
int menu();
void borrarEmpleado(eEmpleado[], int tam);
void empleadoConMayorSueldo (eEmpleado[], int tam);

int main()
{

    eEmpleado gente[TAM];

    inicializarEmpleado(gente, 5);


  int salir=0;
  do
  {
      switch(menu())
      {
          case 1:
              printf("\nAlta de los empleados\n");
              cargarEmpleado(gente,TAM);
              system("pause");
              system("cls");
              break;
          case 2:
              printf("\nBaja de empleados\n");
             borrarEmpleado(gente, TAM);
             mostrarEmpleado(gente,5);
             system("pause");
             system("cls");
              break;
          case 3:
            printf("\nModificar empleado\n");
              system("pause");
              system("cls");
              break;
          case 4:
              printf("\nLista de empleados\n");
              mostrarEmpleado(gente,5);
              system("pause");
              system("cls");
              break;
          case 5:
              printf("\nOrdenar:\n");
              system("pause");
              system("cls");
              break;
          case 6:
              printf("\nEmpleados con mayor sueldo\n");

              system("pause");
              system("cls");
            break;
          case 7:
              printf("\nTotal de sueldos\n");
              empleadoConMayorSueldo(gente, TAM);
              system("pause");
              system("cls");
            break;

          case 8:
               salir=0;
                      break;
            default:
            {
                printf("Opcion incorrecta:\n");
                system("pause");
                system("cls");
            }

      }
  }while(salir !=1);


return 0;
}

int menu()
{
    int retorno;
    printf("1-Alta:\n");
    printf("2-Baja:\n");
    printf("3-Modificaciones:\n");
    printf("4-listar:\n");
    printf("5-ordenar:\n");
    printf("5-Empleados con mayor sueldo:\n");
    printf("5-total de sueldos:\n");
    printf("8-Salir:\n");

    scanf("%d", &retorno);
    system("cls");
    return retorno;
}

void inicializarEmpleado(eEmpleado empleados[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        empleados[i].isEmty = 1;

    }
}


int buscarLibre(eEmpleado empleado[], int tam)
{
  int buscar =-1;
  int i;


  for(i=0; i <tam; i++)
  {
      if(empleado[i].isEmty == 1)
      {
          buscar =  1;
      }



  }
   return buscar;
}

int buscarEmpleado (eEmpleado empleado[], int tam, int legajo)
{
    int indice = -1;
    int i;
    for(i=0; i<tam; i++)
    {
       if(empleado[i].isEmty == 0 && empleado[i].legajo == legajo)
       {
           indice = i;
           break;
       }

    }
    return indice;
}


void cargarEmpleado(eEmpleado empleado[], int tam)
{
  eEmpleado nuevoEmpleado;
  int indice;
  int esta;
  int legajo;

  indice = buscarLibre(empleado, tam);

  if(indice == -1)
  {
      printf("No hay lugar!!!");
  }
  else
  {
      printf("ingrese Legajo:");
      scanf("%d", &legajo);
  }
 esta= buscarEmpleado(empleado, tam, legajo);

 if(esta != -1)
 {
     printf("El empleado se encuentra cargado!!", legajo);
     mostrarEmpleado(empleado, tam);

 }
 else
    {
       nuevoEmpleado.isEmty = 0;
       nuevoEmpleado.isEmty = legajo;

       printf("ingrese Nombre:\n");
       fflush(stdin);
       gets(nuevoEmpleado.nombre);

       printf("ingrese Sexo:\n");
       fflush(stdin);
       scanf("%c", &nuevoEmpleado.sexo);

       printf("ingrese sueldo:\n");
       scanf("%.2f", &nuevoEmpleado.sueldo);

       printf("ingrese fecha de egreso: d m a:\n");
       scanf("%d%d%d",&nuevoEmpleado.fechaIngreso.dia, &nuevoEmpleado.fechaIngreso.mes, &nuevoEmpleado.fechaIngreso.anio);

       empleado[indice] = nuevoEmpleado;

       printf("Alta exitosa!!!");

    }


}


void mostrarEmpleado(eEmpleado empleado[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        printf("%d\n%s\n%c\n%.2f\n%d/%d/%d\n", empleado[i].legajo, empleado[i].nombre, empleado[i].sexo, empleado[i].sueldo, empleado[i].fechaIngreso.dia, empleado[i].fechaIngreso.mes, empleado[i].fechaIngreso.anio);
    }
}

void borrarEmpleado(eEmpleado empleado[], int tam)


{
    int i;
    char opcion;
    int legajo;

    mostrarEmpleado(empleado, 5);

    printf("Ingrese legajo del empleado que desea dar de baja:\n");
    scanf("%d",&legajo);

    for(i=0;i<tam;i++)
    {
        if(legajo == empleado[i].legajo)
        {
            printf("Dar de baja este empleado...? S/N");

            if(opcion == 's'|| opcion == 'S')
            {
                empleado[i].isEmty = 0;
                printf("Se ha dado de baja %s con exito!",empleado[i].nombre);
                break;
            }
                else if(empleado[i].legajo != legajo);
                {
                printf("No se encontro el empleado con ese legajo\n");
                }
        }

    }


}
void empleadoConMayorSueldo (eEmpleado empleado[], int tam)
{
   int i,j;

   int maximos[tam];
   int contadores[tam]=0;
   int sueldo[tam];

    for(i=0;i<tam;i++)
    {
        sueldo[i]= empleado[i].sueldo;
    }

        for(i=0;i<tamI;i++)
        {
            for(j=0;j<tamC;j++)
            {
                if(sueldo[i] == empleado[j].sueldo)
                {
                    contadores[i]++;
                }
            }
        }

        for(i=0;i<tam;i++)
        {
            if(contadores[i] <= (contadores[i+1]))
            {
                maximos[i] = contadores[i+1];
            }
        }
      printf("los empleados con mayor sueldo son:\n");

      for(i=0;i<tam;i++)
      {
          printf("%s------ %d\n",empleado[i].nombre, maximos[i]);
      }

}

/*void sumatoriaDeDuracionDeCancion(eCancion cancion[], eInterprete interprete[], int tamC, int tamI)
{
    float sumador=0;
    int j,i;
    char auxNombre[50];

 printf("ingrese nombre");
 fflush(stdin);
 gets(auxNombre);

 for(i=0;i<tamI;i++)
 {
        for(j=0;j<tamC;j++)
         {

            if(strcmp(interprete[i].nombre, auxNombre)== 0 && cancion[j].estadoC == 1)
            {
                if(interprete[i].idInterprete == cancion[j].interprete)
                {
                    sumador+= cancion[j].duracion;

                    printf("interprete: %s duracion : %.2f",interprete[i].nombre,sumador);
                    break;
                }
            }

         }

    break;
 }

}
