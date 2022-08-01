#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char marca[20];
    int tipo;
    float peso;
} eVehiculo;

eVehiculo* new_Vehiculo();
eVehiculo* new_VehiculoParametros(int id, char* marca, int tipo, float peso);
void destroy_Vehiculo(eVehiculo* e);
int vehiculoSetId(eVehiculo* v, int id);
int vehiculoSetTipo(eVehiculo* v, int tipo);
int vehiculoSetMarca(eVehiculo* v, char* marca);
int vehiculoSetPeso(eVehiculo* v, float peso);
int mostrarVehiculo(eVehiculo* v);


int main()
{
    eVehiculo* aVehiculo = new_VehiculoParametros(100,"Cif",3,450);

    if(aVehiculo == NULL)
    {
        printf("No se pudo conseguir memoria o campos invalidos\n");
        exit(1);
    }
    else
    {
        printf("Todo bien\n");
    }

    mostrarVehiculo(aVehiculo);

    return 0;

}

eVehiculo* new_Vehiculo()
{
    eVehiculo* nuevo;
    nuevo = (eVehiculo*) calloc(1,sizeof(eVehiculo));

    if(nuevo != NULL)
    {
        printf("todo ok\n");
    }

    return nuevo;
}

eVehiculo* new_VehiculoParametros(int id, char* marca, int tipo, float peso)
{
    eVehiculo* nuevo = new_Vehiculo();

    if(nuevo != NULL)
    {
        if(!(vehiculoSetId(nuevo,id) && vehiculoSetMarca(nuevo,marca) &&
           vehiculoSetTipo(nuevo,tipo) && vehiculoSetPeso(nuevo,peso)))
        {
            destroy_Vehiculo(nuevo);
            nuevo = NULL;
        }
    }

    return nuevo;
}


void destroy_Vehiculo(eVehiculo* v)
{
    free(v);
}

int vehiculoSetId(eVehiculo* v, int id)
{
    int todoBien = 0;

    if(v != NULL && id >= 100)
    {
        v->id  = id;
        todoBien = 1;
    }

    return todoBien;
}

int vehiculoSetTipo(eVehiculo* v, int tipo)
{
    int todoBien = 0;

    if(v != NULL && tipo >= 1)
    {
        v->tipo = tipo;
        todoBien = 1;
    }

    return todoBien;
}

int vehiculoSetPeso(eVehiculo* v, float peso)
{
    int todoBien = 0;

    if(v != NULL && peso >= 10)
    {
        v->peso = peso;
        todoBien = 1;
    }

    return todoBien;
}

int vehiculoSetMarca(eVehiculo* v, char* marca)
{
    int todoBien = 0;

    if(v != NULL && marca != NULL && strlen(marca) < 20 && strlen(marca) > 2)
    {
        strcpy(v->marca,marca);
        todoBien = 1;
    }

    return todoBien;
}

int mostrarVehiculo(eVehiculo* v)
{
    int todoBien = 0;
    if(v != NULL)
    {
        printf(" %d  %s  %d  %2.2f\n",v->id,v->marca,v->tipo,v->peso);
    }
    todoBien = 1;

    return todoBien;
}
