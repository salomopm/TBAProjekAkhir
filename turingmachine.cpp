#include <iostream>

using namespace std;

class Node
{
public:
    char data;
    Node *prev;
    Node *next;

    Node(char value)
    {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insert(char value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void displayForward()
    {
        Node *current = head;
        while (current != nullptr)
        {

            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void penjumlahanPositif()
    {
        Node *current = head;
        Node *start = head;
        int hasil = 0;
        while (current != nullptr)
        {
            current = current->next;
            start = start->next;
            if (current->data == 'X' && current->prev->data == 'B')
            {
                // cout<<current->data;
                start->next = current->next;
                start->prev = current->prev;
                start = current;

                break;
            }
        }



        while (start->data != 'B')
        {
            start = start->next;
            if (start->data == 'B' && start->prev->data == 'X')
            {
                start = start->prev;
                start->data = 'B';
                start = start->prev;
                displayForward();
                break;
            }
        }

        while (start->data != 'B')
        {
            start = start->prev;
            if (start->data == '1')
            {
                start->data = 'X';
                displayForward();
                break;
            }
        }

        while (current->data == 'X')
        {
            current = current->next;
            hasil = hasil + 1;
            if (current->data != 'X')
            {
                break;
            }
        }
        cout << "Hasil dari penjumlahan Turing Machine yaitu: " << hasil << endl;
    }

    void penguranganPositif()
    {
        Node *current = head;
        Node *start = head;
        int hasil = 0;
        while (current != nullptr)
        {
            current = current->next;
            start = start->next;
            if (current->data == 'X' && current->prev->data == 'B')
            {
                // cout<<current->data;
                start->next = current->next;
                start->prev = current->prev;
                start = current;

                break;
            }
        }

        while (start->data != 'B')
        {
            start = start->next;
            if (start->data == 'B' && start->prev->data == 'X')
            {
                start = start->prev;
                start->data = 'B';
                start = start->prev;
                displayForward();
                break;
            }
        }

        while (start->data != 'B')
        {
            start = start->prev;
            if (start->data == '1')
            {
                start->data = 'X';
                displayForward();
                break;
            }
        }

        while (current->data == 'X')
        {
            current = current->next;
            hasil = hasil + 1;
            if (current->data != 'X')
            {
                break;
            }
        }
        cout << "Hasil dari penjumlahan Turing Machine yaitu: " << hasil << endl;
    }

    void penjumlahanYXNegatif()
    {

        Node *current = head;
        Node *start = head;
        int hasil = 0;
        while (current != nullptr)
        {
            current = current->next;
            start = start->next;
            if (current->data == 'Y' && current->prev->data == 'B')
            {
                // cout<<current->data;
                start->next = current->next;
                start->prev = current->prev;
                start = current;

                break;
            }
        }

        displayForward();

        while (1)
        {

            while (start->data != 'B')
            {
                start = start->prev;
                if (start->data == 'B' && start->next->data != '1')
                {
                    start = start->next;
                    start->data = 'B';
                    start = start->next;
                    displayForward();
                    break;
                }
            }

            while (start->data != 'B')
            {
                start = start->next;
                if (start->data == 'B' && start->prev->data != '1')
                {
                    start = start->prev;
                    start->data = 'B';
                    start = start->prev;
                    displayForward();
                    break;
                }
            }

            if (start->data == 'B' && start->prev->data == '1')
            {
                start = start->prev;
                start->data = 'Y';
                displayForward();

                while (start->data == 'Y')
                {
                    if (start->data == 'Y')
                    {
                        hasil = hasil + 1;
                        start = start->prev;
                    }
                    else
                    {
                        break;
                    }
                }
                cout << "Hasil dari penjumlahan Turing Machine yaitu: -" << hasil << endl;
                break;
            }
        }

        cout << endl;
    }

    void penguranganYXNegatif()
    {

        Node *current = head;
        Node *start = head;
        int hasil = 0;
        while (current != nullptr)
        {
            current = current->next;
            start = start->next;
            if (current->data == 'Y' && current->prev->data == 'B')
            {
                // cout<<current->data;
                start->next = current->next;
                start->prev = current->prev;
                start = current;

                break;
            }
        }

        displayForward();

        while (1)
        {

            while (start->data != 'B')
            {
                start = start->prev;
                if (start->data == 'B' && start->next->data != '1')
                {
                    start = start->next;
                    start->data = 'B';
                    start = start->next;
                    displayForward();
                    break;
                }
            }

            while (start->data != 'B')
            {
                start = start->next;
                if (start->data == 'B' && start->prev->data != '1')
                {
                    start = start->prev;
                    start->data = 'B';
                    start = start->prev;
                    displayForward();
                    break;
                }
            }

            if (start->data == 'B' && start->prev->data == '1')
            {
                start = start->prev;
                start->data = 'Y';
                displayForward();

                while (start->data == 'Y')
                {
                    if (start->data == 'Y')
                    {
                        hasil = hasil + 1;
                        start = start->prev;
                    }
                    else
                    {
                        break;
                    }
                }
                cout << "Hasil dari pengruangan Turing Machine yaitu: -" << hasil << endl;
                break;
            }
        }

        cout << endl;
    }

    void penjumlahanYXPositif()
    {

        Node *current = head;
        Node *start = head;
        int hasil = 0;
        while (current != nullptr)
        {
            current = current->next;
            start = start->next;
            if (current->data == 'Y' && current->prev->data == 'B')
            {
                // cout<<current->data;
                start->next = current->next;
                start->prev = current->prev;
                start = current;

                break;
            }
        }

        displayForward();

        while (1)
        {

            while (start->data != 'B')
            {
                start = start->prev;
                if (start->data == 'B' && start->next->data != '1')
                {
                    start = start->next;
                    start->data = 'B';
                    start = start->next;
                    displayForward();
                    break;
                }
            }

            if (start->data == 'B' && start->next->data == '1')
            {
                start = start->next;
                start->data = 'B';
                start = start->next;
                displayForward();

                while (start->data == 'X')
                {
                    if (start->data == 'X')
                    {
                        hasil = hasil + 1;
                        start = start->next;
                    }
                    else
                    {
                        break;
                    }
                }
                cout << "Hasil dari penjumlahan Turing Machine yaitu: " << hasil << endl;
                break;
            }

            while (start->data != 'B')
            {
                start = start->next;
                if (start->data == 'B' && start->prev->data != '1')
                {
                    start = start->prev;
                    start->data = 'B';
                    start = start->prev;
                    displayForward();
                    break;
                }
            }
        }

        cout << endl;
    }

    void penguranganYXPositif()
    {

        Node *current = head;
        Node *start = head;
        int hasil = 0;
        while (current != nullptr)
        {
            current = current->next;
            start = start->next;
            if (current->data == 'Y' && current->prev->data == 'B' || current->data == '1')
            {
                // cout<<current->data;
                start->next = current->next;
                start->prev = current->prev;
                start = current;

                break;
            }
        }

        displayForward();

        while (1)
        {

            while (start->data != 'B')
            {
                start = start->prev;
                if (start->data == 'B' && start->next->data != '1')
                {
                    start = start->next;
                    start->data = 'B';
                    start = start->next;
                    displayForward();
                    break;
                }
            }

            if (start->data == 'B' && start->next->data == '1')
            {
                start = start->next;
                start->data = 'B';
                start = start->next;
                displayForward();

                while (start->data == 'X')
                {
                    if (start->data == 'X')
                    {
                        hasil = hasil + 1;
                        start = start->next;
                    }
                    else
                    {
                        break;
                    }
                }
                cout << "Hasil dari pengurangan Turing Machine yaitu: " << hasil << endl;
                break;
            }

            while (start->data != 'B')
            {
                start = start->next;
                if (start->data == 'B' && start->prev->data != '1')
                {
                    start = start->prev;
                    start->data = 'B';
                    start = start->prev;
                    displayForward();
                    break;
                }
            }
        }

        cout << endl;
    }

    void penjumlahanNegatif()
    {
        Node *current = head;
        Node *start = head;
        int hasil = 0;
        while (current != nullptr)
        {
            current = current->next;
            start = start->next;
            if (current->data == 'Y' && current->prev->data == 'B')
            {
                // cout<<current->data;
                start->next = current->next;
                start->prev = current->prev;
                start = current;

                break;
            }
        }

        while (start->data != 'B')
        {
            start = start->next;
            if (start->data == 'B' && start->prev->data == 'Y')
            {
                start = start->prev;
                start->data = 'B';
                start = start->prev;
                displayForward();
                break;
            }
        }

        while (start->data != 'B')
        {
            start = start->prev;
            if (start->data == '1')
            {
                start->data = 'Y';
                displayForward();
                break;
            }
        }

        while (current->data == 'Y')
        {
            current = current->next;
            hasil = hasil + 1;
            if (current->data != 'Y')
            {
                break;
            }
        }
        cout << "Hasil dari penjumlahan Turing Machine yaitu: -" << hasil << endl;
    }

    void penguranganNegatif()
    {
        Node *current = head;
        Node *start = head;
        int hasil = 0;
        while (current != nullptr)
        {
            current = current->next;
            start = start->next;
            if (current->data == 'Y' && current->prev->data == 'B')
            {
                // cout<<current->data;
                start->next = current->next;
                start->prev = current->prev;
                start = current;

                break;
            }
        }

        while (start->data != 'B')
        {
            start = start->next;
            if (start->data == 'B' && start->prev->data == 'Y')
            {
                start = start->prev;
                start->data = 'B';
                start = start->prev;
                displayForward();
                break;
            }
        }

        while (start->data != 'B')
        {
            start = start->prev;
            if (start->data == '1')
            {
                start->data = 'Y';
                displayForward();
                break;
            }
        }

        while (current->data == 'Y')
        {
            current = current->next;
            hasil = hasil + 1;
            if (current->data != 'Y')
            {
                break;
            }
        }
        cout << "Hasil dari pegurangan Turing Machine yaitu: -" << hasil << endl;
    }

    void penjumlahanPositifDiff()
    {
        Node *current = head;
        Node *start = head;
        int hasil = 0;

        while (current != nullptr)
        {
            current = current->next;
            start = start->next;
            if (current->data == 'X' && current->prev->data == 'B')
            {
                // cout<<current->data;
                start->next = current->next;
                start->prev = current->prev;
                start = current;
                current = current->prev;

                break;
            }
        }
        displayForward();

        while (1)
        {

            while (start->data != 'B')
            {
                start = start->prev;
                if (start->data == 'B' && start->next->data != '1')
                {
                    start = start->next;
                    start->data = 'B';
                    start = start->next;
                    displayForward();
                    break;
                }
            }

            while (start->data != 'B')
            {
                start = start->next;
                if (start->data == 'B' && start->prev->data != '1')
                {
                    start = start->prev;
                    start->data = 'B';
                    start = start->prev;
                    displayForward();
                    break;
                }
            }
            if (start->data == 'B' && start->prev->data == '1')
            {
                start = start->prev;
                start->data = 'X';
                displayForward();

                while (start->data == 'X')
                {
                    if (start->data == 'X')
                    {
                        hasil = hasil + 1;
                        start = start->prev;
                    }
                    else
                    {
                        break;
                    }
                }
                cout << "Hasil dari penjumlahan Turing Machine yaitu: " << hasil << endl;
                break;
            }
        }

        cout << endl;
    }

    void penguranganPositifDiff()
    {
        Node *current = head;
        Node *start = head;
        int hasil = 0;

        while (current != nullptr)
        {
            current = current->next;
            start = start->next;
            if (current->data == 'X' && current->prev->data == 'B')
            {
                // cout<<current->data;
                start->next = current->next;
                start->prev = current->prev;
                start = current;
                current = current->prev;

                break;
            }
        }
        displayForward();

        while (1)
        {

            while (start->data != 'B')
            {
                start = start->prev;
                if (start->data == 'B' && start->next->data != '1')
                {
                    start = start->next;
                    start->data = 'B';
                    start = start->next;
                    displayForward();
                    break;
                }
            }

            while (start->data != 'B')
            {
                start = start->next;
                if (start->data == 'B' && start->prev->data != '1')
                {
                    start = start->prev;
                    start->data = 'B';
                    start = start->prev;
                    displayForward();
                    break;
                }
            }
            if (start->data == 'B' && start->prev->data == '1')
            {
                start = start->prev;
                start->data = 'X';
                displayForward();

                while (start->data == 'X')
                {
                    if (start->data == 'X')
                    {
                        hasil = hasil + 1;
                        start = start->prev;
                    }
                    else
                    {
                        break;
                    }
                }
                cout << "Hasil dari pengurangan Turing Machine yaitu: " << hasil << endl;
                break;
            }
        }

        cout << endl;
    }

    void penjumlahanNegatifDiff()
    {
        Node *current = head;
        Node *start = head;
        int hasil = 0;

        while (current != nullptr)
        {
            current = current->next;
            start = start->next;
            if (current->data == 'X' && current->prev->data == 'B')
            {
                // cout<<current->data;
                start->next = current->next;
                start->prev = current->prev;
                start = current;
                current = current->prev;

                break;
            }
            else if (current->data == 'B' && current->next->data == '1')
            {
                break;
            }
        }

        displayForward();

        while (1)
        {

            while (start->data != 'B')
            {
                start = start->prev;
                if (start->data == 'B' && start->next->data != '1')
                {
                    start = start->next;
                    start->data = 'B';
                    start = start->next;
                    displayForward();
                    break;
                }
            }

            if (start->data == 'B' && start->next->data == '1')
            {
                start = start->next;
                start->data = 'B';
                start = start->next;
                displayForward();

                while (start->data == 'Y')
                {
                    if (start->data == 'Y')
                    {
                        hasil = hasil + 1;
                        start = start->next;
                    }
                    else
                    {
                        break;
                    }
                }
                cout << "Hasil dari penjumlahan Turing Machine yaitu: -" << hasil << endl;
                break;
            }

            while (start->data != 'B')
            {
                start = start->next;
                if (start->data == 'B' && start->prev->data != '1')
                {
                    start = start->prev;
                    start->data = 'B';
                    start = start->prev;
                    displayForward();
                    break;
                }
            }
        }

        cout << endl;
    }

    void penguranganNegatifDiff()
    {
        Node *current = head;
        Node *start = head;
        int hasil = 0;

        while (current != nullptr)
        {
            current = current->next;
            start = start->next;
            if (current->data == 'X' && current->prev->data == 'B')
            {
                // cout<<current->data;
                start->next = current->next;
                start->prev = current->prev;
                start = current;
                current = current->prev;

                break;
            }
            else if (current->data == 'B' && current->next->data == '1')
            {
                break;
            }
        }

        displayForward();

        while (1)
        {

            while (start->data != 'B')
            {
                start = start->prev;
                if (start->data == 'B' && start->next->data != '1')
                {
                    start = start->next;
                    start->data = 'B';
                    start = start->next;
                    displayForward();
                    break;
                }
            }

            if (start->data == 'B' && start->next->data == '1')
            {
                start = start->next;
                start->data = 'B';
                start = start->next;
                displayForward();

                while (start->data == 'X')
                {
                    if (start->data == 'X')
                    {
                        hasil = hasil + 1;
                        start = start->next;
                    }
                    else
                    {
                        break;
                    }
                }
                cout << "Hasil dari pengurangan Turing Machine yaitu: -" << hasil << endl;
                break;
            }

            while (start->data != 'B')
            {
                start = start->next;
                if (start->data == 'B' && start->prev->data != '1')
                {
                    start = start->prev;
                    start->data = 'B';
                    start = start->prev;
                    displayForward();
                    break;
                }
            }
        }

        cout << endl;
    }

    void insertX(char data)
    {
        int i;

        Node *newnode = new Node(data);
        Node *tmp;
        if (tail == NULL)
        {
            cout << "No data found in the list!\n";
        }
        else
        {
            tmp = head;
            i = 1;
            while (tmp->next->data == 'B' && tmp->next->data != '1')
            {
                tmp = tmp->next;
                i++;
            }
            if (tmp != NULL)
            {
                newnode->next = tmp->next;
                newnode->prev = tmp;
                if (tmp->next != NULL)
                {
                    tmp->next->prev = newnode;
                }
                tmp->next = newnode;
            }
            else
            {
                cout << "The position you entered is invalid.\n";
            }
        }
    }

    void replaceNodeValueX()
    {
        Node *currentNode = head;
        char targetValue = 'X';
        char newValue = 'B';

        while (currentNode != nullptr)
        {
            if (currentNode->data == targetValue)
            {
                currentNode->data = newValue;
                break;
            }
            currentNode = currentNode->next;
        }
    }

    void replaceNodeValueY()
    {
        Node *currentNode = head;
        char targetValue = 'Y';
        char newValue = 'B';

        while (currentNode != nullptr)
        {
            if (currentNode->data == targetValue)
            {
                currentNode->data = newValue;
                break;
            }
            currentNode = currentNode->next;
        }
    }

    void reverseNode()
    {
        Node *currentNode = head;
        Node *currentNode1 = tail;
        char targetValue1 = 'X';
        char newValue1 = 'Y';

        char targetValue2 = 'Y';
        char newValue2 = 'X';

        while (currentNode->data != '1')
        {
            if (currentNode->data == targetValue1)
            {
                currentNode->data = newValue1;
                break;
            }
            currentNode = currentNode->next;
        }

        while (currentNode1->data != '1')
        {
            if (currentNode1->data == targetValue2)
            {
                currentNode1->data = newValue2;
                break;
            }
            currentNode1 = currentNode1->prev;
        }
    }

    void replaceNodeValueYtoX()
    {
        Node *currentNode = head;
        char targetValue = 'Y';
        char newValue = 'X';

        while (currentNode != nullptr)
        {
            if (currentNode->data == targetValue)
            {
                currentNode->data = newValue;
                break;
            }
            currentNode = currentNode->next;
        }
    }

    void replaceNodeValueXtoY()
    {
        Node *currentNode = head;
        char targetValue = 'X';
        char newValue = 'Y';

        while (currentNode != nullptr)
        {
            if (currentNode->data == targetValue)
            {
                currentNode->data = newValue;
                break;
            }
            currentNode = currentNode->next;
        }
    }

    void insertY(char data)
    {
        int i;

        Node *newnode = new Node(data);
        Node *tmp;
        if (tail == NULL)
        {
            cout << "No data found in the list!\n";
        }
        else
        {
            tmp = head;
            i = 1;
            while (tmp->data != '1')
            {
                tmp = tmp->next;
                i++;
            }
            if (tmp != NULL)
            {
                newnode->next = tmp->next;
                newnode->prev = tmp;
                if (tmp->next != NULL)
                {
                    tmp->next->prev = newnode;
                }
                tmp->next = newnode;
            }
            else
            {
                cout << "The position you entered is invalid.\n";
            }
        }
    }

    void insertYPositif(char data)
    {
        int i;

        Node *newnode = new Node(data);
        Node *tmp;
        if (tail == NULL)
        {
            cout << "No data found in the list!\n";
        }
        else
        {
            tmp = head;
            i = 1;
            while (tmp->data != '1')
            {
                tmp = tmp->next;
                i++;
            }
            if (tmp != NULL)
            {
                newnode->next = tmp->next;
                newnode->prev = tmp;
                if (tmp->next != NULL)
                {
                    tmp->next->prev = newnode;
                }
                tmp->next = newnode;
            }
            else
            {
                cout << "The position you entered is invalid.\n";
            }
        }
    }

    void insertXNegatif(char data)
    {
        int i;

        Node *newnode = new Node(data);
        Node *tmp;
        if (tail == NULL)
        {
            cout << "No data found in the list!\n";
        }
        else
        {
            tmp = head;
            i = 1;
            while (tmp->next->data != '1')
            {
                tmp = tmp->next;
                i++;
            }
            if (tmp != NULL)
            {
                newnode->next = tmp->next;
                newnode->prev = tmp;
                if (tmp->next != NULL)
                {
                    tmp->next->prev = newnode;
                }
                tmp->next = newnode;
            }
            else
            {
                cout << "The position you entered is invalid.\n";
            }
        }
    }
};

int main()
{
    char data;

    int num1, num2, nilai, input, choice;
    string input1, input2;
    string stringNum1, stringNum2;

    DoublyLinkedList list;
    list.insert('B');
    list.insert('B');
    list.insert('B');
    list.insert('X');
    list.insert('1');
    list.insert('Y');
    list.insert('B');
    list.insert('B');
    list.insert('B');

    cout << "Pilih Operasi" << endl;
    cout << "1. Penjumlahan" << endl;
    cout << "2. Pengurangan" << endl;
    cout << "$ ";
    cin >> choice;

    switch (choice)
    {
    case (1):
        cout << "Input Num 1: \n$ ";
        cin >> input1;

        cout << "Input Num 2: \n$ ";
        cin >> input2;

        if (input2[0] == '-' && input1[0] != '-')
        {
            for (int i = 1; i < 3; i++)
            {
                stringNum2 += input2[i];
            }
            num2 = stoi(stringNum2);
            num1 = stoi(input1);
            // cout<<num1;
            if (num2 > num1 && num1 > 0)
            {

                for (int i = 0; i < num1 - 1; i++)
                {
                    list.insertX('X');
                }

                for (int i = 0; i < num2 - 1; i++)
                {
                    list.insertY('Y');
                }
                list.penjumlahanNegatifDiff();
            }
            else if (num1 == 0 && num2 > 0)
            {
                for (int i = 0; i < 1; i++)
                {
                    list.replaceNodeValueX();
                }
                for (int i = 0; i < num2 - 1; i++)
                {
                    list.insertY('Y');
                }
                list.penjumlahanNegatifDiff();
            }
            else if (num1 > num2 && num2 > 0)
            {
                for (int i = 0; i < num1 - 1; i++)
                {
                    list.insertX('X');
                }

                for (int i = 0; i < num2 - 1; i++)
                {
                    list.insertY('Y');
                }
                list.penjumlahanPositifDiff();
            }
            else if (num2 == num1)
            {
                for (int i = 0; i < num1 - 1; i++)
                {
                    list.insertX('X');
                }

                for (int i = 0; i < num2 - 1; i++)
                {
                    list.insertY('Y');
                }
                list.penjumlahanNegatifDiff();
            }
        }
        if (input2[0] != '-')
        {
            num1 = stoi(input1);
            num2 = stoi(input2);
            if (num1 == 0 && num2 == 0)
            {
                for (int i = 0; i < 1; i++)
                {
                    list.replaceNodeValueX();
                }
                for (int i = 0; i < 1; i++)
                {
                    list.replaceNodeValueY();
                }
                list.penjumlahanNegatifDiff();
            }
        }

        if (input1[0] == '-' && input2[0] != '-')
        {

            list.reverseNode();
            for (int i = 1; i < 3; i++)
            {
                stringNum1 += input1[i];
            }
            num1 = stoi(stringNum1);
            num2 = stoi(input2);
            // cout << num1 << endl;
            // cout << num2 << endl;

            if (num1 > num2 && num2 > 0)
            {
                list.displayForward();

                for (int i = 0; i < num1 - 1; i++)
                {
                    list.insertXNegatif('Y');
                }
                for (int i = 0; i < num2 - 1; i++)
                {
                    list.insertYPositif('X');
                }

                list.penjumlahanYXNegatif();
            }
            else if (num2 > num1 && num1 > 0)
            {
                for (int i = 0; i < num1 - 1; i++)
                {
                    list.insertXNegatif('Y');
                }
                for (int i = 0; i < num2 - 1; i++)
                {
                    list.insertYPositif('X');
                }

                list.penjumlahanYXPositif();
            }
            else if (num1 == num2)
            {
                for (int i = 0; i < num1 - 1; i++)
                {
                    list.insertXNegatif('Y');
                }
                for (int i = 0; i < num2 -1; i++)
                {
                    list.insertYPositif('X');
                }
                list.penjumlahanYXPositif();
            }
            else if (num1 > 0 && num2 == 0)
            {
                for (int i = 0; i < num1 - 1; i++)
                {
                    list.insertXNegatif('Y');
                }
                for (int i = 0; i < 1; i++)
                {
                    list.replaceNodeValueX();
                }
                list.penjumlahanYXNegatif();
            }
        }

        if (input1[0] != '-' && input2[0] != '-')
        {
            
            num1 = stoi(input1);
            num2 = stoi(input2);
            list.replaceNodeValueYtoX();
            for (int i = 0; i < num1 - 1; i++)
            {
                list.insertX('X');
            }
            for (int i = 0; i < num2 - 1; i++)
            {
                list.insertYPositif('X');
            }
            list.penjumlahanPositif();
        }


        if (input1[0] == '-' && input2[0] == '-')
        {
            for (int i = 1; i < 3; i++)
            {
                stringNum1 += input1[i];
                stringNum2 += input2[i];
            }

            num1 = stoi(stringNum1);
            num2 = stoi(stringNum2);
            list.replaceNodeValueXtoY();
            for (int i = 0; i < num1 - 1; i++)
            {
                list.insertXNegatif('Y');
            }
            for (int i = 0; i < num2 - 1; i++)
            {
                list.insertY('Y');
            }
            list.penjumlahanNegatif();
        }

        break;
    case (2):

        cout << "Input Num 1: \n$ ";
        cin >> input1;

        cout << "Input Num 2: \n$ ";
        cin >> input2;
    

        if (input2[0] != '-' && input1[0] != '-')
        {
            

            num2 = stoi(input2);
            num1 = stoi(input1);
            // cout<<num1;
            if (num2 > num1 && num1 > 0)
            {
                list.replaceNodeValueYtoX();
                for (int i = 0; i < num1 - 1; i++)
                {
                    list.insertX('X');
                }

                for (int i = 0; i < num2 - 1; i++)
                {
                    list.insertYPositif('X');
                }
                list.displayForward();
                list.penguranganNegatifDiff();

            }else if (num2 == 0 && num1 > num2)
            {
                list.replaceNodeValueY();
                for (int i = 0; i < num1 - 1; i++)
                {
                    list.insertX('X');
                }

                for (int i = 0; i < num2 + 1; i++)
                {
                    list.replaceNodeValueY();
                }
                list.displayForward();
                list.penguranganPositifDiff();
            }
            else if (num1 == 0 && num2 > num1)
            {
                list.replaceNodeValueX();
                for (int i = 0; i < num1 + 1; i++)
                {
                    list.replaceNodeValueY();
                }

                for (int i = 0; i < num2; i++)
                {
                    list.insertYPositif('X');
                }
                list.displayForward();
                list.penguranganNegatifDiff();
            }
            else if (num1 > num2 && num2 > 0)
            {
                list.replaceNodeValueYtoX();
                for (int i = 0; i < num1 - 1; i++)
                {
                    list.insertX('X');
                }

                for (int i = 0; i < num2 - 1; i++)
                {
                    list.insertYPositif('X');
                }
                list.displayForward();
                list.penguranganPositifDiff();
            }
            else if (num2 == num1)
            {
                list.penguranganNegatifDiff();
            }
        }
        if (input2[0] != '-')
        {
            num1 = stoi(input1);
            num2 = stoi(input2);
            if (num1 == 0 && num2 == 0)
            {
                for (int i = 0; i < 1; i++)
                {
                    list.replaceNodeValueX();
                }
                for (int i = 0; i < 1; i++)
                {
                    list.replaceNodeValueY();
                }
                list.penguranganNegatifDiff();
            }
        }

        if (input1[0] == '-' && input2[0] != '-')
        {

            
            for (int i = 1; i < 3; i++)
            {
                stringNum1 += input1[i];
            }
            num1 = stoi(stringNum1);
            num2 = stoi(input2);
            // cout << num1 << endl;
            // cout << num2 << endl;

            if (num1 > num2 && num2 > 0)
            {
                list.replaceNodeValueXtoY();
                for (int i = 0; i < num1 - 1; i++)
                {
                    list.insertXNegatif('Y');
                }

                for (int i = 0; i < num2 - 1; i++)
                {
                    list.insertY('Y');
                }
                list.displayForward();
                list.penguranganNegatif();
            }
            else if (num2 > num1 && num1 > 0)
            {
                list.replaceNodeValueXtoY();
                for (int i = 0; i < num1 - 1; i++)
                {
                    list.insertXNegatif('Y');
                }

                for (int i = 0; i < num2 - 1; i++)
                {
                    list.insertY('Y');
                }
                list.displayForward();
                list.penguranganNegatif();
            }
            else if (num1 == num2)
            {
                for (int i = 0; i < num1 - 1; i++)
                {
                    list.insertXNegatif('Y');
                }

                for (int i = 0; i < num2 + 1; i++)
                {
                    list.insertYPositif('Y');
                }
                
                list.penguranganYXPositif();
            }
            else if (num1 > 0 && num2 == 0)
            {
                list.reverseNode();
                for (int i = 0; i < num1 - 1; i++)
                {
                    list.insertXNegatif('Y');
                }

                for (int i = 0; i < num2 + 1; i++)
                {
                    list.replaceNodeValueX();
                }
                list.displayForward();
                list.penguranganYXNegatif();
            }
        }

        if (input1[0] != '-' && input2[0] == '-')
        {
            for (int i = 1; i < 3; i++)
            {
                stringNum2 += input2[i];
            }

            num1 = stoi(input1);
            num2 = stoi(stringNum2);


            if (num1 < num2 && num1 == 0)
            {
                list.reverseNode();
                for (int i = 0; i < 1; i++)
                {
                    list.replaceNodeValueY();
                }

                for (int i = 0; i < num2 - 1; i++)
                {
                    list.insertYPositif('X');
                }
                list.displayForward();
                list.penguranganYXPositif();
            }
            else if (num2 > num1 && num1 > 0)
            {
                // list.reverseNode();
                list.replaceNodeValueYtoX();
                for (int i = 0; i < num1 - 1; i++)
                {
                    list.insertX('X');
                }

                for (int i = 0; i < num2 - 1; i++)
                {
                    list.insertYPositif('X');
                }
                list.displayForward();
                list.penguranganPositif();
            }else if (num2 < num1 && num2 > 0)
            {
                // list.reverseNode();
                list.replaceNodeValueYtoX();
                for (int i = 0; i < num1 - 1; i++)
                {
                    list.insertX('X');
                }

                for (int i = 0; i < num2 - 1; i++)
                {
                    list.insertYPositif('X');
                }
                list.displayForward();
                list.penguranganPositif();
            }
            
        }
        

        if (input1[0] == '-' && input2[0] == '-')
        {
            for (int i = 1; i < 3; i++)
            {
                stringNum1 += input1[i];
                stringNum2 += input2[i];
            }

            num1 = stoi(stringNum1);
            num2 = stoi(stringNum2);

            if (num1 > num2 && num2 > 0)
            {
                list.reverseNode();
                for (int i = 0; i < num1 - 1; i++)
                {
                    list.insertXNegatif('Y');
                }

                for (int i = 0; i < num2 - 1; i++)
                {
                    list.insertYPositif('X');
                }
                list.penguranganYXNegatif();
            }else if (num1 < num2 && num1 > 0)
            {
                list.reverseNode();
                for (int i = 0; i < num1 - 1; i++)
                {
                    list.insertXNegatif('Y');
                }

                for (int i = 0; i < num2 - 1; i++)
                {
                    list.insertYPositif('X');
                }
                list.penguranganYXPositif();
            }else if (num1 > num2 && num2 == 0)
            {
                list.reverseNode();
                for (int i = 0; i < num1 - 1; i++)
                {
                    list.insertXNegatif('Y');
                }

                for (int i = 0; i < num2 + 1; i++)
                {
                    list.replaceNodeValueX();
                }
                list.penguranganYXNegatif();
            }else if (num1 == num2)
            {
                list.replaceNodeValueXtoY();
                for (int i = 0; i < num1 - 1; i++)
                {
                    list.insertXNegatif('Y');
                }

                for (int i = 0; i < num2 - 1; i++)
                {
                    list.insertY('Y');
                }
                list.penjumlahanNegatif();
            }

        }
            break;
    default:
        break;
    }

    return 0;
}
