package bank;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.StringTokenizer;


public class Test {
//���뵽�ļ���
	 static void writeData(CashAccount[] st1, PrintWriter out)
		      throws IOException
		   {
		      // write number of employees
		     // out.println(n);
		      for (int i=0;i<5;i++)
		         st1[i].writeData(out);
		   }
	 static void writeData(CreditAccount[] st1, PrintWriter out)
		      throws IOException
		   {
		      // write number of employees
		     // out.println(n);
		      for (int i=0;i<5;i++)
		         st1[i].writeData(out);
		   }
//��������
	 static CashAccount[] readData(BufferedReader in)
		      throws IOException
		   {
		      // retrieve the array size
		    //  int nn = Integer.parseInt(in.readLine());

		 CashAccount[] st1 = new CashAccount[5];
		      for (int i = 0; i < 5; i++)
		      {
		         st1[i] = new CashAccount();
		         st1[i].readData(in);
		      }
		      return st1;
		   }
	 static CreditAccount[] readData1(BufferedReader in)
		      throws IOException
		   {
		      // retrieve the array size
		    //  int nn = Integer.parseInt(in.readLine());

		 CreditAccount[] st1 = new CreditAccount[5];
		      for (int i = 0; i < 5; i++)
		      {
		         st1[i] = new CreditAccount();
		         st1[i].readData(in);
		      }
		      return st1;
		   }
	static CreditAccount cr[]=new CreditAccount  [10];
	static CashAccount ca[]=new CashAccount [10];
	static int n=1;
	public static void  main(String a[])
	{
		ca[0]=new CashAccount("cash1","11111111111","���ʿ�  �ֽ��˻�",500);
		ca[1]=new CashAccount("cash2","22222222222","��ǿ�  �ֽ��˻�",500);
		ca[2]=new CashAccount("cash3","33333333333","��ƿ�  �ֽ��˻�",500);
		ca[3]=new CashAccount("cash4","44444444444","���ʿ�  �ֽ��˻�",500);
		ca[4]=new CashAccount("cash5","55555555555","��ƿ�  �ֽ��˻�",500);
		cr[0]=new CreditAccount("credit1","66666666666",'A',500);
		cr[1]=new CreditAccount("credit2","77777777777",'B',500);
		cr[2]=new CreditAccount("credit3","88888888888",'D',500);
		cr[3]=new CreditAccount("credit4","99999999999",'C',500);
		cr[4]=new CreditAccount("credit5","00000000000",'D',500);
		while(true)
		{
			System.out.println("��ѡ��  1 �ֽ��˻�  2 ���ÿ��˻�  ���� �˳�");
			int choose;
			Scanner s=new Scanner(System.in);
			choose=s.nextInt();
			if(choose==1)//�ֽ�
			{
				while(true )
				{
					System.out.println("��ѡ��  1 ���  2 ȡ��  3 ��ѯ���  4 �ļ��������  5 ��ѯ ���� �˳�");
					int choose1;	int m=-1;
					Scanner s1=new Scanner(System.in);
					choose1=s1.nextInt();
					if(choose1!=4&&choose1<=5){
					System.out.println("�������˺ţ�");
						Scanner sc=new Scanner(System.in);
						String zhanghao=sc.next();
						for(int i=0;i<5;i++)
						{
							if(ca[i].aid.equals(zhanghao)){m=i;break;}
						}
					}
					if(choose1==1&&m>=0)
					{
						System.out.println("���������");
						Scanner s11=new Scanner(System.in);
						double d1=s11.nextDouble();
						ca[m].deposit(d1);
						
					}
					
					else if(choose1==2&&m>=0)
					{
						System.out.println("������ȡ���");
						Scanner s12=new Scanner(System.in);
						double d2=s12.nextDouble();
						ca[m].withdraw(d2);
					}
					else if(choose1==3&&m>=0)
					{
						
						System.out.println("����ǣ�"+ca[m].getBalance());
						
					}
					else if(choose1==4)
					{
						try
					      {
					         //�����ݴ�����ClientInfoTable.txt�� 
					         PrintWriter out = new PrintWriter(new FileWriter("ClientInfoTable.txt"));
					         writeData(ca, out);
					         out.close();

					         // retrieve all records into a new array
					         BufferedReader inp = new BufferedReader(new FileReader("ClientInfoTable.txt"));
					         CashAccount[] newSt = readData(inp);
					         inp.close();

					         // print the newly read employee records
					         for (CashAccount e : newSt)
					            System.out.println(e);
					      }
					      catch(IOException exception)
					      {
					         exception.printStackTrace();
					      }
						break;
						
					}
					else if(choose1==5&&m>=0)
					{
						System.out.println("�˺ţ�"+ca[m].aid+"������"+ca[m].name+"��"+ca[m].balance);
					}
					else break;
				}
			}
			else if(choose==2)//���ÿ�
			{
				while(true )
				{
					System.out.println("��ѡ��  1 ���  2 ȡ��  3 ��ѯ���  4 ��ѯ͸֧��  5 �ļ��Ķ�д  6 ��ѯ ���� �˳�");
					int choose1;	int m=-1;
					Scanner s1=new Scanner(System.in);
					choose1=s1.nextInt();
					if(choose1!=5&&choose1<=6){
					System.out.println("�������˺ţ�");
					Scanner sc=new Scanner(System.in);
					String zhanghao=sc.next();
					for(int i=0;i<5;i++)
					{
						if(cr[i].aid.equals(zhanghao)){m=i;break;}
					}
					}
					if(choose1==1&&m>=0)
					{
						System.out.println("���������");
						Scanner s11=new Scanner(System.in);
						double d1=s11.nextDouble();
						cr[m].deposit(d1);
					}
					else if(choose1==2&&m>=0)
					{
						System.out.println("������ȡ���");
						Scanner s12=new Scanner(System.in);
						double d2=s12.nextDouble();
						cr[m].withdraw(d2);
					}
					else if(choose1==3&&m>=0)
					{
						System.out.println("����ǣ�"+cr[0].getBalance());
					}
					else if(choose1==4&&m>=0)
					{
						cr[m].findOverdraw();
					}
					else if(choose1==5)
					{
						try
					      {
					         //�����ݴ�����ClientInfoTable.txt�� 
					         PrintWriter out = new PrintWriter(new FileWriter("ClientInfoTable.txt"));
					         writeData(cr, out);
					         out.close();

					         // retrieve all records into a new array
					         BufferedReader inp = new BufferedReader(new FileReader("ClientInfoTable.txt"));
					         CreditAccount[] newSt = readData1(inp);
					         inp.close();

					         // print the newly read employee records
					         for (CreditAccount e : newSt)
					            System.out.println(e);
					      }
					      catch(IOException exception)
					      {
					         exception.printStackTrace();
					      }
						break;
						
					}
					else if(choose1==6&&m>=0)
					{
						System.out.println("�˺ţ�"+cr[m].aid+"������"+cr[m].name+"��"+cr[m].balance);
					}
					else break;
				}
			}
			else break;
		}
	}

}
abstract class Accounti
{
	String name;String aid;double balance;
	public String yue;
	//���
	void deposit(double a)
	{
		balance+=a;
	}
	//ȡ��
	abstract void withdraw(double a);
	//��ѯ���
	double getBalance()
	{
		return balance;
	}
	
}


