#include<iostream>
#include<string>
using namespace std; 
string order(string preorder,string inorder)   
{   
    if(preorder.size() == 1 || preorder.size() == 0)   //递归的退出条件 
        return preorder;   
    else  
    if(inorder.size() == 1 || inorder.size() == 0)   //递归的退出条件 
        return inorder;   
    else  
    {   
        int index = inorder.find(preorder[0]);   // 到先序第一个在中序中的位置index 
        string lpo = preorder.substr(1,index);     
        string lio = inorder.substr(0,index);    
        
        string rpo = preorder.substr(index+1);   
        string rio = inorder.substr(index+1);   //把先序和中序根据index分为两部分 
        
        return order(lpo,lio) + order(rpo,rio) + inorder[index];   //进行循环递归 
    }   
}

int main(){
    string s1,s2;
    cout<<"请输入先序序列： "; 
    cin>>s1;
    cout<<"请输入中序序列： "; 
    cin>>s2;
    cout<<"后序序列为： "; 
    cout<<order(s1,s2)<<endl;
    system("pause");
    return 0;
}
