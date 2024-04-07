#include <iostream>
#include <cmath>
using namespace std;

class Number{
    private:
        int num;
        int result;
    public:
        //int result;
        Number(){
            num = 0;
            result = 0;
        }
        void setData(int);
        void getData();
        friend void Dec2Bin(Number&);
        friend void Dec2Oct(Number&);
        friend void Bin2Dec(Number&);
        friend void Oct2Dec(Number&);
};

void Number::setData(int num){
    this->num = num;
}
void Number::getData(){
    cout<<"The entered number is "<<num<<" and the result is "<<result;
}

void Dec2Bin(Number& obj){
    int i;
    int temp = 0;
    for(i = obj.num; i > 0; i/=2){
        temp = temp*10 + i%2;
    }
    for(i = temp; i > 0; i/=10){
        obj.result = obj.result*10 + i%10;
    }
}

void Dec2Oct(Number& obj){
    int i;
    int temp = 0;
    for(i = obj.num; i > 0; i/=8){
        temp = temp*10 + i%8;
    }
    for(i = temp; i > 0; i/=10){
        obj.result = obj.result*10 + i%10;
    }
}

void Bin2Dec(Number& obj){
    int i;
    int power = 0;
    int check = 0;
    for(i = obj.num; i > 0; i/=10){
        if(i%10!=0 && i%10!=1){
            check++;
            break;
        }
    }
    if(check == 0){
        for(i = obj.num; i > 0; i/=10){
            obj.result = obj.result + (i%10)*pow(2,power);
            power++;
        }
    }
    else{
        cout<<"Invalid entry."<<endl;
    }
}

void Oct2Dec(Number& obj){
    int i;
    int power = 0;
    int check = 0;
    for(i = obj.num; i > 0; i/=10){
        if(i%10>=7){
            check++;
            break;
        }
    }
    if(check == 0){
        for(i = obj.num; i > 0; i/=10){
            obj.result = obj.result + (i%10)*pow(8,power);
            power++;
        }
    }
    else{
        cout<<"Invalid entry."<<endl;
    }
}

int main() {
    int choice,num;
    Number obj;
    cout<<"1. Decimal to Binary"<<endl;
    cout<<"2. Decimal to Octal"<<endl;
    cout<<"3. Binary to Decimal"<<endl;
    cout<<"4. Octal to Decimal"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    if(choice>4 || choice < 0){
        cout<<"Invalid choice."<<endl;
    }
    cout<<"Enter your number: ";
    cin>>num;
    obj.setData(num);
    switch(choice){
        case 1:
            Dec2Bin(obj);
        break;
        case 2:
            Dec2Oct(obj);
        break;
        case 3:
            Bin2Dec(obj);
        break;
        case 4:
            Oct2Dec(obj);
        break;
        default: cout<<"Invalid choice."<<endl;
    }
    obj.getData();
   
    return 0;
}
