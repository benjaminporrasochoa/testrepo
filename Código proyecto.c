#include<stdio>
#define DATOS 5000 //Cantidad máxima de datos a cargar
#define TEXTO 100 //Cantidad máxima de caracteres para los campos de texto
    typedef struct{ //Estructura para almacenar los datos de cada sesión deportiva
        int anio, mes, dia;
        char dia_semana[TEXTO];
        char hora_inicio[TEXTO];
        char hora_fin[TEXTO];
        char actividad_base[TEXTO];
        char modaldad[TEXTO];
        char centro[TEXTO];
        int plazas;
        int ocupadas;
        int libres;
        char tipo[TEXTO];
    } SesionDeportiva;

    int cargarDatos(SesionDeportiva sesiones[], char nombreArchivo[]){
        FILE *f;
        f = fopen(nombreArchivo, "r");
        int i=0;
        char basura[300]; //Variable para almacenar la línea de cabecera y descartarla
        if (f == NULL){
            printf("Error al abrir el archivo.\n");
            return 0;
        }
        fgets(basura, 300, f); //Leer la primera línea (cabecera) y descartarla

        while (!feof(f) && i < DATOS){
            
            fscanf(f, "%d %d %d %s %s %s %s %s %s %d %d %d %s", 
                &sesiones[i].anio,
                &sesiones[i].mes,
                &sesiones[i].dia, 
                sesiones[i].dia_semana, 
                sesiones[i].hora_inicio, 
                sesiones[i].hora_fin, 
                sesiones[i].actividad_base, 
                sesiones[i].modaldad, 
                sesiones[i].centro,
                &sesiones[i].plazas, 
                &sesiones[i].ocupadas, 
                &sesiones[i].libres, 
                sesiones[i].tipo);
                i++;
        }
        fclose(f);
        return i; //Retorna la cantidad de datos cargados
    }
    int main (){
        SesionDeportiva sesiones[DATOS];
        int data = cargarDatos(sesiones, "deportes_ayuntamiento.txt");
        printf("Cantidad de datos cargados: %d\n", data);
        printf("Primer dato cargado: %d/%d/%d, %s, %s, %s, %s, %s, %d plazas, %d ocupadas, %d libres, tipo: %s\n", 
            sesiones[0].anio,
            sesiones[0].mes,
            sesiones[0].dia, 
            sesiones[0].dia_semana, 
            sesiones[0].hora_inicio, 
            sesiones[0].hora_fin, 
            sesiones[0].actividad_base, 
            sesiones[0].modaldad, 
            sesiones[0].plazas, 
            sesiones[0].ocupadas, 
            sesiones[0].libres, 
            sesiones[0].tipo);
    }
    
    
