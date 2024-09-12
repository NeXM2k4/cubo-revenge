#include <iostream>
using namespace std;

//VARIABLES GLOBALES

string parameter, bit_2da_funcion, indicaciones_cara5, indicaciones_cara2, indicaciones_cara1;
string sentido[3];
string rotaciones[3];
string superficie[3];

int cara1[4][4];
int cara2[4][4];
int cara3[4][4];
int cara4[4][4];
int cara5[4][4];
int cara6[4][4];

int cara1_invariante[4][4];
int cara2_invariante[4][4];
int cara3_invariante[4][4];
int cara4_invariante[4][4];
int cara5_invariante[4][4];
int cara6_invariante[4][4];

//SOLO IMPRIME
void print_cara(int n_cara[4][4]){
    cout << endl;
    for (int i = 0; i < 4; i ++){
        for (int j = 0; j < 4; j ++){
            cout << n_cara[i][j];
        }
    }
}

//ACTUALIZACION DE CARAS TEMPORALES
void actualizar_caras(){
    
    for (int i = 1; i < 4; i ++){
        for (int j = 1; j < 4; j ++){
            cara1_invariante[i][j] = cara1[i][j];
            cara2_invariante[i][j] = cara2[i][j];
            cara3_invariante[i][j] = cara3[i][j];
            cara4_invariante[i][j] = cara4[i][j];
            cara5_invariante[i][j] = cara5[i][j];
            cara6_invariante[i][j] = cara6[i][j];
        }
    }
}

//CONVERTIR HEXADECIMAL A BINARIO
string hex_to_binary(string parameter){
    
    string binary;
    string bits[4];
    
    for (int i = 0; i < 4; i ++){
        
        switch (parameter[i]){
            case '0':
                bits[i] = "0000";
                break;
            case '1':
                bits[i] = "0001";
                break;
            case '2':
                bits[i] = "0010";
                break;
            case '3':
                bits[i] = "0011";
                break;
            case '4':
                bits[i] = "0100";
                break;
            case '5':
                bits[i] = "0101";
                break;
            case '6':
                bits[i] = "0110";
                break;
            case '7':
                bits[i] = "0111";
                break;
            case '8':
                bits[i] = "1000";
                break;
            case '9':
                bits[i] = "1001";
                break;
            case 'A':
            case 'a':
                bits[i] = "1010";
                break;
            case 'B':
            case 'b':
                bits[i] = "1011";
                break;
            case 'C':
            case 'c':
                bits[i] = "1100";
                break;
            case 'D':
            case 'd':
                bits[i] = "1101";
                break;
            case 'E':
            case 'e':
                bits[i] = "1110";
                break;
            case 'F':
            case 'f':
                bits[i] = "1111";
                break;
        }

        binary += bits[i];
    }
    
    return binary;
}

//CONVIERTE UN BINARIO DE 2 BITS EN ENTERO
int binary_to_int(string binary){
    
    //De la forma 00, 01, 10, 11, 0, 1, 2, 3
    int decimal = 0;
    
    if (binary[0] == '1') decimal += 1;
    if (binary[1] == '1') decimal += 2;
    
    return decimal;
    
}

//PONE UN STRING AL REVEZ
string inversion_str(string to_invert){
    
    string str_invertida = "";
    
    for (int i = 1; i >= 0; i --){
        str_invertida += to_invert[i];
    }
    
    return str_invertida;
    
}

