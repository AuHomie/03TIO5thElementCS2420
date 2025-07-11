#ifndef FIFTHELEMENT_H
#define FIFTHELEMENT_H
#include "LinkedList.h"

//Ausha Homer
//template <class Type>


template <class Type>
class FifthElement : public LinkedList<Type>{

    public:

    Type getFifthElement(){

    Node<Type>* currentNode = this->front;

    if (this->count < 5 ){
    throw length_error("There is no fifth element");
    }else {
        for (int i =0; i < 4; i++){
        }
        return currentNode->data;}
    }

    void insertNewFifthElement(const Type &value){
       
        Node<Type>* temp = new Node<Type>();  
        temp->data = value; 
        Node<Type>* currentNode = this->front;

        if(this->count < 4 ){
            throw length_error("There is not that many elements in this list");
        }

        for (int i = 0; i < 3; i++) {
            currentNode = currentNode->next;
        }
            
            temp->next = currentNode->next;
            currentNode->next = temp;

        if(temp->next == nullptr){
         this->back = temp;
        }
        this->count ++;
    }

    void deleteFifthElement(){

        Node<Type>* currentNode = this->front;


        if (count < 5 ){
        throw length_error("There is no fifth element");
        }
        
        for (int i = 0; i < 3; i++) {
            currentNode = currentNode->next;
        }

       Node<Type>* toDelete = currentNode->next;
        if (toDelete->next == nullptr){
        this->back = currentNode;    
        }

        currentNode->next = toDelete->next;

        delete toDelete;

        this->count --;
    }
    
    void swapFourthAndFifthElement(){

        Node<Type>* currentNode = this->front;

        if (count < 5 ){
        throw length_error("There is no fifth element");
        }
        
        for (int i = 0; i < 2; i++) {
            currentNode = currentNode->next;
        }
        Node<Type>*third = currentNode;
        Node<Type>* fourth = third->next;
        Node<Type>* fifth = fourth->next;
        Node<Type>* sixth = fifth->next;
       
        third->next = fifth;
        fifth->next = fourth;
        fourth->next = sixth;

        if (fourth->next == nullptr){
            this->back = fourth;
        }
    }

};


#endif // FIFTHELEMENT_H