#include <iostream>

using namespace std;

// Класс получателя
class Receiver
{
    bool bank;
    bool money;
    bool paypal;
    bool crypto;
    bool cash;

public:
    Receiver(bool bank, bool money, bool paypal, bool crypto, bool cash)
        : bank(bank), money(money), paypal(paypal), crypto(crypto), cash(cash)
    {
    }

    bool CanUseBank() const
    {
        return bank;
    }

    bool CanUseMoney() const
    {
        return money;
    }

    bool CanUsePayPal() const
    {
        return paypal;
    }

    bool CanUseCrypto() const
    {
        return crypto;
    }

    bool CanUseCash() const
    {
        return cash;
    }
};

// Базовый обработчик
class PaymentProcessor
{
protected:
    PaymentProcessor* next;

public:
    void SetNext(PaymentProcessor* next)
    {
        this->next = next;
    }

    virtual void Process(Receiver* receiver) = 0;
};

// Обработчик: Банковский перевод
class BankProcessor : public PaymentProcessor
{
public:
    void Process(Receiver* receiver) override
    {
        if (receiver->CanUseBank())
            cout << "Bank transfer" << endl;
        else if (next != nullptr)
            next->Process(receiver);
    }
};

// Обработчик: Перевод системами денежных переводов
class MoneyProcessor : public PaymentProcessor
{
public:
    void Process(Receiver* receiver) override
    {
        if (receiver->CanUseMoney())
            cout << "Transfer through money systems" << endl;
        else if (next != nullptr)
            next->Process(receiver);
    }
};

// Обработчик: PayPal
class PayPalProcessor : public PaymentProcessor
{
public:
    void Process(Receiver* receiver) override
    {
        if (receiver->CanUsePayPal())
            cout << "Transfer via PayPal" << endl;
        else if (next != nullptr)
            next->Process(receiver);
    }
};

// Обработчик: Криптовалюта
class CryptoProcessor : public PaymentProcessor
{
public:
    void Process(Receiver* receiver) override
    {
        if (receiver->CanUseCrypto())
            cout << "Transfer via Cryptocurrency" << endl;
        else if (next != nullptr)
            next->Process(receiver);
    }
};

// Обработчик: Наличные
class CashProcessor : public PaymentProcessor
{
public:
    void Process(Receiver* receiver) override
    {
        if (receiver->CanUseCash())
            cout << "Payment in Cash" << endl;
        else if (next != nullptr)
            next->Process(receiver);
    }
};

// Запуск цепочки обработки
void StartProcessing(PaymentProcessor* processor, Receiver* receiver)
{
    processor->Process(receiver);
}

int main()
{
    PaymentProcessor* bank = new BankProcessor();
    PaymentProcessor* paypal = new PayPalProcessor();
    PaymentProcessor* money = new MoneyProcessor();
    PaymentProcessor* crypto = new CryptoProcessor();
    PaymentProcessor* cash = new CashProcessor();

    bank->SetNext(paypal);
    paypal->SetNext(money);
    money->SetNext(crypto);
    crypto->SetNext(cash);

    Receiver* receiver = new Receiver(false, false, true, false, false);
    StartProcessing(bank, receiver);
    delete receiver;

    receiver = new Receiver(false, true, false, false, false);
    StartProcessing(bank, receiver);
    delete receiver;

    receiver = new Receiver(true, false, false, false, false);
    StartProcessing(bank, receiver);
    delete receiver;

    receiver = new Receiver(false, false, false, true, false);
    StartProcessing(bank, receiver);
    delete receiver;

    receiver = new Receiver(false, false, false, false, true);
    StartProcessing(bank, receiver);
    delete receiver;

    delete bank;
    delete paypal;
    delete money;
    delete crypto;
    delete cash;

    system("pause");
    return 0;
}
