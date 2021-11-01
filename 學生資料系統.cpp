#include <iostream> 
#include <cstring>
using namespace std;

class ST{

		int no;
		ST *ptr;
		char name[11];
		int com;
		int math;
		
	public:
		
		ST()
		{
			no=0;
			com=0;
			math=0;
			ptr=0;
			strcpy(name,"           ");
		};
		void writedata(int data)
		{
			no=data;
		}
		int readdata()
		{
			return no;
		}
		//
		void writeptr(ST *p)
		{
			ptr=p;
		}
		ST *readptr()
		{
			return ptr;
		}
		//
		void writename(char st[11])
		{
			strcpy(name,st);
		}
		char *readname()
		{
			return name;
		}
		//
		void writecom(int csc)
		{
			com=csc;
		}
		int readcom()
		{
			return com;
		}
		//
		void writemath(int msc)
		{
			math=msc;
		}
		int readmath()
		{
			return math;
		}
		
};

ST *insert(ST *head,ST *a)		//1.�s�W��� 
{
	int data,csc,msc;
	char st[11];
	//��J�y�� 
	cout<<"�y��:";
	cin>>data;
	while(cin.fail() || data<=0)
	{
		if(cin.fail())	cout<<"��J���~"<<endl;
		if(data<=0)		cout<<"�y���ݤj��0"<<endl;
		cin.clear();
		cin.sync();
		cout<<"�Э��s��J�y��:";
		cin>>data;
	}
	//��J�m�W 
	cin.sync();
	cout<<"�m�W:";
	cin.getline(st,11);
	while(cin.fail())
	{
		cout<<"��J���~"<<endl;
		cin.clear();
		cin.sync();
		cout<<"�Э��s��J�m�W:";
		cin.getline(st,11);
	}
	//��J�귧 
	cout<<"�귧���Z:";
	cin>>csc;
	while(cin.fail() || csc<0 || csc>100)
	{
		if(cin.fail())	cout<<"��J���~"<<endl;
		if(csc<0 || csc>100)	cout<<"�귧���Z�ݤ���0~100����"<<endl;
		cin.clear();
		cin.sync();
		cout<<"�Э��s��J�귧���Z:";
		cin>>csc;
	}
	//��J�ƾ� 
	cout<<"�ƾǦ��Z:";
	cin>>msc;
	while(cin.fail() || msc<0 || msc>100)
	{
		if(cin.fail())	cout<<"��J���~"<<endl;
		if(msc<0 || msc>100)	cout<<"�ƾǦ��Z�ݤ���0~100����"<<endl;
		cin.clear();
		cin.sync();
		cout<<"�Э��s��J�ƾǦ��Z:";
		cin>>msc;
	}
	
	ST *p,*q=NULL;
	if(head==NULL)
	{
		head=new ST;
		head->writedata(data);
		head->writeptr(NULL);
		head->writename(st);
		head->writecom(csc);
		head->writemath(msc);
	}
	else
	{
		q=NULL;
		a=new ST;
		a->writedata(data);
		a->writename(st);
		a->writecom(csc);
		a->writemath(msc);
		p=head;
		while(a->readdata() > p->readdata() && p->readptr()!=NULL)
		{
			q=p;
			p=p->readptr();
		}
		
		if(a->readdata()==p->readdata())	cout<<"�y�����ƤF"<<endl;
		else if(a->readdata() > p->readdata() && p->readptr()==NULL)
		{
			p->writeptr(a);
			a->writeptr(NULL);
		}
		else if(q==NULL)
		{
			a->writeptr(head);
			head=a;
		}
		else 
		{
			q->writeptr(a);
			a->writeptr(p);
		}
		
	}
	return head;
}
ST *searchno(ST *head,ST *a)		//2.�ήy���d
{
	int data; 
	cin>>data;
	while(cin.fail() || data<=0)
	{
		if(cin.fail())	cout<<"��J���~"<<endl;
		if(data<=0)		cout<<"�y���ݤj��0"<<endl;
		cin.clear();
		cin.sync();
		cout<<"�Э��s��J�y��:";
		cin>>data;
	}
	ST *p,*q=NULL;
	a=new ST;
	a->writedata(data);
	p=head;
	if(head==NULL)	cout<<"�|�L���"<<endl;
	else{
			while(a->readdata() > p->readdata() && p->readptr()!=NULL)
			{
				q=p;
				p=p->readptr();
			}
			if(a->readdata()==p->readdata())
			{
				cout<<"�y��:"<<p->readdata()<<"  "<<"�m�W:"<<p->readname()<<"  "<<"�귧���Z:"<<p->readcom()
				<<"  "<<"�ƾǦ��Z:"<<p->readmath()<<endl;
			}	
			//�y�����|���� �]���u����X��쪺�@���ǥ͸�� 
			else	cout<<"�d�L���ǥ͸��"<<endl;
		}
}
 
ST *searchname(ST *head,ST *a)		//2.�Ωm�W�d
{
	char st[11];
	int i=0;
	cin.sync();
	cin.getline(st,11);
	while(cin.fail())
	{
		cout<<"��J���~"<<endl;
		cin.clear();
		cin.sync();
		cout<<"�Э��s��J�m�W:";
		cin.getline(st,11);
	}
	ST *p,*q=NULL;
	a=new ST;
	a->writename(st);
	p=head;
	if(head==NULL)	cout<<"�|�L���"<<endl;
	else{ 
	
			if( strcmp( p->readname(),st ) ==0)
			{
				cout<<"�y��:"<<p->readdata()<<"  "<<"�m�W:"<<p->readname()<<"  "<<"�귧���Z:"<<p->readcom()
				<<"  "<<"�ƾǦ��Z:"<<p->readmath()<<endl;
				i++;
			}
			while( p->readptr()!=NULL )
			{
				q=p;
				p=p->readptr();
				if( strcmp( p->readname(),st ) ==0)
				{
					cout<<"�y��:"<<p->readdata()<<"  "<<"�m�W:"<<p->readname()<<"  "<<"�귧���Z:"<<p->readcom()
					<<"  "<<"�ƾǦ��Z:"<<p->readmath()<<endl;
					i++;
				}	
			}
			if(i==0)	cout<<"�d�L���ǥ͸��"<<endl;
		}
}

