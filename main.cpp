#include "Evaluador.h"
#include <fstream>
#include <math.h>
#include<string.h>
using namespace std;

//Las siguientes funciones escribir y leer ingresan y leen respectivamente un numero ubicado al inicio de un archivo de texto
void escribirNumeroTexto(string nombre_archivo, int num)
{
    ofstream out(nombre_archivo.c_str()); //Declaro mi archivo, colocando el parámetro del nombre que ya viene dado.
    out<<num; //Le asigno el numero a ingresar
    out.close(); //Cierro el archivo
}
int leerNumeroTexto(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str()); //Declaro mi archivo, pero esta vez para leer.
    int leida;  //Variable que almacenara lo que leerá del archivo
    in>>leida; //Asignación del contenido.
    return leida; //Retorno lo que estaba dentro del archivo, en este caso el número.
}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente una cadena ubicada al inicio de un archivo de texto
void escribirStringTexto(string nombre_archivo, string str)
{
    ofstream out(nombre_archivo.c_str()); //Declaro mi archivo, colocando el parámetro del nombre que ya viene dado.
    out<<str; //Le asigno la cadena de texto a  ingresar
    out.close(); //Cierro el archivo

}
string leerStringTexto(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str()); //Declaro mi archivo, pero esta vez para leer.
    string leida;  //Variable que almacenara lo que leerá del archivo
    in>>leida; //Asignación del contenido.
    return leida; //Retorno lo que estaba dentro del archivo, en este caso la cadena de texto.
}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente un numero ubicado al inicio de un archivo binario
void escribirNumeroBinario(string nombre_archivo, int num)
{
    ofstream out(nombre_archivo.c_str()); //Declaración de mi archivo binario.
    out.write((char*)&num,4); //Se procede a escribir con el parámetro write el numero dado.
    out.close(); //Se cierra el archivo.
}
int leerNumeroBinario(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str()); //Se declara el archivo, esta vez para leer.
    int leida; //Variable para leer lo que esta dentro del archivo
    in.read((char*)&leida,4); //Se procede a leer y asignarle a la variable leida el contenido.
    return leida; //Se retorna el contenido del archivo
}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente una cadena ubicada al inicio de un archivo binario
void escribirStringBinario(string nombre_archivo, string str)
{
    ofstream out(nombre_archivo.c_str()); //Declaración de mi archivo binario.
    out.write(str.c_str(),10); //Se procede a escribir con el parámetro write el numero dado.
    out.close(); //Se cierra el archivo.
}
string leerStringBinario(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str()); //Se declara el archivo, esta vez para leer.
    char *leida; //Variable para leer lo que esta dentro del archivo
    leida=new char[10];
    in.read(leida,10); //Se procede a leer y asignarle a la variable leida el contenido.
    return leida; //Se retorna el contenido del archivo

}

//Devuelve true si encuentra str (dada) en un archivo dado el nombre
bool existe(string nombre_archivo, string str)
{
    ifstream in(nombre_archivo.c_str()); //Declaro para leer el archivo.
    char *palabra; //Variable para almacenar contenido
    palabra=new char[str.length()]; //Arreglo del tamaño de la palabra que se busca.
    in>>palabra; //Se le asigna lo que se leyó.
    if (str==palabra)
        return true;//Si coinciden returno true.

}

//Devuelve el numero mayor dado el nombre de un archivo binario
int obtenerMayor(string nombre)
{
    ifstream in(nombre.c_str());////Se declara el archivo, esta vez para leer.
    int tamano; //Usada para conocer el numero de posiciones del archivo
    in.seekg(0,ios::end);//Nos vamos al final del archivo
    tamano=in.tellg();//Una vez estando ahí, tellg nos devuelve el tamaño del archivo(cantidad de posiciones)
    in.seekg(0,ios::beg);//Para que no hayan problemas con la lecturas, regresamos el cursor del archivo a la posicion 0.
    int numero; //variable usada para almacer provisionalmente lo que se vaya leyendo.
    int mayor=0; //Variable para ir almacenando el número mayor.
     for(int cont=0;cont<tamano;cont++)
    {
        in.read((char*)&numero,4);//Se le asigna a la variable numero, lo que se este leyendo en ese momento.
        if(numero>mayor)
            mayor=numero;//Si la variable mayor es menor al numero que se esta leyendo, procedemos a reemplazar ese valor.
    }
    return mayor;
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
