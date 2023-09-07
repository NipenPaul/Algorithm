/**
Assignment 03 (Hashing)
Problem : Implement different methods of hashing for collision resolution:
• Linear Probing Method
• Quadratic Probing Method
• Double Hashing Method with C=7
• Separate/Direct Chaining Method
In your implementation define array size as M=13 and take 12 different values as input. Give options for
using any collision method and after applying any 2 methods compare their results (percentage of
collision for same data).
*/

/**
Assignment 03 (Hashing)
Name: Nipen Paul
Student ID: 174038
Year: 2nd
Semester: 2nd
Section: A
Subject: Data Structure

using this code OOP concept and c++ language
*/

#include<bits/stdc++.h>

using namespace std;

/// Const value decleare
/// M means hash table size..
const int M = 13;
/// N means input array value size..
const int N = 12;
/// INF means INT_MAX 2000000000
const int INF = 2e9;

/// input 12 value save this array..
int _input_array[M];

/** Function key value return key = value % M
M is array size */
int keyValue(int num)
{
	return num % M;
}


/// Start all Linear Probing class and Method Solution

class Linear{
private:
    int array_Linear[M];
public:
    /// All member Function decleare
    /// Constructor..
    Linear();
    int count_collision_Linear;
    void Linear_Probing_Method();
    void insert_Linear_Probing_Method_value(int);
    int search_Linear_Probing_Method_value(int);
};
/// Outside the class definition
Linear :: Linear()
{
    count_collision_Linear = 0;
 /** initial all array index value is INF...
	INF means Big int value */
	for(int i = 0; i < M; i++)
	{
		array_Linear[i] = INF;
	}
}
void Linear:: Linear_Probing_Method()
{
	for(int i = 0; i < N; i++)
	{
		int value = _input_array[i];
		insert_Linear_Probing_Method_value(value);
	}
	/// Show Value with key in array...
	cout << "Show the Linear Probing Method value and key..\n";
	for(int i = 0; i < N; i++)
	{
		cout << "Value = " << _input_array[i] << ", key = ";
		cout << search_Linear_Probing_Method_value(_input_array[i]);
		cout << endl;
	}
	cout << "Total collision of Linear Probing Method is ";
	cout << count_collision_Linear << endl << endl;
}

/// Linear Probing insert method
void Linear:: insert_Linear_Probing_Method_value(int value)
{
	///f t (k) = (f(k) + t) % M= (i + t) % M
	int key = keyValue(value);
	if(array_Linear[key] == INF)
	{
		array_Linear[key] = value;
	}
	else
	{
		int t = 0;
		int tem_key = key;
		/// key search stop when the key index INF
		while(array_Linear[tem_key] != INF)
		{
			t++;
			tem_key = keyValue(key + t);
			count_collision_Linear++;
		}
		array_Linear[tem_key] = value;
	}
}
/// Linear Probing Serach Method
int Linear:: search_Linear_Probing_Method_value(int value)
{
	int key = keyValue(value), t = 0;
	int tem_key = key;
	/// key search stop when the key index value
	while(array_Linear[tem_key] != value)
	{
		t++;
		tem_key = keyValue(key + t);
	}
	return tem_key;
}
/// End Linear Probing Method




/// Start all Quadratic Probing Class and Method..

class Quadratic{
private:
    int array_Quadratic[M];
public:
    int count_collision_Quadratic;
    /// All member Function decleare
    /// Constructor..
    Quadratic();
    void Quadratic_Probing_Method();
    void insert_Quadratic_Probing_Method_value(int);
    int search_Quadratic_Probing_Method_value(int);
};
/// Outside the class definition
Quadratic::Quadratic()
{
    count_collision_Quadratic = 0;
    /** initial all array index value is INF...
	INF means Big int value */
	for(int i = 0; i < M; i++)
	{
		array_Quadratic[i] = INF;
	}
}
void Quadratic::Quadratic_Probing_Method()
{
	for(int i = 0; i < N; i++)
	{
		int value = _input_array[i];
		insert_Quadratic_Probing_Method_value(value);
	}
	/// Show Value with key in array...
	cout << "Show the Quadratic Probing Method value and key..\n";
	for(int i = 0; i < N; i++)
	{
		cout << "Value = " << _input_array[i] << ", key = ";
		cout << search_Quadratic_Probing_Method_value(_input_array[i]);
		cout << endl;
	}
	cout << "Total collision of Quadratic Probing Method is ";
	cout << count_collision_Quadratic << endl << endl;
}

