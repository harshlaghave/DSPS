#include<iostream>
#include<cctype>
#define MAX 50
using namespace std;
    char stack[MAX];
    int top = -1, length;
    void push(char x) {
     if (top == MAX-1) {
         cout << "STACK OVERFLOW\n";
      }
 
      stack[++top] = x;
     
    }
     char pop() {
      if (top == -1) {
       cout << "STACK UNDERFLOW\n";
             return '\0';
     }
     
        return stack[top--];
       
       }
       
      bool isPalindrome(string str)
     {
     string cleanStr="";

     for(char c: str)
      {
       if(isalnum(c))
        {
         cleanStr+=tolower(c);
         }
      }

       int n =cleanStr.length();
        for(int i=0;i<n;i++)
     {
        push(cleanStr[i]);

    }
   for (int i = 0; i < n; i++) {
         if (pop() != cleanStr[i]) {
            return false;
           }
      }

      return true;
   }

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin,str);

    if (isPalindrome(str)) {
        cout <<"\'"<< str <<"\'"<< " is a palindrome." << endl;
    } else {
        cout <<"\'"<< str <<"\'"<< " is not a palindrome." << endl;
    }

    return 0;
}


