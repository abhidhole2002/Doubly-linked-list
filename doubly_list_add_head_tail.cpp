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

    void addtail(int x)
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
            dlist* temp;

            for(temp = head;temp->next!=NULL;temp = temp->next){}
            newn->next = NULL;
            newn->prev = temp;
            temp->next = newn;
        }

    }

    void print()
    {
        dlist* temp;

        for(temp = head; temp!=NULL;temp = temp->next)
        {
            cout<<temp->data<<" ";
        }
    }

};
 
int main()
{
    dlist list(0);
    list.addhead(1);
    list.addhead(2);
    list.addhead(3);
    list.addhead(4);
    list.print();

    cout<<endl;

    list.addtail(1);
    list.addtail(2);
    list.addtail(3);
    list.addtail(4);
    list.print();

}