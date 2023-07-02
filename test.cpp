#include <bits/stdc++.h>

using namespace std;

int main(){

    int lmao1, lmao2;
    string input1, input2;
    cin>>input1;
    cin>>input2;
    string num1, num2;
    if (input2[0] == '-')
    {
        for (int i = 1; i < 2; i++)
        {
            num2 += input2[i];
        }
        lmao2 = stoi(num2);
        lmao2 -= 1;
    }
    else if (input2[0] != '-')
    {
        lmao2 = stoi(input2);
        lmao2 += 1;
    }

    if (input1[0] == '-')
    {        
        for (int i = 1; i < 2; i++)
        {
            num1 += input1[i];
        }
        lmao1 = stoi(input1);
        lmao1 -= 1;
    }
    else if (input1[0] != '-')
    {
        lmao1 = stoi(input1);
        lmao1 += 1;
    }
    // if (input1[0] != '-' && input2[0] != '-')
    // {
    //     lmao2 = stoi(input2);
    //     lmao2 += 1;
    //     lmao1 = stoi(input1);
    //     lmao1 += 1;
    // }


    cout<<"Hasil: "<<lmao1<<endl;
    cout<<"Hasil: "<<lmao2<<endl;
    return 0;
}