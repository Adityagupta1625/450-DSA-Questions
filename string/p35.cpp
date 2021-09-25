// Function to find Number of customers who could not get a computer

// Write a function “runCustomerSimulation” that takes following two inputs
// a) An integer ‘n’: total number of computers in a cafe and a string:
// b) A sequence of uppercase letters ‘seq’: Letters in the sequence occur in pairs. The first occurrence indicates the arrival of a customer; the second indicates the departure of that same customer.

// A customer will be serviced if there is an unoccupied computer. No letter will occur more than two times.
// Customers who leave without using a computer always depart before customers who are currently using the computers. There are at most 20 computers per cafe.

// For each set of input the function should output a number telling how many customers, if any walked away without using a computer. Return 0 if all the customers were able to use a computer.

// runCustomerSimulation (2, “ABBAJJKZKZ”) should return 0
// runCustomerSimulation (3, “GACCBDDBAGEE”) should return 1 as ‘D’ was not able to get any computer
// runCustomerSimulation (3, “GACCBGDDBAEE”) should return 0
// runCustomerSimulation (1, “ABCBCA”) should return 2 as ‘B’ and ‘C’ were not able to get any computer.
// runCustomerSimulation(1, “ABCBCADEED”) should return 3 as ‘B’, ‘C’ and ‘E’ were not able to get any computer.

#include <iostream>
using namespace std;
int runCustomerSimulation(int n, string s)
{
    char h[26] = {0};
    int avaliable = n;
    int cnt=0;
    for (int i = 0; i < s.length(); i++)
    {
        if (h[s[i] - 'A'] == 0)
        {
            h[s[i] - 'A']++;
            if (avaliable == 0)
            {
                cnt++;
            }
            else{
                 avaliable--;
            }
        }
        else if (h[s[i] - 'A'] == 1)
        {
            h[s[i] - 'A']--;
            int temp=avaliable;
            avaliable++;
            if(avaliable>n){
                avaliable=temp;
            }
        }
    }

    return cnt;
}
int main()
{
    cout << runCustomerSimulation(2, "ABBAJJKZKZ") << endl;
    cout << runCustomerSimulation(3, "GACCBDDBAGEE") << endl;
    cout << runCustomerSimulation(3, "GACCBGDDBAEE") << endl;
    cout << runCustomerSimulation(1, "ABCBCA") << endl;
    cout << runCustomerSimulation(1, "ABCBCADEED") << endl;
    cout << runCustomerSimulation(4, "ABCBCADEEDFHJKLFHJM") << endl;
    return 0;
}
// 0
// 1
// 0
// 2
// 3