//�ֽ��˻���
class CashAccount extends Accounti
{
	String type;
	CashAccount(String na,String ai,String t,double ba)
	{
		name=na;aid=ai;type=t;balance=ba;
	}
	public CashAccount() {
		// TODO Auto-generated constructor stub
	}
	public void writeData(PrintWriter out)throws IOException
    {
    	out.println(name+"|"+aid+"|"+type+"|"+balance);
    }
	 public void readData(BufferedReader in)throws IOException
     {
     	String str=in.readLine();
     	StringTokenizer t = new StringTokenizer(str, "|");
     	name = t.nextToken();
     	aid = t.nextToken();
     	type = t.nextToken();
     	balance = Double.parseDouble(t.nextToken());
     }
	 public String toString()
	   {
	      return 
	         name + "\t" + aid+"\t"+type + "\t" + balance ;
	   }
	void withdraw(double a)
	{
		if(a>balance)
			try {
				throw new WithdrawException("ȡ����:"+name+" �˻���"+balance+" ȡ��"+a+" ԭ��͸֧ ");
			} 
		     catch (WithdrawException e) {
		    	 System.out.println(e.getMessage());
		    	
			}
		else 
		balance-=a;
	}
}
//���ÿ��˻���
class CreditAccount extends Accounti
{
	char jibie;//��ʾ���ü���
	double lineOfCredit;//��ʾ͸֧�޶�
	CreditAccount(String na,String ai,char j,double ba)
	{
		name=na;aid=ai;jibie=j;balance=ba;
	}
	public CreditAccount() {
		// TODO Auto-generated constructor stub
	}
	public void writeData(PrintWriter out)throws IOException
    {
		if(jibie=='A')
			lineOfCredit=10000;
		else if(jibie=='B')
			lineOfCredit=5000;
		else if(jibie=='C')
			lineOfCredit=3000;
		else if(jibie=='D')
			lineOfCredit=2000;
    	out.println(name+"|"+aid+"|"+lineOfCredit+"|"+balance);
    }
	 public void readData(BufferedReader in)throws IOException
     {
     	String str=in.readLine();
     	StringTokenizer t = new StringTokenizer(str, "|");
     	name = t.nextToken();
     	aid = t.nextToken();
     	lineOfCredit = Double.parseDouble(t.nextToken());
     	balance = Double.parseDouble(t.nextToken());
     }
	 public String toString()
	   {
	      return 
	         name + "\t" + aid+"\t"+lineOfCredit + "\t" + balance+"���ÿ���" ;
	   }

