#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int array[15],positivecount=0,negativecount=0,oddcount=0,evencount=0,zerocount=0,largest=-999999,smallest=0;
    for(int i=0;i<15;i++)
    {
        cout << "Enter an integer: ";
        cin  >> array[i];
        if(array[i]>0)
            positivecount++;
        if(array[i]<0)
            negativecount++;
        if(array[i]%2!=0)
            oddcount++;
        if(array[i]%2==0)
            evencount++;
        if(array[i]==0)
            zerocount++;
        if(array[i]>largest)
            largest=array[i];
        if(array[i]<smallest)
            smallest=array[i];
    }
    cout << "\nThe positive values are: " << positivecount << endl;
    cout << "The negative values are: " << negativecount << endl;
    cout << "The odd values are: " << oddcount << endl;
    cout << "The even values are: " << evencount << endl;
    cout << "The zero values are: " << zerocount << endl;
    cout << "The largest value is: " << largest << endl;
    cout << "The smallest value is: " << smallest << "\n" << endl;

    double index[30];
    for(int i=0;i<30;i++)
    {
        if(i<15)
            index[i]=i*i;
        else
            index[i]=3*i;
    }
    for(int i=0;i<30;i++)
    {
        cout << fixed << setprecision(2) << index[i] << " ";
        if((i+1)%5==0)
            cout << endl;
    }
    cout << "\n" << endl;

    int arr[5],i,ars[5];
    for(i=0;i<5;i++)
    {
        cout << "Enter an integer: ";
        cin  >> arr[i];
    }

    cout << "\nArray 1: ";
    for(i=0;i<5;i++)
        cout << arr[i] << " ";

    for(i=0;i<5;i++)
        ars[i]=arr[4-i];

    cout << "\nArray 2: ";
    for(i=0;i<5;i++)
        cout << ars[i] << " ";
    cout << "\n" << endl;

    int arc[10],num,input,count=0;
    for(i=0;i<10;i++)
    {
        cout << "Input a number: ";
        cin  >> input;
        arc[i]=input;
    }
    cout << "\nEnter a number: ";
    cin  >> num;
    for(int j=0;j<10;j++)
    {
        if(arc[j]==num)
            count++;
    }
    if(count>=1)
        cout << num << " is present in an array" << endl;
    else
        cout << num << " is not present in an array" << endl;
    cout << count << " times " << num << " appear in the array" << endl;
    return 0;
}
