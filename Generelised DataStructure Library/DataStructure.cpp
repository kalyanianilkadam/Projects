///////////////////////////////////////////
//
// Gernerlised Data Structure Library
//
/////////////////////////////////////////


/*
-----------------------------------------------------------------------------------------------------
Type                        Name of class for node                  Name of class for Functionality           
-----------------------------------------------------------------------------------------------------
Singly Linear               SinglyLLLnode                           SinglyLLL           Done
Singly Circular             SinglyCLLnode                           SinglyCLL           Done
Doubly Linear               DoublyLLLnode                           DoublyLLL           Done
Doubly Circular             DoublyCLLnode                           DoublyCLL           Done
Stack                       Stacknode                               Stack               Done
Queue                       Queuenode                               Queue               Done
-----------------------------------------------------------------------------------------------------

*/

#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////
//
//  Singly Linear Linkeslist using Generic Approch
//
///////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class SinglyLLLnode
{
    public:
        T data;
        SinglyLLLnode <T> * next;

        SinglyLLLnode(T no)
        {
           this-> data = no;
           this-> next = NULL;
        }
};

template <class T>
class SinglyLLL
{
    private:        
        SinglyLLLnode <T> * first;                    
        int iCount;

    public:
        SinglyLLL();
        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T,int);
        void DeleteAtPos(int);
};

template <class T>
SinglyLLL<T> :: SinglyLLL()
{
    cout<<"Object of singlyLLL gets created.\n";
    this-> first = NULL;
    this-> iCount = 0;
}


///////////////////////////////////////////////////////////////////////////////
// 
//  Function Name:      InsertFirst
//  Input:              Data of Node
//  Output:             Nothing
//  Description:        Used to insert node at first position
//  Author:             Kalyani Anil Kadam
//  Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: InsertFirst(T no)
{
    SinglyLLLnode <T> * newn = NULL;

    newn = new SinglyLLLnode<T>(no);
    
    newn -> next = this-> first;
    this-> first = newn ;
    
    this-> iCount++;
}

///////////////////////////////////////////////////////////////////////////////
// 
//  Function Name:      InsertLast
//  Input:              Data of Node
//  Output:             Nothing
//  Description:        Used to insert node at last position
//  Author:             Kalyani Anil Kadam
//  Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: InsertLast(T no)
{
    SinglyLLLnode<T> * newn = NULL;
    SinglyLLLnode<T> * temp = NULL;

    newn = new SinglyLLLnode<T>(no);

    if(this-> iCount == 0)                             
    {
        this-> first = newn;
    }
    else
    {
        temp = this-> first;
        
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
        
    }
    this-> iCount++;
}

///////////////////////////////////////////////////////////////////////////////
// 
//  Function Name:      DeleteFirst
//  Input:              Nothing
//  Output:             void
//  Description:        Used to Delete node at first position
//  Author:             Kalyani Anil Kadam
//  Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: DeleteFirst()
{
        SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if( this->first -> next == NULL)                 
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        this->first = this->first -> next;
        delete temp;
    
    }
    this->iCount--;
}

///////////////////////////////////////////////////////////////////////////////
// 
//  Function Name:      DeleteLast
//  Input:              Nothing
//  Output:             Void
//  Description:        Used to delete node at last position
//  Author:             Kalyani Anil Kadam
//  Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL <T>:: DeleteLast()
{
        SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if( this->first -> next == NULL)                 
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;
        while(temp -> next -> next != NULL)
        {
            temp = temp-> next; 
        }
            delete temp -> next;
            temp-> next = NULL;
    }
    this->iCount--;
}

///////////////////////////////////////////////////////////////////////////////
// 
//  Function Name:      Display
//  Input:              Data of Node
//  Output:             Nothing
//  Description:        Used to Display node
//  Author:             Kalyani Anil Kadam
//  Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: Display()
{
    SinglyLLLnode <T>* temp = NULL;
    int iCnt = 0;
        
    temp =this-> first;
    for(iCnt = 1; iCnt <= this->iCount;iCnt++)                    
    {
        cout<<"| "<<temp -> data<<" |->";
        temp = temp -> next;
    }
    cout<<"NULL \n";
}

