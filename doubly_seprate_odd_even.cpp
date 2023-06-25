#include<iostream>
using namespace std;

class dlist
{
    int data;
    dlist* head = NULL;
    dlist* next = NULL;
    dlist* prev = NULL;

    public:

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
            dlist* temp = head;

            for(;temp->next!=NULL;temp = temp->next){}
            newn->next = NULL;
            newn->prev = temp;
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

    void odd_even(dlist* odd,dlist* even)
    {
        dlist* temp = head;

        for(;temp!=NULL;temp = temp->next)
        {
            if(temp->data%2 == 0)
            {
                even->addtail(temp->data);
            }
            else
            {
                odd->addtail(temp->data);
            }
        }
    }

    void odd_even1(dlist& odd,dlist& even)
    {
        dlist* temp = head;

        for(;temp!=NULL;temp = temp->next)
        {
            if(temp->data%2 == 0)
            {
                even.addtail(temp->data);
            }
            else
            {
                odd.addtail(temp->data);
            }
        }
    }

    void odd_even2(dlist* odd,dlist* even)
    {
        dlist* temp = head;

        for(;temp!=NULL;temp = temp->next)
        {
            if(temp->data%2 == 0)
            {
                even->addtail(temp->data);
            }
            else
            {
                odd->addtail(temp->data);
            }
        }
    }

    void odd_even3(dlist* *odd,dlist* *even)
    {
        dlist* temp = head;

        for(;temp!=NULL;temp = temp->next)
        {
            if(temp->data%2 == 0)
            {
                (*even)->addtail(temp->data);
            }
            else
            {
                (*odd)->addtail(temp->data);
            }
        }
    }


    void odd_even4(dlist* &odd,dlist* &even)
    {
        dlist* temp = head;

        for(;temp!=NULL;temp = temp->next)
        {
            if(temp->data%2 == 0)
            {
                even->addtail(temp->data);
            }
            else
            {
                odd->addtail(temp->data);
            }
        }
    }

};
 
int main()
{
    dlist* list = new dlist();
    list->addtail(10);
    list->addtail(11);
    list->addtail(12);
    list->addtail(13);
    list->addtail(14);
    list->addtail(15);
    list->addtail(16);
    list->addtail(17);
    list->print();
    cout<<endl<<endl;

    dlist odd;
    dlist even;
    list->odd_even(&odd,&even);
    odd.print();
    cout<<endl;
    even.print();

    cout<<endl<<endl;

    dlist* odd1 = new dlist();
    dlist* even1 = new dlist();
    list->odd_even1(*odd1,*even1);
    odd1->print();
    cout<<endl;
    even1->print();  
    delete odd1;
    delete even1;
    cout<<endl<<endl;

    dlist odd2;
    dlist even2;
    list->odd_even2(&odd2,&even2);
    odd2.print();
    cout<<endl;
    even2.print();
    cout<<endl<<endl;

    dlist* odd3 = new dlist();
    dlist* even3 = new dlist();
    list->odd_even3(&odd3,&even3);
    odd3->print();
    cout<<endl;
    even3->print();
    delete odd3;
    delete even3;
    cout<<endl<<endl;

    dlist odd4;
    dlist even4;
    dlist* oddp = &odd4;
    dlist* evenp = &even4;
    list->odd_even4(oddp,evenp);
    odd4.print();
    cout<<endl;
    even4.print();

}