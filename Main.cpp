#include"lib\Reader.h"
#include"lib\LR.h"//#define MULTI_THREAD�������߳��Ż�
#include"lib\Divider.h"
#include<iostream>

using namespace std;

int main() {
	//�ָ��ļ�
	//Divider("csv_origin/train.csv");

	//��ȡ�ļ�
	Reader train_reader("train.csv");
	Reader vali_reader("validation.csv");
	Reader test_reader("test.csv");

	//������ʼ����[1......1]
	Omega omega(train_reader.columns);
	//���ļ���������
	//Omega omega;
	//ѵ��
	omega.iterate(train_reader, 50);
	//������д���ļ�
	omega.writeFile();

	//���в��Լ��������д���ļ�
	omega.writeTest(test_reader.data);

	//�����֤����ȷ��
	//cout << "��֤����ȷ��:\n";
	vali_reader.persents(omega.best,1);


	system("pause");
	return 0;
}