///////////////////////////////////////////////////////////////////////////////
// 
//  Function Name:      Count
//  Input:              Nothing
//  Output:             Number of nodes
//  Description:        Used to Count Number of Nodes
//  Author:             Kalyani Anil Kadam
//  Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyLLL<T> :: Count()
{
    return this->iCount;
}


///////////////////////////////////////////////////////////////////////////////
// 
//  Function Name:      InsertAtPos
//  Input:              Data of Node, position of node
//  Output:             Nothing
//  Description:        Used to insert node at any position
//  Author:             Kalyani Anil Kadam
//  Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: InsertAtPos(T no, int pos)
{
        SinglyLLLnode <T>* temp = NULL;
        SinglyLLLnode <T>* newn = NULL;

    int iCnt = 0;
    if((pos<1)||(pos> this->iCount+1))
    {
        cout<<"Invalid POsition";
        return;
    }

    if(pos == 1)
    {
        this-> InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
            newn = new SinglyLLLnode<T>(no);
        
        temp = this->first;

        for(iCnt = 1; iCnt < pos -1; iCnt++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next = newn;
        this->iCount++;
    }
}

///////////////////////////////////////////////////////////////////////////////
// 
//  Function Name:      DeleteAtPos
//  Input:              Position of node
//  Output:             void
//  Description:        Used to delete node at any position
//  Author:             Kalyani Anil Kadam
//  Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: DeleteAtPos(int pos)
{
        SinglyLLLnode<T>* temp = NULL;
        SinglyLLLnode<T> * target = NULL;

    int iCnt = 0;
    if((pos<1)||(pos> this->iCount))
    {
        cout<<"Invalid POsition";
        return;
    }

    if(pos == 1)
    {
        this-> DeleteFirst();
    }
    else if(pos == iCount)
    {
        this->DeleteLast();
    }
    else
    {
    
        temp = this->first;

        for(iCnt = 1; iCnt < pos -1; iCnt++)
        {
            temp = temp -> next;
        }
        target =temp -> next ;
        temp -> next = target ->next;
        delete target;
        this->iCount--;
    }
}

///////////////////////////////////////////////////////////////////
//
//  Doubly Linear Linkeslist using Generic Approch
//
///////////////////////////////////////////////////////////////////

#pragma pack(1)

template <class T>
class DoublyLLLnode
{
    public:
        T data;
        DoublyLLLnode* next;
        DoublyLLLnode* prev;

         DoublyLLLnode(T no)
         {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
         }
};

template <class T>
class DoublyLLL
{
    private:   
         DoublyLLLnode<T> * first;
        int iCount;

    public:
        DoublyLLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

template <class T>
DoublyLLL<T> :: DoublyLLL()
{
    cout<<"Linked List Gets created\n";

    this->first = NULL;
    this->iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////
// 
//  Function Name:      InsertFirst
//  Input:              Data of Node
//  Output:             Nothing
//  Description:        Used to insert node at first position
//  Author:             Kalyani Anil Kadam
//  Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////


template <class T>
void DoublyLLL<T> :: InsertFirst(T no)
{
     DoublyLLLnode<T> * newn = NULL;

    newn = new  DoublyLLLnode<T>(no);

    if(this-> first == NULL)
    {
        first = newn;
    }
    else
    {
        newn -> next = this->first;
        this->first -> prev = newn;
        this->first = newn;
    }
    this->iCount++;
}

///////////////////////////////////////////////////////////////////////////////
// 
//  Function Name:      InsertLast
//  Input:              Data of Node
//  Output:             Nothing
//  Description:        Used to insert node at last position
//  Author:             Kalyani Anil Kadam
//  Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: InsertLast(T no)
{
     DoublyLLLnode<T> * newn = NULL;
     DoublyLLLnode<T> * temp = NULL;

    newn = new  DoublyLLLnode<T>(no);

    if(this-> first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = this->first;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
        newn -> prev = temp;
    }
    this->iCount++;
}


///////////////////////////////////////////////////////////////////////////////
// 
//  Function Name:      InsertAtPos
//  Input:              Data of Node, Position of node
//  Output:             Nothing
//  Description:        Used to insert node at any position
//  Author:             Kalyani Anil Kadam
//  Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////

template <class T>
void  DoublyLLL<T> :: InsertAtPos(T no, int pos)
{
    DoublyLLLnode<T> * newn = NULL;
    DoublyLLLnode<T> * temp = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > this->iCount+1)
    {
        cout<<"Invalid Position";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if( pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new DoublyLLLnode<T>(no);

        temp = this-> first;

        for( iCnt =1; iCnt< pos -1 ; iCnt++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp-> next-> prev = newn;
        temp ->next = newn;
        newn->prev = temp;
        this->iCount++;
    }

}

///////////////////////////////////////////////////////////////////////////////
// 
//  Function Name:      DeleteFirst
//  Input:              Nothing
//  Output:             Void
//  Description:        Used to Delete node at first position
//  Author:             Kalyani Anil Kadam
//  Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL <T>:: DeleteFirst()
{
    if(this->first == NULL)                             
    {
        return;
    }    
    else if(this->first->next == NULL)              
    {
        delete this->first;
        this->first = NULL;
    }
    else                                                
    {

        this->first = this->first->next;
        delete this->first->prev;
        this->first->prev = NULL;
    }
    this->iCount--;
    
}

///////////////////////////////////////////////////////////////////////////////
// 
//  Function Name:      DeleteLast
//  Input:              Nothing
//  Output:             void
//  Description:        Used to delete node at last position
//  Author:             Kalyani Anil Kadam
//  Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL <T>:: DeleteLast()
{
    DoublyLLLnode<T> * temp = NULL;

    if(this->first == NULL)                             
    {
        return;
    }    
    else if(this->first->next == NULL)                 
    {
        delete this->first;
        this->first = NULL;
    }
    else                                               
    {
        temp= this->first;

        while(temp ->next->next != NULL)
        {
            temp = temp -> next;
        }
        delete temp -> next;
        temp -> next = NULL;
    }
    this->iCount--;
}

///////////////////////////////////////////////////////////////////////////////
// 
//  Function Name:      DeleteAtPos
//  Input:              Position of the node
//  Output:             Nothing
//  Description:        Used to delete node at any position
//  Author:             Kalyani Anil Kadam
//  Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL <T>::DeleteAtPos(int pos)
{
    DoublyLLLnode<T> * temp = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid Position";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if( pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = this-> first;

        for( iCnt =1; iCnt< pos -1 ; iCnt++)
        {
            temp = temp -> next;
        }
        temp-> next = temp-> next->next;
        delete temp->next->prev;
        temp->next -> prev = temp;
        this->iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////
// 
//  Function Name:      Display
//  Input:              Data of Node
//  Output:             Nothing
//  Description:        Used to Display node
//  Author:             Kalyani Anil Kadam
//  Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL <T>:: Display()
{
    DoublyLLLnode <T>* temp = NULL;

    temp = this->first;

    cout<<"\nNULL<=>";
    while(temp != NULL)
    {
        cout<<"|"<<temp -> data<<"|<=>";
        temp = temp->next;
    }
    cout<<"NULL \n";
}

//////////////////////////////////////////////////////////////////////////////
// 
//  Function Name:      Count
//  Input:              Nothing
//  Output:             Number of nodes
//  Description:        Used to Count Number of Nodes
//  Author:             Kalyani Anil Kadam
//  Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyLLL<T> ::Count()
{
    return this->iCount;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Singly Circular Linkeslist using Generic Approch
//
///////////////////////////////////////////////////////////////////////////////

#pragma pack(1)

template<class T>
class SinglyCLLnode 
{
    public:
        T data;
        SinglyCLLnode * next;
        
        SinglyCLLnode (T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class SinglyCLL
{
    private:
        SinglyCLLnode <T>* first;
        SinglyCLLnode <T>* last;
        int iCount; 

    public:
        SinglyCLL();
        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T, int);
        void DeleteAtPos(int);

};

template<class T>
SinglyCLL<T> ::SinglyCLL()
{
    cout<<"Linked List Gets created\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}


///////////////////////////////////////////////////////////////////////////////
// 
//  Function Name:      InsertFirst
//  Input:              Data of Node
//  Output:             Nothing
//  Description:        Used to insert node at first position
//  Author:             Kalyani Anil Kadam
//  Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: InsertFirst(T no)
{
    SinglyCLLnode <T>* newn = NULL;

    newn = new SinglyCLLnode <T>(no);
   
    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn -> next = this->first;
        this->first = newn;
    }
    this->last-> next = this->first;
    this->iCount++;
}

///////////////////////////////////////////////////////////////////////////////
// 
//  Function Name:      InsertLast
//  Input:              Data of Node
//  Output:             Nothing
//  Description:        Used to insert node at last position
//  Author:             Kalyani Anil Kadam
//  Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL <T>:: InsertLast(T no)
{
    SinglyCLLnode <T>* newn = NULL;

    newn = new SinglyCLLnode <T>(no);
  
    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last-> next = newn;
        this->last = newn;
    }
    this->last-> next = this->first;
    this->iCount++;

}

///////////////////////////////////////////////////////////////////////////////
// 
//  Function Name:      DeleteFirst
//  Input:              Nothing
//  Output:             Void
//  Description:        Used to Delete node at first position
//  Author:             Kalyani Anil Kadam
//  Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL <T>:: DeleteFirst()
{
    SinglyCLLnode <T>* temp = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;

        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp =this->first;

        this->first = this->first -> next;
            delete temp;
        this->last-> next = this->first;
        this->iCount--;
    }  
}

///////////////////////////////////////////////////////////////////////////////
// 
//  Function Name:      DeleteLast
//  Input:              Nothing
//  Output:             void
//  Description:        Used to delete node at last position
//  Author:             Kalyani Anil Kadam
//  Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL <T>:: DeleteLast()
{
    SinglyCLLnode <T>* temp = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;

        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp =this->first;

        while(temp -> next != this->last)
        {
            temp = temp ->next;
        }
        delete this->last;
        this->last = temp;
        this->last->next = this->first;
        this->iCount--;
    }  
}

///////////////////////////////////////////////////////////////////////////////
// 
//  Function Name:      Display
//  Input:              Data of Node
//  Output:             Nothing
//  Description:        Used to Display node
//  Author:             Kalyani Anil Kadam
//  Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL <T>:: Display()
{
    SinglyCLLnode <T>* temp = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"empty linkedlist";
        return;
    }

    temp = this->first;
    do 
    {
        cout<<"|"<<temp ->data<<"|<=>";
        temp = temp->next;
    }while(temp != last -> next);

    cout<<"\n";
}

//////////////////////////////////////////////////////////////////////////////
// 
//  Function Name:      Count
//  Input:              Nothing
//  Output:             Number of nodes
//  Description:        Used to Count Number of Nodes
//  Author:             Kalyani Anil Kadam
//  Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyCLL<T> :: Count()
{
    return iCount;
}


///////////////////////////////////////////////////////////////////////////////
// 
//  Function Name:      InsertAtPos
//  Input:              Data of Node, Position of node
//  Output:             Nothing
//  Description:        Used to insert node at any position
//  Author:             Kalyani Anil Kadam
//  Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL <T>:: InsertAtPos(T no, int pos)
{
    SinglyCLLnode <T>* temp = NULL;
    SinglyCLLnode <T>* newn = NULL;
    int iCnt = 0;

    if((pos <1) || (pos > iCount+1))
    {
        cout<<"Invalid Position";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new SinglyCLLnode <T>(no);

        temp = this->first;
        
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next = newn;
        this->iCount++;
    }

}

///////////////////////////////////////////////////////////////////////////////
// 
//  Function Name:      DeleteAtPos
//  Input:              Position of the node
//  Output:             Nothing
//  Description:        Used to delete node at any position
//  Author:             Kalyani Anil Kadam
//  Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: DeleteAtPos(int pos)
{
    SinglyCLLnode <T>* target = NULL;
    SinglyCLLnode <T>* temp = NULL;

    int iCnt = 0;

    if((pos <1) || (pos > iCount))
    {
        cout<<"Invalid Position";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = this->first;
        
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp -> next;
        }
        target = temp -> next;

        temp -> next = target -> next;
        delete target;
        this->iCount--;
    }
}

///////////////////////////////////////////////////////////////////
//
//  Doubly Circular Linkeslist using Generic Approch
//
///////////////////////////////////////////////////////////////////

#pragma pack(1)

template<class T>
class DoublyCLLnode
{
    public:
        T data ;
        DoublyCLLnode * next;
        DoublyCLLnode * prev;

        DoublyCLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template<class T>
class DoublyCLL
{
    private:
        DoublyCLLnode<T>* first;
        DoublyCLLnode<T>* last;
        int iCount;

    public:

        DoublyCLL();
        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T,int);
        void DeleteAtPos(int);
};

template<class T>
DoublyCLL<T> :: DoublyCLL()
{
    cout<<"Linked List Gets created\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////
// 
//  Function Name:      InsertFirst
//  Input:              Data of Node
//  Output:             Nothing
//  Description:        Used to insert node at first position
//  Author:             Kalyani Anil Kadam
//  Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: InsertFirst(T no)
{
    DoublyCLLnode<T>* newn = NULL;

    newn = new DoublyCLLnode<T>(no);
    
    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn -> next = this->first;
        this->first -> prev = newn;
        this->first = newn;
    }
    this->last -> next = this->first;
    this->first -> prev = this->last;
    this->iCount++;
}

///////////////////////////////////////////////////////////////////////////////
// 
//  Function Name:      InsertLast
//  Input:              Data of Node
//  Output:             Nothing
//  Description:        Used to insert node at last position
//  Author:             Kalyani Anil Kadam
//  Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: InsertLast(T no)
{
    DoublyCLLnode<T>* newn = NULL;

    newn = new DoublyCLLnode<T>(no);
    
    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last -> next = newn;
        newn -> prev = this->last;
        this->last = newn;
    }
    this->last -> next = this->first;
    this->first -> prev = this->last;
    this->iCount++;
}

///////////////////////////////////////////////////////////////////////////////
// 
//  Function Name:      DeleteFirst
//  Input:              Nothing
//  Output:             Void
//  Description:        Used to Delete node at first position
//  Author:             Kalyani Anil Kadam
//  Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: DeleteFirst()
{
    DoublyCLLnode<T>* temp = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        return;
        
    }
    else if(this->first == this->last)
    {
        delete this->first;

        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;

        this->first = this->first -> next;
        delete temp;
        this->last -> next = this->first;
        this->first -> prev = last;
    }
    this->iCount--;

}