//SACAR LAS INDICACIONES
void rotaciones_indicaciones(string binary){
    
    //cout << endl << binary;
    
    bit_2da_funcion = binary.substr(0,1);
    indicaciones_cara5 = binary.substr(1, 5);
    indicaciones_cara2 = binary.substr(6, 5);
    indicaciones_cara1 = binary.substr(11, 5);
    
    //cout << endl << bit_2da_funcion << endl << cara5 << endl << cara2 << endl << cara1;
    
    //0 para la cara 1, 1 para la cara 2, 2 para la cara 5
    
    string txt_sentido;
    
    //INDICACIONES DE CARA 1
    
    sentido[0] = indicaciones_cara1.substr(0, 1);
    rotaciones[0] = indicaciones_cara1.substr(1, 2);
    rotaciones[0] = inversion_str(rotaciones[0]);
    superficie[0] = indicaciones_cara1.substr(3, 2);
    superficie[0] = inversion_str(superficie[0]);
    
    if (sentido[0] == "0") txt_sentido = "HORARIO";
    else if (sentido[0] == "1") txt_sentido = "ANTIHORARIO";
    
    cout << endl << "CARA 1: LA SUPERFICIE " << (binary_to_int(superficie[0]) + 1) << " GIRÓ " << binary_to_int(rotaciones[0]) << " VECES EN SENTIDO " << txt_sentido;
    
    //INDICACIONES DE CARA 2
    
    sentido[1] = indicaciones_cara2.substr(0, 1);
    rotaciones[1] = indicaciones_cara2.substr(1, 2);
    rotaciones[1] = inversion_str(rotaciones[1]);
    superficie[1] = indicaciones_cara2.substr(3, 2);
    superficie[1] = inversion_str(superficie[1]);
    
    if (sentido[1] == "0") txt_sentido = "HORARIO";
    else if (sentido[1] == "1") txt_sentido = "ANTIHORARIO";
    
    cout << endl << "CARA 2: LA SUPERFICIE " << (binary_to_int(superficie[1]) + 1) << " GIRÓ " << binary_to_int(rotaciones[1]) << " VECES EN SENTIDO " << txt_sentido;
    
    //INDICACIONES DE CARA 5
    
    sentido[2] = indicaciones_cara5.substr(0, 1);
    rotaciones[2] = indicaciones_cara5.substr(1, 2);
    rotaciones[2] = inversion_str(rotaciones[2]);
    superficie[2] = indicaciones_cara5.substr(3, 2);
    superficie[2] = inversion_str(superficie[2]);
    
    if (sentido[2] == "0") txt_sentido = "HORARIO";
    else if (sentido[2] == "1") txt_sentido = "ANTIHORARIO";
    
    cout << endl << "CARA 5: LA SUPERFICIE " << (binary_to_int(superficie[2]) + 1) << " GIRÓ " << binary_to_int(rotaciones[2]) << " VECES EN SENTIDO " << txt_sentido;
    
    //cout << endl << sentido_cara1 << endl << rotaciones_cara1 << endl << superficie_cara1;
    
}

//LLENADO DEL CUBO
void llenar_cubo(int n_cara[4][4], int bit){
    
    for (int i = 0; i < 4; i ++){
        for (int j = 0; j < 4; j ++){
            n_cara[i][j] = bit;
        }
    }
}

//CAMBIOS EN LA ROTACIÓN
void cambios(int tipo, int n_dim, int m_dim, int cara_cambio[4][4], int cara_invariante[4][4]){
    
    /*
    TIPOS:
    1. COLUMNA COLUMNA
    2. FILA FILA
    3. COLUMNA FILA
    4. FILA COLUMNA
    
    DIMS:
    Indicarán qué fila o columna intercambiar
    */
    
    switch (tipo){
        case 1:
            
            //columna columna
            for (int i = 0; i < 4; i ++){
                cara_cambio[i][n_dim] = cara_invariante[i][m_dim];
            }
        
            break;
        case 2:
        
            //fila fila
            for (int i = 0; i < 4; i ++){
                cara_cambio[n_dim][i] = cara_invariante[m_dim][i];
            }
        
            break;
        case 3:
            
            //cambiás una columna por una fila
            for (int i = 0; i < 4; i ++){
                cara_cambio[i][n_dim] = cara_invariante[m_dim][i];
            }
        
            break;
        case 4:
        
            //cambiás una fila por una columna
            for (int i = 0; i < 4; i ++){
                cara_cambio[n_dim][i] = cara_invariante[i][m_dim];
            }
            
            break;
    }
    
}

