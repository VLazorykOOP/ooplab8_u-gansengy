#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

template<typename T>
T minimumElement(T* arr, int size) {
	T minEl = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] < minEl) {
			minEl = arr[i];
		}
	}
	return minEl;
}

template<typename T>
T maximumElement(T* arr, int size) {
	T maxEl = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] > maxEl) {
			maxEl = arr[i];
		}
	}
	return maxEl;
}

template<>
inline char* minimumElement(char** arr, int size) {
	char* minEl = arr[0];
	for (int i = 1; i < size; i++) {
		if (strcmp(arr[i], minEl) < 0) {
			minEl = arr[i];
		}
	}
	return minEl;
}

template<>
inline char* maximumElement(char** arr, int size) {
	char* maxEl = arr[0];
	for (int i = 1; i < size; i++) {
		if (strcmp(arr[i], maxEl) > 0) {
			maxEl = arr[i];
		}
	}
	return maxEl;
}


//////////////////////////// task 2

template<typename T>
void mrgArrays(T* arr1, int size1, T* arr2, int size2, T* result) {
	int i = 0, j = 0, k = 0;
	while (i < size1 && j < size2) {
		if (arr1[i] < arr2[j])
			result[k++] = arr1[i++];
		else
			result[k++] = arr2[j++];
	}
	while (i < size1)
		result[k++] = arr1[i++];
	while (j < size2)
		result[k++] = arr2[j++];
}

template<>
inline void mrgArrays<const char*>(const char** arr1, int size1, const char** arr2, int size2, const char** result) {
	int i = 0, j = 0, k = 0;
	while (i < size1 && j < size2) {
		if (strcmp(arr1[i], arr2[j]) < 0)
			result[k++] = arr1[i++];
		else
			result[k++] = arr2[j++];
	}
	while (i < size1)
		result[k++] = arr1[i++];
	while (j < size2)
		result[k++] = arr2[j++];
}

/////////////////////////// task 3

template <typename T>
class BinaryTreeTmp {
public:
    struct Node {
        T value;
        Node* left;
        Node* right;
        Node* parent;
        Node(const T& v) : value(v), left(nullptr), right(nullptr), parent(nullptr) {}
    };
    Node* root;

public:
    class Iterator {
    private:
        Node* current;
    public:
        Iterator(Node* n) : current(n) {}
        T& operator*() const { return current->value; }
        Iterator& operator++() {
            if (current->right) {
                current = current->right;
                while (current->left) current = current->left;
            }
            else {
                Node* p = current->parent;
                while (p && current == p->right) {
                    current = p;
                    p = p->parent;
                }
                current = p;
            }
            return *this;
        }
        bool operator==(const Iterator& other) const { return current == other.current; }
        bool operator!=(const Iterator& other) const { return !(*this == other); }
    };

    BinaryTreeTmp() : root(nullptr) {}
    ~BinaryTreeTmp() { delete root; }

    void insert(const T& value) {
        Node** pp = &root;
        Node* parent = nullptr;
        while (*pp) {
            parent = *pp;
            if (value < (*pp)->value)
                pp = &((*pp)->left);
            else
                pp = &((*pp)->right);
        }
        *pp = new Node(value);
        (*pp)->parent = parent;
    }

    void traversePreOrder() {
        traversePreOrder(root);
    }

    void traverseInOrder() {
        traverseInOrder(root);
    }

    void traversePostOrder() {
        traversePostOrder(root);
    }

    Iterator begin() {
        Node* n = root;
        while (n && n->left) n = n->left;
        return Iterator(n);
    }

    Iterator end() {
        return Iterator(nullptr);
    }

    Node* search(const T& value) {
        Node* node = root;
        while (node) {
            if (value == node->value)
                return node;
            else if (value < node->value)
                node = node->left;
            else
                node = node->right;
        }
        return nullptr;
    }



private:
   
    void traversePreOrder(Node* node) {
        if (node) {
            std::cout << node->value << " ";
            traversePreOrder(node->left);
            traversePreOrder(node->right);
        }
    }

    void traverseInOrder(Node* node) {
        if (node) {
            traverseInOrder(node->left);
            std::cout << node->value << " ";
            traverseInOrder(node->right);
        }
    }

    void traversePostOrder(Node* node) {
        if (node) {
            traversePostOrder(node->left);
            traversePostOrder(node->right);
            std::cout << node->data << " ";
        }
    }

    public:
        void remove(Node* node) {
            if (!node) return;
            Node* parent = node->parent;

            if (!node->left && !node->right) {
                if (parent) {
                    if (parent->left == node)
                        parent->left = nullptr;
                    else
                        parent->right = nullptr;
                }
                else {
                    root = nullptr;
                }
                delete node;
            }
            else if (!node->left) {
                if (parent) {
                    if (parent->left == node)
                        parent->left = node->right;
                    else
                        parent->right = node->right;
                }
                else {
                    root = node->right;
                }
                node->right->parent = parent;
                delete node;
            }
            else if (!node->right) {
                if (parent) {
                    if (parent->left == node)
                        parent->left = node->left;
                    else
                        parent->right = node->left;
                }
                else {
                    root = node->left;
                }
                node->left->parent = parent;
                delete node;
            }
            else {
                Node* minRight = node->right;
                while (minRight->left) minRight = minRight->left;
                T& temp = node->value;
                node->value = minRight->value;
                minRight->value = temp;
                remove(minRight);
            }
        }


};

///////////////// task 4 :)

class BinaryTree {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;

        Node(int val) {
            data = val;
            left = nullptr;
            right = nullptr;
        }
    };

    Node* root;

public:
    BinaryTree() {
        root = nullptr;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (root == nullptr) {
            root = newNode;
            return;
        }
        Node* currentNode = root;
        while (true) {
            if (val < currentNode->data) {
                if (currentNode->left == nullptr) {
                    currentNode->left = newNode;
                    return;
                }
                currentNode = currentNode->left;
            }
            else {
                if (currentNode->right == nullptr) {
                    currentNode->right = newNode;
                    return;
                }
                currentNode = currentNode->right;
            }
        }
    }

    class Iterator {
    private:
        Node* current;
        stack<Node*> parentStack;

        void pushLeftChildren(Node* node) {
            while (node != nullptr) {
                parentStack.push(node);
                node = node->left;
            }
        }

    public:
        Iterator(Node* root) {
            current = nullptr;
            pushLeftChildren(root);
        }

        bool hasNext() {
            return !parentStack.empty();
        }

        int next() {
            current = parentStack.top();
            parentStack.pop();
            pushLeftChildren(current->right);
            return current->data;
        }
    };

    Iterator getIterator() {
        return Iterator(root);
    }
};



