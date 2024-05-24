#include "DynamicArray.h"
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

void Array::insert(int value)
{
    data.push_back(value);
}

void Array::remove(int index)
{
    if (index < 0 || index >= data.size())
    {
        cout << "Index out of bounds" << endl;
        return;
    }
    data.erase(data.begin() + index);
}

int Array::largestElement()
{
    if (data.empty())
        return INT_MIN;
    return *max_element(data.begin(), data.end());
}

int Array::secondLargestElement()
{
    if (data.size() < 2)
        return INT_MIN;
    int first = INT_MIN, second = INT_MIN;
    for (int num : data)
    {
        if (num > first)
        {
            second = first;
            first = num;
        }
        else if (num > second && num != first)
        {
            second = num;
        }
    }
    return second;
}

bool Array::isSorted()
{
    return std::is_sorted(data.begin(), data.end());
}

void Array::reverse()
{
    std::reverse(data.begin(), data.end());
}

int Array::maxDifference()
{
    if (data.size() < 2)
        return 0;
    int min_element = data[0], max_diff = data[1] - data[0];
    for (int i = 1; i < data.size(); i++)
    {
        max_diff = max(max_diff, data[i] - min_element);
        min_element = min(min_element, data[i]);
    }
    return max_diff;
}

void Array::printFrequencies()
{
    if (data.empty())
        return;
    int count = 1;
    for (int i = 1; i < data.size(); i++)
    {
        if (data[i] == data[i - 1])
        {
            count++;
        }
        else
        {
            cout << data[i - 1] << " occurs " << count << " times" << endl;
            count = 1;
        }
    }
    cout << data.back() << " occurs " << count << " times" << endl;
}

int Array::maxProfit()
{
    if (data.size() < 2)
        return 0;
    int min_price = data[0], max_profit = 0;
    for (int i = 1; i < data.size(); i++)
    {
        max_profit = max(max_profit, data[i] - min_price);
        min_price = min(min_price, data[i]);
    }
    return max_profit;
}

int Array::maxSubarraySum()
{
    int max_ending_here = 0, max_so_far = INT_MIN;
    for (int num : data)
    {
        max_ending_here = max(num, max_ending_here + num);
        max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
}

int Array::maxCircularSum()
{
    int max_kadane = maxSubarraySum();
    int max_wrap = 0;
    for (int i = 0; i < data.size(); i++)
    {
        max_wrap += data[i];
        data[i] = -data[i];
    }
    max_wrap += maxSubarraySum();
    return max(max_kadane, max_wrap);
}

int Array::longestEvenOddSubarray()
{
    if (data.empty())
        return 0;
    int max_length = 1, curr_length = 1;
    for (int i = 1; i < data.size(); i++)
    {
        if ((data[i] % 2 == 0 && data[i - 1] % 2 != 0) ||
            (data[i] % 2 != 0 && data[i - 1] % 2 == 0))
        {
            curr_length++;
            max_length = max(max_length, curr_length);
        }
        else
        {
            curr_length = 1;
        }
    }
    return max_length;
}

void Array::display()
{
    for (int num : data)
    {
        cout << num << " ";
    }
    cout << endl;
}

void Array::menu()
{
    int choice, value, index;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Largest Element\n";
        cout << "4. Second Largest Element\n";
        cout << "5. Check if Sorted\n";
        cout << "6. Reverse\n";
        cout << "7. Maximum Difference\n";
        cout << "8. Frequencies in Sorted Array\n";
        cout << "9. Stock Buy and Sell\n";
        cout << "10. Maximum Subarray Sum\n";
        cout << "11. Maximum Circular Sum\n";
        cout << "12. Longest Even-Odd Subarray\n";
        cout << "13. Display Array\n";
        cout << "14. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            insert(value);
            break;
        case 2:
            cout << "Enter index to delete: ";
            cin >> index;
            remove(index);
            break;
        case 3:
            cout << "Largest Element: " << largestElement() << endl;
            break;
        case 4:
            cout << "Second Largest Element: " << secondLargestElement() << endl;
            break;
        case 5:
            cout << "Array is " << (isSorted() ? "sorted" : "not sorted") << endl;
            break;
        case 6:
            reverse();
            cout << "Array reversed.\n";
            break;
        case 7:
            cout << "Maximum Difference: " << maxDifference() << endl;
            break;
        case 8:
            printFrequencies();
            break;
        case 9:
            cout << "Maximum Profit: " << maxProfit() << endl;
            break;
        case 10:
            cout << "Maximum Subarray Sum: " << maxSubarraySum() << endl;
            break;
        case 11:
            cout << "Maximum Circular Sum: " << maxCircularSum() << endl;
            break;
        case 12:
            cout << "Longest Even-Odd Subarray Length: " << longestEvenOddSubarray() << endl;
            break;
        case 13:
            display();
            break;
        case 14:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 14);
}
