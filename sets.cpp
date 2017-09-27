#include "sets.h"
#include <cstring>
#include <string>
#include <bitset>

enum { SET_POWER = 16 };


namespace SetsOperations
{
    char* unite(char* A, char* B)
    {
        char* C = new char[SET_POWER + 1];
        int k = 0;

        for (int i = 0; i < strlen(A); i++)
        {
            int j = 0;
            for(; j < strlen(B); j++)
                if (A[i] == B[j])
                    break;
            if (B[j] == '\0')
                C[k++] = A[i];

        }
        for (int i = 0; (k < 17) && (i < strlen(B) ); k++, i++)
        {
            C[k] = B[i];
        }
        C[k] = '\0';

        return C;
    }

    char* cross(char* A, char* B)
    {
        char* C = new char[SET_POWER + 1];
        int k = 0;

        for (int i = 0; i < strlen(A); i++)
            for(int j = 0; j < strlen(B); j++)
                if (A[i] == B[j])
                    C[k++] = A[i];
        C[k] = '\0';

        return C;
    }
	
    char* triple_cross(char* A, char* B, char* C)
    {
        return cross(A, cross(B, C));
    }
	
};

namespace ListOperations
{
    ListNode* str_to_list(char* str)
    {
        ListNode* list_head {nullptr};
        for(int i = 0; str[i]; i++)
        {
            list_head = add_element_to_list(list_head, str[i]);
        }
		return list_head;
    };

    ListNode* add_element_to_list(ListNode* list_head, char ch)
    {
        if (!is_element_in_list(list_head,  ch))
        {
            ListNode* tail = list_head;
            if (tail)
            {
                while (tail->next) tail = tail->next;
                tail->next = new ListNode{ch};
            }
            else
            {
                list_head = new ListNode{ch};
            }
        }
        return list_head;
    };

    bool is_element_in_list(ListNode* list_head, char ch)
    {
        for (auto i = list_head; i != nullptr; i = i->next)
        {
            if (ch == i->data)
                return true;
        }
        return false;
    }

    void show(ListNode* head)
    {
        for (auto i = head; i != nullptr; i = i->next)
			std::cout << i->data;
        std::cout << std::endl;
    }

	ListNode* cross(ListNode* head_1, ListNode* head_2)
    {
        ListNode* new_head{nullptr};

        for (auto cur = head_1; cur; cur = cur->next)
        {
            for(auto cur2 = head_2; cur2; cur2 = cur2->next)
				if (cur->data == cur2->data)
					new_head = add_element_to_list(new_head, cur->data);
        }

        return new_head;
    };

	ListNode* unite(ListNode* head_1, ListNode* head_2)
    {
        ListNode* new_head{nullptr};

        for (auto cur = head_1; cur; cur = cur->next)
        {
            auto cur2 = head_2;
            for(; cur2; cur2 = cur2->next)
				if (cur->data == cur2->data)
					break;
            if (!cur2)
				new_head = add_element_to_list(new_head, cur->data);
        }
        for (auto cur2 = head_2; cur2; cur2 = cur2->next)
        {
			new_head = add_element_to_list(new_head, cur2->data);
        }

        return new_head;
    };
};

namespace BitsOperations
{
	int ctb(char ch)
	{
		int bytes = 0x0;

		if (ch >= '0' && ch <= '9')
			bytes = 0x1 << (ch - '0');
		else if (ch >= 'A' && ch <= 'F')
			bytes = 0x400 << (ch - 'A');
		else if (ch >= 'a' && ch <= 'f')
			bytes = 0x400 << (ch - 'a');

		return bytes;
	}

	std::string bts(int bytes)
	{
		std::string str{};
		char cur_hex_digit{ '0' };
		while (bytes)
		{
			if (cur_hex_digit == '9' + 1)
				cur_hex_digit = 'A';
			else if (cur_hex_digit == 'F' + 1)
				break;

			if (bytes & 0x1)
				str += cur_hex_digit;

			cur_hex_digit++;
			bytes >>= 1;
		}

		return str;
	};

	int stb(const std::string& str)
	{
		int new_arr{ 0x0 };
		for (auto ch : str)
			new_arr |= ctb(ch);

		return new_arr;
	};
};
