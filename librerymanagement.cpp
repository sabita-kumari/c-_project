#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
ofstream a;
ifstream b;

/* This class is creates a member */ 
class member
{
	public:
	
	int  id;
	char name[20];
	char dept[40];

	void read() /* This function is read the data member of class member*/
	{

		cout<<"enter  member details\n \n";
		cout<<"enter the member id\n";
		cin>>id;
		cout<<"enter the member name\n";
		cin>>name;
		cout<<"enter the member department\n";
		cin>>dept;
	}
	void write() /*This function is used to open a file and write the data member */
	{
		 a.open("member.txt",ios::app);
                 cout<<"add member\n";
                 read();
                 a<<id<<"\t"<<name<<"\t\t\t"<<dept<<"\n";
                 a.close();
                 
	}
	void show() /*This function is used to read the data from file and show it to on screen */
	{
                        b.open("member.txt",ios::in);
                        while(!b.eof())
                        {
                                b>>id>>name>>dept;
                                cout<<id<<"\t"<<name<<"\t\t\t"<<dept<<"\n";
                        }

                        b.close();
	}
	bool member_search(int x) /* This function is used to search data member on by one from file */
	{
		int s=0;
		int flag=0;
		b.open("member.txt",ios::in);
		while(!b.eof())
		{
			b>>id>>name>>dept;
			if(id==x)
			{
				flag=1;
			}
		}
		b.close();
		if(flag==1)
		{
			return true;
		}
		else
		{
			return false;
		}
		
	}



}Member; /* Here member class is closed */ 

class book_issue_detail /* Another class is created */
{
        public:
                int member_id;
                int book_id;
                char dept[10];
                string issuedate;
                string returndate;
		string status;

		void book_update(int y)/* This is used to insert or update book issue detail when book is issue */
		{
			int book_id;
			char book_name[30];
			char author[30];
			int no_of_copy;

			b.open("book.txt",ios::in);
			a.open("book_update.txt",ios::app);
			while(!b.eof())
			{
				b>>book_id>>book_name>>author>>no_of_copy;
				if(book_id==y)
				{
					a<<book_id<<"\t"<<book_name<<"\t"<<author<<"\t"<<no_of_copy-1<<endl;
				}
				else
				{
					a<<book_id<<"\t"<<book_name<<"\t"<<author<<"\t"<<no_of_copy<<endl;
				}
			}
			a.close();
			b.close();
			remove("book.txt");
			rename("book_update.txt","book.txt");
		}


                void read(int x,int y) /* This function is used to insert detail of member who issue a book */
                {
                        a.open("book_issue_detail.txt",ios::app);
                        cout<<"enter your depatment\n";
                        cin>>dept;
                        cout<<"enter the issue date\n";
                        cin>>issuedate;
                        cout<<"enter the return date\n";
                        cin>>returndate;
                        a<<x<<"\t"<<y<<"\t"<<dept<<"\t"<<issuedate<<"\t"<<returndate<<"\t"<<"NO\n";
			a.close();
			book_update(y);
			
			
                }
		
                void write() /* This function is used to read deatail of issued member from file */
                {
			
                        b.open("book_issue_detail.txt",ios::in);

                        while(!b.eof())
                        {
                                b>>member_id>>book_id>>dept>>issuedate>>returndate>>status;
				cout<<member_id<<"\t"<<book_id<<"\t"<<dept<<"\t"<<issuedate<<"\t"<<returndate<<"\t"<<status<<endl;
                        }
			b.close();
                }

		void return_detail(int x,int y)
		{
			b.open("book_issue_detail.txt",ios::in);
			a.open("update.txt",ios::app);
			while(!b.eof())
			{
				b>>member_id>>book_id>>dept>>issuedate>>returndate>>status;
				if(member_id==x && book_id==y)
				{
					a<<member_id<<"\t"<<book_id<<"\t"<<dept<<"\t"<<issuedate<<"\t"<<returndate<<"\t"<<"YES"<<endl;
				}
				else 
				{
					a<<member_id<<"\t"<<book_id<<"\t"<<dept<<"\t"<<issuedate<<"\t"<<returndate<<"\t"<<status <<"\n";
				}

			}
			a.close();
			b.close();
			remove("book_issue_detail.txt");
			rename("update.txt","book_issue_detail.txt");
		}


		

}Issue; /* Here class is clossed */



