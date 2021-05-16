#pragma once
#include <string>
#include <iostream>

struct TList_Item {
	int inf;
	TList_Item* next;
};

struct Stack {
public:
	TList_Item* sp;
	Stack() {
		sp = NULL;
	}
};

struct Stat_List {
public:
	TList_Item* pHead;
	Stat_List() {
		pHead = new TList_Item();
		pHead->next = 0;
	}
};

	int Push_after(Stat_List* list, int t, int inf) {
		if (t < 0) return 2;
		TList_Item* pCurrent = list->pHead;
		TList_Item* pTemp = new TList_Item();
		for (int i = 0; i < t; i++) {
			if (pCurrent->next == NULL) return 0;
			pCurrent = pCurrent->next;
		}
		pTemp->next = pCurrent->next;
		pCurrent->next = pTemp;
		pTemp->inf = inf;
		return 1;
	}
	int Push_before(Stat_List* list, int t, int inf) {
		if (t < 1) return 0;
		TList_Item* pCurrent = list->pHead;
		TList_Item* pPrev;
		TList_Item* pTemp = new TList_Item();
		for (int i = 0; i < t; i++) {
			if (pCurrent->next == NULL) return 0;
			pPrev = pCurrent;
			pCurrent = pCurrent->next;
		}
		pTemp->next = pCurrent;
		pPrev->next = pTemp;
		pTemp->inf = inf;
		return 1;
	}
	std::string Delete(Stat_List* list, int inf) {
		TList_Item* pCurrent = list->pHead;
		TList_Item* pPrev;
		while(pCurrent != NULL) {
			if (pCurrent->inf == inf) {
				pPrev->next = pCurrent->next;
				delete(pCurrent);
				return "The element was deleted.";
			}
			pPrev = pCurrent;
			pCurrent = pCurrent->next;
		}
		return "The element not found.";
	}

	TList_Item* Pop(Stat_List* list, int inf) {
		TList_Item* pCurrent = list->pHead;
		TList_Item* pPrev;
		while (pCurrent != NULL) {
			if (pCurrent->inf == inf) {
				pPrev->next = pCurrent->next;
				return pCurrent;
			}
			pPrev = pCurrent;
			pCurrent = pCurrent->next;
		}
		return NULL;
	}

	void Push(Stack* stack, TList_Item* a) {
		if (a != NULL) {
			a->next = stack->sp;
			stack->sp = a;
		}
	}


	std::string Get(Stat_List* list, int inf) {
		TList_Item* pCurrent = list->pHead;
		int i = 1;
		while (pCurrent->next != NULL) {
			pCurrent = pCurrent->next;
			if (pCurrent->inf == inf) return "The number with inf: | " + std::to_string(pCurrent->inf)+" | has index: | " + std::to_string(i) + " |.";
			i++;
		}
		return "The number with inf : | " + std::to_string(inf)+" | not found. ";
	}

	std::string Show(Stat_List* list) {
		std::string str;
		TList_Item* pCurrent = list->pHead->next;
		while(pCurrent != NULL) {
			str += " || " + std::to_string(pCurrent->inf) + " || ";
			pCurrent = pCurrent->next;
		}
		return str;
	}

	std::string Show(Stack* stack) {
		std::string str;
		TList_Item* pCurrent = stack->sp;
		while (pCurrent != NULL) {
			str += " || " + std::to_string(pCurrent->inf) + " || ";
			pCurrent = pCurrent->next;
		}
		return str;
	}


