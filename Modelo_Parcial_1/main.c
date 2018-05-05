#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int codUsuario;
    char nombre[50];
    int isEmpty;
    char contrasenia;

} eUsuario;

typedef struct
{
    int codProducto;
    char nombreP[100];
    int idUsuario;
    int canVenta = 0;
    float precio;
    int stock;
    int estados;
    char calificacion[200];

} eProducto;
int menuDeInicio();
int menu();
void mostrarUsuario(eUsuario[], int);
void mostrarProductos(eProducto[], int);
void cargarUsuario(eUsuario[], int);
void borrarUsuario(eUsuario[], int);
int buscarLibre(eUsuario[], int);
int buscarUsuario (eUsuario[], int, int);
void inicializarUsuarios(eUsuario usuarios[], int tamU);
int iniciarSesion(eUsuario[], int);
int comprarProducto(eProducto[], int);


int main()
{


    eUsuario usuarios[] = {{1, "Ana", 1}, {2, "Camila", 1},{3, "Florencia", 1},{4,"Ruth", 1},{5,"Micaela", 1}};
    eProducto productos[] = {{100, "celular", 2, 5, 3000.75,10},{101, "camara", 1, 3, 12900.68, 20},{102, "Television", 3, 9, 16000, 14},{103, "PC",1, 18, 14000.65, 33},{104,"DVD",5, 47, 8345.80, 8},{105,"Licuadora", 4, 123, 3890.45, 23},{106, "Equipo de musica", 1, 45, 13600, 11},{107, "guitarra", 4, 12, 13520.75, 54},{108, "Piano", 4, 6, 20000.88, 50},{109, "Microfono", 2, 70, 12000.65, 21}};
    char respuesta = 's';


    do
    {
        switch(menuDeInicio())
        {
        case 1:
              cargarUsuario(usuarios, tamU);
            break;
        case 2:
            int aux = iniciarSesion(usuarios, tamU);
            if(aux == 1)
            {
                int retorno = menu();
                do
                {
                    switch(menu())
                    {
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                    case 5:
                    case 6:
                    case 7:
                    case 8:
                    case 9:
                    case 10:
                    case 11:
                        break;
                    }
                }
                while (respuesta = 's')
                }

          return 0;
        }

        void inicializarUsuarios(eUsuario usuarios[], int tamU)
        {

            for(int i=0; i< tam; i++)
            {
                usuarios[i].isEmpty = 1;
            }
        }

        void inicializarProductos(eProducto productos[], int tamP)
        {

            for(int i=0; i< tamP; i++)
            {
                productos[i].estados = 1;
            }
        }
        int menu()
        {
            int opcion;
            //printf("1-Alta al usuario: ");
            printf("2-Modificar datos del usuario:");
            printf("3- Dar de baja al usuario:");
            printf("4-Pubricar producto:");
            printf("5-Modificar producto:");
            printf("6-Cancelar publicacion:");
            printf("7-Comprar producto:");
            printf("8-Listar publicaciones por usuario");
            printf("9-Listar publicaciones:");
            printf("10-Listar usuarios:");
            printf("11- Salir:");
            scanf("%d", &opcion);

            return opcion;
        }
        int menuDeInicio()
        {
            int retorno;
            printf("1-Registrarte:");
            printf("2-Iniciar sesion:");
            scanf("%d", &retorno);
            return retorno;
        }

        void mostrarUsuario(eUsuario usuarios[], int tamU)
        {
            int i;

            printf("---LISTA DE USUARIOS----\n");
            for(i=0; i<tamU; i++)
            {
                if(usuarios[i].isEmpty == 1)
                    printf("%d\t\t %s\t", usuarios[i].codUsuario, usuarios[i].nombre);
            }
        }


        void mostrarProductos(eProducto productos[], int tamP)
        {
            int i;

            printf("---LISTA DE PRODUCTOS----\n");
            for(i=0; i<tamP; i++)
            {
                if(productos[i].estados == 1)
                {
                    printf("%d\t\t %s\t\t %d\t %d\t %.2f\t\t %d\n", productos[i].codProducto, productos[i].nombreP, productos[i].idUsuario, productos[i].canVenta, productos[i].precio, productos[i].stock);
                }
            }
        }


        int buscarLibre(eUsuario usuarios[], int tamU)
        {
            int buscar =-1;
            int i;


            for(i=0; i <tamU; i++)
            {
                if(usuarios[i].isEmpty == 1)
                {
                    buscar =  1;
                }



            }
            return buscar;
        }

   void cargarUsuario(eUsuario usuarios[], int tamU)
        {
            eUsuario nuevoUsuario;
            int indice;
            int esta;
            int codigo;

            indice = buscarLibre(usuarios, tamU);

            if(indice == -1)
            {
                printf("No hay lugar!!!");
            }
            else
            {
                printf("ingrese Codigo para usuario:");
                scanf("%d", &codigo);
            }
            esta = buscarUsuario(usuarios, tamU, codigo);

            if(esta != -1)
            {
                printf("El Usuario se encuentra cargado!!", codigo);
                mostrarUsuario(usuarios, tamU);

            }
            else
            {
                nuevoUsuario.isEmpty = 0;
                nuevoUsuario.isEmpty = codigo;


                printf("Ingrese codigo de Usuario");
                scanf("%d", &nuevoUsuario.codUsuario);

                printf("ingrese Nombre:\n");
                fflush(stdin);
                gets(nuevoUsuario.nombre);


                printf("Ingrese contraseña:");
                fflush(stdin);
                gets(usuarios.contrasenia);


                usuarios[indice] = nuevoUsuario;

                printf("Alta exitosa!!!");

            }


        }

        int buscarUsuario (eUsuario usuario[], int tamU, int codigo)
        {
            int indice = -1;
            int i;
            for(i=0; i<tamU; i++)
            {
                if(usuario[i].isEmpty == 0 && usuario[i].codUsuario == codigo)
                {
                    indice = i;
                    break;
                }

            }
            return indice;
        }


        void borrarUsuario(eUsuario usuarios[], int tamU)
        {
            int i;
            char opcion;
            int codigo;

            mostrarUsuario(usuarios, 5);

            printf("Ingrese codigo del usuario que desea dar de baja:\n");
            scanf("%d",&codigo);

            for(i=0; i<tamU; i++)
            {
                if(codigo == usuarios[i].codUsuario)
                {
                    printf("Dar de baja este usuario...? S/N");

                    if(opcion == 's'|| opcion == 'S')
                    {
                        usuarios[i].isEmpty = 0;
                        printf("Se ha dado de baja %s con exito!",usuarios[i].nombre);
                        break;
                    }
                    else if(usuarios[i].codUsuario != codigo);
                    {
                        printf("No se encontro el usuario con ese codigo\n");
                    }
                }

            }


        }


        int iniciarSesion(eUsuario usuarios[], int tamU)
        {
            char auxNombre[100];
            char auxcontrasenia[20];

            printf("Ingrese nombre de usuario:");
            fflush(stdin);
            gets(auxNombre);
            for(int i=0; i<tamU; i++)
            {
                if(strcmp(usuarios[i].nombre, auxNombre) == 0)
                {
                    printf("Ingrese contraseña:");
                    fflush(stdin);
                    gets(auxcontrasenia);
                    for(int i=0; i<tamU; i++)
                    {
                        if(strcmp(usuarios[i].contrasenia, auxcontrasenia) == 0)
                        {
                            return 1;
                        }
                    }
                }
            }

        }


int comprarProducto(eProducto producto[], int tamP)
{
    int auxCodigo;
    char respuesta;
    int retorno = -3;

    mostrarProductos(productos, tamP);
    printf("Ingrese codigo de producto:");
    scanf("%d", &auxCodigo);

    for(int i=0; i<tamP; i++)
    {
        if(productos[i].codProducto == auxCodigo)
        {
            printf("Esta seguro que desea comprar este producto %d ?", auxCodigo);
            fflush(stdin);
            scanf("%c", &respuesta);
            if(respuesta == 's')
            {
                printf("La compra fue realizada con exito!!!");
            }
            else if(respuesta == 's')
            {
                printf("Desea calificar al vendedor S/N?");
                fflush(stdin);
                scanf("%c", &respuesta);
            }
            else if(respuesta == 's')
            {
                printf("ingrese calificacion:");
                fflush(stdin);
                gets(productos.calificacion);
            }
        }
    }




    }

