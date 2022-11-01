#include <stdio.h>
#include <stdlib.h>

int dniIngresado=0;
int valido=0;
int nuevaNota=0;
int dni=0;
int nota=0;
int bandera = 0;
int cantAlumnos = 10;

struct definicionAlumno
{
    int dni;
    int nota;
};

struct definicionAlumno lista_alumnos[10];


void cargarAlumno();
void buscarAlumno();   
void mostrarAlumnos();
void modificarNota();  
int validarNota();
int validarDni();

void main()
{
    int opcion=0;
    do
    {
        printf("\n");
        printf("Ingrese una opci%cn \n", 162);
        printf("1-Cargar alumnos \n");
        printf("2-Buscar un alumno \n");
        printf("3-Modificar la nota de un alumno \n");
        printf("4-Mostrar un listado de los 10 alumnos \n");
        printf("5-Salir \n");
        scanf("%i", &opcion);

        switch (opcion)
        {
        case 1:                             // Para cargar datos.
            cargarAlumno();
            break;

        case 2:                             // Para buscar el alumno.
            buscarAlumno();
            break;

        case 3:                              // Para modificar notas de alumnos.
            modificarNota();
            break;

        case 4:                              // Para mostrar los datos.
            mostrarAlumnos();
            break;
        }

    } while (opcion != 5);

    
}

void cargarAlumno()
{
    printf("Ingrese datos de los alumnos \n");
    printf("\n");
    for (int i=0; i<cantAlumnos; i++)
    {
        do
        {
            printf("DNI del alumno: %i \n", i + 1);
            scanf("%i", &dni);
            valido = validarDni(dni);
            if (valido==1)
            {
                lista_alumnos[i].dni = dni;
            }
            else
            {
                printf("ERROR: no ingres%c un dni valido\n", 162);
            }
        } while (valido==0);

        do
        {
            printf("Nota: \n");
            scanf("%i", &nota);
            valido = validarNota(nota);
            if (valido==1)
            {
                lista_alumnos[i].nota = nota;
            }
            else
            {
                printf("ERROR: no ingres%c una nota valida\n", 162);
            }
        } while (valido==0);

        printf("\n");
    }
}

int validarDni(int dni)
{
    if (dni>=1000000 && dni<=99999999)
    {
        return 1;
    }
    return 0;
}

int validarNota(int nota)
{
    if (nota>=1 && nota<=10)
    {
        return 1;
    }
    return 0;
}

void buscarAlumno()
{
    printf("Por favor, ingrese DNI del alumno a buscar\n");
    scanf("%i", &dniIngresado);
    bandera = 0;
    int i = 0;
    do
    {
        if (dniIngresado == lista_alumnos[i].dni)
        {
            bandera = 1;
        }
        else
        {
            i = i + 1;
        }

    } while (i<cantAlumnos && bandera==0);

    if (bandera == 1)
    {
        printf("DNI: %i \t nota: %i \n", lista_alumnos[i].dni, lista_alumnos[i].nota);
    }
    else
    {
        printf("No se encontr%c el alumno con el DNI: %i \n", 162, dniIngresado);
    }
}

void modificarNota()
{
    printf("Por favor, ingrese DNI del alumno a modificar su nota\n");
    scanf("%i", &dniIngresado);
    int i = 0;
    bandera = 0;
    do
    {
        if (dniIngresado == lista_alumnos[i].dni)
        {
            bandera = 1;
        }
        else
        {
            i = i + 1;
        }
    } while (i<cantAlumnos && bandera==0);

    if (bandera==1)
    {
        printf("El alumno con DNI %i tiene de nota: %i \n", lista_alumnos[i].dni, lista_alumnos[i].nota);
        do
        {
            printf("Por favor, ingrese la nueva nota\n");
            scanf("%i", &nuevaNota);
            valido = validarNota(nuevaNota);
            if (valido == 0)
            {
                printf("ERROR: no ingres%c una nota valida, vuelva a intentarlo.\n", 162);
            }
        } while (valido==0);

        lista_alumnos[i].nota = nuevaNota;

        printf("DNI: %i \t Nota nueva: %i \n", lista_alumnos[i].dni, lista_alumnos[i].nota);
    }
    else
    {
        printf("No se encontr%c un alumno con el DNI ingresado \n", 162);
    }
}

void mostrarAlumnos()
{
    printf("Lista de alumnos \n");
    for (int i=0; i<cantAlumnos; i++)
    {
        printf("Alumno: %i \t DNI: %i \t nota: %i \n", i + 1, lista_alumnos[i].dni, lista_alumnos[i].nota);
    }
}