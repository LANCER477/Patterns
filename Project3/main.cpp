#include "SpamObserver.h"
#include "HappyObserver.h"
#include "Broadcaster.h"
#include <iostream>

int main() {
    Broadcaster* store = new Broadcaster();

    store->Register(new SpamObserver("Дом 1"));
    store->Register(new SpamObserver("Дом 2"));
    store->Register(new SpamObserver("Дом 3"));
    store->Register(new SpamObserver("Дом 4"));
    store->Register(new SpamObserver("Дом 5"));
    store->Register(new HappyObserver("Постоянный покупатель"));

    store->SendSpam();

    delete store;
    return 0;
}
