
/*FIND MID WITH 3 METHOD OF RETURN TYPE*/

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

    void mid()
    {

        dlist* slow = head;
        dlist* fast = head;
        dlist* temp = head;
        int c = 1;
        for(;temp->next!=NULL;temp = temp->next)
        {
            c++;
        }

        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        if(c%2==0)
        {
            cout<<slow->next->data;
        }
        else
        {
            cout<<slow->data;
        }
    }

    int mid1()
    {

        dlist* slow = head;
        dlist* fast = head;
        dlist* temp = head;
        int c = 1;
        for(;temp->next!=NULL;temp = temp->next)
        {
            c++;
        }

        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        if(c%2==0)
        {
            return slow->next->data;
        }
        else
        {
            return slow->data;
        }
    }


    dlist* mid2()
    {

        dlist* slow = head;
        dlist* fast = head;
        dlist* temp = head;
        int c = 1;
        for(;temp->next!=NULL;temp = temp->next)
        {
            c++;
        }

        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        if(c%2==0)
        {
            return slow->next;
        }
        else
        {
            return slow;
        }
    }

    int getdata()
    {
        return data;
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
    cout<<endl<<"MID OF LIST (INT RETURN TYPE ) = "<<list->mid1()<<endl;abhi

    cout<<endl<<"MID OF LIST (VOID RETURN TYPE ) = ";
    list->mid();

    cout<<endl<<"MID OF LIST (DLIST* RETURN TYPE ) = "<<list->mid2()->getdata();
    
    
}