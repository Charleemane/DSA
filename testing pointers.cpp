//--Declaring Pointers and Dereferencing--//
/*#include <iostream>

using namespace std;

int main(){
	int *p, *y;
	
	int x = 100;
	p = &x;
	y = p;
	
	cout << *y;
}*/



//--New and Delete Operators--//
/*#include <iostream>

using namespace std;

int main(){
    int *p1, *p2;
    p1 = new int;
    *p1 = 42;
    p2 = p1;
    
    cout << "*p1 = " << *p1 << endl;
    cout << "*p2 = " << *p2 << endl;
    
    *p2 = 53;
    
    cout << "*p1 = " << *p1 << endl;
    cout << "*p2 = " << *p2 << endl;
    
    delete(p1);
    
    cout << "*p1 = " << *p1 << endl;
    cout << "*p2 = " << *p2 << endl;
}*/



//--Call-by-Value--//
//pointers both in void and main point to same address//
/*#include <iostream>

using namespace std;

typedef int *IntPtr;

void sneaky(IntPtr temp);

int main(){
    IntPtr p;
    p = new int;
    *p = 77;
    
    cout << "Value point to by p: " << *p << endl;
    sneaky(p);
    cout << "Value point to by p: " << *p << endl;
    
}

void sneaky (IntPtr temp) {
	cout << "Value point to by temp: " << *temp << endl;
    *temp = 99;
    cout << "Value point to by temp: " << *temp << endl;
    delete(temp);
}*/



//--Dynamic Array--//
//changes in pointer p[i] affects array a[i]//
#include <iostream>

using namespace std;

typedef int *IntPtr;

int main(){
    IntPtr p;
    int a[10];
    
    for (int i = 0; i<10; i++) {
        a[i] = i;
    }
    
    cout << "Contents of array a...\n";
    for (int i = 0; i<10; i++) {
       cout << a[i] << " ";
    }
    
    p = a;
    cout << "\nContents pointed to by pointer p...\n";
    for (int i = 0; i<10; i++) {
       cout << p[i] << " ";
    }
    
    //change to p[i]
    for (int i = 0; i<10; i++){
        p[i] = p[i] + 1;
    }
    
    cout << "\nNew contents of array a after processing...\n";
    for (int i = 0; i<10; i++){
        cout << a[i] << " ";
    }
    
    cout << "\n";
}
