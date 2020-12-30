#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 
int main(int argc, char** argv) {
	int q;
	cin>>q;
	int tam;
	int A[q][100],n[q]={0},key=0;
	for (int i=0;i<q;i++)
	{
		for (int j=0;j<100;j++)
		{
			if (n[i]==0) cin>>n[i];
			if (j<n[i]) cin>>A[i][j];
			else A[i][j]=0;
			
		}
	}
	for (int i=0;i<q;i++)
	{
		for (int j=0;j<99;j++)
		{	
			if (A[i][j]==2048)
			{
				cout<<"Yes"<<endl;
				key=1;
				break;
			}
			for (int k=j+1;k<100;k++)	
				if (A[i][j]<A[i][k]) 
				{
					tam=A[i][k];
					A[i][k]=A[i][j];
					A[i][j]=tam;
				}
		}
		cout<<endl;
	for (int i=0;i<q;i++)
	{
		for (int j=0;j<100;j++)
		{
			cout<<A[i][j]<<"\t";
		}
	}
		if (key!=1)
		{
			for (int j=0;j<100;j++)
			{
				if (A[i][j]==2048)
				{
					cout<<"Yes"<<endl; 
					key=1;
					break;
				}
				if (A[i][j]!=0 && A[i][j]==A[i][j+1] )
				{
					A[i][j]=A[i][j]+A[i][j+1];
					for (int k=j+1;k<99;k++)
					{
						if (A[i][k+1]!=0)
						{
							A[i][k]=A[i][k+1];
							A[i][k+1]=0;
						}
					}
					j=-1;
				}
			}
			
			if (key!=1) cout<<"No"<<endl;
		}
		key=0;
	}
	cout<<endl;
	for (int i=0;i<q;i++)
	{
		for (int j=0;j<100;j++)
		{
			cout<<A[i][j]<<"\t";
		}
	}
	
	return 0;
}
