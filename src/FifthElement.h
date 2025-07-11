#ifndef FIFTHELEMENT_H
#define FIFTHELEMENT_H
#include "LinkedList.h"

//Ausha Homer

//template <class Type>


template <class Type>
class FifthElement : public LinkedList<Type>{

    public:

    Type getFifthElement(){

    Node<Type>* currentNode = front;

    if (count < 5 ){
    throw length_error("There is no fifth element");
    }else {
        for (int i =0; i < 4; i++){
        }
        return currentNode->data;}
    }

    void insertNewFifthElement(const Type &value){
       
        Node<Type>* temp = new Node<Type>();  
        temp->data = value;                   
        Node<Type>* currentNode = front;
        
        if(count < 4 ){
            throw length_error("There is not that many elements in this list");
        }

        for (int i = 0; i < 3; i++) {
            currentNode = currentNode->next;
            temp->next = currentNode->next;
            currentNode->next = temp;
        }

        if(temp->next == nullptr){
         back = temp;
        }
        count ++;
    }

}
/*
This method inserts a node containing a value between the existing 4 and 5 nodes 
so that the original 5th node becomes the 6th node in the list. If there are only 4 nodes in the list, the new node will become the last node in the list. 
*/

    protected: 


};


/*




*****

template<class Type>
void deleteFifthElement(){

}


;This method deletes the 5th node. If there was a 6th node, the 4th node now points to the 6th node. 
If there was no 6th node, the 4th node becomes the new back node. 
****

template<class Type>
void swapFourthAndFifthElement(){

}

; This method rearranges the 4th and 5th nodes. It cannot swap the data in the nodes, it instead must rearrange pointers.

*/

#endif // FIFTHELEMENT_H