#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>


using namespace std;
const int MAX = 100;


class Student
{
	private:
		string m_name;
		int m_id;
	public:
		SinhVien(string name[],int id){	}
		void Setname(string &name){
			name = m_name;
		}
		
		string Getname()
		{
			return m_name;
		}
		int Setid(int id)
		{
			id = m_id;
		}
		void Show(Student st[], int &num_students, string &name);
		void Add(Student st[], int &num_students, int &pos);
		void Remove(Student st[], int &num_students);
		void Sort(Student st[], int &num_students)	;
		void Writefile( Student st[], int &num_students, ofstream file );
		void Readfile(ifstream file);
		~Student(){		}
};
/*

void Student :: Show(Student st[], int &num_students, string &name)
{
	cout << " Thong tin sinh vien la : " << endl;
	for( int i = 0; i < num_students; i++)
	{
		cout <<st[i].Getname()<<" , "<< st[i].m_id ;
	}
} */
void Student :: Add(Student st[], int &num_students, int &pos)
{
	cout << " Moi nhap thong tin sinh vien moi " << endl;
	Student new_student;
	cout << " Moi nhap thu tu sinh vien muon add " << endl;
	cin >> pos ;
	for(int i = num_students - 1; i > pos ; i--)
	{
		st[i+1] = st [ i];
		
 	}
 	st[pos-1] = new_student;
 	num_students ++;
 	cout << "Sinh vien da duoc them vao list";
}
void Student :: Remove(Student st[], int &num_students)
{
	int order;
	cout << " Moi nhap thu tu sinh Vien muon xoa :  "<<endl;
	cin >> order;
	for (int i = order; i < num_students; i++)
	{
		st[i-1] = st[i];
		num_students --;
	}
	cout << " da xoa sinh vien " << endl;
	
}
void Student :: Sort(Student st[], int &num_students)
{
	for( int i = 0; i< num_students; i++)
	{
		for ( int j = 0; j < num_students - 1; j++)
		{
			if ( strcmp(st[i].Getname().data(),st[j].Getname().data()) > 1)
			{
				Student k = st[i];
				st[i] = st[j + 1];
				st[j + 1] = k;
			}
		
		}
		
	}
}
void Student::Writefile(Student st[], int &num_students, ofstream file )
{
	file.open("danhsachsinhvien.txt");
	for ( int i = 0; i< num_students; i++){
		file<<st[i].Getname();
	}
	file.close();
}
void Student::Readfile(ifstream file)
{
	if( file.is_open())
	{
		while( !file.eof())
		{
			string line;
			getline(file,line);
			cout <<line <<endl;
		}
	}
	else
	{
		cout << " error ! cannot open file";	
	}
	 
	file.close();
	cin.get();
 } 

int main()
{
	
	return 0;
}
