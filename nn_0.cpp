#include <iostream>
#include <vector>
using vec = std::vector<double>;
using namespace std;
// JOAQUIN ARENAS RIVEROS

class Neuron{ 
public:

      vec pesos; double bias;
      
      Neuron(){
      
         pesos = vec(3); 
         for(int i=0; i<3; i++){
         
             pesos[i] = 3.1 + i;
         
         }bias = 0.4;
      
      }
      double forward(vec& entrada){
      
         double suma = bias; 
         for(int i=0; i<3; i++){
             
             suma+= entrada[i]*pesos[i];
         }
         return suma;
      }

};
class Input_Layer{

public:
      
      vec  forward(vec& entrada){
      
           vec salida(3);
           for(int i=0; i<3; i++){
           
               salida[i] = entrada[i];
           }return salida;
      }


};
class Dense_Layer{

public: 
     
     Neuron n[3];
     
      vec  forward(vec& entrada){
      
           vec salida(3);
           for(int i=0; i<3; i++){
           
               salida[i] = n[i].forward(entrada);
           }return salida;
      }


};
class Noise_Layer{
public:

      Neuron n[3];
     
      vec  forward(vec& entrada){
      
           vec salida(3);
           for(int i=0; i<3; i++){
           
               salida[i] = entrada[i]+ 0.05;
           }return salida;
      }


};

double exp(double x){
 
     double resultado = 1.0; 
     double termino = 1.0;
     
     for(int i=1; i<10; i++){
     
         termino *= x / i;
         resultado = resultado + termino;
     }
     return resultado; 
}

double relu(double x){

     return (x > 0) ? x : 0.0; 

}

double sigmoide(double x){

     return 1.0 / (1.0 + exp(-x));
}

class Activation_Layer{

public:
      string tipo;
      
      Activation_Layer(string tipo_activacion){
      
               tipo = tipo_activacion;
      }
      
      vec forward (vec& entrada){
      
          vec salida(3);
          for(int i=0; i<3; i++){
          
              if(tipo == "relu"){
              
                 salida[i] = relu(entrada[i]);
              }
              else if(tipo == "sigmoide"){
              
                 salida[i] = sigmoide(entrada[i]);
              
              }else{
              
                 salida[i] = entrada[i];
              }
          }return salida;
      }


};
class Output_Layer{
public:

       vec  forward(vec& entrada){
      
           vec salida(3);
           for(int i=0; i<3; i++){
           
               salida[i] = entrada[i];
           }return salida;
      }
      

};
class NN{ 

public:

      Input_Layer capa_entrada;
      
      Dense_Layer capa_densa;
      Activation_Layer activacion_relu;
      
      Noise_Layer capa_ruido;
      Activation_Layer activacion_sigmoide;
      
      Output_Layer capa_salida;
      
      NN() : activacion_relu("relu"), activacion_sigmoide("sigmoide"){}
      
      vec forward(vec entrada){
      
           vec salida1 = capa_entrada.forward(entrada);
           
           vec salida2 = capa_densa.forward(salida1);
           vec salida3 = activacion_relu.forward(salida2);
           
           vec salida4 = capa_ruido.forward(salida3);
           vec salida5 = activacion_sigmoide.forward(salida4);
           
           return capa_salida.forward(salida5);
      }

 };


int main(){

    vec entrada = {0.5, 0.6, 0.91};

    NN red; 
    vec salida = red.forward(entrada);
    
    cout<<"Salida: "<<endl;
    for(int i=0; i<3; i++){
    
        cout<<salida[i]<<endl;
    }
    cout<< endl;



return 0;
}
