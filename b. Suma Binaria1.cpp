/******************************************************************************
        Desarrollado por: Luis Javier Romero Anaya
 

    En cada uno de los siguientes ejercicios escriba el diagrama de flujo,
    el pseudocódigo y un programa en lenguaje C++ o Python.

    b. Escriba un programa para sumar dos números binarios.
       e.g. Entre el primer número:   1010
       Entre el segundo número:       0011
       La suma de los dos números es: 1101

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <conio.h>


using namespace std;

bool  Bin1[16];
bool  Bin2[16];
bool  BinZ[16];
bool  Carry=0;
bool  CarryIn=0;
bool  CarryOut=0;

int   n;

int main()
    { 
     cout<< " ***********************************"<<endl;    
     cout<< "    Digite el número de bit: ",cin>> n;    
     cout<< " ***********************************"<<endl;
     cout<< "    Digite primer número binario: "  <<endl;
     cout<< " -----------------------------------"<<endl;
     
         for (int i = n-1; i >=0; i--)
            {
             cout <<" |   Bit "<< i <<": ",  cin>> Bin1[i];     
            }
            
     cout<< " ***********************************"<<endl;    
     cout<< "    Digite segundo número binario: " <<endl;
     cout<< " -----------------------------------"<<endl;
     
         for (int i = n-1; i >=0; i--)
            {
             cout <<" |   Bit "<< i <<": ",cin>> Bin2[i];      
            }

         cout<< " ***********************************"  <<endl;
         cout<< "    Digite el acarreo: ", cin>> CarryIn;
         cout<< " ***********************************"  <<endl;
         cout<< "        La suma es: "                  <<endl; 
         cout<< " -----------------------------------"  <<endl;
         
        for (int i = 0 ; i < n; i++)
            {
//                                                                        __________________________________
              if (CarryIn==0)                                           // C_in  A   B       C_out  (A+B)Z | 		
                {                                                       //---------------------------------|		C_in:  Carry In = 0 
                 BinZ[i] = (( Bin1[i] ^ Bin2[i] ));                     //   0   0   0         0       0   |		C_out: Carry Out (A and B)
                 CarryOut = ( Bin1[i] & Bin2[i] );                      //   0   0   1         0       1   |		(A+B)Z: (A xor B)
                 CarryIn = CarryOut;                                    //   0   1   0         0       1   |
                }                                                       //   0   1   1         1       0   |
                                                                        //---------------------------------|		C_in:  Carry In = 1
                else                                                    //   1   0   0         0       1   | 		C_out: Carry Out (A or B)
                    {                                                   //   1   0   1         1       0   |		(A+B)Z: (A xnor B)
                     BinZ[i] = (!(Bin1[i] ^ Bin2[i]));            	    //   1   1   0         1       0   |
                     CarryOut =  (Bin1[i] | Bin2[i]);                 	//   1   1   1         1       1   |
                                                                        //_________________________________|
                     CarryIn = CarryOut;
                    }
                    
             cout <<" |   Bit "<< i <<": " <<BinZ[i] << endl;  
            }
            
             cout <<" |   C_out: "<< CarryOut << endl;  
             getch();
             
        return 0;
    }
