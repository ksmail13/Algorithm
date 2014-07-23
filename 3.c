#include <stdio.h>
#include <string.h>

#define ISNUM(c) ((c) >= '0' && (c) <= '9')

#define LIMIT 1000
#define STRMAX 101
struct listnode {
	char data[STRMAX];
	int len;
	struct listnode *next;
};

int string_num_cmp(const char *s1, const char *s2) {
	int s1len = strlen(s1), s2len = strlen(s2);
	
	//printf("compare %s %s\n", s1, s2);
	
	if(s1len > s2len) {
		return 1;
	}
	else if(s1len < s2len) {
		return -1;
	}
	else {
		return strcmp(s1, s2);
	}
}

int add(struct listnode **start, struct listnode *node) {
	struct listnode *temp = *start;
	if(!(*start))
		*start = node;
	else {
		temp = *start;
		// 시작 데이터와 비교해서 
		if(string_num_cmp(temp->data, node->data) >= 0) {
			*start = node;
			node->next =  temp;
		}
		else {
			int add=0;
			while(temp->next) {
				// 다음 데이터가 추가한 데이터 보다 크거나 같을 때
				if(string_num_cmp(temp->next->data, node->data) >= 0) {
					node->next = temp->next;
					temp->next = node;
					add=1;
					break;
				}
				
				temp = temp->next;
			}
			
			if(!add) {
				temp->next = node;
			}
		}
	}
}

int main() {
	int testcase;
	scanf("%d", &testcase);
	
	while(testcase--) {
		int lcnt;
		int i,j, len;
		char str[STRMAX];
		struct listnode node[LIMIT] = {};
		struct listnode *start = NULL, *temp, *before;
		
		int nidx=0;
		scanf("%d", &lcnt);
		
		for(i=0;i<lcnt;i++) {
			int before_num=0;
			scanf("%s", str);
			len = strlen(str);
			
			// 문자열을 순회하면서 숫자를 추가한다.
			for(j=0;j<len;j++) {
				if(ISNUM(str[j])) {
					
					node[nidx].data[node[nidx].len] = str[j];
					if(!(node[nidx].len==0 && str[j] == '0'))
						node[nidx].len++;
						
					before_num = 1;
				}
				else if(before_num) {
					add(&start, &node[nidx]);
					
					nidx++;
					before_num = 0;
				}
			}
			if(before_num) {
				add(&start, &node[nidx]);
				before_num = 0;
				nidx++;
			}
			
		}
		
		temp = start;
		
		
		while(temp) {
			printf("%s\n", temp->data);
			temp = temp->next;
		}
		
	}
	return 0;
}