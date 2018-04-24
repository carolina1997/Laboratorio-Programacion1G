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
void mostrarEmpleado(eEmpleado[], int tam, int legajo);
int menu();
int borrarEmpleado(eEmpleado[], int tam, int legajo);

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
              printf("\nAlta:\n");
              cargarEmpleado(gente,TAM);
              system("pause");
              break;
          case 2:
              printf("\nBaja:\n");
              system("pause");
              break;
          case 3:
            printf("\nModificar:\n");
              system("pause");
              break;
          case 4:
              printf("\nListar:\n");
              system("pause");
              break;
          case 5:
              printf("\nOrdenar:\n");
              system("pause");
              break;
          case 6: salir=01;
            break;
            default:
            {
                printf("Opcion incorrecta:\n");
                system("pause");
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
    printf("6-Salir:\n");

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
  int i;void mostrarEmpleado(eEmpleado empleado[], int tam)

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
     mostrarEmpleado(empleado, tam, legajo);

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


void mostrarEmpleado(eEmpleado empleado[], int tam, int legajo)
{
    int i;

    for(i=0; i<tam; i++)
    {
        printf("%d\n%s\n%c\n%.2f\n%d/%d/%d\n", empleado[i].legajo, empleado[i].nombre, empleado[i].sexo, empleado[i].sueldo, empleado[i].fechaIngreso.dia, empleado[i].fechaIngreso.mes, empleado[i].fechaIngreso.anio);
    }
}

int borrarEmpleado(eEmpleado empleado[], int tam, int legajo)
{
  eEmpleado nuevoEmpleado;
  int esta;
  int confirmar = 's';

  esta = buscarLibre(empleado, tam);

  if(esta == -1)
  {
      printf("no se encuentra legajo!!");
  }
  else
    {
      mostrarEmpleado(empleado[esta]);
       if(confirmar == 's')
       {
           empleado[esta].isEmty= 1;
           printf("Se ha cancelado!!!")
       }
       else
       {
           printf("se ha dado de baja con exito!!");
       }


    }



}
