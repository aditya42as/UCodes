/*You are provided with a vector of N integers. Then, you 
are given 2 queries. For the first query, you are provided 
with 1 integer, which denotes a position in the vector. The 
value at this position in the vector needs to be erased. 
The next query consists of 2 integers denoting a range of 
the positions in the vector. The elements which fall under 
that range should be removed. The second query is 
performed on the updated vector which we get after 
performing the first query.*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cout << "enter no. of elements: ";
    cin >> N;

    vector<int> a(N);
    cout << "enter elements: ";
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    int pos;
    cout << "Enter position to delete: ";
    cin >> pos;
    if (pos >= 1 && pos <= (int)a.size())
    {
        a.erase(a.begin() + (pos - 1));
    }

    int l, r;
    cout << "Enter the the two positions from where to erase elements: ";
    cin >> l >> r;
    if (l < 1) {
        l = 1;
    }
    if (r > a.size()) {
        r = a.size();
    }
    if (l <= r && !a.empty())
    {
        a.erase(a.begin() + (l - 1), a.begin() + r);
    }

    cout << "Number of Elements left: " << a.size() << endl;

    cout << "Updated Vector: ";
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}
