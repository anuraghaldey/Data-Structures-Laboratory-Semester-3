#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
struct node
{
 string s_name;
 struct node *next;
};
node *temp,*head;

node* Create(string name)
{

    temp = new(struct node);
	if (temp == NULL)
    {
		cout<<"Memory Allocation Error"<<endl;
		return 0;
	}
	else
	{
		temp -> s_name = name;
		temp -> next = NULL;
		return temp;
	}
}
void AddPresi()
{
    string name1;
    cout<<"Enter the name=";
    cin>>name1;
    temp=Create(name1);
    if (head == NULL)
    {
		head = temp;
		head -> next = NULL;
		cout<<"We have " <<name1<< " as a new President."<<endl;
	}
	else
	{
		temp -> next = head;
		head = temp;
		cout<<"We have " <<name1<< " as a new President."<<endl;
	}
}
void AddMember()
{
    int i;
    int counter = 1;
    cout<<"\nEnter the location where member to be added=";
    cin>>i;
    int pos = i - 1;
	string n;
	struct node *ptr;
	struct node *t = head;
	while ((t -> next) != NULL)
    {
			t = t -> next;
			counter++;
	}
	t = head;
	if (i == 1)
	{
		AddPresi();
	}
	else if (pos > counter || i <= 0)
    {
		cout<<"Entered position is out of scope."<<endl;
	}
	else
    {
		cout<<"Enter Name: ";
		cin>>n;
		temp = Create(n);
		while (pos--)
		{
			ptr = t;
			t = t -> next;
		}
		temp -> next = t;
		ptr -> next = temp;
		cout<<"Member Inserted at Position: "<<i<<endl;
	}
}
void AddSecr()
{
    string name;
	cout<<"Enter Name: ";
	cin>>name;
	struct node *temp1 = head;
	temp = Create(name);
	if (head == NULL)
    {
		head = temp;
		head -> next = NULL;
	} else
	{
		while ((temp1 -> next) != NULL)
		{
			temp1 = temp1 -> next;
		}
		temp -> next = NULL;
		temp1 -> next = temp;
		cout<<"We have " <<name<< " as a new Secretary."<<endl;
	}
}
void DelMember()
{
    int i;
    int counter = 1;
    cout<<"\nEnter the location where member to be added=";
    cin>>i;
    int pos = i - 1;
    string n;
	struct node *ptrl,*ptrr;
	struct node *t = head;
	while ((t -> next) != NULL)
    {
			t = t -> next;
			counter++;
	}
	t = head;
	if (i == 1)
	{
		ptrl = head;
		head = head -> next;
		delete ptrl;
	} else if (pos > counter || i <= 0)
	{
		cout<<"Entered member doesn't exist."<<endl;
	} else
	{
		while (pos--)
		{
			ptrl = t;
			t = t -> next;
			ptrr = t -> next;
		}
		ptrl -> next = ptrr;
		delete t;
		cout<<"Member Deleted at Position: "<<i<<endl;
	}
}
void AddDelete()
{
    int ch,ch1;
    char ch2;
    cout<<"\nWhich operation you want to carry out?\n";
    cout<<"\n1.Add Member\n2.Delete Member\n";
    cin>>ch;
    switch(ch)
    {
        case 1: do
                {
                    cout<<"which member you want to add?\n1.Add President\n2.Add Member\n3.Add Secretary\n";
                    cin>>ch1;
                    switch(ch1)
                    {
                        case 1:AddPresi();
                               break;
                        case 2:AddMember();
                               break;
                        case 3:AddSecr();
                               break;
                    }
                    cout<<"Do you want to keep adding?\nYes\nNo\n";
                    cin>>ch2;
                }while(ch2=='Y' || ch2=='y');
                break;
        case 2: do
                {
                    DelMember();
                    cout<<"Do you want to keep Deleting?\nYes\nNo\n";
                    cin>>ch2;
                }while(ch2=='Y' || ch2=='y');
                break;
    }
}
void TotalNumber()
{
    temp = head;
	int count = 0;
	while (temp != NULL)
    {
		count++;
		temp = temp -> next;
	}
	 cout<<"Total number of members are="<<count<<endl;
}
void Display()
{
   temp = head;
	cout<<"President: ";
	cout<<temp -> s_name<<" -> ";
	if(temp -> next != NULL)
    {
		temp = temp -> next;
	}
	while (temp -> next != NULL)
	{
		cout<< temp -> s_name<<" -> ";
		temp = temp -> next;
	}
	cout<<"Secretary: ";
	cout<< temp -> s_name<<" -> ";
	cout<<"NULL"<<endl;
}
void Rev(node *t)
{

     if(t -> next != NULL)
    {
		Rev (t -> next);
	}
	if(t == head)
		cout<<"Secretary: "<<t -> s_name<<endl;
	else if(t -> next == NULL)
		cout<<"President: "<<t -> s_name<<" -> ";
	else
		cout<<"Member: "<<t -> s_name<<" -> ";
}
void DisplayReverse()
{
    Rev(head);
}

int main()
{
     int ch;
     //head=NULL;
     char ch2;
     do
     {
         cout<<"Enter choice: \n1.Add and Delete Member\n2.Total number of Members\n3.Display Members\n4.Display Members in Reverse Order\n";
         cin>>ch;
        switch(ch)
        {
            case 1:AddDelete();
                break;
            case 2:TotalNumber();
                break;
            case 3:Display();
                break;
            case 4:DisplayReverse();
                break;
        }
        cout<<"Do you want to continue operations?\nYes\nNo\n";
        cin>>ch2;
     } while(ch2=='Y' || ch2=='y');
    return 0;
}