#include<iostream>
#include<stack>
#include<queue>
using namespace std;
typedef char ElementType;
struct Bintree_Node
{
	ElementType data;//数据域
	Bintree_Node* left;//左子树指针
	Bintree_Node* right;//右子树指针
};
//一路创建左子树
void Create(Bintree_Node** p)//形参为指针的指针，那么*p就是传入的指针
{
    ElementType temp;
    cout << "请输入数据,输入#时表示空节点:";
    cin >> temp;
    if (temp == '#')//这里我们用'0'来指示创建一个空结点，对于不同的数据，这个标识可以任意设置
    {
        *p = NULL;
    }
    else
    {
        *p = new Bintree_Node;//如果不空，就创建一个节点
        (*p)->data = temp;//存入数据，注意要用(*p)，因为->的优先级比*高
        Create(&(*p)->left);//递归创建左结点，实参是左指针的地址
        Create(&(*p)->right);
    }
}
//递归的三种遍历
void front(Bintree_Node *p)
{
    if (p)
    {
        cout << p->data;
        front(p->left);
        front(p->right);
    }
}
void middle(Bintree_Node* p)
{
    if (p)
    {
        middle(p->left);
        cout << p->data;
        middle(p->right);
    }
}
void last(Bintree_Node* p)
{
    if (p)
    {
        last(p->left);
        last(p->right);
        cout << p->data;
    }
}
//非递归的三种遍历
void Front(Bintree_Node* p)
{
    if (!p) return;//如果是空树，就直接返回
    Bintree_Node* temp = p;
    stack<Bintree_Node*> s;//创建一个数据栈
    while (temp != NULL || !s.empty())//当temp为空指针且栈空时，遍历就结束了
    {
        while (temp != NULL)//判断结点是否为空
        {
            cout << temp->data;//访问数据
            s.push(temp);//该结点入栈
            temp = temp->left;//将指针指向左子树
        }
        temp = s.top();//抛出前，获得栈顶元素的引用，也就是出栈结点的引用
        s.pop();
        temp = temp->right;//将指针指向出栈结点的右子树，准备处理
    }
    cout << endl;
}

void Middle(Bintree_Node* p)
{
    if (!p) return;//如果是空树，就直接返回
    Bintree_Node* temp = p;
    stack<Bintree_Node*>s;
    while (temp != NULL || !s.empty())
    {
        while (temp != NULL)
        {
            s.push(temp);
            temp = temp->left;
        }
        temp = s.top();
        cout << temp->data;
        s.pop();
        temp = temp->right;
    }
    cout << endl;
}

void Last(Bintree_Node* root)
{
    stack<pair<Bintree_Node*, bool>> s;
    s.push(make_pair(root, false));
    while (!s.empty())
    {
        Bintree_Node* root = s.top().first;
        bool flag = s.top().second;
        s.pop();//先出队
        if (root == NULL)
            continue;
        if (flag == true)//遍历过的就直接输出
            cout << root->data;
        else//如果没遍历过的点，要再次入队
        {
            s.push(make_pair(root, true));//第二次入队，改为true
            s.push(make_pair(root->right, false));
            s.push(make_pair(root->left, false));
        }
    }
    cout << endl;
}
int hight(Bintree_Node* p)
{
    int height = 0;
    int leftheight = 0;
    int rightheight = 0;
    if (p == NULL) {
        return 0;
    }
    else {
        leftheight = hight(p->left);
        rightheight = hight(p->right);
        if (rightheight > leftheight) height = rightheight;
        else height = leftheight + 1;
    }
}
int TreeDepth(Bintree_Node* p)
{
    queue<Bintree_Node*>q;
    if (!p) return 0;
    q.push(p);
    int depth = 0;
    while (!q.empty()) {
        int len = q.size();
        depth++;
        while (len--) {
            Bintree_Node* temp = q.front();
            q.pop();
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
    return depth;
}

void main()
{
    Bintree_Node* P = NULL;
    cout << "输入优先输入左子树，叶子节点后输入两个##"<<endl;
    Create(&P);
    cout << "先序遍历：" << endl;
    cout << "递归结果：";
    front(P);
    cout << endl<<"非递归结果:";
    Front(P);
    cout << "中序遍历" << endl;
    cout << "递归结果：";
    middle(P);
    cout << endl << "非递归结果:";
    Middle(P);
    cout << "后序遍历" << endl;
    cout << "递归结果：";
    last(P);
    cout << endl << "非递归结果:";
    Last(P);
    cout << "树高为：" << hight(P) << endl<<TreeDepth(P);
}
