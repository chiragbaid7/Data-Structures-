#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    string key;
    Node(string k, T d)
    {
        data = d;
        key = k;
        next = NULL;
    }
    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};
template <typename T>
class HashTable
{
    Node<T> **table; //double ptr variable-array of pointers
    int table_size;
    int cs = 0;
    int hashfn(string key)
    {
        int indx = 0;
        int p = 1;
        for (int i = 0; i < key.length(); i++)
        {
            indx += (key[i] * p) % table_size;
            p = (p * 27) % table_size;
        }
        indx %= table_size;
        return indx;
    }
    void rehash()
    {
        //old hash map
        Node<T> **old_table = table;
        int old = table_size;
        table_size = 2 * table_size;
        table = new Node<T> *[table_size];
        for (int i = 0; i < table_size; i++)
        {
            table[i] = NULL;
        }
        cs = 0;
        //shift elements of old table to new table
        for (int i = 0; i < old; i++)
        {
            Node<T> *temp = old_table[i];
            while (temp != NULL)
            {
                insert(temp->key, temp->data);
                temp = temp->next;
            }
            //1.delete linked list in the particular index
            if (old_table[i] != NULL)
            {
                delete old_table[i];
            }
        }
        delete[] old_table;
    }

public:
    HashTable(int ts = 10) //default
    {
        table_size = ts;
        table = new Node<T> *[table_size];
        for (int i = 0; i < table_size; i++)
        {
            table[i] = NULL;
        }
    }
    void insert(string key, T value)
    {
        int hash_key = hashfn(key);
        //create a new node
        //node *temp=new node(value)
        Node<T> *n = new Node<T>(key, value);
        n->next = table[hash_key];
        table[hash_key] = n;
        cs++;
        float load_factor = cs / (1.0 * table_size);
        if (load_factor > 0.7)
        {
            rehash();
        }
    }
    void print()
    {
        for (int i = 0; i < table_size; i++)
        {
            Node<T> *temp = table[i];
            if (temp == NULL)
            {
                cout << "key";
            }
            else
            {
                while (temp)
                {
                    cout << temp->key << "->" << temp->data;
                    temp = temp->next;
                }
            }
            cout << "\n";
        }
    }
    T *search(string key)
    {
        int index = hashfn(key);
        Node<T> *temp = table[index];
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                return &temp->data;
            }
            temp = temp->next;
        }
        return NULL;
    }
    void delete_(string k)
    {

        int indx = hashfn(k);
        Node<T> *temp = table[indx];
        Node<T> *prev = NULL;
        while (temp)
        {
            if (temp->key == k)
            {
                prev->next = temp->next;
                delete temp;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
    }
    T &operator[](string key)
    {
        T *s = search(key);
        if (s == NULL)
        {
            //create karo
            T garbage = 0;
            insert(key, garbage);
            s = search(key);
        }
        return *s;
    }
};
int main()
{
    HashTable<int> h(10);
    h.insert("chirag", 10);
    h.insert("rahul", 80);
    h.insert("rajesh", 70);
    h.insert("mahesh", 60);
    h.insert("sanjay", 50);
    h.insert("nikhar", 10);
    int *s = h.search("nikhar");
    if (s == NULL)
    {
        cout << "NULLL";
    }
    else
    {
        cout << *s << endl;
    }
    h["cc"] = 10;
    h.print();
}
