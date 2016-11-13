#ifndef Queue_H
#define Queue_H

#include "Library.h"

template <class Type>
class LinkedList
{
protected:
	struct Link				//The link
	{
		Type Data;
		Link* Next;
		Link* Previous;
	};

public:
	Link* First;
	Link* Last;
	unsigned int Count;

	LinkedList()
	{
		First = NULL;
		Last = NULL;
		Count = 0;
	}

	~LinkedList()
	{
	}

	void Insert(Type Item)
	{
		Link* NewLink = new Link;
		NewLink->Data = Item;

		Count++;

		if(First == NULL && Count == 0)
		{
			First = NewLink;
			Last = NewLink;
			NewLink->Next = NULL;
			NewLink->Previous = NULL;
			return;
		}
		else
		{
			Link* Temp = First;
			First = NewLink;
			Temp->Previous = NewLink;
			NewLink->Next = First;
		}
	}

	void Display()
	{
		Link* Current = First;

		for(unsigned int i = 0; i < Count; i++)
		{
			std::cout << Current->Data.Name << std::endl;
			Current = Current->Next;
		}
	}

	void GiveItems()
	{
		if(Count < 1)
		{
			return;
		}

		Link* Current = First;
		unsigned int i = 0;

		while(i < Count)
		{
			Engine->Player.Inventory->AddItem(Current.Data, 1);
			Current = Current.Next;
			RemoveFirst();
			Count--;
		}
	}

	void ReceiveItem()
	{
		if(rand%()Engine->Monster->Luck > Engine->Monster->Luck * .70)
		{
			unsigned int Temp = rand%()Count;

			if(IsEmpty() == true)
			{
				return;
			}

			Link* Current = First;

			for(unsigned int i = 0; i < Count; i++)
			{
				Current = Current.Next;
			}
			Engine->Player.Inventory->AddItem(Current.Data, 1);
		}
	}

	void RemoveFirst()
	{
		if(IsEmpty() == true)
		{
			return;
		}

		Link* Temp = First.Next;
		delete First;
		First = Temp;
		First.Previous = NULL;
	}

	void Remove(Type Item)
	{
		if(IsEmpty() == true)
		{
			return;
		}

		Link* Current = First;

		for(unsigned int i = 0; i < Count && Current->Data.Name != Item.Name; i++)
		{
			Current = Current.Next;
		}

		if(Current->Data.Name != First->Data.Name && Current->Data.Name != Last->Data.Name)
		{
			Current.Previous = Current.Next;
			Current.Next = Current.Previous;
			delete Current;
			Count--;
		}
		else if(Current->Data.Name == First->Data.Name)
		{
			RemoveFirst();
		}
		else if(Current->Data.Name == Last->Data.Name)
		{
			RemoveLast();
		}
	}

	void RemoveLast()
	{
		if(IsEmpty() == true)
		{
			return;
		}

		Link* Temp = Last.Previous;
		delete Last;
		Last = Temp;
		Last.Next = NULL;
	}

	bool IsEmpty()
	{
		if(Count == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

#endif