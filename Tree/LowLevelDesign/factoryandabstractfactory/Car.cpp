#include<bits/stdc++.h>
using namespace std;
class Car
{
private:
    /* data */
public:
    Car(/* args */){}
    virtual void drawCar()=0;
};
class Swift : public Car{

    public:
           Swift(){ 
}
           void drawCar(){
            cout<<"creating Swift"<<endl;
           }
          

}; 
class Desizre : public Car{

    public:
           Desizre(){

           }
           void drawCar(){
            cout<<"creating Desire"<<endl;
           }
           //it will fail liskoves substitution principal
           

}; 
class BMW : public Car{

    public:
           BMW(){

           }
           void drawCar(){
            cout<<"creating BMW"<<endl;
           }
           //it will fail liskoves substitution principal
           

}; 
class Audi : public Car{

    public:
           Audi(){

           }
           void drawCar(){
            cout<<"creating Audi"<<endl;
           }
           //it will fail liskoves substitution principal
           

}; 
class CarFactory{
  public:
    Car * createcar(string name){
        if(name=="swift"){
            return new Swift();
        }
       else if(name=="Dezire"){
            return new Desizre();
        }
        else{
            return NULL;
        }
    }

};
class CarAbstractFactory{

    public:
          virtual Car * getVehicle(string car )=0;

};
class LuxryCar:public CarAbstractFactory{
       
       public :
               LuxryCar(){}
               Car * getVehicle(string car ){
                if(car=="BMW")
                    return new BMW();

                else   if(car=="Audi")
                    return new Audi();    
                   else{
                return NULL;
               }    
               }
            

};
class NormalCar:public CarAbstractFactory{
       
       public :
               NormalCar(){}
               Car * getVehicle(string car ){
                if(car=="Dezire")
                    return new Desizre();
                else if(car=="Swift")   
                      return new Swift(); 
                   else{
                return NULL;
               }    
               }

};

class CarFact{
    public :
           CarAbstractFactory * getfactory(string type){
                 if(type=="luxry"){
                    return new LuxryCar();
                 }
                 else{
                    return new NormalCar();
                 }

           }

};


int main(){

//CarFactory * c=new CarFactory();
  //   Car *c1=       c->createcar("swift");
  //        Car *c2=       c->createcar("Dezire");
    //      c1->drawCar();
      //    c2->drawCar();

      CarFact * carFact=new CarFact();
         Car * car=carFact->getfactory("luxry")->getVehicle("BMW");
         car->drawCar();

    return 0;
}