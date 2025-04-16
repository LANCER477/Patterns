#include <iostream>
#include <string>

using namespace std;

class Transaction
{
public:
    virtual void execute(double sum) = 0;
    virtual ~Transaction() {}
};

class CardPayment : public Transaction 
{
public:
    void execute(double sum) override {
        cout << "Метод оплаты: " << sum << " через банковскую карту" << endl;
    }
};

class CashPayment : public Transaction
{
public:
    void execute(double sum) override
    {
        cout << "Метод оплаты: " << sum << " наличными средствами" << endl;
    }
};

void handleTransaction(Transaction* method, double sum)
{
    method->execute(sum);
}

int main()
{
    Transaction* trans1 = new CardPayment();
    Transaction* trans2 = new CashPayment();

    handleTransaction(trans1, 2340);
    handleTransaction(trans2, 950);

    delete trans1;
    delete trans2;

    return 0;
}
