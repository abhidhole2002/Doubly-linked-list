#include<iostream>
using namespace std;

class dlist
{
    int data;
    dlist* head = NULL;
    dlist* next = NULL;
    dlist* prev = NULL;

    public:

    void addhead(int x)
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
            newn->prev = NULL;
            newn->next = head;
            head->prev = newn;
            head = newn;
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

    void reverse()
    {
        dlist* prev = NULL;
        dlist* curr = head;
        dlist* next = NULL;

        while(curr!=NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
    }

    int gethead()
    {
        return head->data;
    }

};

int main()
{
    dlist* list = new dlist();
    
    list->addhead(10);
    list->addhead(20);
    list->addhead(30);
    list->addhead(40);
    list->addhead(50);
    list->addhead(60);
    list->print();
    cout<<endl;

    list->reverse();
    list->print();
}