class book /* Here book class is created */
{
	public:
		int book_id;
		char book_name[30];
		char author[30];
		int no_of_copy;
		void read() /* This function is used to insert the book detail from keyboard */
		{
			cout<<"enter the book details\n\n";
			cout<<"enter the book id\n";
			cin>>book_id;
			cout<<"enter the book name\n";
			cin>>book_name;
			cout<<"enter the name of book author\n";
			cin>>author;
			cout<<"enter the no of copy \n";
			cin>>no_of_copy;
		}

		void write() /* This function is used to write the book detail in file */
		{
			a.open("book.txt",ios::app);
                        cout<<"add book\n";
                        read();
                        a<<book_id<<"\t"<<book_name<<"\t\t"<<author<<"\t"<<no_of_copy<<"\n";
                        a.close();
		}
		void show() /* This function is read the detail of book from file */
		{
                        b.open("book.txt",ios::in);
                        while(!b.eof())
                        {
                                b>>book_id>>book_name>>author>>no_of_copy;
                                cout<<book_id<<"\t"<<book_name<<"\t\t"<<author<<"\t"<<no_of_copy<<"\n";
                        }
                        b.close();
		}
		bool book_search(int x) /* This function is used to search the number-of-copy of book */
		{
			int flag=0;
			b.open("book.txt",ios::in);
			while(!b.eof())
			{
				b>>book_id>>book_name>>author>>no_of_copy;
				if(x==book_id)
				{
					flag=1;
					if(no_of_copy!=0)
					{
						cout<<"no_of__copy="<<no_of_copy<<endl;
					}
					
					else
					{
						cout<<"not available!choose other book \n";
					}
					
				}
			}
			b.close();
			if(flag==1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

	
			


}Book; /* Here claas book is closed. */


/* Here main function is start. */
int main()
{
	//ofstream a;
	//ifstream b;
	int ch;
	while(1)
	{
		cout<<"************************************************* \n";
		cout<<"*\t\t1:Add member \t\t\t*\n";
		cout<<"*\t\t2:Show all member \t\t*\n";
		cout<<"*\t\t3.Add book \t\t\t*\n";
		cout<<"*\t\t4.Show book \t\t\t*\n";
		cout<<"*\t\t5:Issue a book \t\t\t*\n";
		cout<<"*\t\t6:show Issued book \t\t*\n";
		cout<<"*\t\t7:return a book \t\t*\n";
		cout<<"*\t\t8:exit \t\t\t\t* \n";
		cout<<"************************************************* \n";
		cout<<"\n enter the choice\n";
		cin>>ch;
	
	switch(ch)
	{
		case 1: /* Function call for add member. */ 
			Member.write();
			break;

		case 2: /* Function call for show member. */
			Member.show();
			break;
		case 3: /* function call for add a book. */
			Book.write();
			break;
		case 4: /* Function call for show book detail. */
			Book.show();
			break;
		case 5: /* Here first check member id and book id for issuing book. */
			int member_id,book_id;
			cout<<"enter member id"<<endl;
			cin>>member_id;
			cout<<"enter book id"<<endl;
			cin>>book_id;

			/* If member id and book id is valid then proceed to issue book otherwise exit. */

			if(Member.member_search(member_id) && Book.book_search(book_id))
			{
				Issue.read(member_id,book_id);
			}
			else
			{
				cout<<"enter correct credentials"<<endl;
			}
			break;
		case 6:
			Issue.write(); /* Here function call for show issued book detail. */
			break;
		case 7:
			/* Here first chaeck member id and book id which you return then proceed othewise exit. */
			cout<<"return a book"<<endl;
			int x,y;
			cout<<"enter the member id \n";
			cin>>x;
			cout<<"enter the book id \n";
			cin>>y;
			if(Member.member_search(x) && Book.book_search(y))
			{	
				Issue.return_detail(x,y);
			}
			else
			{
				cout<<"wrong credential"<<endl;
				break;
			}
			break;

		case 8:
			exit(0);
		default:
			cout<<"wrong entry\n";
			break;
	}
	}
}

