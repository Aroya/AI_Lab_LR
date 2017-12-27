#include"lib\Reader.h"
#include"lib\LR.h"//#define MULTI_THREAD开启多线程优化
#include"lib\Divider.h"
#include<iostream>

using namespace std;

int main() {
	//分割文件
	//Divider("csv_origin/train.csv");

	//读取文件
	Reader train_reader("train.csv");
	Reader vali_reader("validation.csv");
	Reader test_reader("test.csv");

	//创建初始向量[1......1]
	Omega omega(train_reader.columns);
	//从文件加载向量
	//Omega omega;
	//训练
	omega.iterate(train_reader, 50);
	//将向量写入文件
	omega.writeFile();

	//运行测试集并将结果写入文件
	omega.writeTest(test_reader.data);

	//输出验证集正确率
	//cout << "验证集正确率:\n";
	vali_reader.persents(omega.best,1);


	system("pause");
	return 0;
}