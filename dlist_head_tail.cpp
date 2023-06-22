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

    void odd_even_one(dlist* odd,dlist* even)
    {
        for(dlist* temp = head;temp!=NULL;temp = temp->next)
        {
            if(temp->data%2==0)
            {
                even->addhead(temp->data);
            }
            else
            {
                odd->addhead(temp->data);
            }
        }
    }

    int gethead()
    {
        return head->data;
    }

    int gettail()
    {
        dlist* temp = head;
        for(;temp->next!=NULL;temp=temp->next){}
        return temp->data;
    }


    dlist* gethead1()
    {
        return head;
    }

    dlist* gettail1()
    {
        dlist* temp = head;
        for(;temp->next!=NULL;temp=temp->next){}
        return temp;
    }

    int getdata()
    {
        return data;
    }



    void gethead2()
    {
        cout<<head->data;
    }

    void gettail2(int& value)
    {

        dlist* temp = head;
        for (; temp->next != NULL; temp = temp->next) {}
        cout<<temp->data;
    
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

    dlist odd(0);
    dlist even(0);

    cout<<endl;

    list.odd_even_one(&odd,&even);
    odd.print();
    cout<<endl;
    even.print();
    
    cout<<endl;

    cout<<"head = "<<even.gethead()<<endl;
    cout<<"tail = "<<even.gettail()<<endl;

    cout<<"head = "<<even.gethead1()->getdata()<<endl;
    cout<<"tail = "<<even.gettail1()->getdata()<<endl;


odd.gethead2();
odd.gethead2();


}