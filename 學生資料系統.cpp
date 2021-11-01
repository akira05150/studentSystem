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

ST *insert(ST *head,ST *a)		//1.新增資料 
{
	int data,csc,msc;
	char st[11];
	//輸入座號 
	cout<<"座號:";
	cin>>data;
	while(cin.fail() || data<=0)
	{
		if(cin.fail())	cout<<"輸入錯誤"<<endl;
		if(data<=0)		cout<<"座號需大於0"<<endl;
		cin.clear();
		cin.sync();
		cout<<"請重新輸入座號:";
		cin>>data;
	}
	//輸入姓名 
	cin.sync();
	cout<<"姓名:";
	cin.getline(st,11);
	while(cin.fail())
	{
		cout<<"輸入錯誤"<<endl;
		cin.clear();
		cin.sync();
		cout<<"請重新輸入姓名:";
		cin.getline(st,11);
	}
	//輸入資概 
	cout<<"資概成績:";
	cin>>csc;
	while(cin.fail() || csc<0 || csc>100)
	{
		if(cin.fail())	cout<<"輸入錯誤"<<endl;
		if(csc<0 || csc>100)	cout<<"資概成績需介於0~100之間"<<endl;
		cin.clear();
		cin.sync();
		cout<<"請重新輸入資概成績:";
		cin>>csc;
	}
	//輸入數學 
	cout<<"數學成績:";
	cin>>msc;
	while(cin.fail() || msc<0 || msc>100)
	{
		if(cin.fail())	cout<<"輸入錯誤"<<endl;
		if(msc<0 || msc>100)	cout<<"數學成績需介於0~100之間"<<endl;
		cin.clear();
		cin.sync();
		cout<<"請重新輸入數學成績:";
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
		
		if(a->readdata()==p->readdata())	cout<<"座號重複了"<<endl;
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
ST *searchno(ST *head,ST *a)		//2.用座號查
{
	int data; 
	cin>>data;
	while(cin.fail() || data<=0)
	{
		if(cin.fail())	cout<<"輸入錯誤"<<endl;
		if(data<=0)		cout<<"座號需大於0"<<endl;
		cin.clear();
		cin.sync();
		cout<<"請重新輸入座號:";
		cin>>data;
	}
	ST *p,*q=NULL;
	a=new ST;
	a->writedata(data);
	p=head;
	if(head==NULL)	cout<<"尚無資料"<<endl;
	else{
			while(a->readdata() > p->readdata() && p->readptr()!=NULL)
			{
				q=p;
				p=p->readptr();
			}
			if(a->readdata()==p->readdata())
			{
				cout<<"座號:"<<p->readdata()<<"  "<<"姓名:"<<p->readname()<<"  "<<"資概成績:"<<p->readcom()
				<<"  "<<"數學成績:"<<p->readmath()<<endl;
			}	
			//座號不會重複 因此只須輸出找到的一筆學生資料 
			else	cout<<"查無此學生資料"<<endl;
		}
}
 
ST *searchname(ST *head,ST *a)		//2.用姓名查
{
	char st[11];
	int i=0;
	cin.sync();
	cin.getline(st,11);
	while(cin.fail())
	{
		cout<<"輸入錯誤"<<endl;
		cin.clear();
		cin.sync();
		cout<<"請重新輸入姓名:";
		cin.getline(st,11);
	}
	ST *p,*q=NULL;
	a=new ST;
	a->writename(st);
	p=head;
	if(head==NULL)	cout<<"尚無資料"<<endl;
	else{ 
	
			if( strcmp( p->readname(),st ) ==0)
			{
				cout<<"座號:"<<p->readdata()<<"  "<<"姓名:"<<p->readname()<<"  "<<"資概成績:"<<p->readcom()
				<<"  "<<"數學成績:"<<p->readmath()<<endl;
				i++;
			}
			while( p->readptr()!=NULL )
			{
				q=p;
				p=p->readptr();
				if( strcmp( p->readname(),st ) ==0)
				{
					cout<<"座號:"<<p->readdata()<<"  "<<"姓名:"<<p->readname()<<"  "<<"資概成績:"<<p->readcom()
					<<"  "<<"數學成績:"<<p->readmath()<<endl;
					i++;
				}	
			}
			if(i==0)	cout<<"查無此學生資料"<<endl;
		}
}

ST *delete1(ST *head,ST *a)		//3.刪除資料 
{
	int data;
	cin>>data;
	while(cin.fail() || data<=0)
	{
		if(cin.fail())	cout<<"輸入錯誤"<<endl;
		if(data<=0)		cout<<"座號需大於0"<<endl;
		cin.clear();
		cin.sync();
		cout<<"請重新輸入座號:";
		cin>>data;
	}
	ST *p,*q=NULL;
	a=new ST;
	a->writedata(data);
	p=head;

	if(head==NULL)	cout<<"尚無資料"<<endl;
	else{
			while(a->readdata() > p->readdata() && p->readptr()!=NULL)
			{
				q=p;
				p=p->readptr();
			}
			if(a->readdata()==p->readdata())
			{
				if(p->readptr()==NULL && p!=head)		//刪尾 
				{
					q->writeptr(NULL);
					delete p;
				}
				else if(p->readptr()!=NULL && p!=head)	//刪中間 
				{
					q->writeptr(p->readptr());
					delete p;
				}
				else if(p=head)		//刪頭 
				{
					head=p->readptr();
					delete p;
				}
				cout<<"該筆資料已成工刪除"<<endl;	//成"功"打不出來 故用"工"代替 
			}
			else	cout<<"該筆資料不存在，無法刪除"<<endl;
		}
	return head;
}

void output(ST *x,ST *y)		//4.列印資料 
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
	
	cout<<"學生成績單:"<<endl;
	for(int i=0;i<k;i++)
	{
		cout<<"座號:"<<nofo[i]<<"  "<<"姓名:"<<namefo[i]<<"  "<<"資概成績:"<<comfo[i]<<"  "
		<<"數學成績:"<<mathfo[i]<<"  "<<"總成績:"<<comfo[i]+mathfo[i]<<endl; 
	} 
}

void MENU()
{
	cout<<"(1).新增學生資料"<<endl;
	cout<<"(2).查詢學生資料"<<endl;
	cout<<"(3).刪除學生資料"<<endl;
	cout<<"(4).列印學生成績單"<<endl;
	cout<<"(5).離開"<<endl;
	cout<<"請輸入選擇項目？";
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
			cout<<"輸入錯誤"<<endl;
			cin.clear();
			cin.sync();
			cout<<endl;
			MENU();
			cin>>n;
		}
		switch(n){
			case 1:		
				cout<<"新增學生資料執行中"<<endl;
				head=insert(head,a);
				break;
			
			case 2:		
				cout<<"查詢學生資料執行中"<<endl;
				cout<<"用座號查請選1，用姓名查請選2:";
				cin>>choice;
				while(cin.fail() || (choice!=1&&choice!=2))
				{
					if(cin.fail())	cout<<"輸入錯誤"<<endl;
					if(choice!=1&&choice!=2)	cout<<"請輸入1或2"<<endl;
					cin.clear();
					cin.sync();
					cout<<"請重新輸入選擇:";
					cin>>choice;
				} 
				if(choice==1){
					cout<<"請輸入欲查詢之座號:";
					searchno(head,a);	
				}
				else if(choice==2){
					cout<<"請輸入欲查詢之姓名:";
					searchname(head,a);
				} 
				break;
			
			case 3:	
				cout<<"刪除學生資料執行中"<<endl;
				cout<<"請輸入欲刪除之座號:";
				head=delete1(head,a);
				break;
				
			case 4:	
				cout<<"列印學生資料執行中"<<endl;
				output(head,head);
				if(head==NULL)	cout<<"尚無資料"<<endl;
				break;
			
			case 5:	
				break;
			
			default:
				cout<<"輸入錯誤"<<endl;
				break;
		}
		cout<<endl;
	}while(n!=5);
}
	