ST *delete1(ST *head,ST *a)		//3.�R����� 
{
	int data;
	cin>>data;
	while(cin.fail() || data<=0)
	{
		if(cin.fail())	cout<<"��J���~"<<endl;
		if(data<=0)		cout<<"�y���ݤj��0"<<endl;
		cin.clear();
		cin.sync();
		cout<<"�Э��s��J�y��:";
		cin>>data;
	}
	ST *p,*q=NULL;
	a=new ST;
	a->writedata(data);
	p=head;

	if(head==NULL)	cout<<"�|�L���"<<endl;
	else{
			while(a->readdata() > p->readdata() && p->readptr()!=NULL)
			{
				q=p;
				p=p->readptr();
			}
			if(a->readdata()==p->readdata())
			{
				if(p->readptr()==NULL && p!=head)		//�R�� 
				{
					q->writeptr(NULL);
					delete p;
				}
				else if(p->readptr()!=NULL && p!=head)	//�R���� 
				{
					q->writeptr(p->readptr());
					delete p;
				}
				else if(p=head)		//�R�Y 
				{
					head=p->readptr();
					delete p;
				}
				cout<<"�ӵ���Ƥw���u�R��"<<endl;	//��"�\"�����X�� �G��"�u"�N�� 
			}
			else	cout<<"�ӵ���Ƥ��s�b�A�L�k�R��"<<endl;
		}
	return head;
}

void output(ST *x,ST *y)		//4.�C�L��� 
{
	int i=0,k=0;
	char st[11];
	
	while (x!=NULL){
		k++;
		x=x->readptr();
	}
	
	int nofo[k],comfo[k],mathfo[k];
	char *namefo[k];
	
	
	while (y!=NULL){
		nofo[i]=y->readdata();
		namefo[i]=y->readname();
		comfo[i]=y->readcom();
		mathfo[i]=y->readmath();
		i++;
		y=y->readptr();
	}
	for(int j=0;j<(k-1);j++){
		for(int i=0;i<(k-1);i++){
			if(mathfo[i+1]+comfo[i+1]>mathfo[i]+comfo[i])
			{
				
				swap(nofo[i],nofo[i+1]);
				swap(namefo[i],namefo[i+1]);
				swap(comfo[i],comfo[i+1]);
				swap(mathfo[i],mathfo[i+1]);
			}
		}
	}
	
	cout<<"�ǥͦ��Z��:"<<endl;
	for(int i=0;i<k;i++)
	{
		cout<<"�y��:"<<nofo[i]<<"  "<<"�m�W:"<<namefo[i]<<"  "<<"�귧���Z:"<<comfo[i]<<"  "
		<<"�ƾǦ��Z:"<<mathfo[i]<<"  "<<"�`���Z:"<<comfo[i]+mathfo[i]<<endl; 
	} 
}

void MENU()
{
	cout<<"(1).�s�W�ǥ͸��"<<endl;
	cout<<"(2).�d�߾ǥ͸��"<<endl;
	cout<<"(3).�R���ǥ͸��"<<endl;
	cout<<"(4).�C�L�ǥͦ��Z��"<<endl;
	cout<<"(5).���}"<<endl;
	cout<<"�п�J��ܶ��ءH";
}

int main()
{
	int n,choice;
	ST *a,*p,*q=NULL,*head=NULL;
	do{
		MENU();
		cin>>n;
		while(cin.fail())
		{
			cout<<"��J���~"<<endl;
			cin.clear();
			cin.sync();
			cout<<endl;
			MENU();
			cin>>n;
		}
		switch(n){
			case 1:		
				cout<<"�s�W�ǥ͸�ư��椤"<<endl;
				head=insert(head,a);
				break;
			
			case 2:		
				cout<<"�d�߾ǥ͸�ư��椤"<<endl;
				cout<<"�ήy���d�п�1�A�Ωm�W�d�п�2:";
				cin>>choice;
				while(cin.fail() || (choice!=1&&choice!=2))
				{
					if(cin.fail())	cout<<"��J���~"<<endl;
					if(choice!=1&&choice!=2)	cout<<"�п�J1��2"<<endl;
					cin.clear();
					cin.sync();
					cout<<"�Э��s��J���:";
					cin>>choice;
				} 
				if(choice==1){
					cout<<"�п�J���d�ߤ��y��:";
					searchno(head,a);	
				}
				else if(choice==2){
					cout<<"�п�J���d�ߤ��m�W:";
					searchname(head,a);
				} 
				break;
			
			case 3:	
				cout<<"�R���ǥ͸�ư��椤"<<endl;
				cout<<"�п�J���R�����y��:";
				head=delete1(head,a);
				break;
				
			case 4:	
				cout<<"�C�L�ǥ͸�ư��椤"<<endl;
				output(head,head);
				if(head==NULL)	cout<<"�|�L���"<<endl;
				break;
			
			case 5:	
				break;
			
			default:
				cout<<"��J���~"<<endl;
				break;
		}
		cout<<endl;
	}while(n!=5);
}
	
