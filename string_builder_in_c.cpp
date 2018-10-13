/*KMP Algorithm referred from Cormen*/

#include <bits/stdc++.h>
using namespace std;
int count1 = 0;
char arr[1000];

struct string_node
{
    int size;
    char *data;
    string_node *left = NULL;
    string_node *right = NULL;
    bool isLeaf = true;
};

class stringBuilder
{
  public:
    struct string_node *Node;

  public:
    stringBuilder()
    {
    }
    stringBuilder(int buffer, bool flag, char *value)
    {
        Node = NULL;
        if (!Node)
        {
            Node = new string_node;
        }
        Node->size = buffer;
        Node->data = value;
        Node->isLeaf = flag;
    }

    stringBuilder(bool flag, stringBuilder value1, stringBuilder value2)
    {
        Node = NULL;
        if (!Node)
        {
            Node = new string_node;
            Node->isLeaf = flag;
            Node->left = value1.Node;
            Node->right = value2.Node;
            Node->data = "";
            Node->size = value1.Node->size + value2.Node->size;
        }
    }

    int findSubstring(char *text, char *pattern)
    {

        int n = strlen(text);
        int m = strlen(pattern);
        int *arr = find_prefix(pattern);
        int q = 0;
        for (int i = 0; i < n; i++)
        {
            while (q > 0 && pattern[q] != text[i])
            {
                q = arr[q - 1];
            }
            if (pattern[q] == text[i])
            {
                q = q + 1;
                if (q == m)
                {
                    cout << "Pattern exists \n";
                    return i - m + 1;
                }
            }
        }
        cout << "Pattern does not exits"
             << "\n";
        return -1;
    }

    int *find_prefix(char *pattern)
    {
        int m = strlen(pattern);
        int arr[m];
        arr[0] = 0;
        int k = 0;
        for (int q = 1; q < m; q++)
        {
            while (k > 0 && pattern[k] != pattern[q])
            {
                k = arr[k - 1];
            }
            if (pattern[k] == pattern[q])
                k = k + 1;
            arr[q] = k;
        }
/* 
for (int i = 0; i < m; i++)
    cout << arr[i] << " "; 
*/
        return arr;
    }

    void get_string_value(struct string_node *node, char *t)
    {
        if (node == NULL)
            return;
        if (node->isLeaf == false)
        {
            get_string_value(node->left, t);
            get_string_value(node->right, t);
        }
        else
        {
            int k = 0;
            for (int j = count1; j < count1 + node->size; j++)
            {
                t[j] = node->data[k];
                k++;
            }
            count1 = count1 + node->size;
        }
    }

    char* get_value()
    {
        get_string_value(this->Node, arr);
        arr[count1] = '\0';
        count1 = 0;
        return arr;
    }
};

stringBuilder stringInitialize(char *);
stringBuilder stringAppend(stringBuilder, stringBuilder);
int findSubstring(stringBuilder, char *);

stringBuilder stringInitialize(char *value)
{
    stringBuilder obj = stringBuilder(strlen(value), true, value);
    return obj;
}

stringBuilder stringAppend(stringBuilder source, stringBuilder destination)
{
    stringBuilder obj = stringBuilder(false, source, destination);
    return obj;
}

int findSubstring(stringBuilder value, char *pattern)
{
    int s = value.Node->size;
    char text[s];
    value.get_string_value(value.Node, text);
    text[count1] = '\0';
    count1 = 0;
    int index = value.findSubstring(text, pattern);
    return index;
}

int main()
{
/*     stringBuilder s1 = stringInitialize("hello");
    stringBuilder s2 = stringInitialize("world");
    stringBuilder s4 = stringInitialize("bye");
    s1=stringAppend(s1,s2);
    cout << s1.get_value() << "\n";
    s1=stringAppend(s1,s4);
    cout << s1.get_value() << "\n";
    stringBuilder s3 = stringAppend(s1, s2);
    stringBuilder s4 = stringAppend(s3, s3);    
    stringBuilder s5 = stringAppend(s4, s1);   
    cout << s3.get_value() << "\n";
    cout << s4.get_value() << "\n";
    cout << s3.get_value() << "\n";
    cout << s5.get_value() << "\n";
    int index1 = findSubstring(s3, "hell");
    int index2 = findSubstring(s3, "yell");
    cout << "index1 " << index1 << "\n";
    cout << "index2 " << index2 << "\n"; */
}
