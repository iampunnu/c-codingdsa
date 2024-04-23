#include<bits/stdc++.h>
using namespace std;
class Marker
{
public:
      string name;
      string color;
      int year;
      int price;
public:
    Marker(string name,string color,int year,int price){
          this->name=name;
          this->color=color;
          this->price=price;
          this->year=year;
    }
};

class Invoice{
       public :
               Marker * marker;
               int qty;
        public :
               Invoice(Marker *  marker,int qty){
                this->marker=marker;
                this->qty=qty;
               } 
               int calculatePrice(){
                return marker->price*this->qty;
               } 
               //violating single responsibility so created invoiceDao
               Invoice * saveToDb(){
                cout<<"saving to db "<<this->marker->name<<endl;
                return this;
            }     


};

class InvoiceDao{
    public:
            Invoice * invoice;
            InvoiceDao(Invoice * invoice){
                this->invoice=invoice;
            }
            Invoice saveToDb(){
                cout<<"saving to db "<<invoice->marker->name<<endl;
                return *invoice;
            }
            //adding new change will fail open close principal to resolve this we will create abstract class
               //and will extend the implementation  
            Invoice saveToFile(){
                cout<<"saving to File "<<invoice->marker->name<<endl;
                return *invoice;
            }


};

//open close


class InvoiceDaoSave{
    public:
           virtual Invoice save()=0;
            
};
class InvoiceDaoSaveToDb : public InvoiceDaoSave {
    public :
           Invoice * invoice;
           InvoiceDaoSaveToDb(Invoice * invoice){
            this->invoice=invoice;
           }
           Invoice save(){
            cout<<"saving to db"<<" "<<invoice->marker->name<<endl;
            return *invoice;
           }

};
class InvoiceDaoSaveTofile : public InvoiceDaoSave {
    public :
           Invoice * invoice;
           InvoiceDaoSaveTofile(Invoice * invoice){
            this->invoice=invoice;
           }
           Invoice save(){
            cout<<"saving to file"<<" "<<invoice->marker->name<<endl;
            return *invoice;
           }

};

int main(){
  

     Marker marker("file","black",2012,107);
     Marker marker1("db","black",2012,107);

     cout<<marker.color<<" "<<marker.name<<" "<<marker.price<<" "<<marker.year<<endl; 
     Invoice invoice(&marker,10);
          Invoice invoice1(&marker1,10);


     InvoiceDaoSave * invoiceDaoSave =new InvoiceDaoSaveToDb(&invoice);
      Invoice i=invoiceDaoSave->save();
      InvoiceDaoSave * invoiceDaoSave1=new InvoiceDaoSaveTofile(&invoice1);
      Invoice i1=invoiceDaoSave1->save();


     //InvoiceDao invoiceDao(&invoice);
       //   InvoiceDao invoiceDao1(&invoice);

    // Invoice i1=invoiceDao.saveToDb();
     //Invoice i2=invoiceDao.saveToFile();

    //  Invoice * in=invoice.saveToDb();
    //  cout<<invoice.calculatePrice()<<endl;
    //  InvoiceDao invoiceDao(&invoice);
    //  Invoice invoice1=invoiceDao.saveToDb();
    //  cout<<invoice1.marker->name<<endl;

    return 0;
}