///////////////////////////////////////////////////////////////////////////////
// 
//  Function Name:      DeleteLast
//  Input:              Nothing
//  Output:             void
//  Description:        Used to delete node at last position
//  Author:             Kalyani Anil Kadam
//  Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: DeleteLast()
{
    DoublyCLLnode<T>* temp = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;

        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->last;

        this->last = this->last -> prev;
        delete temp;
        this->last -> next = this->first;
        this->first -> prev = this->last;
    }
    this->iCount--;
}

///////////////////////////////////////////////////////////////////////////////
// 
//  Function Name:      Display
//  Input:              Data of Node
//  Output:             Nothing
//  Description:        Used to Display node
//  Author:             Kalyani Anil Kadam
//  Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: Display()
{
    DoublyCLLnode<T>* temp =NULL;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"empty linkedlist";
        return;
    }

    temp = this->first;
    do
    {
        cout<<"|"<<temp->data<<"|<=>";
        temp = temp -> next;
    }while(temp != last ->next);

    cout<<"\n";

}

//////////////////////////////////////////////////////////////////////////////
// 
//  Function Name:      Count
//  Input:              Nothing
//  Output:             Number of nodes
//  Description:        Used to Count Number of Nodes
//  Author:             Kalyani Anil Kadam
//  Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyCLL<T> :: Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////////////
// 
//  Function Name:      InsertAtPos
//  Input:              Data of Node, Position of node
//  Output:             Nothing
//  Description:        Used to insert node at any position
//  Author:             Kalyani Anil Kadam
//  Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: InsertAtPos(T no, int pos)
{
    DoublyCLLnode<T>* newn = NULL;
    DoublyCLLnode<T>* temp = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid Position";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new DoublyCLLnode<T>(no);
        
        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp ->next;
        }
        newn -> next = temp -> next;
        temp -> next -> prev = newn;
        temp -> next = newn;
        newn -> prev = temp;
        this->iCount++;
    }
}

