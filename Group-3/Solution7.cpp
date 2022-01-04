#include<bits/stdc++.h>
using namespace std;
#define ll int

vector<ll> takeInput()
{
    ll number_of_students;
    cin>>number_of_students;
    vector<ll> studentList(number_of_students);
    for(ll count=0;count<number_of_students;count++)
        cin>>studentList[count];   
    return studentList;
}

ll find_student_in_duo()
{
    vector<ll> studentList = takeInput();
    ll specialStudent=0;
    for(auto student:studentList)
        specialStudent^=student;
    return specialStudent;
}

ll find_student_in_trio()
{
    vector<ll> studentList = takeInput();
    ll ones=0,twos=0,mask=0;
    for(auto student:studentList)
    {
        twos ^= ones & student;
        ones ^= student;
        mask = ~(ones & twos);
        twos &= mask;
        ones &=mask;
    }
    ll specialStudent = ones;
    return specialStudent;
}

int main()
{
    cout<<find_student_in_duo()<<" ";
    cout<<find_student_in_trio();
    return 0;
}

/*
Time Complexity - O(N) + O(N) = O(N)
Space Complexity - O(1) + O(1) = O(1)
*/
