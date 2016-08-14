///********************            单例模式(Singleton)                  ********************/
///*************			特点：①单例类保证全局只有一个唯一的实例对象；     ***************/
///*************				  ②单例类提供获取这个唯一实例的接口。         ***************/
//
//
//1.饿汉式Ⅰ
//#include<iostream>
//using namespace std;
//
//class Singleton
//{
//public:
//	static Singleton* GetInstance()//获取唯一实例对象的接口
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
//	Singleton()//构造函数的私有限制了只能在类内创建对象
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
//2.饿汉式Ⅱ
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
//3.不考虑线程安全的单例类
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
//4.线程安全的单例类
//#include<iostream>
//using namespace std;
//
//#include<mutex>
//class Singleton
//{
//public:
//	static Singleton* GetInstance()//双重检查提高效率的同时避免了高并发场景下每次获取实例对象时都要进行加锁的性能消耗
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
////上述内层if中的语句并非无懈可击，因为其现代的计算机系统为提高性能采取乱序执行，也就是说比如这里的_sInstance=new Singleton();这条语句实际可分为分配空间、调用构造函数、赋值操作这三个步骤，分配空间为首要步骤这毋庸置疑，但编译器编译优化时可能会对第二和第三步骤的指令进行重排，所以一旦处于高并发的环境时，可能优先执行了第三步骤（此时构造函数未能正确调用，使得本应由改造函数初始化对象未能正确处理），而当其他线程进入获取这个对象时，此时的对象中的成员变量已经不是预期的正确数值，所以这里引入了内存栅栏（内存屏障）的概念予以解决。
////内存栅栏（内存屏障）： 是一类同步屏障指令，使得CPU或编译器在对内存随机访问的操作中的一个同步点，使得此点之前的所有读写操作都执行后才可以开始执行此点之后的操作。
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