//DEFINE LAS ROTACIONES PARA CADA UNO DE LOS 6 POSIBLES CICLOS
void ciclos(int ciclo){
    
    /*
    CICLO 1:
    Rotar C1
    C2c1 C6c1 C4c3 C5c1 C2c1

    CICLO 2:
    Rotar C2
    C5f3 C3c1 C6f1 C1c3 C5f3

    CICLO 3:
    Rotar C3
    C2c3 C6c3 C4c1 C5c3 C2c3

    CICLO 4:
    Rotar C4
    C5f1 C3c3 C6f3 C1c1 C5f1

    CICLO 5:
    Rotar C5
    C3f1 C2f1 C1f1 C4f1 C3f1

    CICLO 6:
    Rotar C6
    C1f3 C2f3 C3f3 C4f3 C1f3
    */    
    
    switch (ciclo){
        case 1:
            
            cambios(1, 0, 0, cara6, cara2_invariante);
            cambios(1, 3, 0, cara4, cara6_invariante);
            cambios(1, 0, 3, cara5, cara4_invariante);
            cambios(1, 0, 0, cara2, cara5_invariante);
            
            cambios(3, 0, 3, cara1, cara1_invariante);
            cambios(3, 1, 2, cara1, cara1_invariante);
            cambios(3, 2, 1, cara1, cara1_invariante);
            cambios(3, 3, 0, cara1, cara1_invariante);
            
            actualizar_caras();
            
            break;
        case 2:
            
            cambios(3, 0, 3, cara3, cara5_invariante);
            cambios(4, 0, 0, cara6, cara3_invariante);
            cambios(3, 3, 0, cara1, cara6_invariante);
            cambios(4, 3, 3, cara5, cara1_invariante);
            
            cambios(3, 0, 3, cara2, cara2_invariante);
            cambios(3, 1, 2, cara2, cara2_invariante);
            cambios(3, 2, 1, cara2, cara2_invariante);   
            cambios(3, 3, 0, cara2, cara2_invariante);  
            
            actualizar_caras();
            
            break;
        case 3:
        
            cambios(1, 3, 3, cara5, cara2_invariante);
            cambios(1, 0, 3, cara4, cara5_invariante);
            cambios(1, 3, 0, cara6, cara4_invariante);
            cambios(1, 3, 3, cara2, cara6_invariante);
            
            cambios(3, 0, 3, cara3, cara3_invariante);
            cambios(3, 1, 2, cara3, cara3_invariante);
            cambios(3, 2, 1, cara3, cara3_invariante);
            cambios(3, 3, 3, cara3, cara3_invariante);
            
            actualizar_caras();
            
            break;
        case 4:
        
            cambios(3, 0, 0, cara1, cara5_invariante);
            cambios(4, 3, 0, cara6, cara1_invariante);
            cambios(3, 3, 3, cara3, cara6_invariante);
            cambios(4, 0, 3, cara5, cara3_invariante);
            
            cambios(3, 0, 3, cara4, cara4_invariante);
            cambios(3, 1, 2, cara4, cara4_invariante);
            cambios(3, 2, 1, cara4, cara4_invariante);
            cambios(3, 3, 3, cara4, cara4_invariante);
            
            actualizar_caras();
            
            break;
        case 5:
            
            cambios(2, 0, 0, cara2, cara3_invariante);
            cambios(2, 0, 0, cara1, cara2_invariante);
            cambios(2, 0, 0, cara4, cara1_invariante);
            cambios(2, 0, 0, cara3, cara4_invariante);
            
            cambios(3, 0, 3, cara5, cara5_invariante);
            cambios(3, 1, 2, cara5, cara5_invariante);
            cambios(3, 2, 1, cara5, cara5_invariante);
            cambios(3, 3, 3, cara5, cara5_invariante);
            
            actualizar_caras();
            
            break;
        case 6:
            
            cambios(2, 3, 3, cara2, cara1_invariante);
            cambios(2, 3, 3, cara3, cara2_invariante);
            cambios(2, 3, 3, cara4, cara3_invariante);
            cambios(2, 3, 3, cara1, cara4_invariante);
            
            cambios(3, 0, 3, cara6, cara6_invariante);
            cambios(3, 1, 2, cara6, cara6_invariante);
            cambios(3, 2, 1, cara6, cara6_invariante);
            cambios(3, 3, 3, cara6, cara6_invariante);
            
            actualizar_caras();
            
            break;
    }
}

