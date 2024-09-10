#include <iostream>
using namespace std;

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

void rotaciones(string binary){
    
    //cout << endl << binary;
    
    string bit_2da_funcion = binary.substr(0,1);
    string cara5 = binary.substr(1, 5);
    string cara2 = binary.substr(6, 5);
    string cara1 = binary.substr(11, 5);
    
    //cout << endl << bit_2da_funcion << endl << cara5 << endl << cara2 << endl << cara1;
    
    string sentido_cara1 = cara1.substr(0, 1);
    string rotaciones_cara1 = cara1.substr(1, 2);
    string superficie_cara1 = cara1.substr(3, 2);
    
    string sentido_cara2 = cara2.substr(0, 1);
    string rotaciones_cara2 = cara2.substr(1, 2);
    string superficie_cara2 = cara2.substr(3, 2);
    
    string sentido_cara5 = cara5.substr(0, 1);
    string rotaciones_cara5 = cara5.substr(1, 2);
    string superficie_cara5 = cara5.substr(3, 2);
    
    //cout << endl << sentido_cara1 << endl << rotaciones_cara1 << endl << superficie_cara1;
    
    
    
}

int llenar_cubo(int bit){
    
    int n_cara[4][4];
    
    for (int i = 0; i < 4; i ++){
        for (int j = 0; j < 4; j ++){
            n_cara[i][j] = bit;
        }
    }
    
    return n_cara;
    
}

int main() {

    string parameter;
    
    //lenar caras del cubo
    int cara1[4][4] = llenar_cubo(0);
    int cara2[4][4] = llenar_cubo(1);
    int cara3[4][4] = llenar_cubo(0);
    int cara4[4][4] = llenar_cubo(1);
    int cara5[4][4] = llenar_cubo(0);
    int cara6[4][4] = llenar_cubo(1);
    
    //Ingresar el parámetro en hexadecimal
    cout << "Ingresa el parámetro hexadecimal" << endl;
    cin >> parameter;
    
    //Convertir a binario
    string binary = hex_to_binary(parameter);
    
    rotaciones(binary);
    
    

    return 0;
}