/// Quadratic Probing insert method
void Quadratic::insert_Quadratic_Probing_Method_value(int value)
{
	///[f t (k) = (f(k) + t^2 ) % M]
	int key = keyValue(value);
	if(array_Quadratic[key] == INF)
	{
		array_Quadratic[key] = value;
	}
	else
	{
		int t = 0;
		int tem_key = key;
		/// key search stop when the key index INF
		while(array_Quadratic[tem_key] != INF)
		{
			t++;
			tem_key = keyValue(key + (t * t));
			count_collision_Quadratic++;
		}
		array_Quadratic[tem_key] = value;
	}
}
/// Quadratic Probing Serach Method
int Quadratic::search_Quadratic_Probing_Method_value(int value)
{
	int key = keyValue(value), t = 0;
	int tem_key = key;
	/// key search stop when the key index value
	while(array_Quadratic[tem_key] != value)
	{
		t++;
		tem_key = keyValue(key + (t * t));
	}
	return tem_key;
}
/// End Quadratic Probing Method



/// Start all Double Hashing class and Method Solution
class Double{
private:
    int array_Double[M];
    /**constant C is a prime number less than hash table size M*/
    const int C = 7;
public:
    int count_collision_Double_Hashing;
    /// All member Function decleare
    /// Constructor..
    Double();
    void Double_Hashing_Method();
    void insert_Double_Hashing_Method_value(int);
    int search_Double_Hashing_Method_value(int);

};
/// Outside the class definition...
Double::Double()
{
    count_collision_Double_Hashing = 0;
    /** initial all array index value is INF...
	INF means Big int value */
	for(int i = 0; i < M; i++)
	{
		array_Double[i] = INF;
	}
}

void Double::Double_Hashing_Method()
{
	for(int i = 0; i < N; i++)
	{
		int value = _input_array[i];
		insert_Double_Hashing_Method_value(value);
	}
	/// Show Value with key in array...
	cout << "Show the Double Hashing Method value and key..\n";
	for(int i = 0; i < N; i++)
	{
		cout << "Value = " << _input_array[i] << ", key = ";
		cout << search_Double_Hashing_Method_value(_input_array[i]);
		cout << endl;
	}
	cout << "Total collision of Double_Hashing Method is ";
	cout << count_collision_Double_Hashing << endl << endl;
}

/// Double Hashing insert method
void Double::insert_Double_Hashing_Method_value(int value)
{
	///[ f t (k) = (f t-1 (k) + j) % M= (i t-1 + j) % M]
	int key = keyValue(value);
	if(array_Double[key] == INF)
	{
		array_Double[key] = value;
	}
	else
	{
		int j = C - (value % C);
		/// key search stop when the key index INF
		while(array_Double[key] != INF)
		{
			key = keyValue(key + j);
			count_collision_Double_Hashing++;
		}
		array_Double[key] = value;
	}
}
/// Double Hashing Serach Method
int Double::search_Double_Hashing_Method_value(int value)
{
	int key = keyValue(value);
	int t = C - (value % C);
	/// key search stop when the key index value
	while(array_Double[key] != value)
	{
		key = keyValue(key + t);
	}
	return key;
}
/// End Double Hashing Method


/// Start all Direct or Separate Chaining Method

struct Node
{
	int data;
    Node *next;
};

Node *direct[M];