//REORDENA EL CUBO
void cubo_final(){
 
    /*
    string sentido[3];
    string rotaciones[3];
    string superficie[3];
    */
    
    //PARA LA CARA 1
    
    switch (binary_to_int(superficie[0])){
        case 0:
            if (sentido[0] == "0"){
                for (int i = 0; i < binary_to_int(rotaciones[0]); i++){
                    ciclos(5);
                }
            }
            else{
                for (int i = 0; i < 4 - binary_to_int(rotaciones[0]); i++){
                    ciclos(5);
                }
            }
            break;
        case 1:
            if (sentido[0] == "0"){
                for (int i = 0; i < binary_to_int(rotaciones[0]); i++){
                    ciclos(4);
                }
            }
            else{
                for (int i = 0; i < 4 - binary_to_int(rotaciones[0]); i++){
                    ciclos(4);
                }
            }
            break;
        case 2:
            if (sentido[0] == "0"){
                for (int i = 0; i < binary_to_int(rotaciones[0]); i++){
                    ciclos(6);
                }
            }
            else{
                for (int i = 0; i < 4 - binary_to_int(rotaciones[0]); i++){
                    ciclos(6);
                }
            }
            break;
        case 3:
            if (sentido[0] == "0"){
                for (int i = 0; i < binary_to_int(rotaciones[0]); i++){
                    ciclos(2);
                }
            }
            else{
                for (int i = 0; i < 4 - binary_to_int(rotaciones[0]); i++){
                    ciclos(2);
                }
            }
            break;
    }
            
    //PARA LA CARA 2
        
    switch (binary_to_int(superficie[1])){
        case 0:
            if (sentido[1] == "0"){
                for (int i = 0; i < binary_to_int(rotaciones[1]); i++){
                    ciclos(5);
                }
            }
            else{
                for (int i = 0; i < 4 - binary_to_int(rotaciones[1]); i++){
                    ciclos(5);
                }
            }
            break;
        case 1:
            if (sentido[1] == "0"){
                for (int i = 0; i < binary_to_int(rotaciones[1]); i++){
                    ciclos(1);
                }
            }
            else{
                for (int i = 0; i < 4 - binary_to_int(rotaciones[1]); i++){
                    ciclos(1);
                }
            }
            break;
        case 2:
            if (sentido[1] == "0"){
                for (int i = 0; i < binary_to_int(rotaciones[1]); i++){
                    ciclos(6);
                }
            }
            else{
                for (int i = 0; i < 4 - binary_to_int(rotaciones[1]); i++){
                    ciclos(6);
                }
            }
            break;
        case 3:
            if (sentido[1] == "0"){
                for (int i = 0; i < binary_to_int(rotaciones[1]); i++){
                    ciclos(3);
                }
            }
            else{
                for (int i = 0; i < 4 - binary_to_int(rotaciones[1]); i++){
                    ciclos(3);
                }
            }
            break;
    }
        
    //PARA LA CARA 5
    
    switch (binary_to_int(superficie[2])){
        case 0:
            if (sentido[2] == "0"){
                for (int i = 0; i < binary_to_int(rotaciones[2]); i++){
                    ciclos(4);
                }
            }
            else{
                for (int i = 0; i < 4 - binary_to_int(rotaciones[0]); i++){
                    ciclos(4);
                }
            }
            break;
        case 1:
            if (sentido[2] == "0"){
                for (int i = 0; i < binary_to_int(rotaciones[2]); i++){
                    ciclos(1);
                }
            }
            else{
                for (int i = 0; i < 4 - binary_to_int(rotaciones[0]); i++){
                    ciclos(1);
                }
            }
            break;
        case 2:
            if (sentido[2] == "0"){
                for (int i = 0; i < binary_to_int(rotaciones[2]); i++){
                    ciclos(2);
                }
            }
            else{
                for (int i = 0; i < 4 - binary_to_int(rotaciones[0]); i++){
                    ciclos(2);
                }
            }
            break;
        case 3:
            if (sentido[2] == "0"){
                for (int i = 0; i < binary_to_int(rotaciones[2]); i++){
                    ciclos(3);
                }
            }
            else{
                for (int i = 0; i < 4 - binary_to_int(rotaciones[0]); i++){
                    ciclos(3);
                }
            }
            break;
        
    }
    
}

