#ifndef MYBINARYTREE_HPP
#define MYBINARYTREE_HPP
#include "../../binarytree/binarytree.hpp"
#include "../../binarytree/lnk/binarytreelnk.hpp"
#include "../../binarytree/vec/binarytreevec.hpp"
#include "../../container/container.hpp"
#include "../../container/mappable.hpp"
#include "../../zlasdtest/container/mappable.hpp"
#include "../../zlasdtest/container/traversable.hpp"
#include "../container.hpp"
#include <iostream>
#include <random>
using namespace std;
using namespace miotest;
namespace miotest{

    void testBinaryTree()
    {
        try
        {
            lasd::Vector<string> vec(13);
           
            vec[0]=string("A");
            vec[1]=string("B");
            vec[2]=string("C");
            vec[3]=string("D");
            vec[4]=string("E");
            vec[5]=string("F");
            vec[6]=string("G");
            vec[7]=string("H");
            lasd::BinaryTreeLnk<string> btlnk(vec);

            
            cout<<"btlnk"<<endl;
            MapPreOrder(btlnk, &MapPrint<string>);
            cout<<endl;
            MapInOrder(btlnk, &MapPrint<string>);
            cout<<endl;
            MapPostOrder(btlnk, &MapPrint<string>);
            cout<<endl;
            MapBreadth(btlnk, &MapPrint<string>);
            cout<<endl;
            lasd::BinaryTreeVec<string> btvec(move(vec));
            cout<<"btvec"<<endl;
            MapPreOrder(btvec, &MapPrint<string>);
            cout<<endl;
            MapInOrder(btvec, &MapPrint<string>);
            cout<<endl;
            MapPostOrder(btvec, &MapPrint<string>);
            cout<<endl;
            MapBreadth(btvec, &MapPrint<string>);
            btvec.Clear();
            vec[0]=string("A");
            vec[1]=string("B");
            vec[2]=string("C");
            vec[3]=string("D");
            vec[4]=string("E");
            vec[5]=string("F");
            vec[6]=string("G");
            vec[7]=string("H");
            vec[8]=string("I");
            lasd::BinaryTreeVec btvec2(vec);
            btvec=(move(btvec2));
            cout<<endl<<"btvec pt2"<<endl;
            MapBreadth(btvec, &MapPrint<string>);
            cout<<endl<<" breadth iterator"<<endl;
            lasd::BTBreadthMutableIterator<string> itr1(btlnk);
            while(!itr1.Terminated()){
                cout<<itr1.operator*()<<endl;
                ++itr1;
            }

            cout<<endl<<" post order iterator"<<endl;
            lasd::BTPostOrderMutableIterator<string> itr2(btlnk);
            while(!itr2.Terminated()){
                cout<<itr2.operator*()<<endl;
                ++itr2;
            }
            cout<<endl<<"pre order mutable iterator"<<endl;
            lasd::BTPreOrderMutableIterator<string> itr3(btlnk);
            while(!itr3.Terminated()){
                cout<<itr3.operator*()<<endl;
                ++itr3;
            }
            cout<<endl<<"in order mutable iterator"<<endl;
            lasd::BTInOrderMutableIterator<string> itr4(btlnk);
            while(!itr4.Terminated()){
                cout<<itr4.operator*()<<endl;
                ++itr4;
            }
            lasd::BTInOrderMutableIterator<string> itr5(itr4);
            itr5.Reset();
            cout<<endl<<"In Order Mutable iterator creato con una copy(primo elemento dopo il reset):"<<endl<<itr5.operator*()<<endl;
            lasd::BTPreOrderMutableIterator<string> itr6(move(itr3));
            itr6.Reset();
            cout<<"Pre Order Mutable Iterator creato con una move(primo elemento dopo il reset):"<<endl<<itr6.operator*()<<endl;

            cout << ((itr5==itr4) ? "I due iteratori sono uguali" : "I due iteratori sono diversi") << "!" << endl;
            cout << ((itr5!=itr4) ? "I due iteratori sono diversi" : "I due iteratori sono uguali") << "!" << endl;


            btlnk.Clear();
            lasd::BinaryTreeLnk<string> btlnk2;
            
             cout << ((btlnk==btlnk2) ? "I due alberi vuoti sono uguali" : "I due alberi vuoti sono diversi") << "!" << endl;
             cout << ((btlnk!=btlnk2) ? "I due alberi vuoti sono diversi" : "I due alberi vuoti sono uguali") << "!" << endl;


            lasd::Vector<double> vecd(10);
           
            default_random_engine gen(random_device{}());
            uniform_real_distribution<double> dist(1, 1000);
            for (unsigned long i = 0; i < 10; i++)
            {
                vecd[i]=dist(gen);
            }
            lasd::BinaryTreeLnk<double> btlnkd(vecd);

            
            
            lasd::BinaryTreeVec<double> btvecd(move(vecd));
           
            btvecd.Clear();
    
            lasd::BinaryTreeVec btvecd2(vecd);
            btvecd=(move(btvecd2));
            // MapBreadth(btvecd, &MapPrint<string>);
            cout<<endl<<" breadth iterator"<<endl;
            lasd::BTBreadthMutableIterator<double> itr1d(btlnkd);
            while(!itr1d.Terminated()){
                cout<<itr1d.operator*()<<endl;
                ++itr1d;
            }

            cout<<endl<<" post order iterator"<<endl;
            lasd::BTPostOrderMutableIterator<double> itr2d(btlnkd);
            while(!itr2d.Terminated()){
                cout<<itr2d.operator*()<<endl;
                ++itr2d;
            }
            cout<<endl<<"pre order mutable iterator"<<endl;
            lasd::BTPreOrderMutableIterator<double> itr3d(btlnkd);
            while(!itr3d.Terminated()){
                cout<<itr3d.operator*()<<endl;
                ++itr3d;
            }
            cout<<endl<<"in order mutable iterator"<<endl;
            lasd::BTInOrderMutableIterator<double> itr4d(btlnkd);
            while(!itr4d.Terminated()){
                cout<<itr4d.operator*()<<endl;
                ++itr4d;
            }
            lasd::BTPostOrderMutableIterator<double> itr5d=itr2d;
            itr5d.Reset();
            cout<<endl<<"Post Order Mutable iterator con una copy assignment(primo elemento dopo il reset):"<<endl<<itr5d.operator*()<<endl;
            lasd::BTBreadthMutableIterator<double> itr6d=move(itr1d);
            itr6d.Reset();
            cout<<"Breadth Mutable Iterator con una move assignment(primo elemento dopo il reset):"<<endl<<itr6d.operator*()<<endl;

            lasd::BinaryTreeLnk<double> btlnkd2;
            btlnkd2=btlnkd;
            cout << ((btlnkd==btlnkd2) ? "I due alberi sono uguali" : "I due alberi sono diversi") << "!" << endl;
            btlnkd=move(btlnkd2);
            btvecd2=btvecd;
            cout << ((btvecd2==btvecd) ? "I due alberi sono uguali" : "I due alberi sono diversi") << "!" << endl;


            
        }
        catch (exception &exc)
        {
            cout << exc.what() << endl;
        }
    }
}

#endif