///////////////////////////////////////////////////////////////////////////////
// 
//  Function Name:      DeleteAtPos
//  Input:              Position of the node
//  Output:             Nothing
//  Description:        Used to delete node at any position
//  Author:             Kalyani Anil Kadam
//  Date:               06/01/2026
//
///////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: DeleteAtPos(int pos)
{
    DoublyCLLnode<T>* temp = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid Position";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp ->next;
        }
        temp -> next = temp -> next-> next;
        delete temp -> next -> prev;
        temp -> next -> prev = temp;
        this->iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Stack  using Generic Approch
//
///////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class Stacknode
{
    public:
        T data;
        Stacknode<T> *next;

        Stacknode(T no)
        {
            this->data = no;
            this-> next = NULL;
        }
};

template <class T>
class Stack
{
    private:
        Stacknode<T> * first;
        int iCount;

    public:
        Stack();
        void push(T);                                 
        T pop();                                      
        T peep();
        void Display();
        int Count();
};

template <class T>
Stack<T>::Stack()
{
    cout<<"Stack Gets Created Successfully....\n";
    this->first = NULL;
    this->iCount = 0;
}

template <class T>
void Stack<T> :: push(T no)
{
   Stacknode<T> *newn = NULL;

   newn = new Stacknode<T>(no);

   newn ->next = this->first;
   this->first = newn;
   this->iCount++;
   
}

