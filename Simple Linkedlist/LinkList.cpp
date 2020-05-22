#include<bits/stdc++.h>
#include<ctype.h>
#include<string.h>

#include<stdio.h>

#define TAKING                      freopen("input.txt" , "r" , stdin);
#define MAKING                      freopen("output.txt","w" , stdout);

#define     ll                      long long
#define     sf                      scanf
#define     pf                      printf
#define     pb                      push_back
#define     mp                      make_pair
#define     nl                      "\n"
#define     BOLT                    ios_base::sync_with_stdio(0)

#define     all(x)                  x.begin(), x.end()
#define     rall(x)                 x.rbegin(), x.rend()
#define     fi                      first
#define     se                      second
#define     sz(v)                   (int)(v).size()
#define     REMOVE_ALL(str , c)     str.erase(remove(str.begin(), str.end(), c), str.end())
#define     PIE                     acos(-1)
#define     pline                   cout << nl

using namespace std;

inline int ini(){int n;cin >> n;return n;}
inline int ini(string s){ cout << s; int n;cin >> n;return n;}

inline ll inl(){ll n;cin >> n;return n;}
inline ll inl(string s){ cout << s; ll n;cin >> n;return n;}

inline double ind(){double n;cin >> n;return n;}
inline double ind(string s){ cout << s; double n;cin >> n;return n;}

inline string ins(){string n;cin >> n;return n;}
inline string ins(string s){ cout << s;string n;cin >> n;return n;}

inline string insl(){string n;getline(cin,n);return n;}
inline string insl(string s){ cout << s;string n;getline(cin,n);return n;}

inline int string_to_int(string s){int n;stringstream ss;ss << s;ss >> n;return n;}    // Same for double and long long
inline string int_to_string(int n){string s;stringstream ss;ss << n;ss >> s;return s;} // Same for double and long long
inline long long string_to_Long_Long(string s){ll res = 0;for(int i = 0 ; i < s.size() ; i++){res = res*10 + (s[i]-'0');}return res;}

typedef vector <int> 	   	 vi;
typedef pair <int,long long> 	pii;

struct Node{
    int data;
    Node *next;
};

Node *Head;

void Insert(int num){
    Node *temp = Head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node *newNode = new Node();
    newNode->data = num;
    temp->next = newNode;
}

void Delete(int pos){
    Node *frontNode = Head->next;
    Node *backNode = Head;
    while(frontNode->next != NULL && pos--){
        backNode= frontNode;
        frontNode = frontNode->next;
    }
    backNode->next = frontNode->next;

}

void Insert(int num , int pos){
    Node *temp = Head;
    while(temp->next != NULL && pos--){
        temp = temp->next;
    }
    Node *newNode = new Node();
    newNode->data = num;
    newNode->next = temp->next;
    temp->next = newNode;
}


void Print(){
    Node *temp = Head;
    cout << "My List : ";
    while(temp->next != NULL){
        temp = temp->next;
        cout << temp->data << " ";
    }
    cout << nl;
}
bool Search(int num){
    Node *temp = Head;
    while(temp->next != NULL){
        temp = temp->next;
        if(temp->data == num){
            return 1;
        }
    }
return 0;
}
int main(){
    Head = new Node();
    Head->next = NULL;
    int n = ini("Enter Number of Element: ");
    for(int i = 0 ; i < n ; i++){
        int num = ini("Enter the Element: ") , pos = ini("Enter Position: ");
        Insert(num , pos);
        Print();
    }

    cout << Search(5) << nl;
    cout << Search(10) << nl;
    cout << Search(15) << nl;

    Delete(3);
    Print();
    Delete(0);
    Print();
    Delete(7);
    Print();

return 0;
}




