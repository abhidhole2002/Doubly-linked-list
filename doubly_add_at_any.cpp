#include<iostream>
using namespace std;

class dlist
{
    int data;
    dlist* head;
    dlist* prev;
    dlist* next;

    public:

    dlist(int data)
    {
        this->data = data;
        this->head = NULL;
        this->prev = NULL;
        this->next = NULL;
    }

    void addhead(int x)
    {
        dlist* newn = new dlist(x);
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
            newn->next = head;
            newn->prev = NULL;
            head->prev = newn;
            head = newn;

        }
    }

    void add_any_pos(int pos,int x)
    {
        dlist* newn = new dlist(x);
        newn->next = NULL;
        newn->prev = NULL;

        if(pos == 1)
        {
            addhead(x);
        }

        else
        {
            dlist* temp = head;

            for(int i=1;i<pos-1;i++)
            {
                temp = temp->next;
            }

            newn->next = temp->next;
            newn->prev = temp;
            temp->next = newn;
            if(newn->next!=NULL)
            {
                newn->next->prev = newn;
            }
        }

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
    dlist* obj = new dlist(0);
    obj->addhead(1);
    obj->addhead(2);
    obj->addhead(3);
    obj->addhead(4);
    obj->add_any_pos(5,100);
    obj->print();
    cout<<endl;

    delete obj;
    obj->addhead(1);
    obj->addhead(1);
    obj->addhead(1);
    obj->print();
    

}