// 中缀表达式：表达式写成 (1 + 2) * (3 + 4)，加减乘除等运算符写在中间。
// 波兰表达式（前缀表达式）：写法为 (* (+ 1 2) (+ 3 4))，将运算符写在前面。
// 逆波兰表达式（后缀表达式）：写法为 ((1 2 +) (3 4 +) *)，将运算符写在后面。

// 中缀表达式转换成前缀表达式和后缀表达式
//       1：按照运算符的优先级对所有的运算单位加括号~
//       式子变成拉：（（a+（b*c））+（（（d*e+f）*g））
//        2：转换前缀与后缀表达式
//       前缀：把运算符号移动到对应的括号前面
//       则变成拉：+(+(a*(bc))*(+(*(de)+g))
//       把括号去掉：++a*bc*+*de+g 前缀式子出现

//       后缀：把运算符号移动到对应的括号后面
//       则变成拉：((a(bc)*)+(((de)*f)+g)*)+
//       把括号去掉：abc*+de*f+g *+后缀式子出现


// 中缀转后缀思路：
// 1、建立一个记录操作符的栈stack和一个list;
// 2、遍历字符串：
//     (1)遇到操作数，直接放入list中；
//     (2)遇到操作符：
//         假设遇到"("，直接压入栈stack;
//         假设遇到")"，判断栈顶是否是"("，如果是，则弹出，否则的话，将栈中元素放入list中，直到遇到"("并将其弹出；
//         假设是"+"、"-"、"*"、"/"，则需要判断当前符号与stack中栈顶符号的优先级，如果栈顶符号优先级高，则需要将栈顶符号弹出放入list，否则当前符号压入stack;
// 3、利用后缀表达式计算值
//     （1）遍历list，
//         假设遇到数字，则压入栈中；
//         假设遇到符号，将栈顶两个数字弹出并计算值后再压入栈中;

// 牛客137、表达式求值:请写一个整数计算器，支持加减乘三种运算和括号。—————中缀表达式求值
// 思路：中缀转后缀，再计算后缀表达式的值



#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<map>
using namespace std;

class Solution{      
    public:
    
    // 中缀表达式求值
    int solve(string s){    
        map<string, int> m;
        m["+"]=0;
        m["-"]=0;
        m["*"]=1;
        // 将中缀表达式转换为后缀表达式
        int length = s.size();
        vector<string> tmp;    // 记录字符串中的操作数
        stack<string> tmp1;   // 记录字符串中的操作符
        string t="";
        for(int i=0;i<length;i++){
            
            if((s.compare(i,i+1,"0")==0) && (s.compare(i,i+1,"9")==0)){
                t+=to_string(s[i]);
            }
            else{
                if(t!=""){
                    tmp.push_back(t);
                    t="";
                }
                if(s[i]=='('){
                    tmp1.push(to_string(s[i]));
                }
                else if(s[i]==')'){

                    while(tmp1.top() != "("){
                        tmp.push_back(tmp1.top());
                        tmp1.pop();
                    }
                    tmp1.pop();      // 去除"("
                }
                else{
                    if(tmp1.empty() || tmp1.top()=="(" || (tmp1.top()>="0" && tmp1.top()<="9")){
                        tmp1.push(to_string(s[i]));
                    }
                    else{
                        string tt1 = tmp1.top();
                        if(m[to_string(s[i])]>m[tt1]){
                            tmp1.push(to_string(s[i]));
                        }
                        else{
                            while(!tmp1.empty() && m.count(tt1)>0 && m[to_string(s[i])]>m[tt1]){
                                tmp1.pop();
                                tmp.push_back(tt1);
                            }
                            tmp1.push(to_string(s[i]));
                        }
                        
                    }
                }
            }
        }
        
        if(t != ""){
            tmp.push_back(t);
        }

        while(!tmp1.empty()){
            string tt1 = tmp1.top();
            tmp.push_back(tt1);
            tmp1.pop();
        }
        // 计算后缀表达式的值
        return evalRPN(tmp);

    }


    //// 后缀表达式求值（逆波兰表达式求值）—— 按顺序读取，遇到数字就压入栈，遇到运算符就从栈中取两个数计算后再压回栈中
    int evalRPN(vector<string>& tokens) {
        int length=tokens.size();
        stack<int> a;
        for(int i=0;i<length;i++){
            if(tokens[i]!="+"&&tokens[i]!="-"&&tokens[i]!="*"&&tokens[i]!="/"){
                int tmp = atoi(tokens[i].c_str());
                a.push(tmp);

            }
            else if(tokens[i]=="+"){
                int top0 = a.top();
                a.pop();
                int top1 = a.top();
                a.pop();
                a.push(top0+top1);
            }
            else if(tokens[i]=="-"){
                int top0 = a.top();
                a.pop();
                int top1 = a.top();
                a.pop();
                a.push(top1-top0); 
            }
            else if(tokens[i]=="*"){
                int top0 = a.top();
                a.pop();
                int top1 = a.top();
                a.pop();
                a.push(top0*top1);
            }else{
                int top0 = a.top();
                a.pop();
                int top1 = a.top();
                a.pop();
                a.push(top1/top0);
            }
        }
        return a.top();
    }
};


int main(){
    string s="(2*(3-4))*5";
    Solution func = Solution();

    cout<<func.solve(s)<<endl;

    return 1;
}
