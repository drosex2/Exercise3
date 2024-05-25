#ifndef MYHTCLSADR_HPP
#define MYHTCLSADR_HPP

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

    void testHashTableClosedAddressing()
    {
        unsigned long value,val;
        default_random_engine gen(random_device{}());
        uniform_int_distribution<int> dist(1, 1000);

        lasd::HashTableClsAdr<int> htDef;
        lasd::HashTableClsAdr<int> ht1(1000);
        cout << ((htDef == ht1) ? "Le due hashTable sono uguali" : "Le due hashTable sono diverse") << "!" << endl;
        lasd::BST<int> bst1;
        for (unsigned long i = 0; i <= 100; i++)
        {
            bst1.Insert(dist(gen));
        }

        lasd::HashTableClsAdr<int> htTravCon1(bst1);
        lasd::HashTableClsAdr<int> htTravCon2(50, bst1);

        cout << ((htTravCon1 == htTravCon2) ? "Le due hashTable sono uguali" : "Le due hashTable sono diverse") << "!" << endl;

        lasd::Vector<int> vec1(100);
        for (unsigned long i = 0; i < 100; i++)
        {
            vec1[i] = dist(gen);
        }
        lasd::Vector<int> vec2(vec1);

        lasd::HashTableClsAdr<int> htMapCon1(move(vec1));
        lasd::HashTableClsAdr<int> htMapCon2(50, move(vec2));

        cout << ((htMapCon1 == htMapCon2) ? "Le due hashTable sono uguali" : "Le due hashTable sono diverse") << "!" << endl;

        lasd::HashTableClsAdr<int> htCopy(htMapCon1);
        

        cout<<"Size: "<<htCopy.Size()<<endl;
        //cout<<"Size: "<<htMove.Size()<<endl;

        value = dist(gen);
        htCopy.Insert(value);
        
        cout<<"Size: "<<htCopy.Size()<<endl;
        val=value;
        htCopy.Insert(move(value));
        cout<<"Size: "<<htCopy.Size()<<endl;
        htCopy.Remove(val);
        cout<<"Size: "<<htCopy.Size()<<endl;

        lasd::HashTableClsAdr<int> htOpCopy;
        htOpCopy=htCopy;
        cout << ((htOpCopy == htCopy) ? "Le due hashTable sono uguali" : "Le due hashTable sono diverse") << "!" << endl;
        lasd::HashTableClsAdr<int> htOpMove;
        htOpMove=move(htCopy);
        cout << ((htOpMove == htOpCopy) ? "Le due hashTable sono uguali" : "Le due hashTable sono diverse") << "!" << endl;

        lasd::HashTableClsAdr<int> htMove(move(htOpCopy));
        cout << ((htOpMove == htMove) ? "Le due hashTable sono uguali" : "Le due hashTable sono diverse") << "!" << endl;


        lasd::List<int> list;
        for (unsigned long i = 0; i <= 10; i++)
        {
            list.Insert(dist(gen));
        }

        lasd::HashTableClsAdr<int> htDictionary;
        cout << ((htDictionary.InsertAll(list)) ? "Sono stati inseriti tutti i valori presenti in list" : "Non sono stati inseriti tutti i valori presenti in list") << "!" << endl;
        list.Clear();
        for (unsigned long i = 0; i <= 10; i++)
        {
            list.Insert(dist(gen));
        }

        cout << ((htDictionary.InsertAll(move(list))) ? "Sono stati inseriti tutti i valori presenti in list" : "Non sono stati inseriti tutti i valori presenti in list") << "!" << endl;
        for (unsigned long i = 0; i <= 10; i++)
        {
            list.Insert(dist(gen));
        }

        cout << ((htDictionary.RemoveAll(list)) ? "Sono stati rimossi tutti i valori presenti in list" : "Non sono stati rimossi tutti i valori presenti in list") << "!" << endl;
        cout<<"Size: "<<htDictionary.Size()<<endl;
        
        for (unsigned long i = 0; i <= 10; i++)
        {
            list.Insert(dist(gen));
        }

        cout << ((htDictionary.InsertSome(list)) ? "Sono stati inseriti alcuni valori presenti in list" : "Non è stato inserito alcun valore presente in list") << "!" << endl;
        cout<<"Size: "<<htDictionary.Size()<<endl;
        for (unsigned long i = 0; i <= 10; i++)
        {
            list.Insert(dist(gen));
        }

        cout << ((htDictionary.InsertSome(move(list))) ? "Sono stati inseriti alcuni valori presenti in list" : "Non è stato inserito alcun valore presente in list") << "!" << endl;
        cout<<"Size: "<<htDictionary.Size()<<endl;
        list.Clear();
        for (unsigned long i = 0; i <= 10; i++)
        {
            list.Insert(dist(gen));
        }

        cout << ((htDictionary.RemoveSome(list)) ? "Sono stati rimossi alcuni dei valori presenti in list" : "Non è stato rimosso alcun valore presente in list") << "!" << endl;
        cout<<"Size: "<<htDictionary.Size()<<endl;

        htDictionary.Resize(20);
        cout<<"Size (dopo la resize): "<<htDictionary.Size()<<endl;



    }
}

#endif