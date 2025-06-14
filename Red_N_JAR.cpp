#include <iostream>
using namespace std;

class NN{};

class Capa:public NN{
private:

      int numero_de_neuronas[100];
      int parte_proceso;
      

      Capa(int neuronas, int procesos){
          
           numero_de_neuronas = neuronas;
           parte_proceso = procesos;
      }
     
public:

};
class Capa_de_Entrada:public Capa{
    
private:
      
      int parte_entrada[100];

      Capa_de_Entrada(int entrada):Capa( neuronas, procesos){
          
          parte_entrada = entrada;
      }
      
public:
    
};

class Capa_de_Salida:public Capa{
    
private: 
      
      int parte_salida[100];
      
    
      Capa_de_Salida(int salida):Capa(neuronas, procesos){
          
          parte_salida = salida;
      }

public:

};


class Neurona: public Capa{
     
private:
   
      float peso_neurona;
      float bias_neurona;
      float activacion_neurona;


     Neurona(float peso, float bias, float activacion):Capa(neuronas, procesos){
      
           peso_neurona = peso;
           bias_neurona = bias;
           activacion_neurona = activacion;
     }   
 
 public:
 
     float Funcion_activacion(){}
     float Error(){}
       
     
};


class Entrenamiento:public Capa_de_Entrada, public Capa_de_Salida{

private:

     int tasa;
     int epocas;


     Entrenamiento(int tasa_de_aprendizaje, int epocas_entrenamiento):Capa_de_Entrada(), Capa_de_Salida(){
         
         tasa =  tasa_de_aprendizaje;
         epocas = epocas_entrenamiento;
     }

public:


};  

int main() {
   
    return 0;
}
