#include<iostream>
using namespace std;
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

    void print()
    {
        dlist* temp;

        for(temp = head;temp!=NULL;temp = temp->next)
        {
            cout<<temp->data<<" ";
        }
    }


    void del_data(int x)
    {
        dlist* tmp = head;
        if (tmp->data == x)
        {
            head = head->next;
            head->prev = NULL;
            delete tmp;
            tmp = NULL;
            return;
        }

        dlist* temp = head;

        for(;temp != NULL;temp = temp->next)
        {
            if (temp->data == x)
            {
                dlist* node = temp;
                temp->prev->next = temp->next;
                if (temp->next != NULL)
                {
                    temp->next->prev = temp->prev;
                }

                delete node;
                return;
            }        
        }
    }

    void del_pos(int pos)
    {
        dlist* temp = head;
        if(pos == 1)
        {
            head = head->next;
            head->prev = NULL;
            delete temp;
            temp = NULL;
            return;
        }

        for(int i=1;i<pos-1;i++)
        {
            temp = temp->next;
        }

        dlist* node = temp->next;
        temp->next = temp->next->next;
        if(temp->next!=NULL)
        {
            temp->next->prev = temp;
        }
        delete node;
        node = NULL;
    }


};
 
int main()
{
    dlist* obj = new dlist();
    obj->addtail(100);
    obj->addtail(200);
    obj->addtail(300);
    obj->addtail(400);
    obj->print();
    cout<<endl;
    cout<<"AFTER DELETING NODE 100 = ";
    obj->del_data(100);
    obj->print();

    cout<<endl<<"AFTER DELETING NODE AT POSITION 4TH = ";
    obj->del_pos(3);
    obj->print();
 
 
}