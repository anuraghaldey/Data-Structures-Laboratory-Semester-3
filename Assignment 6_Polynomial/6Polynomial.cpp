#include <iostream>
using namespace std;
struct polynomial
{
    int coeff;
    int expo;
};
int ipoly(struct polynomial p[])
{
    int t1, i, k;
    cout << "\n Enter the polynomial details:";
    cout << "\n Enter the Total number of terms in the polynomial:";
    cin >> t1;
    cout << "\n Enter the COEFFICIENT and EXPONENT" << endl;
    for (i = 0; i < t1; i++)
    {
        cout << " Enter the Coefficient(" << i + 1 << "):";
        cin >> p[i].coeff;
        cout << " Enter the Exponent(" << i + 1 << "):";
        cin >> p[i].expo;
    }
    cout << "\n The polynomial is :";
    for (k = 0; k < t1 - 1; k++)
    {
        cout << p[k].coeff << "(x^" << p[k].expo << ")+";
    }
    cout << p[k].coeff << "(x^" << p[k].expo << ")";
    return t1;
}
void add_polynomial()
{
    int t1, t2;
    struct polynomial p2[20];
    struct polynomial p3[20];
    struct polynomial p4[20];
    cout << "\n First polynomial :";
    t1 = ipoly(p2);
    cout << "\n Second polynomial:";
    t2 = ipoly(p3);
    int i, j, k;

    i = 0;
    j = 0;
    k = 0;

    while (i < t1 && j < t2)
    {
        if (p2[i].expo == p3[j].expo)
        {
            p4[k].coeff = p2[i].coeff;
            p4[k].expo = p2[i].expo;
            i++;
            k++;
        }
        else
        {
            p4[k].coeff = p3[j].coeff;
            p4[k].expo = p3[j].expo;
            j++;
            k++;
        }
    }
    /*for rest over terms of polynomial 1 */
    while (i < t1)
    {
        p4[k].coeff = p2[i].coeff;
        p4[k].expo = p2[i].expo;
        i++;
        k++;
    }
    /* for rest over terms of polynomial 2 */
    while (j < t2)
    {
        p4[k].coeff = p3[j].coeff;
        p4[k].expo = p3[j].expo;
        j++;
        k++;
    }
    cout << "\n Addition of the given polynomial is:";
    for (i = 0; k - 1; i++)
        cout << p4[i].coeff << "(x^" << p4[i].expo << ")+";
    cout << p4[i].coeff << "(x^" << p4[i].expo << ")";
}
void mul_polynomial()
{
    int t1, t2, i, j, c;
    struct polynomial p2[20];
    struct polynomial p3[20];
    struct polynomial p4[50];
    cout << "\n First polynomial";
    t1 = ipoly(p2);
    cout << "\n Second polynomial";
    t2 = ipoly(p3);
    c = -1;
    for (i = 0; i < t1; i++)
    {
        for (j = 0; j < t2; j++)

        {
            p4[++c].expo = p2[i].expo + p3[j].expo;
            p4[c].coeff = p2[i].coeff * p3[j].coeff;
        } /*end of j loop*/

    } /* end of i loop*/
    cout << "\n Product of two polynomial is:\n";
    cout << endl;
    for (i = 0; i < c; i++)
        cout << p4[i].coeff << "(x^" << p4[i].expo << ")+";
    cout << p4[i].coeff << "(x^" << p4[i].expo << ")";
}
int main()
{

    int ch;
    char ans;
    struct polynomial p1[20];
    do
    {
        cout << "\n 1.Taking input and printing polynomial\n 2.Addition \n 3.Multiplication \n Enter choice";
        cin >> ch;
        switch (ch)
        {
        case 1:
            ipoly(p1);
            break;
        case 2:
            add_polynomial();
            break;
        case 3:
            mul_polynomial();
            break;
        }
        cout << "\n Do you want to continue(Y/y)=>";
        cin >> ans;
    } while (ans == 'Y' || ans == 'y');
    return 0;
}
