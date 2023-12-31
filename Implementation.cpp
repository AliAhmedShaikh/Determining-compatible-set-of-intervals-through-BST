#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
class program{
	public:
		int starttime;
		int duration;
		int ctime;
		program *nextshow;
		program *previousshow;
		program()
		{
			starttime = 0;
			duration = 0;
			ctime = 0;
			nextshow = NULL;
			previousshow = NULL;
		}
};
class transmission
{
	private:
		program* starting;
		ofstream compt;
		ofstream collision;
	public:
		transmission()
		{
			starting = NULL;
			compt.open("compatible.txt");
			collision.open("conflict.txt");
		}
		void entershow(int starttime,int duration,int ctime)
		{
			program* show = new program();
			show->ctime = ctime;
			show->starttime = starttime;
			show->duration = duration;
			if(starting == NULL)
			{
				starting = show;
			}
			else if(starttime+duration+ctime <= starting->starttime)
			{
				if(starting->previousshow == NULL)
				{
					starting->previousshow = show;
				}
				else
				{
					entershow(starttime,duration,ctime,starting->previousshow);
				}
			}
			else if(starttime >= starting->starttime+starting->duration+starting->ctime)
			{
				if(starting->nextshow == NULL)
				{
					starting->nextshow = show;
				}
				else
				{
					entershow(starttime,duration,ctime,starting->nextshow);
				}
			}
			else
			{
				collision << starttime << ' ' << duration << ' ' << ctime << '\n';	
			}			
		}
		void entershow(int starttime,int duration,int ctime,program* control)
		{
			program* show = new program();
			show->ctime = ctime;
			show->starttime = starttime;
			show->duration = duration;
			if(starttime+duration+ctime <= control->starttime)
			{
				if(control->previousshow == NULL)
				{
					control->previousshow = show;
				}
				else
				{
					entershow(starttime,duration,ctime,control->previousshow);
				}
			}
			else if(starttime >= control->starttime+control->duration+control->ctime)
			{
				if(control->nextshow == NULL)
				{
					control->nextshow = show;
				}
				else
				{
					entershow(starttime,duration,ctime,control->nextshow);
				}
			}
			else
			{
				collision << starttime << ' ' << duration << ' ' << ctime << '\n';	
			}			
		}
		void showtimings()
		{
			if(starting->previousshow != NULL)
			{
				showtimings(starting->previousshow);
			}
			compt << starting->starttime << ' ' << starting->duration << ' ' << starting->ctime << '\n';
			cout << starting->starttime << " " << starting->duration << " " << starting->ctime << endl;
			if(starting->nextshow != NULL)
			{
				showtimings(starting->nextshow);
			}			
		}
		void showtimings(program* start)
		{
			if(start->previousshow != NULL)
			{
				showtimings(start->previousshow);
			}
			compt << start->starttime << ' ' << start->duration << ' ' << start->ctime << '\n';
			cout << start->starttime << " " << start->duration << " " << start->ctime << endl;
			if(start->nextshow != NULL)
			{
				showtimings(start->nextshow);
			}			
		}
		~transmission(){
			compt.close();
			collision.close();
		}
};
int main()
{
	int a=0,b,c,n=0;
	transmission t;
	int i=1;
	ifstream infile("1.txt");
	ifstream infil("2.txt");
	ifstream infie("3.txt");
	ifstream ifile("4.txt");
	ifstream infle("5.txt");
	ofstream merge("input.txt");
	if(!infile.eof())
	{
		infile >> a;
		n+= a;}
	if(!infil.eof())
	{
		infil >> a;
		n+= a;	}
	if(!infie.eof())
	{
		infie >> a;
		n+= a;}
	if(!infil.eof())
	{
		ifile >> a;
		n+= a;	}
	if(!ifile.eof())
	{
		infle >> a;
		n+= a;}	
	while(1)
	{
		if(i==0) 
		{
			if(infile.eof())
				break;
			infile >> a >> b >> c;
			merge << a << ' ' << b << ' ' << c << '\n';
			if(infile.eof())
				break;
		}
		else if(i==1)
		{
			if(infil.eof())
				break;	
			infil >> a >> b >> c;
			merge << a << ' ' << b << ' ' << c << '\n';
			if(infil.eof())
				break;
		}
		else if(i==2)
		{
			if(infie.eof())
				break;
			infie >> a >> b >> c;
			merge << a << ' ' << b << ' ' << c << '\n';
			if(infie.eof())
				break;
		}
		else if(i==3)
		{
			ifile >> a >> b >> c;
			merge << a << ' ' << b << ' ' << c << '\n';
			if(ifile.eof())
				break;			
		}
		else if(i==4)
		{
			infle >> a >> b >> c;
			merge << a << ' ' << b << ' ' << c << '\n';
			if(infle.eof())
				break;				
		}
	}
	while(!infile.eof())
	{
		if(infile.eof())
			break;
		infile >> a >> b >> c;
		merge << a << ' ' << b << ' ' << c << '\n';
		if(infile.eof())
			break;
	}
	while(!infil.eof())
	{
		if(infil.eof())
			break;
		infil >> a >> b >> c;
		merge << a << ' ' << b << ' ' << c << '\n';
		if(infil.eof())
			break;
	}
	while(!infie.eof())
	{
		if(infie.eof())
			break;
		infie >> a >> b >> c;
		merge << a << ' ' << b << ' ' << c << '\n';
		if(infie.eof())
			break;
	}
	while(!ifile.eof())
	{
		if(ifile.eof())
			break;
		ifile >> a >> b >> c;
		merge << a << ' ' << b << ' ' << c << '\n';
		if(ifile.eof())
			break;
	}
	while(!infle.eof())
	{
		if(infie.eof())
			break;
		infle >> a >> b >> c;
		merge << a << ' ' << b << ' ' << c << '\n';
		if(infie.eof())
			break;
	}
	merge.close();
	ifstream uyy("input.txt");
	int *we = new int[n];
	int *q = new int[n];
	int *w = new int[n];
	i=0;
	uyy >> a >> b >> c;
	t.entershow(a,b,c);
	while(!uyy.eof())
	{
		uyy >> a >> b >> c;
		we[i] = a;
		q[i] = b;
		w[i] = c; 
		i++;
	}
	uyy.close();
	int k=0;
	for(i=n/2;i>=1;i=i/2)
	{
		k=0;
		for(int j=i;j<n-1;j++)
		{
			if(we[i] > we[j])
			{
				k=1;
				a = we[i];
				b = q[i];
				c = w[i];
				we[j]= we[j-i];
				q[j] = q[j-i];
				w[j] = w[j-i];
				we[j-i] = a;
				q[j-i] = b;
				w[j-i] = c;
			}
		}
		if(k==1 && i==1)
		{
			i = 2;	
		}
	}
	for(i=0;i<n-1;i++)
	{
		cout << we[i] << " " << q[i] << " " << w[i] << endl;
	}
	cout << endl;
	ifstream se("input.txt");
	i = 0;
	while(i<n)
	{
		t.entershow(we[i],q[i],w[i]);
		i++;
	}	
	t.showtimings();
}
