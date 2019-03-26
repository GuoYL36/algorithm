/* 在D天内运送包裹——LeetCode1014
题目：
	传送带上的包裹必须在 D 天内从一个港口运送到另一个港口。
	
	传送带上的第 i 个包裹的重量为 weights[i]。每一天，我们都会按给出重量的顺序往传送带上装载包裹。
	我们装载的重量不会超过船的最大运载重量。

	返回能在 D 天内将传送带上的所有包裹送达的船的最低运载能力。

注意：货物必须按照给定的顺序装运

	示例1：
		输入：weights = [1,2,3,4,5,6,7,8,9,10], D = 5
		输出：15
		解释：
		船舶最低载重 15 就能够在 5 天内送达所有包裹，如下所示：
			第 1 天：1, 2, 3, 4, 5
			第 2 天：6, 7
			第 3 天：8
			第 4 天：9
			第 5 天：10

		请注意，货物必须按照给定的顺序装运，因此使用载重能力为 14 的船舶并将包装分成 (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) 是不允许的。 

	示例2：
		输入：weights = [3,2,2,4,1,4], D = 3
		输出：6
		解释：
		船舶最低载重 6 就能够在 3 天内送达所有包裹，如下所示：
			第 1 天：3, 2
			第 2 天：2, 4
			第 3 天：1, 4
		
	示例3：
		输入：weights = [1,2,3,1,1], D = 4
		输出：3
		解释：
			第 1 天：1
			第 2 天：2
			第 3 天：3
			第 4 天：1, 1

			

解题思路：
		1、首先算出获取，在规定天数的平均值，向上取整。
		2、不断的按照获取顺序，累加重量，直到超过当前尝试的重量为止。（循环）
		3、如果发现，在规定的天数内，还有剩余的重量未运送，那么把当前尝试的重量+1，再次走第2步。

*/


#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

int minWeightCapability(int p[],int D,int length){
	int tmp = 0; // 当天要运送的重量
	int beginIndex = 0; //当前要运送货物的下标

	int sum = 0; //所有货物的重量
	for(int i=0;i<length;i++){
		sum += p[i];
	}
	int avg = sum / D; // 计算运送完所有货物，D天中每天要运送的平均重量
	
	while(true){
		
		for(int i=0;i<D;i++){
			for(int j=beginIndex;j<length;j++){
				//表示不能装下当前index的货物
				if(tmp+p[j] > avg){
					cout<<"当前载货量："+to_string(avg)+"，当前是第"+to_string(i)+"天，无法载："+to_string(p[j])+"，当前总货量："+to_string(tmp)<<endl;
					tmp = 0;
					break;
				}
				tmp += p[j];
				cout<<"当前是第"+to_string(i)+"天，正在载："+to_string(p[j])+"，当前总货量："+to_string(tmp)<<endl;
				beginIndex++;
				
			}
			
		}
		if(beginIndex >= length){   //在D天内全部运送完
			break;
		}
		// 在D天内未运送完
		avg++;
		beginIndex = 0;
		tmp = 0;
	}
	
	return avg;
}

int main(){
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int b[]
	int D = 5;
	
	int length = sizeof(a)/sizeof(a[0]);
	int result = minWeightCapability(a, D,length);
	cout<< "最小的载重量："<<result<<endl;

	return 0;
}