template <class T>
T Stack<T> :: pop()
{
    T Value = 0;
    Stacknode <T>* temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is Empty\n";
        return -1;
    }

    Value = this->first->data;

    this->first= this->first->next;
    delete temp;

    this ->iCount--;
    return Value;

}   

template <class T>
T Stack<T> :: peep()
{
    T Value = 0;

    if(this->first == NULL)
    {
        cout<<"Stack is Empty\n";
        return -1;
    }

    Value = this->first->data;

    return Value;
}

template <class T>
void Stack<T> :: Display()
{
    Stacknode<T> *temp = this->first;
    if(this->first == NULL)
    {
        cout<<"Stack is empty";
        return;
    }

    while(temp!= NULL)
    {
        cout<<"|\t"<<temp ->data<<"\t|\n";
        temp = temp->next;
    }

}

template <class T>
int Stack<T> :: Count()
{
    return this->iCount;
}

///////////////////////////////////////// End Of Library///////////////////////////////////////


int main()
{
    SinglyLLL<int> *obj = new SinglyLLL<int>();
    int iRet = 0;

    obj->InsertFirst(51);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";
 
    obj->InsertLast(101);
    obj->InsertLast(111);
    obj->InsertLast(121);

    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";
 
    obj->DeleteFirst();

    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

    obj->DeleteLast();
    
    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

    obj->InsertAtPos(105,4);

    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

    obj->DeleteAtPos(4);

    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

    delete obj;

////////////////////////////////////////////////////////////////////////////////////

    DoublyLLL<char> *dobj = new DoublyLLL<char>();
    
    dobj->InsertFirst('A');
    dobj->InsertFirst('B');
    dobj->InsertFirst('C');

    dobj->Display();
    cout<<"Number of nodes :"<<dobj->Count()<<"\n";

    dobj->InsertLast('X');
    dobj->InsertLast('Y');
    dobj->InsertLast('Z');

    dobj->Display();
    cout<<"Number of nodes :"<<dobj->Count()<<"\n";

    dobj->DeleteFirst();

    dobj->Display();
    cout<<"Number of nodes :"<<dobj->Count()<<"\n";

    dobj->DeleteLast();

    dobj->Display();
    cout<<"Number of nodes :"<<dobj->Count()<<"\n";

    dobj->InsertAtPos('$',2);

    dobj->Display();
    cout<<"Number of nodes :"<<dobj->Count()<<"\n";

    dobj->DeleteAtPos(2);

    dobj->Display();
    cout<<"Number of nodes :"<<dobj->Count()<<"\n";

    delete dobj;

 ////////////////////////////////////////////////////////////////////////////////////////

    SinglyCLL <int>* Sobj = new SinglyCLL<int>();
    
    Sobj->InsertFirst(51);
    Sobj->InsertFirst(21);
    Sobj->InsertFirst(11);

    Sobj->Display();
    cout<<"Number of nodes are:"<<Sobj->Count()<<"\n";

    Sobj->InsertLast(101);

    Sobj->Display();
    cout<<"Number of nodes are:"<<Sobj->Count()<<"\n";

    Sobj->DeleteFirst();

    Sobj->Display();
    cout<<"Number of nodes are:"<<Sobj->Count()<<"\n";

    Sobj->DeleteLast();

    Sobj->Display();
    cout<<"Number of nodes are:"<<Sobj->Count()<<"\n";

    Sobj->InsertAtPos(35,2);

    Sobj->Display();
    cout<<"Number of nodes are:"<<Sobj->Count()<<"\n";

    Sobj->DeleteAtPos(2);

    Sobj->Display();
    cout<<"Number of nodes are:"<<Sobj->Count()<<"\n";

    delete Sobj;

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////

    DoublyCLL<int> *dcobj = new DoublyCLL<int>();
    
    dcobj->InsertFirst(111);
    dcobj->InsertFirst(101);    
    dcobj->InsertFirst(51);
    dcobj->InsertFirst(21);
    dcobj->InsertFirst(11);

    dcobj->Display();
    cout<<"Number of nodes are:"<< dcobj->Count()<<"\n";

    dcobj->InsertLast(151);

    dcobj->Display();
    cout<<"Number of nodes are:"<< dcobj->Count()<<"\n";

    dcobj->DeleteFirst();

    dcobj->Display();
    cout<<"Number of nodes are:"<< dcobj->Count()<<"\n";

    dcobj->DeleteLast();

    dcobj->Display();
    cout<<"Number of nodes are:"<< dcobj->Count()<<"\n";

    dcobj->InsertAtPos(45,3);

    dcobj->Display();
    cout<<"Number of nodes are:"<< dcobj->Count()<<"\n";

    dcobj->DeleteAtPos(3);

    dcobj->Display();
    cout<<"Number of nodes are:"<< dcobj->Count()<<"\n";

    delete dcobj;

    ///////////////////////////////////////////////////////////////////////////////////////////////////

    Stack <char>*sobj1 = new Stack<char>();

    sobj1->push('a');
    sobj1->push('b');
    sobj1->push('c');
    sobj1->push('d');

    sobj1->Display();
    cout<<"Number of elements in stack:"<<sobj1->Count()<<"\n";

    cout<<"Return value of peep is:"<<sobj1->peep()<<"\n";

    sobj1->Display();
    cout<<"Number of elements in stack:"<<sobj1->Count()<<"\n";

    cout<<"Poped element is:"<<sobj1->pop()<<"\n";

    sobj1->Display();
    cout<<"Number of elements in stack:"<<sobj1->Count()<<"\n";

    cout<<"Poped element is:"<<sobj1->pop()<<"\n";

    sobj1->Display();
    cout<<"Number of elements in stack:"<<sobj1->Count()<<"\n";

    sobj1->push('e');

    sobj1->Display();
    cout<<"Number of elements in stack:"<<sobj1->Count()<<"\n";

    delete sobj1;
    return 0;
}