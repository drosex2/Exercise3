#ifndef MYHTOPNADR_HPP
#define MYHTOPNADR_HPP

#include "../../hashtable/clsadr/htclsadr.hpp"
#include "../../hashtable/opnadr/htopnadr.hpp"
#include "../../binarytree/binarytree.hpp"
#include "../../binarytree/lnk/binarytreelnk.hpp"
#include "../../binarytree/vec/binarytreevec.hpp"
#include "../../list/list.hpp"
#include "../../bst/bst.hpp"
#include "../../container/container.hpp"
#include "../../container/mappable.hpp"
#include "../../zlasdtest/container/mappable.hpp"
#include "../../zlasdtest/container/traversable.hpp"
#include "../container.hpp"
#include <iostream>
#include <random>

using namespace std;

using namespace miotest;

namespace miotest
{

    void testHashTableOpenAddressing()
    {
        //unsigned long value,val;
        default_random_engine gen(random_device{}());
        uniform_real_distribution<double> dist(1, 1000);
        cout<<"Hash Table di default e con dimensione in input: "<<endl;
        lasd::HashTableOpnAdr<double> htDef;
        lasd::HashTableOpnAdr<double> ht1(1000);
        cout << ((htDef == ht1) ? "Le due hashTable sono uguali" : "Le due hashTable sono diverse") << "!" << endl;
        ht1.Insert(dist(gen));
        cout << ((htDef == ht1) ? "Le due hashTable sono uguali" : "Le due hashTable sono diverse") << "!" << endl;
        lasd::HashTableOpnAdr<double> ht2(50);
        cout << ((htDef == ht2) ? "Le due hashTable sono uguali" : "Le due hashTable sono diverse") << "!" << endl;
        lasd::List<double> lst;

        for(unsigned long i=0;i<200;i++){
            lst.Insert(dist(gen));
        }
        cout<<"Hash Table create da traversable container con e senza dimensione in input: "<<endl;
        lasd::HashTableOpnAdr<double> htTravCon1(lst);
        lasd::HashTableOpnAdr<double> htTravCon2(500,lst);

        cout << ((htTravCon1 == htTravCon2) ? "Le due hashTable sono uguali" : "Le due hashTable sono diverse") << "!" << endl;

        lasd::HashTableOpnAdr<double> htTravCon3(130,lst);
        cout << ((htTravCon1 == htTravCon3) ? "Le due hashTable sono uguali" : "Le due hashTable sono diverse") << "!" << endl;

        lasd::HashTableOpnAdr<double> htTravCon4(50,lst);
        cout << ((htTravCon4 == htTravCon1) ? "Le due hashTable sono uguali" : "Le due hashTable sono diverse") << "!" << endl;

        lasd::List<double> lst2(lst);
        lasd::List<double> lst3(lst);
        cout<<"Hash Table create da mappable container con e senza dimensione in input: "<<endl;
        lasd::HashTableOpnAdr<double> htMapCon1(move(lst));
        lasd::HashTableOpnAdr<double> htMapCon2(500,move(lst2));
        lasd::HashTableOpnAdr<double> htMapCon3(30,move(lst3));

        cout << ((htMapCon1 != htMapCon2) ? "Le due hashTable sono diverse" : "Le due hashTable sono uguali") << "!" << endl;
        cout << ((htMapCon3 != htMapCon2) ? "Le due hashTable sono diverse" : "Le due hashTable sono uguali") << "!" << endl;

        cout<<"Hash Table create da copy e move constructor: "<<endl;

        lasd::HashTableOpnAdr<double> htCopy(htMapCon1);
        cout << ((htCopy == htMapCon1) ? "Le due hashTable sono uguali" : "Le due hashTable sono diverse") << "!" << endl;

        lasd::HashTableOpnAdr<double> htMove(move(htMapCon1));
        cout << ((htCopy == htMove) ? "Le due hashTable sono uguali" : "Le due hashTable sono diverse") << "!" << endl;

        cout<<"Hash Table con copy e move assignment: "<<endl;

        htDef=htCopy;
        ht1=move(htMove);

        cout << ((htDef == ht1) ? "Le due hashTable sono uguali" : "Le due hashTable sono diverse") << "!" << endl;


        cout<<"Size (pre-Resize): "<<ht1.Size()<<endl;
        ht1.Resize(300);
        cout<<"Size (post prima Resize): "<<ht1.Size()<<endl;
        ht1.Resize(10);
        cout<<"Size (post seconda Resize): "<<ht1.Size()<<endl;
        ht1.Resize(0);
        cout<<"Size (post Resize a 0(Clear)): "<<ht1.Size()<<endl;

        lst.Clear();

        for (unsigned long i = 0; i < 10; i++)
        {
            lst.Insert(dist(gen));
        }

        cout << ((ht1.InsertAll(lst)) ? "Sono stati inseriti tutti i valori presenti in list" : "Non sono stati inseriti tutti i valori presenti in list") << "!" << endl;
        cout<<"Size: "<<ht1.Size()<<endl;
        lst.Clear();

        for (unsigned long i = 0; i < 10; i++)
        {
            lst.Insert(dist(gen));
        }

        cout << ((ht1.InsertAll(move(lst))) ? "Sono stati inseriti tutti i valori presenti in list" : "Non sono stati inseriti tutti i valori presenti in list") << "!" << endl;
        cout<<"Size: "<<ht1.Size()<<endl;

        lst.Clear();

        for (unsigned long i = 0; i < 200; i++)
        {
            lst.Insert(dist(gen));
        }

        cout << ((ht1.RemoveAll(lst)) ? "Sono stati rimossi tutti i valori presenti in list" : "Non sono stati rimossi tutti i valori presenti in list") << "!" << endl;
        cout<<"Size: "<<ht1.Size()<<endl;

        lst.Clear();

        for (unsigned long i = 0; i < 10; i++)
        {
            lst.Insert(dist(gen));
        }
        cout << ((ht1.InsertSome(lst)) ? "E' stato inserito almeno un valore presente in list" : "Non è stato inserito nessun valore presente in list") << "!" << endl;

        cout<<"Size: "<<ht1.Size()<<endl;

        lst.Clear();

        for (unsigned long i = 0; i < 10; i++)
        {
            lst.Insert(dist(gen));
        }
        cout << ((ht1.InsertSome(move(lst))) ? "E' stato inserito almeno un valore presente in list" : "Non è stato inserito nessun valore presente in list") << "!" << endl;
        cout<<"Size: "<<ht1.Size()<<endl;

        

        for (unsigned long i = 0; i < 500; i++)
        {
            lst.Insert(dist(gen));
        }
        cout << ((ht1.RemoveSome(lst)) ? "E' stato rimosso almeno un valore presente in list" : "Non è stato rimosso nessun valore presente in list") << "!" << endl;

        cout<<"Size: "<<ht1.Size()<<endl;


    }
}

#endif