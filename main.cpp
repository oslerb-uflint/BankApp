#include <iostream>
#include "BankAccount.h"
#include "CheckingAccount.h"

int main() {  // sandbox to play with objects
    /*BankAccount customer1("Mick Mouse","1234567",2350.50);
    customer1.display();

    BankAccount* customer2 = new BankAccount("Billy","1111112",250000);
    customer2->display();
    delete customer2;*/

    CheckingAccount customer3("Bab","1234444",120,300);
    customer3.display();

    BankAccount* customer4 = new CheckingAccount("Bobby","1234445",1200,200);
    customer4->display();
    customer4->withdraw(1300);
    customer4->display();
    delete customer4;
    return 0;
}
