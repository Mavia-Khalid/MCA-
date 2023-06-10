#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class trienode
{
public:
    char data;
    trienode *child[52];
    int freq;
    trienode(char data)
    {
        this->data = data;
        for (int i = 0; i < 52; i++)
        {
            child[i] = NULL;
        }
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
    int getIndex(char word)
    {
    	int index;
    	if((word <65 || word>90)&&(word<97||word>122))
    	{
    		return -1;
		}
		if (isupper(word))
	    {
	        index = word - 'A';
	    }
	        else
	    {
	        index = word - 'a' + 26;
	    }
        return index;
	}
    void InsertWord(string word)
    {
        //bool IsPresent = SeacrhWord(word);
        //if(IsPresent)
        //{
        //    cout << "\n\t Word Already Present ";
        //    return;
        //}
        trienode *node = root;
        int index;
        trienode *childs;
        for (int i = 0; i < word.length(); i++)
        {
            index = getIndex(word[i]);
            if(index == -1)
            {
            	cout << "\n\t Invalid Input ";
            	return;
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
                node->freq++;
            }
        }
    }
    bool SearchWord(string word)
    {
        trienode *node = root;
        int index;
        for (int i = 0; i < word.length(); i++)
        {
            index = getIndex(word[i]);
            if(index == -1)
            {
            	return false;
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
                return node->freq;
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
    int index = 0 , height = 0;
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
    	int len = words[i].length();
    	if(height <= len)
    	{
    		height = len;
		}
        t->InsertWord(words[i]);
    }
    cout << "\n\t Words Inserted From File = " << i << endl;
    
	ifstream f("search.txt");
	int j = 0;
	string search_word[100];
	while(f >> word)
    {
        search_word[j++] = word;
    }
    f.close();
    for (int k = 0; k < j; k++)
    {
    	cout << "\n\t Word to Search : " << search_word[k] << endl;
        bool isFound = t->SearchWord(search_word[k]);
        if (isFound)
        {
            cout << "\n\t Words Exists \n" << endl;
            t->PrintWord(search_word[k]);
        	cout << "\n\t Height of Trie : " << height << endl;;
        }
        else
        {
        	cout << "\n\t Word Not Exists " << endl;;
		}
    }
    system("pause");
    return 0;
}







//    do
//    {
//        cout << "\n\t Enter 1 to Search a Word : ";
//        cout << "\n\t Enter 2 to Insert a Word : ";
//        cin >> ch;
//        switch (ch)
//        {
//        case '1':
//        {
//            string word;
//            cout << "\n\t Enter Word to Seacrh : ";
//            cin >> word;
//            bool isFound = t->SeacrhWord(word);
//            if (isFound)
//            {
//                cout << "\n\t Words Exists " << endl;
//                t->PrintWord(word);
//                cout << "\n\t height of Trie : " << height;
//            }
//            else
//            {
//                cout << "\n\t Word Not Found ";
//            }
//            break;
//        }
//        case '2':
//        {
//            string word;
//            cout << "\n\t Enter Word to Insert : ";
//            cin >> word;
//            t->InsertWord(word);
//            break;
//        }
//        default:
//        {
//            break;
//        }
//        }
//        cout << "\n\t Do You want to go to Menu ? Press 1 if Yes ";
//        cin >> ch;
//    } while (ch == '1');
