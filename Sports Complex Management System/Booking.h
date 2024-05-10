#include <iostream>
#include <string.h>
using namespace std;
class node_booking
{
public:
    int num = 1;
    int fill = 0;
    char name[3][10];
    node_booking* next;   //doubly linked list
    node_booking* prev;

    node_booking()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                name[i][j] = NULL;
            }
        }
        next = NULL;
        prev = NULL;
    }

};
class court
{
    node_booking* header[3];   //main courts
    node_booking* list_one;    //subcourts

public:
    court()
    {
        list_one = NULL;
        for (int i = 0; i < 3; i++)   //constructor 
            header[i] = NULL;  
    }
    void create()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                node_booking* list_two = new node_booking;
                list_two->next = NULL;
                list_two->prev = NULL;
                if (header[i] == NULL)
                {
                    header[i] = list_two;
                    list_two->num = 1;
                }
                else
                {
                    node_booking* list_one = header[i];
                    while (list_one->next != NULL)
                    {
                        list_one = list_one->next;
                    }
                    if (j == 3 || j == 5 || j == 7 || j == 8)
                    {
                        list_one->num = 3;
                    }
                    if (j == 2 || j == 4 || j == 6)
                    {
                        list_one->num = 2;
                    }
                    list_one->next = list_two;
                    list_two->prev = list_one;
                }
            }
        }
    }
    void display()
    {
        int j = 0, k = 0, l = 0;
        for (int i = 0; i < 58; i++)
        {
            cout << "--";
        }
        cout << "\n ";

        for (int i = 1; i < 4; i++)
        {
            cout << "| \t\tMain Court : " << i << " \t\t";
        }

        cout << "|\n";
        cout << "\n";
        for (int i = 0; i < 58; i++)
        {
            cout << "--";
        }
        list_one = header[j];
        node_booking* sn = header[j + 1];
        node_booking* tn = header[j + 2];
        cout << "\n ";
        while (list_one != NULL)
        {
            if (list_one->fill != list_one->num && list_one->num != 0)
            {
                j++;
                cout << "| court no : " << j;
                cout << "->Available slots->" << list_one->num;
            }
            else
            {
                j++;
                cout << "| court no : " << j;
                cout << "->Booked          ";
            }
            if (sn->fill != sn->num && sn->num != 0)
            {
                k++;
                cout << "\t | court no : " << j;
                cout << "->Available slots->" << sn->num;
            }
            else
            {
                k++;
                cout << " \t | court no : " << j;
                cout << "->Booked           ";
            }
            if (tn->fill != tn->num && tn->num != 0)
            {
                l++;
                cout << "\t | court no : " << j;
                cout << "->Available slots->" << tn->num << "| ";
            }
            else
            {
                l++;
                cout << "\t | court no : " << j;
                cout << "->Booked " << " | ";
            }
            cout << " \n ";
            for (int i = 0; i < 58; i++)
            {
                cout << "--";
            }
            cout << "\n ";
            list_one = list_one->next;
            sn = sn->next;
            tn = tn->next;

        }
    }
    void book(int people)
    {
        int court_num, sub_court;
        cout << "\nEnter the court you want to book : ";
        cin >> court_num;
        try
        {
            if (court_num < 0 || court_num > 4)

            {
                throw(court_num);
            }
            list_one = header[court_num - 1];

            cout << "\nEnter the court number you prefer : ";
            cin >> sub_court;
            try
            {

                if (sub_court < 0 || sub_court > 10)
                {
                    throw(sub_court);
                }
                else
                {
                    int i = 1;
                    while (i < sub_court)
                    {
                        list_one = list_one->next;
                        i++;
                    }
                        if (list_one->num >= people)
                        {
                            cout << "\ncourt is vacant you can apply for court";

                            int count = 0;
                            while (list_one->fill - 1 <= list_one->num)
                            {

                                cout << "\nEnter name " << list_one->fill + 1 << " : ";

                                cin >> list_one->name[list_one->fill];
                                count++;
                                list_one->fill++;
                                if (count >= people)
                                {
                                    break;
                                }
                            }
                            list_one->num = list_one->num - people;
                        }
                        else
                        {
                            cout << "\nInsufficient space or court is not vacant ... SORRY. Try again !!!";
                        }
                }
            }
            catch (int r)
            {
                cout << "\ninvalid subcourt number : " << r;
            }
        }
        catch (int r)
        {
            cout << " \ninvalid number for a court entered : " << r;
        }
    }
    void cancel(int check)
    {
        char namecheck[10];
        int flag = 0;
        int sub_court, i = 1;
        try
        {
            if (check < 0 || check > 4)

            {
                throw(check);
            }
            else
            {
                cout << " Enter the court no : ";
                /*
                string temp;

                cin >> temp;

                if (is_)
                {
                    sub_cort = stoi()
                }
                */
                cin >> sub_court;
                try
                {
                    if (sub_court < 0 || sub_court> 10)
                    {
                        throw(sub_court);
                    }
                    else
                    {
                        cout << " Enter the name to be delete :";

                        cin >> namecheck;
                        list_one = header[check - 1];
                        while (i < sub_court)
                        {
                            list_one = list_one->next;
                            i++;
                        }
                        i = 0;
                        while (i < 3)
                        {

                            if (!strcmp(namecheck, list_one->name[i]))

                            {
                                flag = 1;
                                break;
                                i = 0;
                            }
                            else
                                i++;
                        }
                        if (flag == 1 && list_one->fill != 0)
                        {
                            cout << "\nrecord deleted : " << list_one->name[i];

                            list_one->name[i][0] = 'A';
                            list_one->name[i][1] = '\0';
                            list_one->fill--;
                            list_one->num++;
                        }
                        else

                            cout << "\nrecord not present ";
                    }
                }
                catch (int r)
                {
                    cout << "\ninvalid court number : " << r;
                }
            }
        }

        catch (int r)

        {
            cout << " \n court dosen't exist : " << r;
        }
    }
    void upgrade(int check)
    {
        char namecheck[10];
        int sub_court, i = 1;
        try
        {
            if (check < 0 || check > 4)

            {
                throw(check);
            }
            else
            {
                cout << " Enter the court no : ";
                cin >> sub_court;
                try
                {
                    if (sub_court < 0 || sub_court > 10)

                    {
                        throw(sub_court);
                    }
                    else
                    {
                        cout << "Enter the name to be updated :";

                        cin >> namecheck;
                        list_one = header[check - 1];
                        while (i < sub_court)
                        {
                            list_one = list_one->next;
                            i++;
                        }
                        i = 0;
                        while (i < 3)
                        {
                            if (!strcmp(namecheck, list_one->name[i]))

                            {
                                cout << "\nEnter updated name : ";

                                cin >> list_one->name[i];
                                break;
                            }
                            else
                                i++;
                        }
                        if (i >= 3)
                            cout << "record not found ";
                        else
                        {
                            cout << "\nrecord updated\nprevious name : " << namecheck << "\nupdated name : " << list_one->name[i];
                        }
                    }
                }
                catch (int r)
                {
                    cout << "\ninvalid court number : " << r;
                }
            }
        }

        catch (int r)

        {
            cout << "\n Court dosn't exist : " << r;
        }
    }
};


