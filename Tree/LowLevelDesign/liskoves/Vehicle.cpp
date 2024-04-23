#include<bits/stdc++.h>
using namespace std;
class Vehicle
{
private:
    /* data */
public:
    Vehicle(/* args */){}
    virtual bool hasEngine()=0;
    virtual int noOfWheel()=0;
};

class Car : public Vehicle{

    public:
           Car(){

           }
           bool hasEngine(){
            cout<<"inside car"<<endl;
            return true;
           }
           int noOfWheel(){
            cout<<"has 4 wheel"<<endl;
            return 4;
           }

}; 
class Bicycle : public Vehicle{

    public:
           Bicycle(){

           }
           //it will fail liskoves substitution principal
           bool hasEngine(){
            cout<<"will throw error"<<endl;
            return NULL;
           }
           int noOfWheel(){
            cout<<"has 2 wheel"<<endl;
            return 2;
           }

}; 

class Vehicle1
{
private:
    /* data */
public:
    Vehicle1(){};
    virtual int noOfWheel()=0;
};

class VehicleWithEngine : public Vehicle1 {

    public:
           virtual bool hasEngine()=0;
};

class Car1 : public VehicleWithEngine{

    public : 
            int noOfWheel(){
                cout<<"has 4 wheel"<<endl;
                return 4;
            }
            bool hasEngine(){
                cout<<"yes has engine"<<endl;
                return true;
            }
};
class Cycle : public Vehicle1{

    public : 
            int noOfWheel(){
                cout<<"has 2 wheel"<<endl;
                return 2;
            }
        
};







int main(){
    // Vehicle *vehicleCar = new Car();
    // Vehicle *vehicleCycle = new Bicycle();
    // vector<Vehicle *> v={vehicleCar,vehicleCycle};

    // for(auto i=v.begin();i<v.end();i++){
    //     cout<<(*i)->hasEngine()<<endl;
    //     cout<<(*i)->noOfWheel()<<endl;
    // }

    Vehicle1 *v1=new  Car1();
    Vehicle1 *v2=new  Cycle();
    VehicleWithEngine * v3=new Car1();
    v1->noOfWheel();
    v2->noOfWheel();
    v3->hasEngine();
    v3->noOfWheel();


    
    return 0;
}