//SACAR LA LLAVE MUTANTE
void llave_mutante(){
    
    string kC1, kC2, kC3, kC4, kC5, kC6, llave_mutante;
    
    //LOS DEFINIDOS POR LA GUÍA
    
    kC1 = to_string(cara1[0][3]) + to_string(cara1[0][2]) + to_string(cara1[0][1]) + to_string(cara1[0][0]) + to_string(cara1[1][3]) + to_string(cara1[1][2]) + to_string(cara1[1][1]) + to_string(cara1[1][0]) + to_string(cara1[2][3]) + to_string(cara1[2][2]) + to_string(cara1[2][1]) + to_string(cara1[2][0]) + to_string(cara1[3][3]) + to_string(cara1[3][2]) + to_string(cara1[3][1]) + to_string(cara1[3][0]);
    
    kC2 = to_string(cara2[0][0]) + to_string(cara2[1][0]) + to_string(cara2[2][0]) + to_string(cara2[3][0]) + to_string(cara2[0][1]) + to_string(cara2[1][1]) + to_string(cara2[2][1]) + to_string(cara2[3][1]) + to_string(cara2[0][2]) + to_string(cara2[1][2]) + to_string(cara2[2][2]) + to_string(cara2[3][2]) + to_string(cara2[0][3]) + to_string(cara2[1][3]) + to_string(cara2[2][3]) + to_string(cara2[3][3]);
    
    kC5 = to_string(cara5[3][0]) + to_string(cara5[3][1]) + to_string(cara5[3][2]) + to_string(cara5[3][3]) + to_string(cara5[2][0]) + to_string(cara5[2][1]) + to_string(cara5[2][2]) + to_string(cara5[2][3]) + to_string(cara5[1][0]) + to_string(cara5[1][1]) + to_string(cara5[1][2]) + to_string(cara5[1][3]) + to_string(cara5[0][0]) + to_string(cara5[0][1]) + to_string(cara5[0][2]) + to_string(cara5[0][3]);
    
    //LOS INVERSOS
    
    kC3 = to_string(cara3[3][0]) + to_string(cara3[3][1]) + to_string(cara3[3][2]) + to_string(cara3[3][3]) + to_string(cara3[2][0]) + to_string(cara3[2][1]) + to_string(cara3[2][2]) + to_string(cara3[2][3]) + to_string(cara3[1][0]) + to_string(cara3[1][1]) + to_string(cara3[1][2]) + to_string(cara3[1][3]) + to_string(cara3[0][0]) + to_string(cara3[0][1]) + to_string(cara3[0][2]) + to_string(cara3[0][3]);
    
    kC4 = to_string(cara4[3][3]) + to_string(cara4[2][3]) + to_string(cara4[1][3]) + to_string(cara4[0][3]) + to_string(cara4[3][2]) + to_string(cara4[2][2]) + to_string(cara4[1][2]) + to_string(cara4[0][2]) + to_string(cara4[3][1]) + to_string(cara4[2][1]) + to_string(cara4[1][1]) + to_string(cara4[0][1]) + to_string(cara4[3][0]) + to_string(cara4[2][0]) + to_string(cara4[1][0]) + to_string(cara4[0][0]);
    
    kC6 = to_string(cara6[3][3]) + to_string(cara6[2][3]) + to_string(cara6[1][3]) + to_string(cara6[0][3]) + to_string(cara6[3][2]) + to_string(cara6[2][2]) + to_string(cara6[1][2]) + to_string(cara6[0][2]) + to_string(cara6[3][1]) + to_string(cara6[2][1]) + to_string(cara6[1][1]) + to_string(cara6[0][1]) + to_string(cara6[3][0]) + to_string(cara6[2][0]) + to_string(cara6[1][0]) + to_string(cara6[0][0]);
    
    llave_mutante = kC6 + kC5 + kC4 + kC3 + kC2 + kC1;
    
    cout << endl << endl << "LLAVE MUTANTE : " << llave_mutante;
    
}

//SEGUNDA FUNCION
string segunda_funcion(string __bit_de_segunda_funcion, string binary){

    string new_binary = "";
    int option;
    
    if (__bit_de_segunda_funcion == "0") option = 0;
    else if (__bit_de_segunda_funcion == "1") option = 1;

    switch (option){
        
        case 0:
            
            for(int i = 0; i < 16; i ++){
                if (binary[i] == '0'){
                    new_binary += '1';
                }
                else{
                    new_binary += '0';
                }
            }
            
            break;
        case 1:
        
            string parte1 = binary.substr(0, 8);
            string parte2 = binary.substr(8, 8);
            
            new_binary = parte1 + parte2;
        
            break;
    }
    
    return new_binary;
}

//FUNCION PRINCIPAL
int main() {
    
    llenar_cubo(cara1, 0);
    llenar_cubo(cara2, 1);
    llenar_cubo(cara3, 0);
    llenar_cubo(cara4, 1);
    llenar_cubo(cara5, 0);
    llenar_cubo(cara6, 1);
    
    actualizar_caras();
    
    //Ingresar el parámetro en hexadecimal
    cout << "Ingresa el parámetro hexadecimal" << endl;
    cin >> parameter;
    
    //Convertir a binario
    string binary = hex_to_binary(parameter);
    
    cout << endl << "Parámetro convertido a binario: " << binary;
    
    //PRIMERA FUNCIÓN
    
    //Sacar las indicaciones
    rotaciones_indicaciones(binary);
    
    //Hace todas las rotaciones en base a las indicaciones
    cubo_final();
    
    //SEGUNDA FUNCIÓN
    
    //Convierte el parámetro inicial en base al bit de segunda función
    binary = segunda_funcion(bit_2da_funcion, binary);
    
    cout << endl << endl << "Parámetro de segunda función: " << binary;
    
    //Sacar las nuevas indicaciones
    rotaciones_indicaciones(binary);
    
    //Gacer las nuevas rotaciones
    cubo_final();
    
    //OUTPUT
    
    //Imprimir la llave mutante
    llave_mutante();

    return 0;
}
