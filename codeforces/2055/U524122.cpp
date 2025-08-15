// 无头链表
// 单向
#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

struct NODE{
	i64 val;
	NODE* next;
};

struct LIST{
	NODE* head;
	int length;

	LIST() {
		head = (NODE*)malloc(sizeof(NODE));
		length = 0;
		*head = {NULL, nullptr};
	}

	NODE* createNode(i64 val) {
		NODE* node = (NODE*)malloc(sizeof(NODE));
		*node = {val, nullptr};
		return node;
	}

	void insert(int pos, i64 val) {
		assert(pos <= length);
		NODE* ptr = head;
		for (int i = 1; i <= pos; i++) {
			ptr = ptr->next;
		}
		// ptr (new) ptr.next
		NODE* newNode = createNode(val);
		newNode->next = ptr->next;
		ptr->next = newNode;
		length++;
	}

	int find(i64 val) {
		NODE* ptr = head;
		for (int i = 1; i <= length; i++) {
			ptr = ptr->next;
			if (ptr->val == val) {
				return i;
			} 
		}
		return -1;
	}

	void erase(int pos) {
		assert(pos <= length);
		NODE* ptr = head;
		NODE* prePtr, *nowPtr, *posPtr;
		for (int i = 1; i <= pos + 1; i++) {
			ptr = ptr->next;
			if (i == pos - 1) {
				prePtr = ptr;
			} else if (i == pos) {
				nowPtr = ptr;
			} else if (i == pos + 1) {
				posPtr = ptr;
			}
		}
		prePtr->next = posPtr;
		free(nowPtr);
		length--;
	}

	void clear() {
		NODE* ptr = head;
		for (int i = 1; i <= length; i++) {
			free(head);
			head = ptr->next;
			ptr = ptr->next;
		}
		length = 0;
	}

	void print() {
		NODE* ptr = head;
		for (int i = 1; i <= length; i++) {
			ptr = ptr->next;
			std::cout << ptr->val;
			std::cout << (i == length ? "\n" : "->");
		}
	}
};

void solve() {
	LIST list;
	list.insert(0, 10);
	list.insert(1, 15);
	list.insert(2, 20);
	list.print();
	std::cout << list.find(15) << '\n';
	list.clear();
	list.insert(0, 200);
	list.insert(1, 150);
	list.insert(0, 15);
	list.insert(1, 25);
	list.insert(0, 1);
	list.insert(1, 2);
	list.print();
	list.erase(3);
	list.print();
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}