//Tyler Wells
//CIS 1202
// 07/30/2023
//Exceptions

#include<iostream>

using namespace std;

//Exception classes

//class invalidCharacterExcpeption
class invalidCharacterExcpeption
{

};
//class invalidRangeException
class invalidRangeException
{

};
//class caseConversionException
class caseConversionException
{

};


//char character function
char character(char start, int offset)
{

    int startValue = int(start);
    int target = startValue + offset;


    try {
        if (startValue < 65 || (startValue > 90 && startValue < 97) || startValue > 122)
        {
            throw invalidCharacterExcpeption();
        }

        else if (target < 65 || (target > 90 && target < 97) || target > 122)
        {
            throw invalidRangeException();
        }
        else if ((target >= 65 && target <= 90 && startValue >= 95 && startValue <= 122) || (target >= 95 && target <= 122 && startValue >= 65 && startValue <= 90))
        {
            throw caseConversionException();
        }
    }

    catch (invalidCharacterExcpeption exception1)
    {
        cout << " Invalid Character Exception " << endl;
        return ' ';
    }
    catch (invalidRangeException exception2)
    {
        cout << " Invalid Range Exception " << endl;
        return ' ';
    }
    catch (caseConversionException exception3)
    {
        cout << " Cannot make case changes from upper to lower or otherwise " << endl;
        return ' ';
    }
    return char(target);
}

int main()
{
    cout << character('a', 1) << endl;
    cout << character('a', -1) << endl;
    cout << character('Z', -1) << endl;
    cout << character('?', 5) << endl;
    cout << character('A', 32) << endl;
}