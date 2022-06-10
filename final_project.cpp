#include <iostream>
#include <string.h>

using namespace std ;

// declaring  transportation class that include all the properties of vehicles  
class Transportation {
    private :
    const string plaque ;
    protected :
        string color , model ;
    public : 
        void set_vehicle_informations(string pl , string col , string mod ){
            plaque = pl ; 
            color = col ; 
            model = mod ;
        }

        void show_vehicle_informations(){
            cout << "The model of vehicle is : " << model ;
            cout << "The color of vehicle is : " << color ;
            cout << "The plaque of vehicle is : " << plaque ;
        }         
};

// declaring drivers properties 
class Drivers {
    private :
        string name , family , id ; 
        int age ;
    public : 
        void set_driver_informations(string n , string f , string i , int a){
            name = n ;
            family = f ;
            id = i ;
            age = a ; 
        }
        
        void show_driver_informations(){
            cout << "The name of driver is : " << name ;
            cout << "The family of driver is : " << family ;
            cout << "The id of driver is : " << id ;
        }       
};

// declaring a class to set travel properties
class Travel {
    private:
        static int numberOfTravels;
    protected : 
        string origin , destination , time , type ; 
        float cost ;
    public :
        void set_Travel_informations (string org , string dest , string t , string tp ){
            origin = org ;
            destination = dest ; 
            time = t ;
            type = tp ;
        }
        class friend Ticket;
        // a pure virtual function to calculate cost 
        virtual void calculate_cost ()=0;  
};
Travel:: int numberOfTravels;

// declaring two classes to define properties of Freightage and passenger service travels  
class Freightage : public Travel { 
    protected :
        float freight_weight ; 
    public :
        void set_freight_weight (float x){
            freight_weight = x ; 
        }  
};

class Passenger : public Travel {
    private:
        string name, family, _id, mobile;
        unsigned int age;
    protected : 
        float passenger_number ;
    public : 
        void set_passenger_number (float x){
            passenger_number = x ;
        }
        void setPassengerInformation(string n, string f, string id, string m, int a)
        {
            name = n;
            family = f;
            _id = id;
            mobile = m;
            age = a;
        }
        class friend Ticket;
};
class Ticket {
    public:
        Ticket()
        {
            numberOfTravels++;
        }
        void showTicket()
        {
            if (age <=8)
            {
                cost/=2;
            }
            cout<<"Name: "<<Name<<"\tFamily: "<<family<<"\nAge: "<<age<<"\tID: "<<id<<"\nMobile: "<<mobile;
            cout << "\nOrigin: "<<origin<<"\tDestinition: "<<destination<<"\nDate: "<<time<<"\tType: "<<type<<endl;
            cout "Cost: "<<cost<<endl;
        }
};

//defining all types of transportations and calculate cost of travel   
class Bus : public Transportation ,Travel , Freightage , Passenger {
    public :
        Bus() {
            void calculate_cost () {
                if (type == "Passenger"){
                    cost = passenger_number * 40000;
                }
                else {
                    cost = freight_weight * 10000 ;
                } 
            }
        } 
};

class Airplane : public Transportation , Freightage , Passenger {
    public :
        Airplane() {
            void calculate_cost () {
                if (type == "Passenger"){
                    cost = passenger_number * 90000;
                }
                else {
                    cost = freight_weight *40000 ;
                }
            }
        }     
};

class Taxi : public Transportation , Freightage , Passenger{
    public :
        Taxi() {
            void calculate_cost () {
                if (type == "Passenger"){
                    cost = passenger_number * 60000;
                }
                else {
                    cost = freight_weight *30000 ;
                }
            }
        } 
};

class Train : public Transportation , Freightage , Passenger {
    public :
        Train() {
            void calculate_cost () {
                if (type == "Passenger"){
                    cost = passenger_number * 30000;
                }
                else {
                    cost = freight_weight * 9000 ;
                }
            }
        } 
};

class Truck : public Transportation , Freightage {
    public :
        Truck() {
            void calculate_cost () {
                cost = freight_weight *20000;
            }
        } 
};

int main (){
    return 0;
}