	//��ѯ͸֧���
		void  findOverdraw()
		{
			if(balance>=0){System.out.println("û��͸֧��");}
			else if(jibie=='A')
				{
					if(balance>-10000)System.out.println("͸֧�����"+balance);
					else System.out.println("�Ѿ�͸֧");
				}
			else	if(jibie=='B')
				{
					if(balance>-5000)System.out.println("͸֧�����"+balance);
					else System.out.println("�Ѿ�͸֧");
				}
			else 	if(jibie=='C')
				{
					if(balance>-2000)System.out.println("͸֧�����"+balance);
					else System.out.println("�Ѿ�͸֧");
				}
			else //if(jibie=='D')
				{
					if(balance>-1000)System.out.println("͸֧�����"+balance);
					else System.out.println("�Ѿ�͸֧");
				}
			
		}
	//ȡ��
	void withdraw(double a)
	{
		if(jibie=='A')
			{
			if(a>balance+10000)
				try {
					throw new WithdrawException("ȡ����:"+name+" �˻���"+balance+" ȡ��"+a+" ԭ��͸֧ ");
				} 
			     catch (WithdrawException e) {
			    	 System.out.println(e.getMessage());
					}
				else 
					balance-=a;
				}
		if(jibie=='B')
		{
			if(a>balance+5000)
				try {
					throw new WithdrawException("ȡ����:"+name+" �˻���"+balance+" ȡ��"+a+" ԭ��͸֧ ");
				} 
			     catch (WithdrawException e) {
			    	 System.out.println(e.getMessage());
					}
				else 
					balance-=a;
				}
		if(jibie=='C')
		{
			if(a>balance+2000)
				try {
					throw new WithdrawException("ȡ����:"+name+" �˻���"+balance+" ȡ��"+a+" ԭ��͸֧ ");
				} 
			     catch (WithdrawException e) {
			    	 System.out.println(e.getMessage());
					}
				else 
					balance-=a;
				}
		if(jibie=='D')
		{
			if(a>balance+1000)
				try {
					throw new WithdrawException("ȡ����:"+name+" �˻���"+balance+" ȡ��"+a+" ԭ��͸֧ ");
				} 
			     catch (WithdrawException e) {
			    	 System.out.println(e.getMessage());
					}
				else 
					balance-=a;
				}
	}
	
}

//ȡ���쳣
class WithdrawException extends Exception
{
	WithdrawException(String e)
	{
		super(e);
	}
	/* public String getMessage()
	{
	String a = null;		 
		return a;
	}*/
}