class Separate{
public:
    int count_direct_Hashing = 0;
    /// All member Function decleare
    void Separate_Chaining_Method();
    void insert_direct_value(int);
    void direct_show(int);
};
/// Outside the class definition...
void Separate::Separate_Chaining_Method()
{
	for(int i = 0; i < M; i++)
	{
        direct[i] = NULL;
	    direct[i] = new Node;
	    // direct[i] = new Node;
	    /// initial key value insert in link list
	    direct[i]->data = i;
		direct[i]->next = NULL;
	}

	for(int i = 0; i < N; i++)
	{
		int value = _input_array[i];
		insert_direct_value(value);
	}
	/// Show Value with key in array...
	cout << "Show the Direct or Separate Chaining Method value and key..\n\n";
	cout << "Key \t\t Value..\n";
	for(int i = 0; i < M; i++)
	{
		direct_show(i);
	}
	cout << "\nTotal collision of Direct or Separate Chaining Method is ";
	cout << count_direct_Hashing << endl << endl;
}

void Separate::insert_direct_value(int value)
{
	int key = keyValue(value);
	/// create new node
    Node *ptr = new Node;
	ptr->data = value;
	ptr->next = NULL;

    Node *head = direct[key];
	bool ok = false;
	/// if already value inserted then pointer move last node
	while(head->next != NULL)
	{
		head = head->next;
		ok = true;
	}
	head->next = ptr;
	/// if any value collision then ok true
	if(ok)count_direct_Hashing++;
}

void Separate::direct_show(int key)
{
    Node *head = direct[key];
	while(head != NULL)
	{
	    cout << head->data << " -> ";
		head = head->next;
	}
	cout << endl;
}

/// End Direct or Separate Chaining Method



