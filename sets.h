#ifndef SETS_H
#define SETS_H
#include <iostream>

struct ListNode
{
    char data;
    ListNode* next;

    ListNode (char d, ListNode* n=nullptr) : data{d}, next{n} {};
    ~ListNode() { delete next; };
};

namespace SetsOperations
{
	char* unite(char*, char*);
	char* cross(char*, char*);
	char* triple_cross(char*, char*, char*);
};

namespace ListOperations
{
    ListNode* str_to_list(char* str);
    ListNode* add_element_to_list(ListNode* list_head, char ch);
    bool is_element_in_list(ListNode* list_head, char ch);
	void show(ListNode* head);
	ListNode* cross(ListNode* head_1, ListNode* head_2);
	ListNode* unite(ListNode* head_1, ListNode* head_2);

};

namespace BitsOperations
{
	int ctb(char ch);
	std::string bts(int bytes);
	int stb(const std::string& str);
};


#endif
