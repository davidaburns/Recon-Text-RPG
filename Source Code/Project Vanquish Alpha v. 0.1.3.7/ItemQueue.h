//#ifndef ITEMQueue_H
//#define ITEMQueue_H
//
//#include "Library.h"
//
//template <class T>
//class Queue
//{
//public:
//	T* Data;
//	unsigned int MaxSize;
//	unsigned short int Top;
//	unsigned short int Bottom;
//
//	Queue(unsigned int Limit);
//	~Queue();
//
//	void Push(T Temp);
//	void Display();
//	void GiveItems();
//	void CompleteQuest(std::string Id);
//	bool Is_Empty();
//	bool Is_Full();
//};
//
//template <class T>
//Queue<T>::Queue(unsigned int Limit = 1)
//{
//	MaxSize = Limit;
//	Data = new T[Limit];
//	Bottom = 0;
//	Top = 0;
//}
//
//template <class T>
//Queue<T>::~Queue()
//{
//}
//
//template <class T>
//void Queue<T>::Push(T Temp)
//{
//	Data[Top] = Temp;
//	Top++;
//
//	if(Top >= MaxSize && !Is_Full())
//	{
//		Top = 0;
//	}
//}
//
//template <class T>
//void Queue<T>::Display()
//{
//	for(unsigned int i = Bottom; i != Top; i++)
//	{
//		if(i >= MaxSize)
//		{
//			i = 0;
//		}
//		std::cout << Data[0].Name << std::endl;
//	}
//}
//
//template <class T>
//void Queue<T>::GiveItems()
//{
//	for(unsigned int i = Bottom; i != Top; i++)
//	{
//		if(i >= MaxSize)
//		{
//			i = 0;
//		}
//		Engine->Player.Inventory->AddItem(&Data[i], 1);
//	}
//}
//
//template <class T>
//void Queue<T>::CompleteQuest(std::string Id)
//{
//}
//
//template <class T>
//bool Queue<T>::Is_Empty()
//{
//	if(Bottom == Top)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//template <class T>
//bool Queue<T>::Is_Full()
//{
//	if(Top == Bottom -1 || Top == MaxSize)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//#endif