/// Main Function..
int main()
{
    again:
	cout << "Please take 12 different values as input:" << endl;
	for(int i = 0; i < N; i++)
	{
		cin >> _input_array[i];
	}
	same_data:

    /// all class object created..
	Linear obj_linear;
    Quadratic obj_quadratic;
    Double obj_double;
    Separate obj_separate;

	bool ok1 = false, ok2 = false, ok3 = false, ok4 = false;
	int ct = 0;
	cout << "\nPlease Applying any 2 methods then compare their results..\n" << endl;
	lebel:
	cout << "Now option using any collision method:"<< endl;
	cout << "Press 1 Linear Probing Method" << endl;
	cout << "Press 2 Quadratic Probing Method" << endl;
	cout << "Press 3 Double Hashing Method" << endl;
	cout << "Press 4 Direct or Separate Chaining Method\n" << endl;

	int press; cin >> press;
	if(press == 1)
    {
        obj_linear.Linear_Probing_Method();
        ok1 = true;
        ct++;
    }
    else if(press == 2)
    {
        obj_quadratic.Quadratic_Probing_Method();
        ok2 = true;
        ct++;
    }
    else if(press == 3)
    {
        obj_double.Double_Hashing_Method();
        ok3 = true;
        ct++;
    }
    else if(press == 4)
    {
        obj_separate.Separate_Chaining_Method();
        ok4 = true;
        ct++;
    }
    else
    {
        cout << "Invalid key press..! please try again.." << endl;
        goto lebel;
    }
    if(ct == 1)
    {
        cout << "\nPlease Applying another method.." << endl;
        goto lebel;
    }
    if(ct == 2)
    {
        if(ok1 && ok2)
        {
            double collision1, collision2;
            collision1 = (100.0 * obj_linear.count_collision_Linear) / N;
            collision2 = (100.0 * obj_quadratic.count_collision_Quadratic) / N;
            cout << "Linear Probing Method collision is " << collision1 << "%" << endl;
            cout << "Quadratic Probing Method collision is " << collision2 << "%" << endl;
            if(collision1 < collision2)
            {
                cout << "Linear probing is better then Quadratic Probing Method." << endl;
            }
            else if(collision1 > collision2)
            {
                cout << "Quadratic Probing is better then Linear probing Method." << endl;
            }
            else
            {
                cout << "Linear probing and Quadratic Probing Method collision is equal." << endl;
            }
        }
        else if(ok1 && ok3)
        {
            double collision1, collision2;
            collision1 = (100.0 * obj_linear.count_collision_Linear) / N;
            collision2 = (100.0 * obj_double.count_collision_Double_Hashing) / N;
            cout << "Linear Probing Method collision is " << collision1 << "%" << endl;
            cout << "Double Hashing Method collision is " << collision2 << "%" << endl;
            if(collision1 < collision2)
            {
                cout << "Linear probing is better then Double Hashing Method." << endl;
            }
            else if(collision1 > collision2)
            {
                cout << "Double Hashing is better then Linear probing Method." << endl;
            }
            else
            {
                cout << "Double Hashing and Linear probing Method collision is equal." << endl;
            }
        }
        else if(ok1 && ok4)
        {
            double collision1, collision2;
            collision1 = (100.0 * obj_linear.count_collision_Linear) / N;
            collision2 = (100.0 * obj_separate.count_direct_Hashing) / N;
            cout << "Linear Probing Method collision is " << collision1 << "%" << endl;
            cout << "Separate Chaining Method collision is " << collision2 << "%" << endl;
            if(collision1 < collision2)
            {
                cout << "Linear probing is better then Separate Chaining Method." << endl;
            }
            else if(collision1 > collision2)
            {
                cout << "Separate Chaining is better then Linear probing Method." << endl;
            }
            else
            {
                cout << "Separate Chaining and Linear probing Method collision is equal." << endl;
            }
        }
        else if(ok2 && ok3)
        {
            double collision1, collision2;
            collision1 = (100.0 * obj_double.count_collision_Double_Hashing) / N;
            collision2 = (100.0 * obj_quadratic.count_collision_Quadratic) / N;
            cout << "Double Hashing Method collision is " << collision1 << "%" << endl;
            cout << "Quadratic Probing Method collision is " << collision2 << "%" << endl;
            if(collision1 < collision2)
            {
                cout << "Double Hashing is better then Quadratic Probing Method." << endl;
            }
            else if(collision1 > collision2)
            {
                cout << "Quadratic Probing is better then Double Hashing Method." << endl;
            }
            else
            {
                cout << "Quadratic Probing and Double Hashing Method collision is equal." << endl;
            }
        }
        else if(ok2 && ok4)
        {
            double collision1, collision2;
            collision1 = (100.0 * obj_separate.count_direct_Hashing) / N;
            collision2 = (100.0 * obj_quadratic.count_collision_Quadratic) / N;
            cout << "Separate Chaining Method collision is " << collision1 << "%" << endl;
            cout << "Quadratic Probing Method collision is " << collision2 << "%" << endl;
            if(collision1 < collision2)
            {
                cout << "Separate Chaining is better then Quadratic Probing Method." << endl;
            }
            else if(collision1 > collision2)
            {
                cout << "Quadratic Probing is better then Separate Chaining Method." << endl;
            }
            else
            {
                cout << "Quadratic Probing and Separate Chaining Method collision is equal." << endl;
            }
        }
        else if(ok3 && ok4)
        {
            double collision1, collision2;
            collision1 = (100.0 * obj_separate.count_direct_Hashing) / N;
            collision2 = (100.0 * obj_double.count_collision_Double_Hashing) / N;
            cout << "Separate Chaining Method collision is " << collision1 << "%" << endl;
            cout << "Double Hashing Method collision is " << collision2 << "%" << endl;
            if(collision1 < collision2)
            {
                cout << "Separate Chaining is better then Double Hashing Method." << endl;
            }
            else if(collision1 > collision2)
            {
                cout << "Double Hashing is better then Separate Chaining Method." << endl;
            }
            else
            {
                cout << "Double Hashing and Separate Chaining Method collision is equal." << endl;
            }
        }
    }
    char ch;
    cout << "\n Same Data compare the other Method Press 1 otherwise press any key..\n";
    cin >> ch;
    if(ch == '1') goto same_data;
    cout << endl << "You are continue program and new data input press 1 otherwise press any key..\n";
    cin >> ch;
    if(ch == '1') goto again;
    cout << "Good bye\n";
	return 0;
}
