#include <iostream>

using namespace std;


struct node {
    node *next;
    int data;
};

node *ptr=NULL;
node *head=NULL;

/*Code for creating new Node*/
int newNode(int data1)
{
    static int i=0;

    if(i==0) {

        head=new node;
        head->data=data1;
        head->next=ptr;
        cout<<head->data;
        ptr=head;
    } else {
        node *temp=NULL;
        temp=new node;
        temp->data=data1;
        temp->next=NULL;
        ptr->next=temp;
        ptr=ptr->next;
    }
    i++;
}

/*Code for Displaying elements on linklist*/
int display()
{
    node *pr=NULL;
    pr=head;
    while(pr!=NULL) {
        cout<<pr->data<<endl;
        pr=pr->next;

    }
    return 0;
}

/*Code for delete by value*/
int dbi(int i)
{
    int a=0;
    node* prev=NULL;
    node* next1=NULL;
    prev=head;
    if(i==0) {
        head=head->next;
    } else {
        for(a; a<i-1; a++) {
            prev=prev->next;
        }
        prev->next=prev->next->next;
    }
    return 0;
}

int dbv(int j)
{

    node *prev=NULL;
    node *next1=NULL;

    prev=head;
    next1=head;

    while(prev!=NULL) {
        if(prev->data==j) {
            if(prev==head) {
                head=head->next;
                return 0;
            } else {
                next1->next=prev->next;
                return 0;
            }

        }
        next1=prev;
        prev=prev->next;
    }
}

int revll(node *ptr)
{
    if(ptr==NULL) {
        return 0;
    }

    else {
        revll(ptr->next);
        cout<<ptr->data<<"\n";
        return 0;
    }

}

int sortinc()
{
    node *ptr=NULL;
    node *ptr1=NULL;
    ptr1=head;
    int t=0;
    while(ptr1->next!=NULL) {
        ptr=head;
        while((ptr->next)!=NULL) {
            if((ptr->data) > ((ptr->next)->data)) {
                int i;
                i=ptr->data;
                ptr->data=(ptr->next)->data;
                (ptr->next)->data=i;
            }
            ptr=ptr->next;

        }
        ptr1=ptr1->next;

    }
    return 0;
}


int sortdec()
{
    node *ptr=NULL;
    node *ptr1=NULL;
    ptr1=head;
    int t=0;
    while(ptr1->next!=NULL) {
        ptr=head;
        while((ptr->next)!=NULL) {
            if((ptr->data) < ((ptr->next)->data)) {
                int i;
                i=ptr->data;
                ptr->data=(ptr->next)->data;
                (ptr->next)->data=i;
            }
            ptr=ptr->next;

        }
        ptr1=ptr1->next;

    }
    return 0;
}

/* Main Function */
int main()
{
    bool b;
    b=1;
    while(b) {
        cout<<"Enter the number correspoding the operation to be performed on the linked list";
        cout<<"\n1.Enter a node"<<"\n2.Delete a node"<<"\n3.Print the data in reverse of linklist"<<"\n4.Sort the linklist in ascending order"<<"\n5.Sort the linklist in descending order\n"<<"6.Display Linklist element\n"<<"7.Exit loop\n";
        int a;
        cin>>a;
        switch(a) {
        case 1:
            int data1;
            cout<<"\nEnter the data for the node\n";
            cin>>data1;
            newNode(data1);
            break;

        case 2:
            cout<<"1. Delete by Index\n"<<"2. Delete by value\n";
            int d;
            cin>>d;
            switch(d) {

            case 1:
                cout<<"Enter the index of node you want you want to delete\n";
                int i;
                cin>>i;
                dbi(i);
                break;

            case 2:
                cout<<"Enter the value which you want to delete\n";
                int j;
                cin>>j;
                dbv(j);
                break;
            }
            break;

        case 3:
            revll(head);
            break;

        case 4:
            sortinc();
            break;

        case 5:
            sortdec();
            break;

        case 6:
            display();
            break;

        case 7:
            b=0;
        }
    }
}
