#include <iostream>
#include <cstring>
#include "Functions.cpp"

using namespace std;

void FirstTask() {
    int intArr[] = { 5, 3, 8, 1, 7 };
    int intArrSize = sizeof(intArr) / sizeof(int);

    int intMinEl = minimumElement<int>(intArr, intArrSize);
    int intMaxEl = maximumElement<int>(intArr, intArrSize);

    cout << "Minimum element (int): " << intMinEl << endl;
    cout << "Maximum element (int): " << intMaxEl << endl;

    double doubleArr[] = { 2.5, 1.2, 4.7, 3.1, 0.8 };
    int doubleArrSize = sizeof(doubleArr) / sizeof(double);

    double doubleMinEl = minimumElement<double>(doubleArr, doubleArrSize);
    double doubleMaxEl = maximumElement<double>(doubleArr, doubleArrSize);

    cout << "Minimum element (double): " << doubleMinEl << endl;
    cout << "Maximum element (double): " << doubleMaxEl << endl;

    const char* arr3[] = { "apple", "banana", "pear", "orange", "kiwi" };
    int size3 = sizeof(arr3) / sizeof(char*);

    const char* minEl3 = minimumElement<const char*>(arr3, size3);
    const char* maxEl3 = maximumElement<const char*>(arr3, size3);

    cout << "Minimum element: " << minEl3 << endl;
    cout << "Maximum element: " << maxEl3 << endl;
}

void SecondTask() {
    int intArr1[] = { 1, 3, 5, 7, 9 };
    int intArr2[] = { 2, 4, 6, 8, 10 };
    int intResult[10];
    mrgArrays(intArr1, 5, intArr2, 5, intResult);

    cout << "Merged int array: ";
    for (int i = 0; i < 10; i++)
        cout << intResult[i] << " ";
    cout << endl;

    const char* charArr1[] = { "apple", "banana", "kiwi" };
    const char* charArr2[] = { "apricot", "blueberry", "orange", "peach" };
    const char** charResult = new const char* [7];
    mrgArrays(charArr1, 3, charArr2, 4, charResult);

    cout << "Merged char array: ";
    for (int i = 0; i < 7; i++)
        cout << charResult[i] << " ";
    cout << endl;

    delete[] charResult;
}

void ThirdTask() {
    BinaryTreeTmp<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(13);
    tree.insert(18);

    std::cout << "Original tree: ";
    tree.traverseInOrder();
    std::cout << std::endl;

    BinaryTreeTmp<int>::Node* node = tree.search(7);
    if (node) {
        std::cout << "Found node with value 7" << std::endl;
        tree.traverseInOrder();
        std::cout << std::endl;
    }

    node = tree.search(15);
    if (node) {
        std::cout << "Found node with value 15" << std::endl;
        tree.traverseInOrder();
        std::cout << std::endl;
    }

    tree.insert(12);
    tree.insert(14);
    std::cout << "After insertions: ";
    tree.traverseInOrder();
    std::cout << std::endl;

    node = tree.search(15);
    if (node) {
        std::cout << "Removing node with value 15" << std::endl;
        tree.traverseInOrder();
        std::cout << std::endl;
        tree.remove(node);
        tree.traverseInOrder();
        std::cout << std::endl;
    }

    std::cout << "Final tree: ";
    tree.traverseInOrder();
    std::cout << std::endl;
}

void FourthTask() {
    BinaryTree tree;
    tree.insert(4);
    tree.insert(2);
    tree.insert(6);
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);
    tree.insert(7);

    BinaryTree::Iterator it = tree.getIterator();
    while (it.hasNext()) {
        cout << it.next() << " ";
    }
    cout << endl;
}

int main()
{
    char answer = '2';
    
    while (answer != 'e' && answer != 'E') {
        cout << "Press E to exit ..." << endl;
        cout << "Please enter the task that you want to review (1-4) : ";
        cin >> answer;
        switch (answer)
        {
        case '1': FirstTask(); break;
        case '2': SecondTask(); break;
        case '3': ThirdTask(); break;
        case '4': FourthTask(); break;
        case 'e': case 'E': break;
        default: cout << "You entered the wrong option, please try again.\n" << endl; break;
        }
    } 
    cout << "Thank you for using the program, have a good day !\n\n" << endl;
}

