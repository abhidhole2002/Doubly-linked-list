#include<iostream>
using namespace std;

class dlist
{
    int data;
    dlist* head = NULL;
    dlist* prev = NULL;
    dlist* next = NULL;

    public:

    /*dlist(int data)
    {
        data = data;
        head = NULL;
        prev = NULL;
        next = NULL;
    }*/

    void addtail(int x)
    {
        dlist* newn = new dlist();
        newn->data = x;
        newn->next = NULL;
        newn->prev = NULL;

        if(head == NULL)
        {
            head = newn;
            newn->next = NULL;
            newn->prev = NULL;
        }

        else
        {
            dlist* temp;
            
            for(temp = head;temp->next!=NULL;temp = temp->next){}
            newn->prev = temp;
            newn->next = NULL;
            temp->next = newn;
        }
    }

    void delhead()
    {
        dlist* temp = head;
        if(head == NULL)
        {
            cout<<"0 node present ";
            return;
        }

        if(head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }

        head = head->next;
        head->prev = NULL;
        delete temp;
        temp = NULL;
    }

    void deltail()
    {
        dlist* temp = head;
        for(;temp->next->next!=NULL;temp = temp->next){}

        dlist* node = temp->next;
        temp->next = NULL;
        delete node;
        node = NULL;
    }

    void print()
    {
        dlist* temp;

        for(temp = head;temp!=NULL;temp = temp->next)
        {
            cout<<temp->data<<" ";
        }
    }
};
 
int main()
{
    dlist* obj = new dlist();

    obj->addtail(1);
    obj->addtail(2);
    obj->addtail(3);
    obj->addtail(4);
    obj->addtail(5);
    obj->delhead();
    obj->deltail();
    obj->print();
    

}
