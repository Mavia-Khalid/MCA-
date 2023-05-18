#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
class trienode
{
public:
    char data;
    trienode *child[52];
    bool isEnd;
    int freq;
    trienode(char data)
    {
        this->data = data;
        for (int i = 0; i < 52; i++)
        {
            child[i] = NULL;
        }
        isEnd = false;
        freq = 0;
    }
};
class trie
{
public:
    trienode *root;
    trie()
    {
        root = new trienode('\0');
    }
    void InsertWord(string word)
    {
        bool IsPresent = SeacrhWord(word);
        if(IsPresent)
        {
            cout << "\n\t Word Already Present ";
            return;
        }
        trienode *node = root;
        int index;
        trienode *childs;
        for (int i = 0; i < word.length(); i++)
        {
            if (isupper(word[i]))
            {
                index = word[i] - 'A';
            }
            else
            {
                index = word[i] - 'a' + 26;
            }
            if (node->child[index] != NULL)
            {
                node = node->child[index];
            }
            else
            {
                childs = new trienode(word[i]);
                node->child[index] = childs;
                node = node->child[index];
            }
            if (i == word.length() - 1)
            {
                node->isEnd = true;
                node->freq++;
            }
        }
    }
    bool SeacrhWord(string word)
    {
        trienode *node = root;
        int index;
        for (int i = 0; i < word.length(); i++)
        {
            if (isupper(word[i]))
            {
                index = word[i] - 'A';
            }
            else
            {
                index = word[i] - 'a' + 26;
            }
            if (node->child[index] != NULL)
            {
                node = node->child[index];
            }
            else
            {
                return false;
            }
            if (i == word.length() - 1)
            {
                return node->isEnd;
            }
        }
        return -1;
    }
    void PrintWord(string word)
    {
        trienode *node = root;
        int index;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->data == '\0')
            {
                cout << "Address of Root " << " = " << node << endl;
                cout << "[";
                for (int i = 0; i < 52; i++)
                {
                    cout << node->child[i] << ",";
                }
                cout << "\b]" << endl ;
                cout << "\t Frequency : " << node->freq << endl << endl;
            }
            if (isupper(word[i]))
            {
                index = word[i] - 'A';
            }
            else
            {
                index = word[i] - 'a' + 26;
            }
            node = node->child[index];
            cout << "Address of " << node->data << " = " << node << endl;
            cout << "[";
            for (int i = 0; i < 52; i++)
            {
                cout << node->child[i] << ",";
            }
            cout << "\b]" << endl;
            cout << "\t Frequency : " << node->freq << endl << endl;
        }
    }
};
int main()
{
    trie *t = new trie();
    string *words = new string[1000000];
    int index = 0;
    char ch;
    string word;
    ifstream fin("words.txt");

    while (fin >> word)
    {
        words[index++] = word;
    }
    fin.close();
    int i;
    for (i = 0; i < index; i++)
    {
        t->InsertWord(words[i]);
    }
    cout << "\n\t Words Inserted From File = " << i << endl;

    do
    {
        cout << "\n\t Enter 1 to Search a Word : ";
        cout << "\n\t Enter 2 to Insert a Word : ";
        cin >> ch;
        switch (ch)
        {
        case '1':
        {
            string word;
            cout << "\n\t Enter Word to Seacrh : ";
            cin >> word;
            bool isFound = t->SeacrhWord(word);
            if (isFound)
            {
                cout << "\n\t Words Exists " << endl;
                t->PrintWord(word);
            }
            else
            {
                cout << "\n\t Word Not Found ";
            }
            break;
        }
        case '2':
        {
            string word;
            cout << "\n\t Enter Word to Insert : ";
            cin >> word;
            t->InsertWord(word);
            break;
        }
        default:
        {
            break;
        }
        }
        cout << "\n\t Do You want to go to Menu ? Press 1 if Yes ";
        cin >> ch;
    } while (ch == '1');
    return 0;
}