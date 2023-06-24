#include<iostream>
using namespace std;

class dlist
{
    int data;
    dlist* head;
    dlist* next;
    dlist* prev;

    public:

    dlist(int data)
    {
        this->data = data;
        this->head = NULL;
        this->next = NULL;
        this->prev = NULL;
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

    int nth_min_max(int x)
    {
        dlist* temp = head;
        dlist* curr = NULL;
        int count = 0;
        int min_max = 0;

        for(;temp!=NULL;temp = temp->next)
        {
            for(curr = temp->next;curr!=NULL;curr = curr->next)
            {
                if(temp->data > curr->data)
                {
                    int tdata = temp->data;
                    temp->data = curr->data;
                    curr->data = tdata;
                }
            }

            count++;

            if(count==x)
            {
                min_max = temp->data;
            }
        }

        return min_max;
    }

};
 
int main()
{
    dlist* list = new dlist(0);

    list->addtail(10);
    list->addtail(11);
    list->addtail(12);
    list->addtail(13);
    list->print();

    cout<<endl<<"min max = "<<list->nth_min_max(1);
    delete list;
    cout<<endl<<"This will give garbage value because object is deleted : ";
    list->print();
}