#include <iostream>
using namespace std;
#include <string.h>


int main(){
    string arreglo_1[50]; //Arreglo que guardara cada letra de la palabra
	int arreglo_2[50];  //Guardara la posicion donde aparece por primera vez una letra diferente en la palabra
	int arreglo_aux[50]; //Almacenara la cantidad de veces que aparece cada letra en la palabra
	int var_random; //Variable booleana del programa
	string elegido; //Palabra que ingresara el usuario
	int largo;    //Se guardara el numero de caracteres de la palabra
	int contador_pal = 0;  //Contador de letras
	cout << "Ingrese una palabra: " << endl;
	cin >> elegido; //El usuario ingresa una palabra cualquiera
	largo = elegido.size();
	cout << endl;
	for(int i = 0; i < largo; i++){ //el primer for "grande" tiene como finalidad encontrar todas las letras de la palabra y la posicion donde fueron encontradas
        var_random = 0;
		if(i==0){
			arreglo_1[i] = elegido[i]; //La primera letra se guarda automaticamente en arreglo_1
			arreglo_2[i] = 0; //Al ser la primera letra, queda automaticamente guardada con la posicion inicial (0)
			contador_pal += 1;
		}
		else{
            for(int u = 0; u < i; u++){
                if(elegido[u] == elegido[i]){  //Compara si las letras de la oalabra son iguales, por ejemplo: de la palabra "arroz" se compara la "a" con la primera "r"
                    var_random = 1;
                    break;
                }
            }
            if(var_random == 0){ //Si var_random sigue siendo igual a 0, entonces:
                int t = contador_pal;  //Variable auxiliar
                arreglo_1[t] = elegido[i]; //arreglo_1 almacena la nueva letra encontrada
                arreglo_2[t] = i; // arreglo_2 la posicion em que se ubicaba en la palabra
                contador_pal += 1;
            }
		}
	}
	for(int e = 0; e < contador_pal; e++)  //el segundo for "grande" tiene como objetivo contar la cantidad de veces que se repite cada letra en la palabra
    {
        int contador_letras = 0; //Utilizamos una variable auxiliar, que guarda el numero de veces que aparece la letra en cuestion
        for(int w = 0; w < largo; w++) //Este for permite iterar toda la palabra, y asi facilitar la comparacion de caracteres
        {
            int op = arreglo_2[e]; //Variable que almacena la posicion donde aparecio cada letra por primera vez
            if(elegido[w] == elegido[op]) //La comparacion sera verdadera si el caracter comparado es igual a la letra elegida por la iteracion
            {
                contador_letras++;
            }
        }
        arreglo_aux[e] = contador_letras;
    }
	for(int r = 0; r < contador_pal; r++){
        cout << arreglo_1[r] << "" << arreglo_aux[r];

	}

}

