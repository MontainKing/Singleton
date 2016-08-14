///********************            ����ģʽ(Singleton)                  ********************/
///*************			�ص㣺�ٵ����ౣ֤ȫ��ֻ��һ��Ψһ��ʵ������     ***************/
///*************				  �ڵ������ṩ��ȡ���Ψһʵ���Ľӿڡ�         ***************/
//
//
//1.����ʽ��
//#include<iostream>
//using namespace std;
//
//class Singleton
//{
//public:
//	static Singleton* GetInstance()//��ȡΨһʵ������Ľӿ�
//	{
//		static Singleton Instance;
//		return &Instance;
//	}
//
//	void Display()
//	{
//		cout << "Showdata:" << _data << endl;
//	}
//
//private:
//	Singleton()//���캯����˽��������ֻ�������ڴ�������
//		:_data(0)
//	{}
//
//	Singleton(const Singleton&);
//	Singleton& operator=(const Singleton&);
//	int _data;
//};
//
//int main()
//{
//	Singleton::GetInstance()->Display();
//	return 0;
//}
//
//
//
//2.����ʽ��
//#include<iostream>
//using namespace std;
//
//#include<assert.h>
//class Singleton
//{
//public:
//	static Singleton* GetInstance()
//	{
//		assert(_sInstance);
//		return _sInstance;
//	}
//
//	void Print()
//	{
//		cout << "Showdata:" << _data << endl;
//	}
//
//protected:
//	Singleton()
//		:_data(0)
//	{}
//
//	int _data;
//	static Singleton* _sInstance;
//};
//
//Singleton* Singleton::_sInstance = new Singleton;
//
//int main()
//{
//	Singleton::GetInstance()->Print();
//	return 0;
//}
//
//
//
//3.�������̰߳�ȫ�ĵ�����
//#include<iostream>
//using namespace std;
//
//class Singleton
//{
//public:
//	static Singleton* GetInstance()
//	{
//		if (_sInstance == NULL)
//		{
//			if (_sInstance == NULL)
//			{
//				_sInstance = new Singleton();
//			}
//		}
//		return _sInstance;
//	}
//
//	static void DelInstance()
//	{
//		if (_sInstance)
//		{
//			delete _sInstance;
//			_sInstance = NULL;
//		}
//
//		cout << "Delete Success!" << endl;
//	}
//
//	void Display()
//	{
//		cout << "Showdata:" << _data << endl;
//	}
//
//private:
//	Singleton()
//		:_data(0)
//	{}
//	Singleton(const Singleton&);
//	Singleton& operator=(const Singleton&);
//	static Singleton* _sInstance;
//	int _data;
//};
//Singleton* Singleton::_sInstance = NULL;
//
//int main()
//{
//	Singleton::GetInstance()->Display();
//	Singleton::DelInstance();
//	return 0;
//}
//
//
//
//4.�̰߳�ȫ�ĵ�����
//#include<iostream>
//using namespace std;
//
//#include<mutex>
//class Singleton
//{
//public:
//	static Singleton* GetInstance()//˫�ؼ�����Ч�ʵ�ͬʱ�����˸߲���������ÿ�λ�ȡʵ������ʱ��Ҫ���м�������������
//	{
//		if (_sInstance == NULL)
//		{
//			std::lock_guard<std::mutex>lck(_mtx);			
////			if (_sInstance == NULL)                  
////			{                                          
////				_sInstance = new Singleton();				//Singleton* tmp = new Singleton;
//																MemoryBarrier();
//																_sInstance = tmp;
////			}
////�����ڲ�if�е���䲢����и�ɻ�����Ϊ���ִ��ļ����ϵͳΪ������ܲ�ȡ����ִ�У�Ҳ����˵���������_sInstance=new Singleton();�������ʵ�ʿɷ�Ϊ����ռ䡢���ù��캯������ֵ�������������裬����ռ�Ϊ��Ҫ��������ӹ���ɣ��������������Ż�ʱ���ܻ�Եڶ��͵��������ָ��������ţ�����һ�����ڸ߲����Ļ���ʱ����������ִ���˵������裨��ʱ���캯��δ����ȷ���ã�ʹ�ñ�Ӧ�ɸ��캯����ʼ������δ����ȷ���������������߳̽����ȡ�������ʱ����ʱ�Ķ����еĳ�Ա�����Ѿ�����Ԥ�ڵ���ȷ��ֵ�����������������ڴ�դ�����ڴ����ϣ��ĸ������Խ����
////�ڴ�դ�����ڴ����ϣ��� ��һ��ͬ������ָ�ʹ��CPU��������ڶ��ڴ�������ʵĲ����е�һ��ͬ���㣬ʹ�ô˵�֮ǰ�����ж�д������ִ�к�ſ��Կ�ʼִ�д˵�֮��Ĳ�����
//		}
//		return _sInstance;
//	}
//
//	static void DelInstance()
//	{
//		std::lock_guard<std::mutex>lck(_mtx);
//		if (_sInstance)
//		{
//			delete _sInstance;
//			_sInstance = NULL;
//		}
//		cout << "Delete Success!" << endl;
//	}
//
//	void Display()
//	{
//		cout << "Showdata:" << _data << endl;
//	}
//
//private:
//	Singleton()
//		:_data(0)
//	{}
//
//	Singleton(const Singleton&);
//	Singleton& operator=(const Singleton&);
//	static Singleton* _sInstance;
//	int _data;
//	static mutex _mtx;
//};
//Singleton* Singleton::_sInstance = NULL;
//mutex Singleton::_mtx;
//
//
//int main()
//{
//	Singleton::GetInstance()->Display();
//	Singleton::DelInstance();
//	return 0;
//}
//
