#include<iostream>
#include"doublyll.h"
using namespace std;

int main(){
    List* list = new DoublyLL();
    int num, pos, res;
    char op;

    do{
        cout<<"Enter op: ";
        cin>>op;

        switch (op){
        case 'h':
            cin>>num;
            list->addHead(num);
            break;

        case 't':
            cin>>num;
            list->addTail(num);
            break;
        case 'g'://get number from the given pos
            cin>>pos;
            if (list->getNum(pos) != -1)cout<<"Position "<<pos<<" is number "<<list->getNum(pos)<<endl;
            else cout<<"The number does not exist"<<endl;
            break;
        case 'G'://get pos from the given num
            cin>>num;
            if (list->getPos(num) != -1)cout<<"Position: "<<list->getPos(num)<<endl;
            else cout<<"The number does not exist"<<endl;
            break;
        case '@':
            cin>>num;
            cin>>pos;
            list->addAt(num, pos);
            break;
        case 'r'://removeAt 
            cin>>pos;
            res = list->removeAt(pos); 
            if (res != -1) cout<<"Removed "<<res<<endl;
            else cout<<"No number is removed"<<endl;
            break;
        case 'y'://remove 
            cin>>num;
            res = list->remove(num);
            if (res != -1)cout<<"Remove position "<<res<<endl;
            else cout<<"No number is removed"<<endl;
            break;
        case 'R'://removeAll
            cin>>num;
            res = list->removeAll(num);
            if (res != -1)cout<<"Removed "<<res<<" element/s"<<endl;
            else cout<<"No number/s removed"<<endl;
            break;
        case 'p':
            list->printHead();
            break;
        case 'P':
            list->printTail();
            break;
        case 'x':
            cout<<"Exiting..."<<endl;
            break;
        }
    } while (op != 'x');
    
}