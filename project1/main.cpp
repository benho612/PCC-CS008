#include <iostream>
#include <vector>
#include <string>

void twoDArray();

void functionVector();

void selection();

using namespace std;

int main() {
    string yesNo;
    string answer;
    cout << "Do you really want to use this program(yes/no)?";
    cin >> yesNo;
    if(yesNo == "Yes" || yesNo == "yes")
    {
        cout<<"Do you like 2d-array or vector?";
        cin>> answer;
        if(answer == "2d-array")
        {
            twoDArray();
        }
        else
        {
            functionVector();
        }
    }
    else
    {
        cout <<"See ya";
        return 0;
    }
}

void twoDArray() {
    int rows, columns;
    int i,j;
    cout<<"Enter the row of 2d-array\n";
    cin >> rows;
    cout<<"Enter the column of 2d-array\n";
    cin >> columns;
    int arr[rows][columns];
    for(i=0;i<rows;i++)
    {
        for(j=0;j<columns;j++)
        {
            cout<<"\narr["<<i<<"]["<<j<<"]=  ";
            cin>>arr[i][j];
        }
    }
    cout<<"Printing:\n";
    for(i=0;i<rows;i++)
    {
        for(j=0;j<columns;j++)
        {
            cout<<"\t"<<arr[i][j];
        }
        cout<<endl;
    }
    selection();
}

void functionVector() {
    vector<string> vec;
    string a;
    string NewVar;
    int pos;
    int answer;
    cout << "Enter any number(Press 0 to stop)\n";
    while(cin>>a)
    {
        vec.push_back(a);
        cout<<"next?\n";
        if(a == "0")
        {
            break;
        }
    }
    cout <<"Printing:\n";
    for (auto & i : vec)
    {
        cout << i << " ";
    }
    cout <<"\n";
    cout <<"Any changes\n 1-Check the Size\n 2-insert new var\n 3-Done\n";
    cin >>answer;
    switch (answer)
    {
        case 1:
            cout<<"The size of the vector is " << vec.size();
            selection();
            break;
        case 2:
            cout<<"What is the variable?\n";
            cin>>NewVar;
            cout<<"Where do you want to insert\n";
            cin>>pos;
            vec.insert(vec.begin()+pos,NewVar);
            cout <<"Printing:\n";
            for (auto & i : vec)
            {
                cout << i << " ";
            }
            selection();
            break;
        case 3:
            cout<<"ok";
            selection();
            break;
        default:
            cout<<"Choices other than 1,2,3,4\n";
            selection();
            break;
    }
}

void selection(){
    int x;
    cout<<"\nPress-1 Try Vector\nPress 2-Try 2d-Array\nPress 3-exit program\n";
    cin >>x;
    switch(x){
        case 1:
            functionVector();
            break;
        case 2:
            twoDArray();
            break;
        case 3:
            cout<<"goodbye";
            exit(0);
        default:
            printf("Choice other than 1, 2 and 3");
            break;

    }

}